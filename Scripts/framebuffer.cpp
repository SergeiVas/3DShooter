#include <iostream>
#include <vector>
#include <cstdint>
#include <cassert>

#include "framebuffer.h"
#include "utils.h"


void FrameBuffer::set_pixel(const size_t x, const size_t y, const uint32_t color)
{
    assert(image.size() == image_width * image_height && x < image_width && y < image_height);
    image[x + y * image_width] = color;
}

void FrameBuffer::draw_rectangle(const size_t rect_x, const size_t rect_y,
                                 const size_t rect_w, const size_t rect_h, const uint32_t color)
{
    assert(image.size() == image_width * image_height);
    for (size_t i = 0; i < rect_w; ++i)
    {
        for (size_t j = 0; j < rect_h; ++j)
        {
            size_t cx = rect_x + i;
            size_t cy = rect_y + j;
            if (cx < image_width && cy < image_height)
            {
                set_pixel(cx, cy, color);
            }
        }
    }
}

void FrameBuffer::clear(const uint32_t color)
{
    image = std::vector<uint32_t>(image_height * image_width, color);
}