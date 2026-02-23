#include "core.h"
#include "platform.h"
#include <SDL3/SDL.h>
#include <stdbool.h>

#define WIDTH 1280
#define HEIGHT 720

int main() {
    SDL_Window* win = init_window(
        "Hello World!", // title
        1280, // width
        720, // height
        SDL_WINDOW_RESIZABLE // flags
    );
    if (win == NULL) {
        return 1;
    }

    SDL_Renderer* ren = init_renderer(
        win,
        "Renderer"
    );
    if (ren == NULL) {
        return 1;
    }

    SDL_Texture* tex = init_texture(
        ren,
        WIDTH,
        HEIGHT
    );
    if (tex == NULL) {
        return 1;
    }

    Framebuffer* fb = init_framebuffer(
        WIDTH,
        HEIGHT
    );
    if (fb == NULL) {
        return 1;
    }


    bool running = true;
    SDL_Event event;

    while (running) {
        SDL_UpdateTexture(
            tex,
            NULL,
            fb->pixels,
            WIDTH * sizeof(u32)
        );
        
        SDL_RenderClear(ren);
        SDL_RenderTexture(ren, tex, NULL, NULL);
        SDL_RenderPresent(ren);
        
        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT) {
            running = false;
        }

        SDL_Delay(16); // ~60fps
    }

    platform_shutdown(win, ren, tex);

    free(fb->pixels);
    free(fb);
    return 0;
}
