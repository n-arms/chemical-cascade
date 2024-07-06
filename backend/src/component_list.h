#ifndef component_list_h
#define component_list_h

#include <iostream>
#include <vector>
#include <optional>
#include <bitset>
#include "entity.h"

struct components {
  virtual int size() {
    return 0;
  }
};

template <typename C>
struct component_list: components {
  std::vector<C> components;
  std::bitset<MAX_COMPONENTS> alive;

  void delete_component(int ref) {
    alive.reset(ref);
  }

  void set(int ref, C component) {
    if (ref > 1000) {
      std::cout << "reference was too large" << std::endl;
      exit(1);
    }
    for (int i = components.size(); i <= ref; i++) {
      components.push_back({});
    }
    components[ref] = component;
    alive.set(ref);
  }

  std::optional<C> at(int ref) {
    if (alive.test(ref)) {
      return components[ref];
    } else {
      return {};
    }
  }

  virtual int size() {
    return components.size();
  }
};

#endif