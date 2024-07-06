#ifndef entity_h
#define entity_h

#include <functional>
#include <string>
#include <bitset>

const int MAX_COMPONENT_TYPES = 64;
const int MAX_COMPONENTS = 2048;

struct entity {
  std::bitset<MAX_COMPONENT_TYPES> components;
  int id;

  entity(int id): id(id) {}
  entity(int id, std::bitset<MAX_COMPONENT_TYPES> components): id(id), components(components) {}
  bool has_component(int component_id) {
    return components.test(component_id);
  }
};

#endif