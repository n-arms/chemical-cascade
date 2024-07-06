#ifndef tile_h
#define tile_h

#include "ecs/entity.h"

struct tile {
  entity object;
};

struct tile_ref {
  int x;
  int y;
};

enum direction {
  north,
  south,
  east,
  west
};

#endif