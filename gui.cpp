#include <iostream>
#include <algorithm>
#include "view.hpp"

namespace vge_gui
{

Object::~Object(){}

Widget::Widget(std::size_t h, std::size_t w):
    m_height{h},
    m_width{w}
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Widget::~Widget(){}

Button::Button(std::size_t h, std::size_t w):
    Widget{h, w}
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Button::on_mouse_press()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Button::show()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Window::Window(std::size_t h, std::size_t w):
    Widget{h ,w}
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Window::on_mouse_press()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Window::show()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

}
