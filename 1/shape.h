#pragma once

static const double pi = 3.1416;

class Sphere {
private:
  const int _radius;

public:
  Sphere();

  Sphere(int radius);

  double Square();

  double Valume();
};
