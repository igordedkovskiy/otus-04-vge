#pragma once

#include <vector>
#include <memory>

namespace vge_gui
{

class Object
{
public:
    virtual ~Object() = 0;
    virtual void on_mouse_press() = 0;
    virtual void show() = 0;
};

class Widget: public Object
{
public:
    Widget(std::size_t h, std::size_t w);
    ~Widget() = 0;
private:
    std::size_t m_height = 0;
    std::size_t m_width = 0;
};

class Button: public Widget
{
public:
    Button(std::size_t h = 10, std::size_t w = 10);
    void on_mouse_press() override;
    void show() override;
};

class Window: public Widget
{
public:
    Window(std::size_t h = 100, std::size_t w = 100);

    void on_mouse_press() override;
    void show() override;

private:
    Button m_close;
};

}
