#ifndef world_h
#define world_h

#include "tile_grid.h"
#include "object/belt.h"
#include "object/source.h"
#include "object/goal.h"
#include "objects.h"
#include "molecule.h"

struct world {
  tile_grid grid;
  objects<belt> belts;
  objects<source> sources;
  objects<goal> goals;
  std::vector<molecule> molecules;

  void tick(double dt) {
    belts.iterate([dt, this](belt &o) {
      o.tick(dt, *this);
    });
    sources.iterate([dt, this](source &o) {
      o.tick(dt, *this);
    });
    goals.iterate([dt, this](goal &o) {
      o.tick(dt, *this);
    });
  }

  void make_molecule(molecule m) {
    molecules.push_back(m);
  }
};

#endif