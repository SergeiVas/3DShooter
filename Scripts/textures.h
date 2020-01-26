#ifndef TEXTURES_H
#define TEXTURES_H

#include <vector>
#include <cstdint>
#include <string>

class Texture
{
private:
public:
    size_t img_w, img_h;
    size_t count, size;
    std::vector<uint32_t> img;

    //Загружает текстуру filename и записывает ее в img
    Texture(const std::string filename);

    //Возвращает i-ый, j-ый пиксель текстуры под номером idx
    uint32_t& get(const size_t i, const size_t j, const size_t idx);

    // Накладываем текстуру на вертикальную линию
    std::vector<uint32_t> get_scaled_column(const size_t texture_id,
            const size_t tex_coord, const size_t column_height);
};


#endif // TEXTURES_H
