#include <iostream>
#include "file.hpp"

namespace vge_model
{

namespace
{

Model read_svg(const std::string&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return Model{};
}

Model read_wmf(const std::string&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return Model{};
}

Model read_ai(const std::string&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return Model{};
}

void write_svg(const std::string&, Model&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void write_wmf(const std::string&, Model&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void write_ai(const std::string&, Model&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

}
    
Model read(FileFormat fmt, const std::string& name)
{
    if(fmt == FileFormat::svg)
        return read_svg(name);
    else if(fmt == FileFormat::wmf)
        return read_wmf(name);
    else
        return read_ai(name);
}

void write(FileFormat fmt, const std::string& name, Model& mod)
{
    if(fmt == FileFormat::svg)
        return write_svg(name, mod);
    else if(fmt == FileFormat::wmf)
        return write_wmf(name, mod);
    else
        return write_ai(name, mod);
}

}
