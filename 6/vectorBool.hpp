#pragma once

#include <iostream>

#define DEBUG

namespace lp {

template <typename T> class vector {
private:
public:
};

template <> class vector<bool> {
private:
  char *_pointer = nullptr;
  size_t _size = 0;
  char _position = 0;
#ifdef DEBUG

public:
  char pos() { return _position; }
#endif

public:
  vector();

  vector(bool);

  vector(vector<bool> &);

  vector(char[], size_t n);
  vector(char[], int n);

  void push_back(bool obj);
  void pop_back();

  bool operator[](size_t) const;

  void insert(size_t, bool);

  void erase(size_t);
  size_t size() const;
};

} // namespace lp
