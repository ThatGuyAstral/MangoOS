#pragma once

#include <stdint.h>
#include <stddef.h>
#include <limine.h>
#include <main.h>

/// @brief Sets a pixel on the screen / framebuffer to a color.
void setPixel(uint32_t color, int x, int y);
/// @brief Gets a pixel on the screen / framebuffer and returns the color.
uint32_t getPixel(int x, int y);
/// @brief Draws a filled rectangle onto the screen / framebuffer
void drawRect(uint32_t color, int x, int y, int w, int h);
/// @brief Clears the screen / framebuffer.
void clear(uint32_t color);
