#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <tuple>
#include <memory>
#include <string>

class Shape
{
public:
    using Vec3 = std::tuple<double, double, double>;

    int test{};

    virtual Vec3 get_3d_point(double t) const = 0;
    virtual Vec3 get_first_derivative(double t) const = 0;
    virtual std::string get_type() const = 0;
    virtual ~Shape() = default;
};

#endif