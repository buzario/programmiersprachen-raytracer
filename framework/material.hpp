#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include<glm/vec3.hpp>
#include"color.hpp"

struct Material
{
	std::string name = " ";
	Color ka = { 0.5f, 0.5f, 0.5f };
	Color kd = { 0.5f, 0.5f, 0.5f };
	Color ks = { 0.5f, 0.5f, 0.5f };
	float m = 0.0f;


	std::ostream& print(std::ostream& os) const {
		os << "Name: " << name << "\n";
		os << "ka: " << ka << "\n";
		os << "kd: " << kd << "\n";
		os << "ks: " << ks << "\n";
		os << "m: " << m << "\n";
		return os;
	}


};

std::ostream& operator <<(std::ostream& os, Material const& material)
	{
		return material.print(os);
	}
#endif // define MATERIAL_HPP