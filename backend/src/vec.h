#ifndef vec_h
#define vec_h

#include <array>

template<int N>
struct vec {
  std::array<float, N> elements;

  vec<N> operator+(const vec<N> &other) {
    vec<N> copy = *this;
    copy += other;
    return copy;
  }

  vec<N> operator-(const vec<N> &other) {
    vec<N> copy = *this;
    copy -= other;
    return copy;
  }

  vec<N> operator*(float scalar) {
    vec<N> copy = *this;
    copy *= scalar;
    return copy;
  }

  void operator+=(const vec<N> &other) {
    for (int i = 0; i < elements.size(); ++i) {
      elements[i] += other[i];
    }
  }

  void operator-=(const vec<N> &other) {
    for (int i = 0; i < elements.size(); ++i) {
      elements[i] -= other[i];
    }
  }

  void operator*=(float scalar) {
    for (int i = 0; i < elements.size(); ++i) {
      elements[i] *= scalar;
    }
  }

  float operator[](int n) {
    return elements[n];
  }

  float sq_mag() {
    float total = 0;
    for (const auto &elem : elements) {
      total += elem * elem;
    }
    return total;
  }

  float mag() {
    return sqrt(sq_mag());
  }
};

#endif