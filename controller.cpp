#include "controller.hpp"

namespace vge_controller
{

void Controller::update()
{
    ;
}

void Controller::read_data(vge_model::FileFormat fmt, const std::string& name)
{
    m_model = vge_model::read(fmt, name);
}

void Controller::write_data(vge_model::FileFormat fmt, const std::string &name, vge_model::Document &doc)
{
    vge_model::write(fmt, name, doc);
}



}
