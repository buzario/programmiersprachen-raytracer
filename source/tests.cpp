#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES
#include <catch.hpp>
#include<cmath>
#include<glm/gtx/intersect.hpp>
#include<glm/glm.hpp>
#include"sphere.hpp"
#include"box.hpp"

TEST_CASE("Sphere constructor and methods area() and volume()", "[sphere area and volume]") {
    std::shared_ptr<Shape> s = std::make_shared<Sphere>();
    
    SECTION("Sphere has default values, methods can be called on base-class pointer") {
        REQUIRE(4.0f * M_PI == Approx(s->area()));
        REQUIRE(4.0f / 3.0f * M_PI == Approx(s->volume()));
    }
    
    s = std::make_shared<Sphere>(glm::vec3{ 3.0f, -2.0f, 1.5f }, 4.3f);
    SECTION("normal radius returns expected values") {
        REQUIRE(232.352f == Approx(s->area()));
        REQUIRE(333.038f == Approx(s->volume()));
    }
    
    s = std::make_shared<Sphere>(glm::vec3{ -10.0f, -99948.23, -32 }, 0.01f);
    SECTION("border case radius returns expected values") {
        REQUIRE(0.0012566370f == Approx(s->area()));
        REQUIRE(0.0000041888f == Approx(s->volume()));
    }

    s = std::make_shared<Sphere>(glm::vec3{ -0.0f, 299948.23, -323422 }, 0.0f);
    SECTION("Sphere with radius 0 has no area or volume") {
        REQUIRE(0.0f == Approx(s->area()));
        REQUIRE(0.0f == Approx(s->volume()));
    }
}


TEST_CASE("Box constructor and methods", "[box area and volume]") {
    std::shared_ptr<Shape> s = std::make_shared<Box>();
    SECTION("Box has default values, methods can be called on base-class pointer") {
        REQUIRE(6.0f == Approx(s->area()));
        REQUIRE(1.0f == Approx(s->volume()));
    }

    s = std::make_shared<Box>(glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{ 0.0f, 0.0f, 0.0f });
    SECTION("Box has no area and volume") {
        REQUIRE(0.0f == Approx(s->area()));
        REQUIRE(0.0f == Approx(s->volume()));
    }

    s = std::make_shared<Box>(glm::vec3{ 0.0f, 0.0f, 0.0f }, glm::vec3{ 10.0f, 0.0f, 10.0f});
    SECTION("2D - Box has area, but no volume") {
        REQUIRE(100.0f == Approx(s->area()));
        REQUIRE(0.0f == Approx(s->volume()));
    }

    s = std::make_shared<Box>(glm::vec3{ 0.0f, 0.0f, 0.0f }, glm::vec3{ 0.00001f, 0.00001f, 0.00001f });
    SECTION("Border case Box has expected values") {
        REQUIRE(0.0000000006f == Approx(s->area()));
        REQUIRE(0.000000000000001f == Approx(s->volume()));
    }

    s = std::make_shared<Box>(glm::vec3{ 0.0f, 0.0f, 0.0f }, glm::vec3{ 23.0f, 3.0f, 10.45f });
    SECTION("Border case Box has expected values") {
        REQUIRE(681.40f == Approx(s->area()));
        REQUIRE(721.05f == Approx(s->volume()));
    }

    s = std::make_shared<Box>(glm::vec3{ 13.3f, -34.145f, 245.0094f }, glm::vec3{ 94.23f, 0.938f, 534.5f });
    SECTION("Border case Box has expected values") {
        REQUIRE(72847.88f == Approx(s->area()));
        REQUIRE(821941.16f == Approx(s->volume()));
    }
}


TEST_CASE("Box & Sphere constructor", "[constructors]") {
    std::shared_ptr<Shape> s = std::make_shared<Sphere>(glm::vec3{ 3.0f, -2.0f, 1.5f }, 4.3f);
    SECTION("Sphere without explicit Shape-Members should be constructed") {
        REQUIRE(232.352f == Approx(s->area()));
        REQUIRE(333.038f == Approx(s->volume()));
    }

    s = std::make_shared<Sphere>(glm::vec3{ 3.0f, -2.0f, 1.5f }, 4.3f, "Sphere2", Color{0.2f, 0.4f, 0.2f});
    SECTION("Sphere with explicit Shape-Members should be constructed") {
        REQUIRE(232.352f == Approx(s->area()));
        REQUIRE(333.038f == Approx(s->volume()));
    }

    s = std::make_shared<Box>(glm::vec3{ 0.0f, 0.0f, 0.0f }, glm::vec3{ 23.0f, 3.0f, 10.45f });
    SECTION("Box without explicit Shape-Members should be constructed") {
        REQUIRE(681.40f == Approx(s->area()));
        REQUIRE(721.05f == Approx(s->volume()));
    }

    s = std::make_shared<Box>(glm::vec3{ 0.0f, 0.0f, 0.0f }, glm::vec3{ 23.0f, 3.0f, 10.45f },
        "Box2", Color{0.4f, 0.6f, 0.2f});
    SECTION("Box with explicit Shape-Members should be constructed") {
        REQUIRE(681.40f == Approx(s->area()));
        REQUIRE(721.05f == Approx(s->volume()));
    }
}

