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
    Controller(vge_model::Document& mod, vge_view::View& view);
    void update() override;
    void read_data(vge_model::FileFormat fmt, const std::string& name);
    void write_data(vge_model::FileFormat fmt, const std::string& name, vge_model::Document& doc);

private:
    // controller
    vge_gui::MainWindow m_window;

    vge_model::Document& m_model;
    vge_view::View& m_view;
};

}
