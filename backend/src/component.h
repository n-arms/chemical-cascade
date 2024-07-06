#ifndef component_h
#define component_h

struct component {};

struct component_type {
  component_type(int ref): ref(ref) {}
  private:
   int ref;
};

#endif