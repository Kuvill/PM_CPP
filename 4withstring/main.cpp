#include "bigint.hpp"
#include <iostream>

int main() {
  Bigint a;
  std::cout << "Enter a: ";
  std::cin >> a;

  Bigint b;
  std::cout << "Enter b: ";
  std::cin >> b;

  std::cout << "a + b = " << a + b << std::endl;

  return 0;
}
