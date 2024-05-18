#include "bigint.hpp"

Bigint::Bigint() {}

Bigint::Bigint(char obj) { _number = std::to_string(obj); }

Bigint::Bigint(int obj) { _number = std::to_string(obj); }

Bigint::Bigint(long long &obj) { _number = std::to_string(obj); }
Bigint::Bigint(long long &&obj) { _number = std::to_string(obj); }

Bigint::Bigint(std::string &obj) : _number(obj) {}
Bigint::Bigint(std::string &&obj) : _number(obj) {}

Bigint Bigint::operator+(Bigint &other) {
  :q
}
