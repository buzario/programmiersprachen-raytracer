#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES
#include <catch.hpp>
#include<cmath>
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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
