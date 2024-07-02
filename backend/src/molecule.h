#ifndef molecule_h
#define molecule_h

#include <array>
#include <variant>

struct point {
  double x;
  double y;
};

struct chain;

struct molecule {
  point position;
  point velocity;
};

#endif