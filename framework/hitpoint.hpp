#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include<glm/vec3.hpp>
#include"color.hpp"

struct HitPoint
{
	bool hit = false;
	float distance;
	std::string name;
	Color color;
	glm::vec3 position;
	glm::vec3 direction;
};

#endif // define HITPOINT_HPP