TEST_CASE("operator<< and print mehtods", "[operator<< & print]") {
    std::shared_ptr<Shape> s = std::make_shared<Sphere>(glm::vec3{ 3.0f, -2.0f, 1.5f }, 4.3f);
    std::cout << (*s) << std::endl;

    s = std::make_shared<Sphere>(glm::vec3{ 3.0f, -2.0f, 1.5f }, 4.3f, "Sphere2", Color{ 0.2f, 0.4f, 0.2f });
    std::cout << (*s) << std::endl;

    s = std::make_shared<Sphere>(glm::vec3{ 1.34f, 65.0f, 0.314f }, 0.213f, "Sphere3", Color{ 0.1f, 0.1f, 0.8f });
    std::cout << (*s) << std::endl;

    s = std::make_shared<Box>(glm::vec3{ 0.0f, 0.0f, 0.0f }, glm::vec3{ 23.0f, 3.0f, 10.45f });
    std::cout << (*s) << std::endl;

    s = std::make_shared<Box>(glm::vec3{ 0.0f, 0.0f, 0.0f }, glm::vec3{ 23.0f, 3.0f, 10.45f },
        "Box2", Color{ 0.4f, 0.6f, 0.2f });
    std::cout << (*s) << std::endl;

    s = std::make_shared<Box>(glm::vec3{ 704.0f, -244.0f, 34.95f }, glm::vec3{ 7400.0f, -24.593f, 90.84f },
        "Box3", Color{ 0.99f, 0.66f, 0.33f });
    std::cout << (*s) << std::endl;
}



