#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "shape.hpp"

class Ellipse : public Shape
{
public:
    double r1{};
    double r2{};

    Ellipse(double _r1, double _r2);
    Vec3 get_3d_point(double t) const override;
    Vec3 get_first_derivative(double t) const override;
    std::string get_type() const override;
};

#endif