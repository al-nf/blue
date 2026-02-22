#ifndef PLATFORM_H
#define PLATFORM_H
#include <SDL3/SDL.h>

SDL_Window* init_window(const char* title, int width, int height, SDL_WindowFlags flags);
SDL_Renderer* init_renderer(SDL_Window* window, const char* name);
SDL_Texture* init_texture(SDL_Renderer* renderer, int w, int h);


void platform_shutdown(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture);

#endif // PLATFORM_H