TEST_CASE("intersect_ray_sphere", "[intersect]")
{
    // Ray
    glm::vec3 ray_origin{ 0.0f, 0.0f, 0.0f };
    // ray direction has to be normalized !
    // you can use :
    // v = glm :: normalize ( some_vector )
    glm::vec3 ray_direction{ 0.0f, 0.0f, 1.0f };
    // Sphere
    glm::vec3 sphere_center{ 0.0f ,0.0f, 5.0f };
    float sphere_radius{ 1.0f };
    float distance = 0.0f;
    auto result = glm::intersectRaySphere(
        ray_origin, ray_direction,
        sphere_center,
        sphere_radius * sphere_radius, // squared radius !!!
        distance);
    REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("Sphere intersect_method", "[intersect_method]")
{
    SECTION("Should not hit") {
        Ray ray = { glm::vec3{ -0.79f, 3.92f, 0.0f }, glm::vec3{ 1.51f, -0.85f, 1.13f } };
        auto sphere = std::make_shared<Sphere>(glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f);
        auto hitpoint = sphere->intersect(ray);
        REQUIRE(hitpoint.hit == false);
    }

    SECTION("Should not hit") {
        Ray ray = { glm::vec3{ -2.9f, 3.2f, 7.2f }, glm::vec3{ -0.82f, -1.97f, 6.97f } };
        auto sphere = std::make_shared<Sphere>
            (glm::vec3{ -4.99f, -7.72f, 0.0f }, 5.0f);
        auto hitpoint = sphere->intersect(ray);
        REQUIRE(hitpoint.hit == false);
    }

    SECTION("Should not hit") {
        Ray ray = { glm::vec3{ 0.0f, 0.0f, 7.2f }, glm::vec3{ 0.0f, 0.0f, 2.8f } };
        auto sphere = std::make_shared<Sphere>
            (glm::vec3{ 0.0f, 0.0f, 0.0f }, 5.0f);
        auto hitpoint = sphere->intersect(ray);
        REQUIRE(hitpoint.hit == false);
    }

    SECTION("Should hit") {
        Ray ray = { glm::vec3{ -0.79f, 3.92f, 0.0f }, glm::vec3{ 1.51f, -0.85f, 1.13f } };
        auto sphere = std::make_shared<Sphere>
            (glm::vec3{ 8.14f, -1.11f, 6.68f }, 3.30f,
                "Sphere1", Color{ 0.01f, 0.0f, 0.4f });
        auto hitpoint = sphere->intersect(ray);
        REQUIRE(hitpoint.hit == true);
        REQUIRE(hitpoint.name == "Sphere1");
        REQUIRE(hitpoint.color.r == 0.01f);
        REQUIRE(hitpoint.color.g == 0.0f);
        REQUIRE(hitpoint.color.b == 0.4f);
        REQUIRE(hitpoint.direction.x == Approx(0.72993f).epsilon(0.0001));
        REQUIRE(hitpoint.direction.y == Approx(-0.41089f).epsilon(0.0001));
        REQUIRE(hitpoint.direction.z == Approx(0.54624f).epsilon(0.0001));
        REQUIRE(hitpoint.position.x == Approx(5.73111f).epsilon(0.0001));
        REQUIRE(hitpoint.position.y == Approx(0.24918f).epsilon(0.0001));
        REQUIRE(hitpoint.position.z == Approx(4.88004f).epsilon(0.0001));
    }

    SECTION("Should hit in one point") {
        Ray ray = { glm::vec3{ 0.0f, 0.0f, 0.0f }, glm::vec3{ 0.0f, 0.0f, 10.0f } };
        auto sphere = std::make_shared<Sphere>
            (glm::vec3{ 0.0f, 0.0f, 0.0f }, 5.0f,
                "Sphere1", Color{ 0.0f, 0.8f, 0.2f });
        auto hitpoint = sphere->intersect(ray);
        REQUIRE(hitpoint.hit == true);
        REQUIRE(hitpoint.name == "Sphere1");
        REQUIRE(hitpoint.color.r == 0.0f);
        REQUIRE(hitpoint.color.g == 0.8f);
        REQUIRE(hitpoint.color.b == 0.2f);
        REQUIRE(hitpoint.direction.x == Approx(0.0f));
        REQUIRE(hitpoint.direction.y == Approx(0.f));
        REQUIRE(hitpoint.direction.z == Approx(1.0f));
        REQUIRE(hitpoint.position.x == Approx(0.0f));
        REQUIRE(hitpoint.position.y == Approx(0.0f));
        REQUIRE(hitpoint.position.z == Approx(5.0f));
    }

    SECTION("Should hit in one point") {
        Ray ray = { glm::vec3{ 0.0f, 1.0f, 5.0f }, glm::vec3{ 0.0f, 0.0f, -10.0f } };
        auto sphere = std::make_shared<Sphere>
            (glm::vec3{ .0f, 0.0f, 0.0f }, 1.0f,
                "Sphere1", Color{ 0.2f, 0.3f, 0.4f });
        auto hitpoint = sphere->intersect(ray);
        REQUIRE(hitpoint.hit == true);
        REQUIRE(hitpoint.name == "Sphere1");
        REQUIRE(hitpoint.color.r == 0.2f);
        REQUIRE(hitpoint.color.g == 0.3f);
        REQUIRE(hitpoint.color.b == 0.4f);
        REQUIRE(hitpoint.direction.x == Approx(0.0f));
        REQUIRE(hitpoint.direction.y == Approx(0.f));
        REQUIRE(hitpoint.direction.z == Approx(-1.0f));
        REQUIRE(hitpoint.position.x == Approx(0.0f));
        REQUIRE(hitpoint.position.y == Approx(1.0f));
        REQUIRE(hitpoint.position.z == Approx(0.0f));
    }

    SECTION("Should hit") {
        Ray ray = { glm::vec3{ 4.3f, 2.65f, -3.72f }, glm::vec3{ -16.3f, 0.65f, 53.92f } };
        auto sphere = std::make_shared<Sphere>
            (glm::vec3{ 12.38f, 1.0f, 5.64f }, 11.00f,
                "Sphere1", Color{ 0.13f, 0.5f, 0.13f });
        auto hitpoint = sphere->intersect(ray);
        REQUIRE(hitpoint.hit == true);
        REQUIRE(hitpoint.name == "Sphere1");
        REQUIRE(hitpoint.color.r == 0.13f);
        REQUIRE(hitpoint.color.g == 0.5f);
        REQUIRE(hitpoint.color.b == 0.13f);
        REQUIRE(hitpoint.direction.x == Approx(-0.28935f).epsilon(0.001));
        REQUIRE(hitpoint.direction.y == Approx(0.01154f).epsilon(0.001));
        REQUIRE(hitpoint.direction.z == Approx(0.95715f).epsilon(0.001));
        REQUIRE(hitpoint.position.x == Approx(3.25622f).epsilon(0.0001));
        REQUIRE(hitpoint.position.y == Approx(2.69162f).epsilon(0.0001));
        REQUIRE(hitpoint.position.z == Approx(-0.26720f).epsilon(0.0001));
    }
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
