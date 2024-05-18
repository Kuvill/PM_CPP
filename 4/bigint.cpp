#include "bigint.hpp"

#include <cmath>
#include <cstdint>

Bigint::Bigint() { *_number = 0; }

Bigint::Bigint(char number) : _size(1) { *_number = number; }

Bigint::Bigint(int number) : _size(1) { *_number = number; }

Bigint::Bigint(long long number) : _size(1) { *_number = number; }

Bigint::Bigint(const Bigint &other) { *this = other; }

Bigint::~Bigint() { delete[] _number; }

bool Bigint::NeedResize(const Bigint &other) const {
  if (_size == other._size) {
    if (INT16_MAX - _number[_size - 1] < other._number[other._size - 1])
      return true;
    return false;
  } else {
    if (INT16_MAX - _number[other._size - 1] < other._number[other._size - 1]) {
      for (short i = other._size; i < _size; ++i) {
        if (_number[i] != INT16_MAX)
          return false;
      }
      return true;
    } else
      return false;
  }
}
/**/

Bigint Bigint::operator=(const Bigint &other) {
  _size = other._size;
  for (uint i = 0; i < _size; ++i)
    _number[i] = other._number[i];
  return *this;
}

Bigint Bigint::operator=(Bigint &&other) {
  for (uint i = 0; i < _size; ++i)
    _number[i] = other._number[i];
  return *this;
}

Bigint Bigint::operator+=(Bigint &other) {
  if (NeedResize(other)) {
    ++_size;
    delete _number;
    _number = new short[_size];
  }
  // if ()
}

Bigint Bigint::operator+(Bigint &);

Bigint Bigint::operator*=(Bigint &);

Bigint Bigint::operator*(Bigint &);

/**/

bool Bigint::operator<(Bigint &);

bool Bigint::operator>(Bigint &);

bool Bigint::operator==(Bigint &);

bool Bigint::operator!=(Bigint &);

std::ostream &operator<<(std::ostream &os, Bigint &obj) {
  for (int i = 0; i < obj._size; ++i)
    os << obj._number[i] * std::pow(int(INT16_MAX) + 1, i);
  return os;
}
std::istream &operator>>(std::istream &is, Bigint obj) {
  long long translator;
  is >> translator;
  for (int i = 0; translator > 0; ++i, translator /= int(INT16_MAX) + 1) {
    is >> obj._number[obj._size];
  }
  return is;
}
