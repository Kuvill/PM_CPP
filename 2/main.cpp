#include "matrix.h"

#include <iostream>

int main() {
  lp::Matrix a(2, 2);
  std::cin >> a;

  lp::Matrix b = a;
  std::cout << b << std::endl;

  return 0;
}
