#ifndef belt_h
#define belt_h

#include "../tile.h"
#include "../object.h"

struct belt: tile_object {
  direction input;
  direction output;
};

#endif