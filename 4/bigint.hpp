#pragma once

#include <cstdint>
#include <sstream>

class Bigint {
private:
  short *_number = nullptr;

  short _size = 0;

  bool NeedResize(const Bigint &) const;

  friend std::ostream &operator<<(std::ostream &os, Bigint &);

  friend std::istream &operator>>(std::istream &is, Bigint);

public:
  Bigint();

  Bigint(char);

  Bigint(int);

  Bigint(long long);

  Bigint(const Bigint &);

  ~Bigint();

  /**/

  Bigint operator=(const Bigint &);

  Bigint operator=(Bigint &&);

  Bigint operator+=(Bigint &);

  Bigint operator+(Bigint &);

  Bigint operator*=(Bigint &);

  Bigint operator*(Bigint &);

  /**/

  bool operator<(Bigint &);

  bool operator>(Bigint &);

  bool operator==(Bigint &);

  bool operator!=(Bigint &);
};

std::ostream &operator<<(std::ostream &os, Bigint &);

std::istream &operator>>(std::istream &is, Bigint);
