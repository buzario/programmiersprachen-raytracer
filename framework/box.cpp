
#define _USE_MATH_DEFINES
#include "box.hpp"
#include <cmath>
#include<glm/vec3.hpp>
#include<iostream>


Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
  min_{ min },
  max_{ max } {}

float Box::area() const {
	auto x = abs(max_.x - min_.x);
	auto y = abs(max_.y - min_.y);
	auto z = abs(max_.z - min_.z);
	
	// checking if object is 2D  
	if (x == 0.0f || y == 0.0f || z == 0.0f) {
		return x * y + x * z + y * z;
	}
	return 2 * (x * y + x * z + y * z);
}

float Box::volume() const { 
	return (max_.x - min_.x) * (max_.y - min_.y) * (max_.z - min_.z); }