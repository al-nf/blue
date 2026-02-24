#ifndef CORE_H
#define CORE_H
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "vec.h"
#define u32 uint32_t

typedef struct Framebuffer {
    int width;
    int height;
    u32* pixels;
} Framebuffer;

Framebuffer* init_framebuffer(int width, int height);
void fb_clear(Framebuffer* fb, u32 color);
void fb_put_pixel(Framebuffer* fb, int x, int y, u32 color);
void fb_draw_line(Framebuffer* fb, int x0, int y0, int x1, int y1, u32 color);
void fb_draw_tri_wire(Framebuffer* fb, vec2 a, vec2 b, vec2 c, u32 color);
void fb_draw_tri(Framebuffer* fb, vec2 a, vec2 b, vec2 c, u32 color);
void fb_draw_cir_wire(Framebuffer* fb, int cx, int cy, int r, u32 color);
void fb_draw_cir(Framebuffer* fb, int cx, int cy, int r, u32 color);
void fb_draw_rect_wire(Framebuffer* fb, int x, int y, int w, int h, u32 color);
void fb_draw_rect(Framebuffer* fb, int x, int y, int w, int h, u32 color);

#endif // CORE_H
