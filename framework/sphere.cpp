
#define _USE_MATH_DEFINES
#include "sphere.hpp"
#include <cmath>
/*
Sphere::Sphere(glm::vec3 const& ctr, float r) :
	Shape{ "Sphere", std::make_shared<Material>() },
	center_{ctr},
	radius_{r} {}
*/

Sphere::Sphere(glm::vec3 const& ctr, float r, std::string const& nm, std::shared_ptr<Material> const& mat) :
	Shape{ nm, mat },
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

HitPoint Sphere::intersect(Ray const& ray, float& t) const {
	
	auto norm_direction = glm::normalize(ray.direction);
	auto hit = glm::intersectRaySphere(
		ray.origin, norm_direction,
		center_, radius_ * radius_, t);
	HitPoint hp;
	if (hit) {
		hp.hit = true;
		hp.distance = t;
		hp.name = name_;
		hp.color = material_->ka;  // provisional
		hp.position = ray.origin + (norm_direction * t);
		hp.direction = norm_direction;
	}
	return hp;
}