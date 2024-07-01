#ifndef belt_h
#define belt_h

#include "../tile.h"
#include "../object.h"

struct source: tile_object {
  direction output;
};

#endif