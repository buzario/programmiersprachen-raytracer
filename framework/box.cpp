#include"box.hpp"

/*
Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
	Shape{ "Box", std::make_shared<Material>() },
	min_{min},
	max_{max} {}
*/

Box::Box(glm::vec3 const& min, glm::vec3 const& max,
	std::string const& nm, std::shared_ptr<Material> const& mat) :
	Shape{ nm, mat },
	min_{ min },
	max_{ max } {
	// uncomment for Task 5.8
	//std::cout << "Box Konstruktor\n";
}

Box::~Box() {
	// uncomment for Task 5.8
	//std::cout << "Box Destruktor\n";
}

float Box::area() const {
	auto x = max_.x - min_.x;
	auto y = max_.y - min_.y;
	auto z = max_.z - min_.z;
	
	// checking if object is 2D  
	if (x == 0.0f || y == 0.0f || z == 0.0f) {
		return x * y + x * z + y * z;
	}
	return 2 * (x * y + x * z + y * z);
}

float Box::volume() const { 
	return (max_.x - min_.x) * (max_.y - min_.y) * (max_.z - min_.z); }


HitPoint Box::intersect(Ray const& ray, float& t) const {
	HitPoint hp;
	bool hit = false;
	auto norm_direction = glm::normalize(ray.direction);
	t = (min_.x - ray.origin.x) / norm_direction.x;
	auto intersect_test = ray.origin + t * norm_direction;

	if (min_.y <= intersect_test.y && intersect_test.y <= max_.y) {
		if (min_.z <= intersect_test.z && intersect_test.z <= max_.z) {
			hit = true;
		}
	}

	if (hit) {
		std::vector<float> coord_vec{
			min_.y, ray.origin.y, norm_direction.y,
			min_.z, ray.origin.z, norm_direction.z,
			max_.x, ray.origin.x, norm_direction.x,
			max_.y, ray.origin.y, norm_direction.y,
			max_.z, ray.origin.z, norm_direction.z,
		};
		for (auto i = 0; i < coord_vec.size(); i + 3) {
			float alt_t = (coord_vec[i] - coord_vec[i + 1]) / norm_direction[i + 2];
			if (alt_t > 0 && alt_t < t) {
				t = alt_t;
			}
		}
		auto position = ray.origin + (norm_direction * t);
		hp = { true, t, name_, material_->ka, position, norm_direction };
	}
	return hp;
}


std::ostream& Box::print(std::ostream& os) const {
	Shape::print(os);
	os << "Min-Point: (" << min_.x << ", " << min_.y << ", " << min_.z << ")\n";
	os << "Max-Point: (" << max_.x << ", " << max_.y << ", " << max_.z << ")\n";
	return os;
}