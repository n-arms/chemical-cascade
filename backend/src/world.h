#ifndef world_h
#define world_h

#include "tile_grid.h"
#include "ecs/entity_list.h"

class world {
  tile_grid grid;
  entity_list entities;
};

#endif