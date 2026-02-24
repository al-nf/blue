#include "core.h"
#include "platform.h"
#include <SDL3/SDL.h>
#include <stdbool.h>

#define WIDTH 512
#define HEIGHT 512

#define BLACK 0xFF000000
#define WHITE 0xFFFFFFFF
#define RED 0xFFFF0000
#define GREEN 0xFF00FF00
#define BLUE 0xFF0000FF
#define YELLOW 0xFFFFFF00
#define CYAN 0xFF00FFFF
#define MAGENTA 0xFFFF00FF
#define ORANGE 0xFFFF8800

static void draw_all(Framebuffer* fb) {
    fb_clear(fb, BLACK);

    // fb_put_pixel: small cluster top-left
    for (int dy = 0; dy < 4; ++dy)
        for (int dx = 0; dx < 4; ++dx)
            fb_put_pixel(fb, 10 + dx, 10 + dy, WHITE);

    // fb_draw_line: vertical, horizontal, diagonal, shallow, steep
    fb_draw_line(fb, 60, 10, 60, 110, RED);
    fb_draw_line(fb, 10, 60, 110, 60, GREEN);
    fb_draw_line(fb, 10, 10, 110, 110, BLUE);
    fb_draw_line(fb, 110, 10, 10, 110, YELLOW);
    fb_draw_line(fb, 10, 35, 110, 85, CYAN);
    fb_draw_line(fb, 35, 10, 85, 110, MAGENTA);

    // fb_draw_rect_wire
    fb_draw_rect_wire(fb, 130, 10, 80, 50, RED);
    fb_draw_rect_wire(fb, 230, 10, 50, 80, GREEN);

    // fb_draw_rect
    fb_draw_rect(fb, 130, 80, 80, 50, BLUE);
    fb_draw_rect(fb, 230, 100, 50, 60, YELLOW);

    // fb_draw_tri_wire: flat-bottom, flat-top, general
    fb_draw_tri_wire(fb, (vec2){10, 140}, (vec2){90, 140}, (vec2){50, 200}, CYAN);
    fb_draw_tri_wire(fb, (vec2){10, 260}, (vec2){50, 200}, (vec2){90, 260}, MAGENTA);
    fb_draw_tri_wire(fb, (vec2){10, 330}, (vec2){80, 280}, (vec2){60, 360}, ORANGE);

    // fb_draw_tri: flat-bottom, flat-top, general
    fb_draw_tri(fb, (vec2){120, 140}, (vec2){200, 140}, (vec2){160, 200}, CYAN);
    fb_draw_tri(fb, (vec2){120, 260}, (vec2){160, 200}, (vec2){200, 260}, MAGENTA);
    fb_draw_tri(fb, (vec2){120, 360}, (vec2){200, 300}, (vec2){170, 380}, ORANGE);

    // two adjacent triangles sharing a diagonal - check for holes/overdraw
    // should look like a solid rectangle with a clean diagonal seam
    fb_draw_tri(fb, (vec2){230, 140}, (vec2){330, 140}, (vec2){330, 240}, RED);
    fb_draw_tri(fb, (vec2){230, 140}, (vec2){230, 240}, (vec2){330, 240}, GREEN);

    // fb_draw_cir_wire
    fb_draw_cir_wire(fb, 60, 430, 50, WHITE);
    fb_draw_cir_wire(fb, 60, 430, 1, RED);
    fb_draw_cir_wire(fb, 60, 430, 0, GREEN); // degenerate

    // fb_draw_cir
    fb_draw_cir(fb, 190, 430, 50, BLUE);
    fb_draw_cir(fb, 190, 430, 1, RED);
    fb_draw_cir(fb, 190, 430, 0, WHITE); // degenerate

    // circles near the edge to probe boundary assumptions
    fb_draw_cir_wire(fb, 460, 460, 60, YELLOW);
    fb_draw_cir(fb, 360, 460, 40, CYAN);
}

int main(void) {
    SDL_Window* win = init_window(
        "test",
        WIDTH,
        HEIGHT,
        SDL_WINDOW_RESIZABLE);

    if (!win) return 1;

    SDL_Renderer* ren = init_renderer(win, NULL);
    if (!ren) return 1;

    SDL_Texture* tex = init_texture(ren, WIDTH, HEIGHT);
    if (!tex) return 1;

    Framebuffer* fb = init_framebuffer(WIDTH, HEIGHT);
    if (!fb) return 1;

    draw_all(fb);

    bool running = true;
    SDL_Event event;

    while (running) {
        SDL_UpdateTexture(tex, NULL, fb->pixels, WIDTH * sizeof(u32));
        SDL_RenderClear(ren);
        SDL_RenderTexture(ren, tex, NULL, NULL);
        SDL_RenderPresent(ren);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT ||
                (event.type == SDL_EVENT_KEY_DOWN &&
                 event.key.key == SDLK_ESCAPE)) {
                running = false;
            }
        }

        SDL_Delay(16);
    }

    platform_shutdown(win, ren, tex);
    free(fb->pixels);
    free(fb);
    return 0;
}
