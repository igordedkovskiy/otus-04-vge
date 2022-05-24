#pragma once

#include <string>
#include <memory>
#include "model.hpp"

namespace vge_model
{

enum class FileFormat
{
    svg,
    wmf,
    eps,
    pdf,
    cdr,
    ai
};
    
Model read(FileFormat fmt, const std::string& name);
void write(FileFormat fmt, const std::string& name, Model& mod);

}
