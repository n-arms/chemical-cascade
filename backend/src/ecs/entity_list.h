#ifndef entity_list_h
#define entity_list_h

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <optional>
#include "entity.h"
#include "component_list.h"

template<class T>
int get_id() {
  return typeid(T).hash_code();
}

struct entity_list {
  std::vector<entity> entities;
  std::unordered_map<int, int> comp_types;
  std::vector<std::shared_ptr<components>> comps;

  int make_entity() {
    auto id = entities.size();
    entities.push_back(entity(id));
    return id;
  }

  template<class T>
  void assign(int ref, T component) {
    get_component_list<T>() -> set(ref, component);
    entities[ref].components.set(component_id<T>());
  }

  template<class T>
  void remove(int ref) {
    get_component_list<T>() -> delete_component(ref);
    entities[ref].components.reset();
  }

  template<class T>
  std::optional<T> get(int ref) {
    return get_component_list<T>() -> at(ref);
  }

  template<class T>
  std::shared_ptr<component_list<T>> get_component_list() {
    auto id = component_id<T>();
    if (id >= comps.size()) {
      std::cout << "unknown id " << id << std::endl;
      exit(1);
    }
    auto comp = comps[id];
    return std::static_pointer_cast<component_list<T>>(comp);
  }

  template<class T>
  int component_id() {
    auto hash = get_id<T>();
    int id;
    bool should_push = false;
    if (comp_types.find(hash) == comp_types.end()) {
      id = comps.size();
      comp_types[hash] = id;
      should_push = true;
    } else {
      id = comp_types[hash];
    }
    if (should_push) {
      auto comp = std::make_shared<component_list<T>>();
      comps.push_back(std::static_pointer_cast<components>(comp));
    }   
    return id;
  }
};

#endif