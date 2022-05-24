#pragma once

#include <vector>
#include <memory>

#include "gui.hpp"
#include "model.hpp"

namespace vge_view
{

using Observer = vge_gui::Observer;
using Notifier = vge_gui::Notifier;
using MouseEvent = vge_gui::MouseEvent;

class Object: public Observer, public Notifier
{
public:
    virtual ~Object() = 0;
    // slots (in qt's definition)
    virtual void on_mouse_move(MouseEvent& ev) = 0;
    virtual void on_mouse_press(MouseEvent& ev) = 0;
    // signals (in qt's definition)
    virtual void on_mouse_move() = 0;
    virtual void on_mouse_press() = 0;
};

class Shape: public Object
{
public:
    using point_id_t = unsigned int;
    using point_coord_t = std::pair<double, double>;
    using points_t = std::unordered_map<point_id_t, point_coord_t>;

    virtual void draw(const vge_gui::ViewType* vt) = 0;
    virtual void add_point(point_coord_t coord) = 0;
protected:
    points_t m_points;
};

class Line: public Shape
{
public:
    void on_mouse_move(MouseEvent& ev) override;
    void on_mouse_press(MouseEvent& ev) override;
    void on_mouse_move() override;
    void on_mouse_press() override;

    void notify() override;

    void draw(const vge_gui::ViewType* vt) override;
    void add_point(point_coord_t coord) override;
};

class Rectangle: public Shape
{
public:
    void on_mouse_move(MouseEvent& ev) override;
    void on_mouse_press(MouseEvent& ev) override;
    void on_mouse_move() override;
    void on_mouse_press() override;

    void notify() override;

    void draw(const vge_gui::ViewType* vt) override;
    void add_point(point_coord_t coord) override;
};


class View
{
public:
    using ViewType = vge_gui::ViewType;
    View() = default;
    void draw(ViewType* vt);
    void add(Shape* sh);
    void remove(Shape* sh);
    Shape* get_shape();
private:
    std::vector<std::unique_ptr<Shape>> m_shapes;
};

}
