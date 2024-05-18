#include <sstream>
#include <string>

class Bigint {
  std::string _number;

  friend std::ostream &operator<<(std::ostream &, Bigint &);

  friend std::istream &operator<<(std::istream &, Bigint &);

public:
  Bigint();

  Bigint(char);

  Bigint(int);

  Bigint(long long &);
  Bigint(long long &&);

  Bigint(std::string &);
  Bigint(std::string &&);

  Bigint operator=(Bigint &);

  Bigint operator+=(Bigint &);

  Bigint operator+(Bigint &);

  Bigint operator*=(Bigint &);

  Bigint operator*(Bigint &);

  bool operator==(Bigint &);

  bool operator<(Bigint &);

  bool operator>(Bigint &);

  bool operator!=(Bigint &);
};

std::ostream &operator<<(std::ostream &, Bigint &);

std::istream &operator>>(std::istream &, Bigint &);
