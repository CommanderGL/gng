#include <SDL2/SDL.h>
#include "../../../utils.h"
#include "../../gameobject.hpp"

#ifndef TILE_HEADER_DEFINED
#define TILE_HEADER_DEFINED

extern SDL_Renderer* renderer;
extern const float TILE_SIZE;
extern const int SCREEN_START_X;

class Tile : GameObject {
    public:
        Vector2 pos;
        Vector2 size;
        SDL_Texture* texture = NULL;
        SDL_Color color;
        bool solid;
        int id;

        Tile(Vector2 defaultSize, bool defaultSolid, void* textureMem, int textureSize) {
            size = defaultSize;
            texture = loadTexture(textureMem, textureSize);
            solid = defaultSolid;
        };

        Tile(Vector2 defaultSize, bool defaultSolid, SDL_Color defaultColor) {
            size = defaultSize;
            color = defaultColor;
            solid = defaultSolid;
        };

        SDL_Rect toRect() {
            return {
                pos.x * TILE_SIZE + SCREEN_START_X,
                pos.y * TILE_SIZE,
                size.x * TILE_SIZE,
                size.y * TILE_SIZE
            };
        };

        virtual void update() {};

        void draw() {
            if (id == 0) return;

            SDL_Rect tmpRect = toRect();

            if (texture == NULL) {
                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
                SDL_RenderFillRect(renderer, &tmpRect);
            } else {
                SDL_RenderCopy(renderer, texture, NULL, &tmpRect);
            }
        }
};
#endif