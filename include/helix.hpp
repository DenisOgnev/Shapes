#ifndef HELIX_HPP
#define HELIX_HPP

#include "shape.hpp"

class Helix : public Shape
{
public:
    double r{};
    double step{};

    Helix(double _r, double _step);
    Vec3 get_3d_point(double t) const override;
    Vec3 get_first_derivative(double t) const override;
    std::string get_type() const override;
};

#endif