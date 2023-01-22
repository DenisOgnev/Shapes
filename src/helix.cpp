#include "helix.hpp"
#include <cmath>
#include <exception>

Helix::Helix(double _r, double _step) : r{_r}, step{_step}
{
    if (r < 0.0)
    {
        throw std::exception("Radius can't be less than zero");
    }
};

Helix::Vec3 Helix::get_3d_point(double t) const
{
    return {r * std::cos(t), r * std::sin(t), step * t};
};

Helix::Vec3 Helix::get_first_derivative(double t) const
{
    return {-r * std::sin(t), r * std::cos(t), step};
};

std::string Helix::get_type() const 
{
    return "Helix";
};