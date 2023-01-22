#include "ellipse.hpp"
#include <cmath>
#include <exception>

Ellipse::Ellipse(double _r1, double _r2) : r1{_r1}, r2{_r2}
{
    if (r1 < 0.0 || r2 < 0.0)
    {
        throw std::exception("Radius can't be less than zero");
    }
};

Ellipse::Vec3 Ellipse::get_3d_point(double t) const
{
    return {r1 * std::cos(t), r2 * std::sin(t), 0.0};
};

Ellipse::Vec3 Ellipse::get_first_derivative(double t) const
{
    return {-r1 * std::sin(t), r2 * std::cos(t), 0.0};
};

std::string Ellipse::get_type() const 
{
    return "Ellipse";
};