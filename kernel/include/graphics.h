<<<<<<< HEAD
#pragma once

#include <stdint.h>
#include <stddef.h>
#include <limine.h>
#include <main.h>

/// @brief Sets a pixel on the screen / framebuffer to a color.
void setPixel(uint32_t color, int x, int y);
// Gets a pixel on the screen / framebuffer and returns the color.
uint32_t getPixel(int x, int y);
// Draws a filled rectangle onto the screen / framebuffer
void drawRect(uint32_t color, int x, int y, int w, int h);
// Clears the screen / framebuffer.
void clear(uint32_t color);
=======
#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <stdint.h>
#include <stddef.h>
#include <limine.h>

// Sets a pixel on the screen / framebuffer to a color.
void setPixel(struct limine_framebuffer *fb, uint32_t color, int x, int y);
// Gets a pixel on the screen / framebuffer and returns the color.
uint32_t getPixel(struct limine_framebuffer *fb, int x, int y);
// Draws a filled rectangle onto the screen / framebuffer
void drawRect(struct limine_framebuffer *fb, uint32_t color, int x, int y, int w, int h);
// Clears the screen / framebuffer.
void clear(struct limine_framebuffer *fb, uint32_t color);

#endif
>>>>>>> b8148e61b8142a029bdccc0b3d7358738ed5ef88
