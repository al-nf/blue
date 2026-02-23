#include "platform.h"
#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_render.h"
#include <stdio.h>

SDL_Window* init_window(const char* title, int width, int height, SDL_WindowFlags flags) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL initialization error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Window *window = SDL_CreateWindow(
        title,
        width,
        height,
        flags
    );

    if (window == NULL) {
        printf("SDL window creation error: %s\n", SDL_GetError());
        SDL_Quit();
    }

    return window;
}

SDL_Renderer* init_renderer(SDL_Window* window, const char* name) {
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        NULL
    );

    if (renderer == NULL) {
        printf("SDL renderer creation error: %s\n", SDL_GetError());
        SDL_Quit();
    }

    return renderer;
}

SDL_Texture* init_texture(SDL_Renderer* renderer, int w, int h) {
    SDL_Texture* texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        w,
        h
    );

    if (texture == NULL) {
        printf("SDL texture creation error %s\n", SDL_GetError());
        SDL_Quit();
    }

    return texture;
}

void platform_shutdown(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture) {
    if (texture != NULL) {
        SDL_DestroyTexture(texture);
    }
    if (renderer != NULL) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != NULL) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}
