
#include "shape.hpp"


Shape::Shape(std::string const& nm, std::shared_ptr<Material> const& mat) :
	name_{nm},
	material_{mat} {
	// uncomment for Task 5.8
	//std::cout << "Shape Konstruktor\n";
}

Shape::~Shape() {
	// uncomment for Task 5.8
	//std::cout << "Shape Destruktor\n";
}

std::ostream& Shape::print(std::ostream& os) const {
	os << "Name: " << name_ << "\n";
	os << "Material: (" << material_ << ")\n";
	return os;
}


std::ostream& operator <<(std::ostream& os, Shape const& s)
{
	return s.print(os);
}