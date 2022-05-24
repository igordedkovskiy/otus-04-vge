#include <iostream>
#include "file.hpp"

namespace vge_model
{

namespace
{

Document read_svg(const std::string&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return Document{};
}

Document read_wmf(const std::string&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return Document{};
}

Document read_ai(const std::string&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return Document{};
}

void write_svg(const std::string&, Document&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void write_wmf(const std::string&, Document&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void write_ai(const std::string&, Document&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

}
    
Document read(FileFormat fmt, const std::string& name)
{
    if(fmt == FileFormat::svg)
        return read_svg(name);
    else if(fmt == FileFormat::wmf)
        return read_wmf(name);
    else
        return read_ai(name);
}

void write(FileFormat fmt, const std::string& name, Document& doc)
{
    if(fmt == FileFormat::svg)
        return write_svg(name, doc);
    else if(fmt == FileFormat::wmf)
        return write_wmf(name, doc);
    else
        return write_ai(name, doc);
}

}
