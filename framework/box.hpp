#ifndef BOX_HPP
#define BOX_HPP

#include<glm/vec3.hpp>
#include"shape.hpp"

class Box : public Shape
{
public:
	
	Box() = default;
	Box(glm::vec3 const& min, glm::vec3 const& max,
		std::string const& nm = "Box", Color const& clr = {0.5f, 0.5f, 0.5f});
	~Box() /*override*/;
	float area() const override;
	float volume() const override;
	std::ostream& print(std::ostream& os) const override;

private:
	glm::vec3 min_ = { 0.0f, 0.0f, 0.0f };
	glm::vec3 max_ = {1.0f, 1.0f, 1.0f};
};

#endif // define BOX_HPP