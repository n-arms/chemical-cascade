#ifndef components_tile_h
#define components_tile_h

#include "../tile.h"

struct single_tile {
  tile_ref tile;
};

struct tile_box {
  tile_ref small;
  tile_ref big;
};

struct source {
  tile_ref tile;
  direction direction;
};

struct sink {
  tile_ref tile;
  direction direction;
};

#endif