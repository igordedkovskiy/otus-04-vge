#pragma once

#include <vector>
#include <unordered_map>
#include <memory>

#include "model.hpp"
#include "gui.hpp"

namespace vge_controller
{
    
class Controller
{
public:
    void on_shape_change()
private:
    vge_model::Document m_doc;
    vge_gui::MainWindow m_window;
};