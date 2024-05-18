#include "bigint.hpp"

#include <iostream>

/*---helper functions-----------*/

bool isOverflow(char &c) {
  if (c > '9')
    return true;
  return false;
}

/*---initialize-----------------*/

Bigint::Bigint() {}

Bigint::Bigint(const long long &other) { _number = std::to_string(other); }
Bigint::Bigint(const long long &&other) { _number = std::to_string(other); }

Bigint::Bigint(int other) { _number = std::to_string(other); }

Bigint::Bigint(char other) { _number = std::to_string(other); }

Bigint::Bigint(const std::string &other) : _number(other) {}
Bigint::Bigint(const std::string &&other) : _number(other) {}

/*---math functions--------------*/

Bigint Bigint::operator+=(
    Bigint &other) {    // invalid cast std::string to const std::string???????
  return *this + other; // call + from += faster, but idk how with min and max
}

Bigint Bigint::operator+(Bigint &other) {
  bool wasOverflow = false;
  std::string result;
  if (_number.length() > other._number.length())
    result = _number;
  else
    result = other._number;

  for (short i = _number.length() - 1, j = _number.length() - 1,
             k = result.length() - 1;
       i >= 0 && j >= 0; --i, --j, --k) {

    if (wasOverflow) {
      ++(_number)[k];
      wasOverflow = false;
    }

    result[k] = (_number)[j] + (other._number)[i] - '0';

    if (result[k] > '9') {
      result[k] -= 10;

      if (i != 0 && j != 0)
        wasOverflow = true;

      else if ((i == 0 || j == 0) && k != 0) {
        ++result[--k];

        while (result[k] > '9' && k != 0) {
          result[k--] -= 10;
          ++result[k];
        }

        if (k == 0 && result[k] > '9') {
          result.insert(result.begin(), '1');
        }
      } else {
        if (k == 0 && result[k] > '9') {
          result.insert(result.begin(), '1');
        }
      }

      if (i || k || j == 0)
        break;
    }

    return result;
  }

  Bigint Bigint::operator*=(Bigint &other) {}

  Bigint Bigint::operator*(Bigint &other) {
    std::string result{""};

    std::string *min;
    std::string *max;

    if (other._number.length() > _number.length()) {
      max = &other._number;
      min = &_number;
    } else {
      max = &_number;
      min = &other._number;
    }

    short i = min->length() - 1;
    short j = max->length() - 1;

    while (j > 0) {
      char addict = 0;

      while (i > 0) {
        result[i + j] = _number[1];
      }
    }

    return result;
  }

  bool Bigint::operator<(const Bigint &other) {
    if (_number.length() != other._number.length()) { //<=>c++20
      return _number.length() != other._number.length();
    }
    for (short i = std::min(_number.length(), other._number.length()); i > 0;
         --i) {                           //<=>
      if (_number[i] != other._number[i]) //<=>
        return _number[i] < other._number.length();
    }
    return false;
  }

  /*---compare functions-----------*/

  bool Bigint::operator>(const Bigint &other) {}

  bool Bigint::operator==(const Bigint &other) {}

  bool Bigint::operator!=(const Bigint &other) {}

  /*---IO functions-----------------*/

  std::ostream &operator<<(std::ostream &os, const Bigint &obj) {
    for (short i = 0; i < obj._number.length(); ++i) {
      os << obj._number[i];
    }
    return os;
  }

  std::istream &operator>>(std::istream &, Bigint &);
