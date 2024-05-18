#include <algorithm>
#include <iostream>
int main() {
  char *p = new char[2];
  char *d = new char[1];
  *p++ = '1';
  *p = '2';
  std::copy(p, p + 1, d);
  std::cout << *d;
  return 0;
}
