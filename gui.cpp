#include <iostream>
#include <algorithm>
#include "view.hpp"

namespace vge_gui
{

void Notifier::add_observer(std::shared_ptr<Observer>& o)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    m_observers.emplace_back(o);
}

void Notifier::rm_observer(std::shared_ptr<Observer>& o)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    auto cond = [&o](const auto& el)
    {
        if(auto observer = el.lock())
        {
            if(observer.get() == o.get())
                return true;
        }
        return false;
    };
    auto el = std::find_if(std::begin(m_observers), std::end(m_observers), cond);
    if(el != std::end(m_observers))
        m_observers.erase(el);
}

ViewType::~ViewType(){}

Object::~Object(){}

Observer::~Observer(){}

MainWindow::MainWindow(std::size_t h, std::size_t w): Window{h,w} {}

void MainWindow::on_mouse_press(MouseEvent&){}
void MainWindow::on_mouse_press(){}
void MainWindow::show(ViewType* vt)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    m_menu_bar.show(vt);
    m_tool_bar.show(vt);
}

void MainWindow::notify()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}


void MenuBar::on_mouse_press(MouseEvent&){}

void MenuBar::on_mouse_press(){}

void MenuBar::show(ViewType*)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void MenuBar::notify()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Widget::Widget(std::size_t h, std::size_t w): m_hight{h}, m_width{w} {}

Widget::~Widget(){}

Window::Window(std::size_t h, std::size_t w): Widget{h,w} {}

void Window::on_mouse_press(MouseEvent&){}
void Window::on_mouse_press(){}

void Window::show(ViewType* vt)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    m_close.show(vt);
}

void Window::notify()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Button::Button(std::size_t h, std::size_t w): Widget{h,w} {}
void Button::on_mouse_press(MouseEvent &){}
void Button::on_mouse_press(){}

void Button::show(ViewType*)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Button::notify()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

}
