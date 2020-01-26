#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <cstdint>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include "map.h"
#include "utils.h"
#include "player.h"
#include "framebuffer.h"
#include "textures.h"
#include "sprite.h"

// Расчёт x координаты для текстурирования стены
int wall_x_texcoord(const float hitx, const float hity, Texture &tex_walls) {
    float x = hitx - floor(hitx+.5);
    float y = hity - floor(hity+.5);

    int tex = x * tex_walls.size;

    if (std::abs(y)>std::abs(x))
    {
        tex = y * tex_walls.size;
    }

    if (tex<0)
    {
        tex += tex_walls.size;
    }

    assert(tex>=0 && tex<(int)tex_walls.size);
    return tex;
}

void map_show_sprite(Sprite& sprite, FrameBuffer& fb, Map& map) {
    const size_t rect_w = fb.image_width / (map.width * 2);
    const size_t rect_h = fb.image_height / map.height;
    fb.draw_rectangle(sprite.x * rect_w - 3, sprite.y * rect_h - 3, 6, 6, pack_color(255, 0, 0));
}

void draw_sprite(Sprite &sprite, std::vector<float>& depth_buffer,
        FrameBuffer &fb, Player &player, Texture &tex_sprites) {
    // Вычисляем абсолютный угол между игроком и врагом в радианах
    float sprite_dir = atan2(sprite.y - player.y_pos, sprite.x - player.x_pos);

    // Убираем лишнии периоды
    while (sprite_dir - player.a >  M_PI) sprite_dir -= 2*M_PI;
    while (sprite_dir - player.a < -M_PI) sprite_dir += 2*M_PI;

    size_t sprite_screen_size;

    if (sprite.player_dist)
    {
        sprite_screen_size = std::min(1000, static_cast<int>(fb.image_height / sprite.player_dist));
    }
    else
    {
        sprite_screen_size = 1000;
    }

    int h_offset = (sprite_dir - player.a)/player.fov*(fb.image_width / 2) + (fb.image_width / 2) / 2 - tex_sprites.size / 2; // do not forget the 3D view takes only a half of the framebuffer
    int v_offset = fb.image_height / 2 - sprite_screen_size / 2;

    for (size_t i = 0; i < sprite_screen_size; ++i)
    {
        if (h_offset + i < 0 || h_offset + i >= fb.image_width / 2) continue;
        if (depth_buffer[h_offset + i] < sprite.player_dist) continue;
        for (size_t j = 0; j < sprite_screen_size; ++j)
        {
            if (v_offset + j < 0 || v_offset + j >= fb.image_height) continue;
            uint32_t color = tex_sprites.get(i * tex_sprites.size / sprite_screen_size,
                    j * tex_sprites.size / sprite_screen_size, sprite.tex_id);
            uint8_t r, g, b, a;
            unpack_color(color, r, g, b, a);
            if (a > 128)
            {
                fb.set_pixel(fb.image_width / 2 + h_offset + i, v_offset + j, color);
            }
        }
    }
}

void render(FrameBuffer& fb, Map& map, Player& player, std::vector<Sprite>& sprites,
        Texture& tex_walls, Texture& tex_monsters) {
    fb.clear(pack_color(255, 255, 255));
    const size_t rect_w = fb.image_width / (map.width * 2);
    const size_t rect_h = fb.image_height / map.height;

    for (size_t j = 0; j < map.height; ++j)
    {
        for (size_t i = 0; i < map.width; ++i)
        {
            if (map.isEmpty(i,j)) continue;
            size_t rect_x = i * rect_w;
            size_t rect_y = j * rect_h;
            size_t texid = map.get(i,j);

            assert(texid < tex_walls.count);

            fb.draw_rectangle(rect_x, rect_y, rect_w, rect_h, tex_walls.get(0,0,texid));
        }
    }

    std::vector<float> depth_buffer(fb.image_width / 2, 1e3);
    for (size_t i = 0; i < fb.image_width / 2; ++i)
    {
        float angle = player.a - player.fov / 2 + player.fov * i / float(fb.image_width / 2);
        for (float t = 0; t < 20; t += .01)
        {
            float x = player.x_pos + t*cos(angle);
            float y = player.y_pos + t*sin(angle);

            fb.set_pixel(x*rect_w, y*rect_h, pack_color(160, 160, 160));

            if (map.isEmpty(x, y)) continue;

            size_t texid = map.get(x, y);
            assert(texid < tex_walls.count);

            float dist = t*cos(angle-player.a);
            depth_buffer[i] = dist;
            size_t column_height = fb.image_height / dist;

            int x_texcoord = wall_x_texcoord(x, y, tex_walls);
            std::vector<uint32_t> column = tex_walls.get_scaled_column(texid, x_texcoord, column_height);

            int pix_x = i + fb.image_width / 2;
            for (size_t j = 0; j < column_height; ++j) {
                int pix_y = j + fb.image_height / 2 - column_height / 2;
                if (pix_y >= 0 && pix_y < (int)fb.image_height)
                {
                    fb.set_pixel(pix_x, pix_y, column[j]);
                }
            }
            break;
        }
    }

    for (size_t i = 0; i < sprites.size(); ++i)
    {
        sprites[i].player_dist = std::sqrt(pow(player.x_pos - sprites[i].x, 2) +
                pow(player.y_pos - sprites[i].y, 2));
    }
    std::sort(sprites.begin(), sprites.end()); // sort it from farthest to closest

    for (size_t i = 0; i < sprites.size(); ++i)
    {
        map_show_sprite(sprites[i], fb, map);
        draw_sprite(sprites[i],depth_buffer, fb, player, tex_monsters);
    }
}

int main() {
    FrameBuffer fb{1024, 512,
                   std::vector<uint32_t>(1024*512, pack_color(255, 255, 255))};
    Player player{3.456, 2.345, 1.523, M_PI/3.};
    Map map;
    Texture tex_walls("../Textures/walltext.png");
    Texture tex_monst("../Textures/monsters.png");

    if (!tex_walls.count || !tex_monst.count)
    {
        std::cerr << "Failed to load textures" << std::endl;
        return -1;
    }

    std::vector<Sprite> sprites{ {3.523, 3.812, 2}, {1.834, 8.765, 0},
                                 {5.323, 5.365, 1}, {4.123, 10.265, 1} };

    for (size_t frame = 0; frame < 1; ++frame)
    {
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(5) << frame << ".ppm";
        player.a += 2 * M_PI / 360;
        render(fb, map, player, sprites, tex_walls, tex_monst);
        drop_ppm_image(ss.str(), fb.image, fb.image_width, fb.image_height);
    }
    return 0;
}
