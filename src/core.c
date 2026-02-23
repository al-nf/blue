#include "core.h"

Framebuffer* init_framebuffer(int width, int height) {
    Framebuffer* fb = malloc(sizeof(Framebuffer));
    fb->width = width;
    fb->height = height;
    fb->pixels = malloc(sizeof(u32)*width*height);
    return fb;
}

void fb_clear(Framebuffer* fb, u32 color) {
    for (int i = 0; i < (fb->width * fb->height); ++i) {
        fb->pixels[i] = color;
    }
}

void fb_put_pixel(Framebuffer* fb, int x, int y, u32 color) {
    if (x < 0 || x >= fb->width || y < 0 || y >= fb->height) {
        return;
    }
    fb->pixels[(y * fb->width) + x] = color;
}

void fb_draw_line(Framebuffer* fb, int x0, int y0, int x1, int y1, u32 color) {
    for (int x = x0; x <= x1; ++x) {
        int y = (y1-y0)*(x-x0)/(x1-x0) + y0;
        fb_put_pixel(fb, x, y, color);
    }
}

void fb_draw_tri_wire(Framebuffer* fb, vec2 a, vec2 b, vec2 c, u32 color) {
    fb_draw_line(fb, a.x, a.y, b.x, b.y, color);
    fb_draw_line(fb, b.x, b.y, c.x, c.y, color);
    fb_draw_line(fb, c.x, c.y, a.x, a.y, color);
}

void fb_draw_tri(Framebuffer* fb, vec2 a, vec2 b, vec2 c, u32 color) {
    // TODO: implement triangle rasterization
}
