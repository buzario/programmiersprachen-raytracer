
#include "shape.hpp"


Shape::Shape(std::string const& nm, Color const& clr) :
	name_{nm},
	color_{clr} {
	// uncomment for Task 5.8
	//std::cout << "Shape Konstruktor\n";
}

Shape::~Shape() {
	// uncomment for Task 5.8
	//std::cout << "Shape Destruktor\n";
}

std::ostream& Shape::print(std::ostream& os) const {
	os << "Name: " << name_ << "\n";
	os << "Color: (" << color_.r << ", " << color_.g << ", " << color_.b << ")\n";
	return os;
}


// in cpp :
std::ostream& operator <<(std::ostream& os, Shape const& s)
{
	return s.print(os);
}