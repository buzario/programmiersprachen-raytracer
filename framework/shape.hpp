#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include "hitpoint.hpp"
#include "ray.hpp"
#include "material.hpp"
#include<iostream>

class Shape
{
public:
	Shape() = default;
	Shape(std::string const& nm, std::shared_ptr<Material> const& mat);
	virtual ~Shape();
	//~Shape();		// uncomment for Task 5.8
	virtual float area() const = 0;
	virtual float volume() const = 0;
	virtual HitPoint intersect(Ray const& ray, float& t) const = 0; // float& t wofür?
	virtual std::ostream& print(std::ostream& os) const;
protected:
	std::string name_ = "Shape";
	std::shared_ptr<Material> material_ = std::make_shared<Material>(0.5f, 0.5f, 0.5f);
};

std::ostream& operator <<(std::ostream& os, Shape const& s);

#endif // define SHAPE_HPP