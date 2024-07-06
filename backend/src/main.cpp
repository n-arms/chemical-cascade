#include <iostream>
#include "tile.h"
#include "object.h"
#include "ref.h"
#include "object/belt.h"
#include "object/goal.h"
#include "object/source.h"
#include "molecule.h"
#include "tile_grid.h"
#include "world.h"
#include "entity.h"
#include "entity_list.h"
#include "component.h"
#include "component_list.h"
#include "all.h"
#include "system.h"

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