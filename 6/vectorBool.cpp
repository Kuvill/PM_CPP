#include "vectorBool.hpp"

#include <iostream>
#include <iterator>

namespace lp {

/*-------init zone-------*/

void write(char &pointer, char position, bool value) {
  if (value) {
    char conjugate = 1 << (position);
    pointer |= conjugate;
  } else {
    char conjugate = ~(1 << (position));
    pointer &= conjugate;
  }
}

vector<bool>::vector() {}

vector<bool>::vector(bool obj) {
  _pointer = new char[1](); //() to init massive by 0
  write(_pointer[0], _position, obj);
  _size = 1;
  _position = 1;
}

vector<bool>::vector(vector<bool> &other)
    : _size(other._size), _position(other._position) {
  _pointer = new char[_size];
  std::copy(other._pointer, other._pointer + other._size, _pointer);
}

/*-------operation zone-------*/

void vector<bool>::push_back(bool obj) {
  if (_position == 8) {
    vector<bool> tmp(*this);
    delete[] _pointer;
    _pointer = new char[++_size]();
    std::copy(tmp._pointer, tmp._pointer + tmp._size, _pointer);
    _position = 0;
  } else if (_size == 0)
    _pointer = new char[++_size]();

  write(_pointer[_size - 1], _position++, obj);
}

void vector<bool>::pop_back() {
  if (_size > 0) {
    if (_position > 1) {
      write(_pointer[_size - 1], --_position, false);

    } else {
      vector<bool> tmp(*this);
      delete[] _pointer;
      if (_size != 1) {
        _pointer = new char[--_size];
        std::copy(tmp._pointer, tmp._pointer + _size, _pointer);
        _position = 8;
      }
    }
  } else
    exit(1);
}

bool vector<bool>::operator[](size_t length) const {
  char conjugate = 1 << (length % 8);
  return _pointer[length / 8] & conjugate;
} // hope &bool isn't nesessury.)

void vector<bool>::insert(size_t length, bool obj) {
  if (length > size()) { /*out of range case*/
    exit(2);
  } else if (length == size()) {
    push_back(obj);
  } else { /*out of range case*/

    if (_position == 8) {
      vector<bool> tmp(*this);
      delete[] _pointer;
      _pointer = new char[++_size];
      std::copy(tmp._pointer, tmp._pointer + _size, _pointer);
      _position = 0;
    } else
      ++_position;

    const size_t insert_pos = length / 8;
    const char insert_cell = length % 8;

    for (size_t i = _size - 1; i > insert_pos; --i) {
      for (char j = 7; j > 0; --j) {
        write(_pointer[i], j, (*this)[i * 8 + j - 1]);
      }
      write(_pointer[i], 0,
            (*this)[i * 8 - 1]); // not sure that it's nesessury
    }

    for (char i = 7; i > insert_cell; --i) {
      write(_pointer[insert_pos], i, (*this)[insert_pos * 8 + i - 1]);
    }

    write(_pointer[insert_pos], insert_cell, obj);
  }
}

void vector<bool>::erase(size_t length) {
  if (length > size()) { /*out of range case*/
    exit(2);
  } else if (length == size() - 1) {
    pop_back();
  } else { /*out of range case*/

    if (_position == 1) {
      vector<bool> tmp(*this);
      delete[] _pointer;
      _pointer = new char[--_size];
      std::copy(tmp._pointer, tmp._pointer + _size, _pointer);
      _position = 9;
    } else
      --_position;

    const size_t insert_pos = length / 8;
    const char insert_cell = length % 8;

    for (char i = insert_cell; i < 8; ++i) {
      write(_pointer[insert_pos], i, (*this)[insert_pos * 8 + i + 1]);
    }

    for (size_t i = insert_pos; i <= _size; ++i) {
      for (char j = 0; j < 8; ++j) {
        write(_pointer[i], j, (*this)[i * 8 + j + 1]);
      }
    }
  }
}

size_t vector<bool>::size() const {
  return ((_size == 0) ? 0 : (_size - 1) * 8 + _position);
}

} // namespace lp
