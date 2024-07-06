#ifndef tile_h
#define tile_h

#include "object.h"
#include "ref.h"

struct tile {
  object_ref object;
};

enum direction {
  north,
  south,
  east,
  west
};

#endif