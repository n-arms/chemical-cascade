#ifndef objects_h
#define objects_h

#include <optional>
#include <vector>
#include "object.h"

template <typename T>
struct objects {
  std::vector<std::optional<T>> list;

  std::optional<T> &operator[](object_ref ref) {
    return list.at(ref.id);
  }

  void delete_object(object_ref ref) {
    list[ref.id] = {};
  }

  void iterate(std::function<void(T&)> perObject) {
    for (auto &object : list) {
      if (object.has_value()) {
        perObject(*object);
      }
    }
  }
};

#endif