#ifndef physical_h
#define physical_h

#include <optional>
#include <chrono>
#include "../vec.h"
#include "../tile.h"

struct position {
  vec<2> pos;
};

struct velocity {
  vec<2> vel;
};

struct timestamp {
  double seconds;
};

struct gets_hit {
  std::optional<entity> last_hit;
  timestamp time;
};

struct hitcircle {
  vec<2> centre;
  float radius;

  bool hits(const hitcircle &other) {
    float total = radius + other.radius;
    return (centre - other.centre).sq_mag() <= total * total;
  }

  bool hits(tile_ref ref) {
    auto x = abs(centre[0] - ref.x);
    auto y = abs(centre[1] - ref.y);

    auto dX = fmax(0, x - 1);
    auto dY = fmax(0, y - 1);

    auto sq_distance = dX*dX + dY*dY;

    return sq_distance < radius * radius;
  }
};

#endif