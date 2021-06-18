
#define _USE_MATH_DEFINES
#include "sphere.hpp"
#include <cmath>
#include<glm/vec3.hpp>
#include<iostream>


Sphere::Sphere(glm::vec3 const& ctr, float r) :
  center_{ctr},
  radius_{r} {}

float Sphere::area() const { return 4.0f * M_PI * pow(radius_, 2); }

float Sphere::volume() const { return (4.0f / 3.0f * M_PI * pow(radius_, 3));}