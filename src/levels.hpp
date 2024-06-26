#include "gameobjects/tiles/base/tileGrid.hpp"
#include "utils.h"
#include <array>

extern void reset();

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const float TILE_SIZE;
extern const int SCREEN_START_X;
extern const int SCREEN_END_X;

#ifndef LEVELS_HEADER_DEFINED
#define LEVELS_HEADER_DEFINED

class Level {
public:
  TileGrid* tileGrid;
  Vector2 playerPos;
  Vector2 boxPos;

  Level(Vector2 defaultPlayerPos, Vector2 defaultBoxPos,
        std::array<int, 255> tiles) {
    playerPos = defaultPlayerPos;
    boxPos = defaultBoxPos;
    tileGrid = new TileGrid(tiles);
  }
};

Level* levels[] = {
    new Level({219, 32}, {603, 416},
              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0,
               1, 1, 0, 0, 0, 0, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 9, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
               1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0}),
    new Level({219, 32}, {603, 416},
              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
               0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 10, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 10, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0,
               0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 9, 1, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})};

int currentLevelIndex = 0;
Level* currentLevel = levels[currentLevelIndex];

void setLevel(int levelIndex) {
  currentLevelIndex = levelIndex;
  currentLevel = levels[levelIndex];
  reset();
}

void nextLevel() { setLevel(currentLevelIndex + 1); }
#endif