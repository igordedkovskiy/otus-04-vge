#pragma once

#include <vector>
#include <memory>

namespace vge_gui
{

class Observer
{
public:
    virtual ~Observer() = 0;
    virtual void update() = 0;
};

class Notifier
{
public:
    void add_observer(Observer* o);
    void rm_observer(Observer* o);
protected:
    std::vector<Observer*> m_observers;
};

class MouseEvent{};


class ViewType
{
public:
    virtual ~ViewType() = 0;
};

class ClassicView: public ViewType
{
public:
    virtual ~ClassicView();
};


class Object: public Observer, public Notifier
{
public:
    virtual ~Object() = 0;
    // slots
    virtual void on_mouse_move(MouseEvent& ev) = 0;
    virtual void on_mouse_press(MouseEvent& ev) = 0;
    // signals
    virtual void on_mouse_move() = 0;
    virtual void on_mouse_press() = 0;

    virtual void show(ViewType* vt) = 0;
};

class MenuBar: public Object
{
public:
    void on_mouse_move(MouseEvent& ev) override;
    void on_mouse_press(MouseEvent& ev) override;
    void on_mouse_move() override;
    void on_mouse_press() override;

    virtual void show(ViewType* vt) override;

    void update() override;
};

class MainWindow: public Object
{
public:
    void on_mouse_move(MouseEvent& ev) override;
    void on_mouse_press(MouseEvent& ev) override;
    void on_mouse_move() override;
    void on_mouse_press() override;

    virtual void show(ViewType* vt) override;

    void update() override;
private:
    MenuBar m_menu_bar;
    // tool bar: new doc, open doc, save doc
};

}
