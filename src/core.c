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
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int xi = (x0 < x1) ? 1 : -1;
    int yi = (y0 < y1) ? 1 : -1;
    int steep = dy > dx;
    int D, x, y;

    if (steep) { // step along y
        if (y0 > y1) { // swap to go top to bottom
            int tmp;
            tmp = x0; x0 = x1; x1 = tmp;
            tmp = y0; y0 = y1; y1 = tmp;
            xi = -xi;
            yi = -yi;
        }
        D = 2*dx - dy;
        x = x0;
        for (y = y0; y <= y1; ++y) {
            fb_put_pixel(fb, x, y, color);
            if (D > 0) {
                x += xi;
                D += 2*(dx - dy);
            } else {
                D += 2*dx;
            }
        }
    } else { // step along x
        if (x0 > x1) { // swap to go left to right
            int tmp;
            tmp = x0; x0 = x1; x1 = tmp;
            tmp = y0; y0 = y1; y1 = tmp;
            xi = -xi;
            yi = -yi;
        }
        D = 2*dy - dx;
        y = y0;
        for (x = x0; x <= x1; ++x) {
            fb_put_pixel(fb, x, y, color);
            if (D > 0) {
                y += yi;
                D += 2*(dy - dx);
            } else {
                D += 2*dy;
            }
        }
    }
}

void fb_draw_tri_wire(Framebuffer* fb, vec2 a, vec2 b, vec2 c, u32 color) {
    fb_draw_line(fb, a.x, a.y, b.x, b.y, color);
    fb_draw_line(fb, b.x, b.y, c.x, c.y, color);
    fb_draw_line(fb, c.x, c.y, a.x, a.y, color);
}

void fb_draw_tri(Framebuffer* fb, vec2 a, vec2 b, vec2 c, u32 color) {
    if (a.y > b.y) swap(&a, &b);
    if (a.y > c.y) swap(&a, &c);
    if (b.y > c.y) swap(&b, &c);

    if (a.y == b.y) { // flat top
        float invslope1 = (c.x - a.x) / (c.y - a.y);
        float invslope2 = (c.x - b.x) / (c.y - b.y);

        float curx1 = c.x;
        float curx2 = c.x;

        for (int scanlineY = c.y; scanlineY > a.y; --scanlineY) {
            fb_draw_line(fb, (int)curx1, scanlineY, (int)curx2, scanlineY, color);
            curx1 -= invslope1;
            curx2 -= invslope2;
        }

    } else if (b.y == c.y) { // flat bottom
        float invslope1 = (b.x - a.x) / (b.y - a.y);
        float invslope2 = (c.x - a.x) / (c.y - a.y);

        float curx1 = a.x;
        float curx2 = a.x;

        for (int scanlineY = a.y; scanlineY <= b.y; ++scanlineY) {
            fb_draw_line(fb, (int)curx1, scanlineY, (int)curx2, scanlineY, color);
            curx1 += invslope1;
            curx2 += invslope2;
        }

    } else { // general case - split the triangle in twain
        vec2 d = {(int)(a.x + (float)(b.y - a.y) / (float)(c.y - a.y)*(c.x - a.x)), b.y};

        // flat bottom part
        float invslope1 = (b.x - a.x) / (b.y - a.y);
        float invslope2 = (d.x - a.x) / (d.y - a.y);

        float curx1 = a.x;
        float curx2 = a.x;

        for (int scanlineY = a.y; scanlineY <= b.y; ++scanlineY) {
            fb_draw_line(fb, (int)curx1, scanlineY, (int)curx2, scanlineY, color);
            curx1 += invslope1;
            curx2 += invslope2;
        }

        // flat top part
        invslope1 = (c.x - b.x) / (c.y - b.y);
        invslope2 = (c.x - d.x) / (c.y - d.y);

        curx1 = c.x;
        curx2 = c.x;

        for (int scanlineY = c.y; scanlineY > b.y; --scanlineY) {
            fb_draw_line(fb, (int)curx1, scanlineY, (int)curx2, scanlineY, color);
            curx1 -= invslope1;
            curx2 -= invslope2;
        }
    }
}

void fb_draw_cir_wire(Framebuffer* fb, int cx, int cy, int r, u32 color) {
    if (r <= 0) {
        fb_put_pixel(fb, cx, cy, color);
        return;
    }
    int x = r;
    int y = 0;
    int E = 3 - 2*r;

    while (x >= y) {
        fb_put_pixel(fb, cx + x, cy + y, color);
        fb_put_pixel(fb, cx - x, cy + y, color);
        fb_put_pixel(fb, cx + x, cy - y, color);
        fb_put_pixel(fb, cx - x, cy - y, color);
        fb_put_pixel(fb, cx + y, cy + x, color);
        fb_put_pixel(fb, cx - y, cy + x, color);
        fb_put_pixel(fb, cx + y, cy - x, color);
        fb_put_pixel(fb, cx - y, cy - x, color);

        if (E < 0) {
            E += 4*y + 6;
        } else {
            E += 4*(y - x) + 10;
            --x;
        }
        ++y;
    }
}
