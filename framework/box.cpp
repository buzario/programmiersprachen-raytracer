#include"box.hpp"


Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
	Shape{},
	min_{min},
	max_{max} {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max,
	std::string const& nm, Color const& clr) :
	Shape{ nm, clr },
	min_{ min },
	max_{ max } {
	// uncomment for Task 5.8
	//std::cout << "Box Konstruktor\n";
}

Box::~Box() {
	// uncomment for Task 5.8
	//std::cout << "Destruktor Box \n";
}

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

std::ostream& Box::print(std::ostream& os) const {
	Shape::print(os);
	os << "Min-Point: (" << min_.x << ", " << min_.y << ", " << min_.z << ")\n";
	os << "Max-Point: (" << max_.x << ", " << max_.y << ", " << max_.z << ")\n";
	return os;
}