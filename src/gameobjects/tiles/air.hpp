#include "../../utils.h"
#include "base/tile.hpp"

#ifndef AIR_HEADER_DEFINED
#define AIR_HEADER_DEFINED

class Air : public Tile {
public:
  Air() : Tile({1, 1}, {0, 0}, false, 0xffffff){};
};
#endif