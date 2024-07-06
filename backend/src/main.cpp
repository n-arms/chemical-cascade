#include <iostream>
#include "tile.h"
#include "tile_grid.h"
#include "world.h"
#include "ecs/entity.h"
#include "ecs/entity_list.h"
#include "ecs/component.h"
#include "ecs/component_list.h"
#include "ecs/all.h"
#include "ecs/system.h"

struct position {};
struct velocity {};

int main() {
  entity_list list = {};
  auto entity = list.make_entity();
  list.assign(entity, position());
  list.assign(entity, velocity());
  auto e2 = list.make_entity();
  list.assign(e2, position());
  auto e3 = list.make_entity();
  list.assign(e3, position());
  list.assign(e3, velocity());
  std::cout << list.entities.size() << " entities and " << list.comps.size() << " components" << std::endl;
  all<position, velocity> query;
  run(query, [=](std::tuple<position, velocity> result) {
    std::cout << "used entity!" << std::endl;
  }, list);
  return 0;
}