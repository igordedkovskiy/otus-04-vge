#pragma once

#include <vector>
#include <unordered_map>
#include <memory>
#include <string>

#include "gui.hpp"
#include "model.hpp"
#include "view.hpp"
#include "file.hpp"

namespace vge_controller
{

class Controller: public vge_gui::Observer, public vge_gui::Notifier
{
public:
    Controller(std::unique_ptr<vge_model::Model> mod, std::unique_ptr<vge_view::View> view);
    void notify() override;
    void read_data(vge_model::FileFormat fmt, const std::string& name);
    void write_data(vge_model::FileFormat fmt, const std::string& name, vge_model::Model& doc);

    void show();

private:
    std::unique_ptr<vge_gui::ViewType> m_view_type;

    // controller
    vge_gui::MainWindow m_mwindow;

    std::unique_ptr<vge_model::Model> m_model;
    std::unique_ptr<vge_view::View> m_view;
};

}
