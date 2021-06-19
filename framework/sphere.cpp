
#define _USE_MATH_DEFINES
#include "sphere.hpp"
#include <cmath>

Sphere::Sphere(glm::vec3 const& ctr, float r, std::string const& nm, Color const& clr) :
	Shape{ nm, clr },
	center_{ctr},
	radius_{r} {}

float Sphere::area() const { return 4.0f * M_PI * pow(radius_, 2); }

float Sphere::volume() const { return (4.0f / 3.0f * M_PI * pow(radius_, 3));}