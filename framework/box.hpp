#ifndef BOX_HPP
#define BOX_HPP

#include<glm/vec3.hpp>
#include<glm/gtx/intersect.hpp>
#include"shape.hpp"
#include"hitpoint.hpp"
#include"ray.hpp"
#include<vector>

class Box : public Shape
{
public:
	
	Box() = default;
	//Box(glm::vec3 const& min, glm::vec3 const& max);
	Box(glm::vec3 const& min, glm::vec3 const& max,
		std::string const& nm, std::shared_ptr<Material> const& mat);
	~Box() /* override */;
	float area() const override;
	float volume() const override;
	HitPoint intersect(Ray const& ray, float& t) const override;
	std::ostream& print(std::ostream& os) const override;

private:
	glm::vec3 min_ = { 0.0f, 0.0f, 0.0f };
	glm::vec3 max_ = { 1.0f, 1.0f, 1.0f };
};

#endif // define BOX_HPP