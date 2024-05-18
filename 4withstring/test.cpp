#include "bigint.hpp"
#include <iostream>

int main() {
  int a = 1, b = 2;
  std::cout << a << " " << b << std::endl;
  a > b ? a = 1, b = 2 : a = 2, b = 1;
  std::cout << a << " " << b << std::endl;
  return 0;
}
