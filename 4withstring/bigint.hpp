#pragma once

#include <sstream>
#include <string>

#define DEBUG

class Bigint {
private:
  std::string _number; // char* take more time to release

  friend std::ostream &operator<<(std::ostream &, const Bigint &);

  friend std::istream &operator>>(std::istream &, Bigint &);

#ifdef DEBUG
  friend int main();
#endif // DEBUG

  void reverse();

public:
  Bigint();

  Bigint(const long long &);
  Bigint(const long long &&);

  Bigint(int);

  Bigint(char);

  Bigint(const std::string &);
  Bigint(const std::string &&);

  Bigint operator+=(Bigint &);

  Bigint operator+(Bigint &);

  Bigint operator*=(Bigint &);

  Bigint operator*(Bigint &);

  bool operator<(const Bigint &);

  bool operator>(const Bigint &);

  bool operator==(const Bigint &);

  bool operator!=(const Bigint &);
};

std::ostream &operator<<(std::ostream &, const Bigint &);

std::istream &operator>>(std::istream &, Bigint &);
