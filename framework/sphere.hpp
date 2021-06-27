#ifndef SPHERE_HPP
#define SPHERE_HPP

#include<glm/vec3.hpp>
#include<glm/gtx/intersect.hpp>
#include"shape.hpp"
#include"hitpoint.hpp"
#include"ray.hpp"

class Sphere : public Shape
{
public:
	
	Sphere() = default;
	Sphere(glm::vec3 const& ctr, float r);
	Sphere(glm::vec3 const& ctr, float r,
		std::string const& nm, Color const& clr);
	~Sphere() /*override*/;
	float area() const override;
	float volume() const override;
	std::ostream& print(std::ostream& os) const override;
	HitPoint intersect(Ray const& ray);

private:
	glm::vec3 center_ = {0.0f, 0.0f, 0.0f};
	float radius_ = {1.0f};
};

#endif // define SPHERE_HPP