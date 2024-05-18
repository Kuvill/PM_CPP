#include <algorithm>
#include <iostream>

#include "string.hpp"

// #define DEBUG

namespace lp {

/*----------------------------RAII
 * BLOCK-----------------------------------------*/

String::String() {
  // ctor
}

String::String(const String &other) {
  if (_size != other._size) {
    _point = new char[other._size];
    _size = other._size;
  }

  std::copy(other._point, other._point + other._size, _point);
}

String::String(const char *addjoin) {
  const char *start = addjoin;
  unsigned int i = 1;
  while (*addjoin != '\0') {
    ++i;
    addjoin = std::next(addjoin);
  }
  _point = new char[_size + i];
  std::copy(start, start + i, _point);
  _size = i;
}

String::String(char addjoin) {
  _point = new char[1];
  _point[0] = addjoin;
  _size = 1;
}

String::~String() { delete[] _point; }

/*----------------------------math
 * BLOCK-----------------------------------------*/

String String::operator=(String &other) {
  if (_size != other._size) {
    delete[] _point;
    _point = new char[other._size];
    _size = other._size;
  }

  std::copy(other._point, other._point + other._size, _point);

  return *this; // not sure tbh
}

String String::operator+(String &other) {
  String result;
  result._point = new char[this->_size + other._size];

  std::copy(this->_point, this->_point + this->_size, result._point);
  result._size = this->_size + other._size;

  std::copy(other._point, other._point + other._size, result._point + _size);

  return result;
}

String String::operator+(String &&other) {
  String result;
  result._point = new char[this->_size + other._size];

  std::copy(this->_point, this->_point + this->_size, result._point);
  result._size = this->_size + other._size;

  std::copy(other._point, other._point + other._size, result._point + _size);

  return result;
}

void String::operator+=(String &other) { // not working with length = 1 FIXME!!!
  String tmp(*this);

#ifdef DEBUG
  std::cout << "-- " << other._point << "\t";
#endif

  if (other._size != 1) {

    _size += other._size;

    delete[] _point;
    _point = new char[_size];
    std::copy(tmp._point, tmp._point + tmp._size, _point);

    std::copy(other._point, other._point + other._size, _point + _size);
  } else {
    ++_size;
    delete[] _point;
    _point = new char[_size];

    std::copy(tmp._point, tmp._point + tmp._size, _point);
    _point[_size - 1] = other._point[0];
  }
}

void String::operator+=(String &&other) {
  String tmp(*this);

#ifdef DEBUG
  std::cout << "-- " << other._point << "\t";
#endif

  if (other._size != 1) {
    _size += other._size;

    delete[] _point;
    _point = new char[_size];

    std::copy(tmp._point, tmp._point + tmp._size, _point);

    std::copy(other._point, other._point + other._size, _point + _size);
  } else {
    ++_size;
    delete[] _point;
    _point = new char[_size];
    std::copy(tmp._point, tmp._point + tmp._size, _point);
    _point[_size - 1] = other._point[0];
  }
}
/*----------------------------compare
 * BLOCK-----------------------------------------*/

bool String::operator<(String &other) const {
  if (_size < other._size)
    return true;
  if (_size > other._size)
    return false;
  for (unsigned int i = 0; i < _size; ++i)
    if (_point[i] != other._point[i]) // c++20 <=>
      return _point[i] < other._point[i];
  return false;
}

bool String::operator>(String &other) const {
  if (_size > other._size)
    return true;
  if (_size < other._size)
    return false;
  for (unsigned int i = 0; i < _size; ++i)
    if (_point[i] != other._point[i]) // c++20 <=>
      return _point[i] > other._point[i];
  return false;
}

bool String::operator==(String &other) const {
  if (_size != other._size)
    return false;
  for (unsigned int i = 0; i < _size; ++i)
    if (_point[i] != other._point[i])
      return false;
  return true;
}
} // namespace lp

/*----------------------------syntax
 * BLOCK-----------------------------------------*/

char lp::String::operator[](unsigned int index) const {
  return *(_point + index);
}

std::ostream &operator<<(std::ostream &os, const lp::String &obj) {
  for (unsigned int i = 0; i < obj.GetSize(); ++i)
    os << obj[i];
  return os;
}

std::istream &operator>>(std::istream &is, lp::String &obj) {
  char tmp{};
  for (;;) {
    is.get(tmp);
    if (tmp == '\n')
      break;
    obj += tmp;
  }
  return is;
}
