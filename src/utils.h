#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern SDL_Renderer* renderer;

#ifndef UTILS_HEADER_DEFINED
#define UTILS_HEADER_DEFINED
typedef struct Vector2 {
    float x;
    float y;
} Vector2;

SDL_Texture* loadTexture(void* mem, int size) {
    SDL_RWops* loadedRWops = SDL_RWFromMem(mem, size);
    SDL_Surface* loadedSurface = IMG_Load_RW(loadedRWops, 1);
    SDL_Texture* loadedTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    return loadedTexture;
}
#endif