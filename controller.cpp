#include <iostream>
#include "controller.hpp"
#include "file.hpp"

namespace vge_controller
{

MainWindow::MainWindow(std::unique_ptr<vge_model::Model> model, std::unique_ptr<vge_view::View> view):
    m_model{std::move(model)},
    m_view{std::move(view)}
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void MainWindow::on_save_cmd()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    vge_model::write(vge_model::FileFormat::svg, std::string{"name"}, *m_model.get());
}

void MainWindow::on_open_cmd()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    m_model.release();
    m_model = std::make_unique<vge_model::Model>(vge_model::read(vge_model::FileFormat::svg, std::string{"name"}));
    m_view.release();
    //m_view = std::make_unique<vge_view::View>(*(m_model.get()));
    // for each shape in model:
    //     make view-shape out of shape
    //     add view-shape into view
}

void MainWindow::on_new_doc_cmd()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    m_view.release();
    m_view = std::make_unique<vge_view::View>();
    m_model.release();
    //m_model = std::make_unique<vge_model::Model>(*(m_view.get()));
    // for each shape in view:
    //     make mod-shape out of shape
    //     add mod-shape into view
}

void MainWindow::show()
{
    m_view->draw();
}



}
