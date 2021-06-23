
#define _USE_MATH_DEFINES
#include "sphere.hpp"
#include <cmath>

Sphere::Sphere(glm::vec3 const& ctr, float r, std::string const& nm, Color const& clr) :
	Shape{ nm, clr },
	center_{ctr},
	radius_{r} {
	// uncomment for Task 5.8
	//std::cout << "Sphere Konstruktor\n";
}

Sphere::~Sphere() {
	// uncomment for Task 5.8
	//std::cout << "Sphere Destruktor\n";
}

float Sphere::area() const { return 4.0f * M_PI * pow(radius_, 2); }

float Sphere::volume() const { return (4.0f / 3.0f * M_PI * pow(radius_, 3));}

std::ostream& Sphere::print(std::ostream& os) const {
	Shape::print(os);
	os << "Center: (" << center_.x << ", " << center_.y << ", " << center_.z << ")\n";
	os << "Radius: " << radius_ << "\n";
	return os;
}

HitPoint Sphere::intersect(Ray const& ray) {
	
	auto norm_direction = glm::normalize(ray.direction);
	float distance;
	auto boo = glm::intersectRaySphere(
		ray.origin, norm_direction,
		center_, radius_ * radius_, distance);
	HitPoint hp;
	if (boo) {
		hp.hit = true;
		hp.distance = distance;
		hp.name = name_;
		hp.color = color_;
		hp.position = ray.origin + (norm_direction * distance);
		hp.direction = norm_direction;
	}
	return hp;
}