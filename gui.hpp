#pragma once

#include <vector>
#include <memory>

namespace vge_gui
{

class Observer
{
public:
    virtual ~Observer() = 0;
    virtual void notify() = 0;
};

class Notifier
{
public:
    void add_observer(std::shared_ptr<Observer>& o);
    void rm_observer(std::shared_ptr<Observer>& o);
protected:
    std::vector<std::weak_ptr<Observer>> m_observers;
};

class MouseEvent{};

class ViewType
{
public:
    virtual ~ViewType() = 0;
};

class ClassicView: public ViewType{};
class DarkView: public ViewType{};


class Object: public Observer, public Notifier
{
public:
    virtual ~Object() = 0;
    // slots
    virtual void on_mouse_press(MouseEvent& ev) = 0;
    // signals
    virtual void on_mouse_press() = 0;

    virtual void show(ViewType* vt) = 0;
};

class MenuBar: public Object
{
public:
    void on_mouse_press(MouseEvent& ev) override;
    void on_mouse_press() override;

    virtual void show(ViewType* vt) override;

    void notify() override;
};

class Widget: public Object
{
public:
    Widget(std::size_t h, std::size_t w);
    ~Widget() = 0;
private:
    std::size_t m_hight = 0;
    std::size_t m_width = 0;
};

class Button: public Widget
{
public:
    Button(std::size_t h = 10, std::size_t w = 10);
    // slots
    virtual void on_mouse_press(MouseEvent& ev) override;
    // signals
    virtual void on_mouse_press() override;

    virtual void show(ViewType* vt) override;

    void notify() override;
};

class Window: public Widget
{
public:
    Window(std::size_t h, std::size_t w);

    void on_mouse_press(MouseEvent& ev) override;
    void on_mouse_press() override;

    virtual void show(ViewType* vt) override;

    void notify() override;

private:
    Button m_close;
};

class MainWindow: public Window
{
public:
    MainWindow(std::size_t h, std::size_t w);

    void on_mouse_press(MouseEvent& ev) override;
    void on_mouse_press() override;

    virtual void show(ViewType* vt) override;

    void notify() override;

private:
    MenuBar m_menu_bar;
    MenuBar m_tool_bar;
    // tool bar: new doc, open doc, save doc
};

}
