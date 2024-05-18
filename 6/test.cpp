#include <algorithm>

int main() {
  int *i = new int[0];
  int *b = new int[1];
  std::copy(b, b + 1, i);
  return 0;
}
