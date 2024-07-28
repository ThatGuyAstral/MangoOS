#include <graphics.h>

void setPixel(uint32_t color, int x, int y) {
    volatile uint32_t *ptr = (uint32_t*)fb->address;
    ptr[y * fb->width + x] = color;
}

uint32_t getPixel(int x, int y) {
    volatile uint32_t *ptr = (uint32_t*)fb->address;
    return ptr[y * fb->width + x];
}

void drawRect(uint32_t color, int x, int y, int w, int h) {
    volatile uint32_t *ptr = (uint32_t*)fb->address;
    for (size_t i = x; i < x + w; i++)
        for (size_t j = y; j < y + h; j++)
            ptr[j * fb->width + i] = color; 
}

void clear(uint32_t color) {
    volatile uint32_t *ptr = (uint32_t*)fb->address;
    for (size_t i = 0; i < fb->width; i++)
        for (size_t j = 0; j < fb->height; j++)
            ptr[j * fb->width + i] = color; 
}