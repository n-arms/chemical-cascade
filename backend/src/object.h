#ifndef object_h
#define object_h

#include <functional>
#include "tile.h"
#include "ref.h"

struct world;

enum object_type {
  belt_object, source_object, goal_object
};

struct object_ref {
  int id;
  object_type type;
};

struct object {
  void iterate(const std::function<void(tile_ref)> &perElement) {}
  void tick(double dt, world &w);
};

struct tile_object: object {
  tile_ref tile;
  void iterate(const std::function<void(tile_ref)> &perElement) {
    perElement(tile);
  }
};

template<size_t T>
struct array_object: object {
  std::array<tile_ref, T> tiles;
  void iterate(const std::function<void(tile_ref)> &perElement) {
    for (const auto &ref : tiles) {
      perElement(ref);
    }
  }
};

struct box_object: object {
  tile_ref top_left;
  int height;
  int width;

  void iterate(const std::function<void(tile_ref)> &perElement) {
    for (int x = 0; x < width; ++x) {
      for (int y = 0; y < height; ++y) {
        perElement({ x + top_left.x, y + top_left.y });
      }
    }
  }
};

#endif