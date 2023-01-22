#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <algorithm>
#include <numeric>

#include <omp.h>

#include "shape.hpp"
#include "circle.hpp"
#include "ellipse.hpp"
#include "helix.hpp"

constexpr double PI{3.14159265358979323846};
constexpr std::size_t container_size{25};

std::shared_ptr<Shape> get_random_shape()
{
    static std::mt19937 mt{std::random_device{}()};
    static std::uniform_int_distribution picker{1, 3};
    static std::uniform_real_distribution<double> dist{0.0, 100.0};

    std::shared_ptr<Shape> shape;
    switch (picker(mt))
    {
    case 1:
        shape = std::make_shared<Circle>(dist(mt));
        break;
    case 2:
        shape = std::make_shared<Ellipse>(dist(mt), dist(mt));
        break;
    case 3:
        shape = std::make_shared<Helix>(dist(mt), dist(mt));
        break;
    }

    return shape;
};

int main()
{
    std::vector<std::shared_ptr<Shape>> shapes(container_size);
    std::generate(shapes.begin(), shapes.end(), get_random_shape);

    for (const auto& shape : shapes)
    {
        auto point{shape->get_3d_point(PI / 4)};
        auto derivative{shape->get_first_derivative(PI / 4)};
        std::cout << "Coordinates:\t x = " << std::get<0>(point) << ", y = " << std::get<1>(point) << ", z = " << std::get<2>(point) << "\n";
        std::cout << "Derivative:\t (" << std::get<0>(derivative) << ", " << std::get<1>(derivative) << ", " << std::get<2>(derivative) << ")\n\n";
    }
    // std::vector<std::shared_ptr<Shape>> circles;
    // std::copy_if(shapes.begin(), shapes.end(), std::back_inserter(circles), [](std::shared_ptr<Shape> shape){ return shape->get_type() == "Circle"; });

    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto& shape : shapes)
    {
        if (shape->get_type() == "Circle")
        {
            circles.push_back(std::dynamic_pointer_cast<Circle>(shape));
        }
    }
    std::sort(circles.begin(), circles.end(), [](std::shared_ptr<Circle> c1, std::shared_ptr<Circle> c2){ return c1->r < c2->r; });

    double sum{std::accumulate(circles.begin(), circles.end(), 0.0, [](double sum, std::shared_ptr<Circle> c){ return sum + c->r; })};

    double parallel_sum{0.0};
    #pragma omp parallel for reduction(+:sum)
    for (int i{0}; i < circles.size(); i++)
    {
        parallel_sum += circles[i]->r;
    }

    std::cout << sum << " " << parallel_sum << "\n";

    return 0;
}