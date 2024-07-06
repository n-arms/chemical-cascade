#ifndef tile_grid_h
#define tile_grid_h

#include <array>
#include <optional>
#include "tile.h"
#include <unordered_map>

struct chunk {
  std::array<std::optional<tile>, 256> tiles;

  chunk() {
    for (int i = 0; i < 256; ++i) {
      tiles[i] = std::nullopt;
    }
  }

  std::optional<tile> get(tile_ref tile) {
    return tiles[index(tile)];
  }

  size_t index(tile_ref tile) {
    return (tile.x % 16) + (tile.y % 16) * 16;
  }

  void destory_tile(tile_ref tile) {
    tiles[index(tile)] = {};
  }

  void insert_tile(tile_ref ref, tile tile) {
    tiles[index(ref)] = tile;
  }
};

struct chunk_id {
  int x;
  int y;

  static chunk_id from_tile(tile_ref tile) {
    return {
      tile.x / 16,
      tile.y / 16
    };
  }
};

bool operator==(const chunk_id &a, const chunk_id &b) {
  return a.x == b.x && a.y == b.y;
}

namespace std {
  template<>
  struct hash<chunk_id> {
    size_t operator()(const chunk_id &id) const {
      auto int_hasher = hash<int>();
      return int_hasher(id.x) + int_hasher(id.y) * 1000000009;
    }
  };
}

struct tile_grid {
  std::unordered_map<chunk_id, chunk> chunks;

  void load_chunk(chunk_id id) {
    if (chunks.find(id) == chunks.end()) {
      chunks.insert({id, chunk()});
    }
  }

  chunk &get_chunk(chunk_id id) {
    load_chunk(id);
    return chunks.at(id);
  }

  chunk &get_chunk(tile_ref tile) {
    return get_chunk(chunk_id::from_tile(tile));
  }

  std::optional<tile> operator[](tile_ref tile) {
    auto chunk = get_chunk(tile);
    return chunk.get(tile);
  }

  void destroy_tile(tile_ref tile) {
    auto chunk = get_chunk(tile);
    chunk.destory_tile(tile);
  }

  void insert_tile(tile_ref ref, tile tile) {
    auto chunk = get_chunk(ref);
    chunk.insert_tile(ref, tile);
  }
};

#endif