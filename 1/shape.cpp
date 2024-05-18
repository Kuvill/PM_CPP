#include "shape.h"

Sphere::Sphere() : _radius(1) {}

Sphere::Sphere(int radius) : _radius(radius) {}

double Sphere::Square() { return 4 * pi * _radius; }

double Sphere::Valume() { return 4 * pi * _radius * _radius * _radius / 3; }
