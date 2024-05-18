#include "vectorBool.hpp"
#include <iostream>

void test(bool obj) { std::cout << ((obj) ? "True\n" : "False\n"); }

int main() { // how to make {} construct?
  lp::vector<bool> a;
  a.push_back(false);
  a.push_back(false);
  a.push_back(false);
  a.push_back(false);
  a.push_back(false);
  a.push_back(false);
  a.push_back(false);
  a.push_back(false);
  a.push_back(false);

  for (int i = 0; i < a.size(); ++i) {
    std::cout << i << ": ";
    test(a[i]);
  }

  a.insert(0, true);
  a.insert(8, true);
  std::cout << '\n';

  a.erase(8);

  for (int i = 0; i < a.size(); ++i) {
    std::cout << i << ": ";
    test(a[i]);
  }

  return 0;
}
