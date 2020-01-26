#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <cstdlib>
#include <vector>
#include <cstdint>

class FrameBuffer {
private:

public:
    size_t image_width, image_height;
    std::vector<uint32_t> image;

    void clear(const uint32_t color);
    void set_pixel(const size_t x, const size_t y, const uint32_t color);

    // Рисует закрашенный прямоугольник, где x,y - координаты нижнего левого угла.
    void draw_rectangle(const size_t x, const size_t y, const size_t w, const size_t h, const uint32_t color);
};


#endif // FRAMEBUFFER_H
