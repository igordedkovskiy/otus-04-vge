#pragma once

#include <vector>
#include <unordered_map>
#include <memory>
#include <string>

#include "gui.hpp"
#include "model.hpp"
#include "view.hpp"

namespace vge_controller
{

class MainWindow: vge_gui::Window
{
public:
    MainWindow(std::unique_ptr<vge_model::Model> model, std::unique_ptr<vge_view::View> view);

    void on_save_cmd();
    void on_open_cmd();

    void on_new_doc_cmd();

    vge_view::Shape* on_new_shape_cmd();
    void on_rm_shape_cmd(vge_view::Shape*);

    void show();

private:
    std::unique_ptr<vge_model::Model> m_model;
    std::unique_ptr<vge_view::View> m_view;

    vge_gui::Button m_save;
    vge_gui::Button m_open;
    vge_gui::Button m_new_doc;
    vge_gui::Button m_new_line;
};

}
