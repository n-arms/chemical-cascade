#ifndef molecule_h
#define molecule_h

#include <array>
#include <variant>
#include "tile.h"

struct point {
  double x;
  double y;

  static point centered_on(tile_ref pos) {
    return {
      (double) pos.x + 0.5,
      (double) pos.y + 0.5
    };
  }

  point(direction dir, double speed) {
    switch (dir) {
      case north:
        y = -speed;
        break;
      case south:
        y = speed;
        break;
      case east:
        x = speed;
        break;
      case west:
        x = -speed;
        break;
    }
  }

  point(double x, double y): x(x), y(y) {}
};

struct molecule {
  point position;
  point velocity;

  molecule(point position, point velocity): position(position), velocity(velocity) {}
};

#endif