#include <iostream>

#include "string.hpp"

int main() {
  lp::String stable = "Hello, ";
  std::cout << stable + "world\n";
  lp::String a;
  std::cout << "input a: ";
  std::cin >> a;
  std::cout << "a is: " << a << std::endl;

  auto b = a;
  std::cout << "b is: " << b << std::endl;

  lp::String c;
  std::cout << "input c: ";
  std::cin >> c;

  std::cout << "c + 1 is: " << (c + '1') << std::endl;

  c > a ? std::cout << "c > a\n" : std::cout << "a > c\n";
  return 0;
}
