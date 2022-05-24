#pragma once

#include <vector>
#include <unordered_map>
#include <memory>
//#include "file.hpp"

namespace vge_model
{

class Shape
{
public:
    using point_id_t = unsigned int;
    using point_coord_t = std::pair<double, double>;
    using points_t = std::unordered_map<point_id_t, point_coord_t>;

    Shape();
    Shape(const Shape& sh);
    Shape(Shape&& sh);
    Shape& operator=(const Shape& sh);
    Shape& operator=(Shape&& sh);
    virtual ~Shape() = 0;
    
    virtual void add_point(const point_coord_t& coord) = 0;
    virtual void choose_point(point_coord_t coord) = 0;
    virtual void change_point(point_coord_t coord) = 0;

protected:
    point_id_t m_current_point;
    points_t m_points;
};

class Document
{
public:
    Shape* add_shape(std::unique_ptr<Shape> sh);
    Shape* choose_shape(Shape* sh);
    void remove_shape(Shape* sh);
private:
    Shape* m_cur_shape = nullptr;
    std::vector<std::unique_ptr<Shape>> m_shapes;
};

class Line: public Shape
{
public:
    using point_coord_t = Shape::point_coord_t;
    Line(const Line& ln);
    Line(Line&& ln);
    Line& operator=(const Line& ln);
    Line& operator=(Line&& ln);
    ~Line();

    virtual void add_point(const point_coord_t& coord) override;
    virtual void choose_point(point_coord_t coord) override;
    virtual void change_point(point_coord_t coord) override;
};

class Rectangle: public Shape
{
public:
    using point_coord_t = Shape::point_coord_t;
    Rectangle(const Rectangle& rc);
    Rectangle(Rectangle&& rc);
    Rectangle& operator=(const Rectangle& rc);
    Rectangle& operator=(Rectangle&& rc);
    ~Rectangle();

    virtual void add_point(const point_coord_t& coord) override;
    virtual void choose_point(point_coord_t coord) override;
    virtual void change_point(point_coord_t coord) override;
};

}
