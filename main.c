#include "SDL3/SDL_video.h"
#include <stdio.h>
#include <SDL3/SDL.h>

int main() {
    SDL_Window *win = SDL_CreateWindow(
        "Hello World!", // title
        100, // width
        100, // height
        SDL_WINDOW_FULLSCREEN // flags
    );

    if (win == NULL) {
        printf("sdl window creation error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Delay(10000);

    SDL_DestroyWindow(win);
    SDL_Quit();
}
