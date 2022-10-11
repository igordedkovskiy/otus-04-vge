#pragma once

#include <vector>
#include <memory>
#include "gui.hpp"

namespace vge_view
{

class Shape: public vge_gui::Widget
{
public:
    using point_coord_t = std::pair<double, double>;
    using points_t = std::vector<point_coord_t>;

    virtual void draw() = 0;
    virtual void add_point(point_coord_t coord) = 0;
protected:
    points_t m_points;
};

class Line: public Shape
{
public:
    void draw() override;
    void add_point(point_coord_t coord) override;
};

class Rectangle: public Shape
{
public:
    void draw() override;
    void add_point(point_coord_t coord) override;
};


class View
{
public:
    void draw();
    void add_shape(std::unique_ptr<Shape> sh);
    void remove_shape(std::unique_ptr<Shape> sh);
    Shape* get_shape();

private:
    std::vector<std::unique_ptr<Shape>> m_shapes;
};

}
