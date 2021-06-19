#ifndef SPHERE_HPP
#define SPHERE_HPP

#include<glm/vec3.hpp>
#include"shape.hpp"

class Sphere : public Shape
{
public:
	
	Sphere() = default;
	Sphere(glm::vec3 const& ctr, float r,
		std::string const& nm = "Sphere", Color const& clr = {0.5f, 0.5f, 0.5f});
	float area() const override;
	float volume() const override;

private:
	glm::vec3 center_ = {0.0f, 0.0f, 0.0f};
	float radius_ = {1.0f};
};

#endif // define SPHERE_HPP