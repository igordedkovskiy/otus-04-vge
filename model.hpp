#pragma once

#include <vector>
#include <unordered_map>
#include <memory>
//#include "file.hpp"

namespace vge_model
{

using point_coord_t = std::pair<double, double>;

class Shape
{
public:
    using points_t = std::vector<point_coord_t>;

    virtual ~Shape() = 0;
    virtual void add_point(const point_coord_t& coord) = 0;
    virtual void choose_point(const point_coord_t& coord) = 0;
    virtual void change_point(const point_coord_t& coord) = 0;

protected:
    points_t m_points;
};

class Line: public Shape
{
public:
    void add_point(const point_coord_t& coord) override;
    void choose_point(const point_coord_t& coord) override;
    void change_point(const point_coord_t& coord) override;
};

class Rectangle: public Shape
{
public:
    void add_point(const point_coord_t& coord) override;
    void choose_point(const point_coord_t& coord) override;
    void change_point(const point_coord_t& coord) override;
};

class Model
{
public:
    void add_shape(Shape* sh);
    void add_shape(std::unique_ptr<Shape> sh);
    Shape* choose_shape(const point_coord_t& coord);
    void remove_shape(const point_coord_t& coord);
    void remove_shape(Shape* sh);

private:
    std::vector<std::unique_ptr<Shape>> m_shapes;
};

}
