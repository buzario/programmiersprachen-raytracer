#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"

class Shape
{
public:
	Shape() = default;
	Shape(std::string const& nm, Color const& clr);
	virtual float area() const = 0;
	virtual float volume() const = 0;
private:
	std::string name_ = "Shape";
	Color color_ = { 0.5f, 0.5f, 0.5f };
};

#endif // define SHAPE_HPP