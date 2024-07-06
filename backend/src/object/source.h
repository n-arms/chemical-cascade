#ifndef source_h
#define source_h

#include "../tile.h"
#include "../object.h"
#include "../molecule.h"

struct source: tile_object {
  direction output;
  double elapsed;

  void tick(double dt, world& w);
};

#include "../world.h"

void source::tick(double dt, world& w) {
  elapsed += dt;

  if (elapsed > 2) {
    w.make_molecule(molecule(
      point::centered_on(tile),
      point(output, 0.5)
    ));
  }
}

#endif