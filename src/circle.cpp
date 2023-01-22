#include "circle.hpp"
#include <cmath>
#include <exception>

Circle::Circle(double _r) : r{_r}
{
    if (r < 0.0)
    {
        throw std::exception("Radius can't be less than zero");
    }
};

Circle::Vec3 Circle::get_3d_point(double t) const
{
    return {r * std::cos(t), r * std::sin(t), 0.0};
};

Circle::Vec3 Circle::get_first_derivative(double t) const
{
    return {-r * std::sin(t), r * std::cos(t), 0.0};
};

std::string Circle::get_type() const 
{
    return "Circle";
};