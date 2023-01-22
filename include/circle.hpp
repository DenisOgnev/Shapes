#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle final : public Shape
{
public:
    double r{};

    Circle(double _r);
    Vec3 get_3d_point(double t) const override;
    Vec3 get_first_derivative(double t) const override;
    std::string get_type() const override;
};

#endif