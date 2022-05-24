#include <iostream>
#include "controller.hpp"

namespace vge_controller
{

Controller::Controller(std::unique_ptr<vge_model::Model> mod, std::unique_ptr<vge_view::View> view):
    m_view_type{std::make_unique<vge_gui::ClassicView>()},
    m_mwindow{100,100},
    m_model{std::move(mod)},
    m_view{std::move(view)}
{}

void Controller::notify()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Controller::read_data(vge_model::FileFormat fmt, const std::string& name)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    m_model.release();
    m_model = std::make_unique<vge_model::Model>(vge_model::read(fmt, name));
}

void Controller::write_data(vge_model::FileFormat fmt, const std::string &name, vge_model::Model& mod)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    vge_model::write(fmt, name, mod);
}

void Controller::show()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    m_mwindow.show(m_view_type.get());
    m_view->draw(m_view_type.get());
}

}
