#pragma once

#include <string>
#include "model.hpp"

enum class FileFormat
{
    svg,
    wmf,
    eps,
    pdf,
    cdr,
    ai
}

class File
{
public:
    virtual ~File() = default;
    virtual Document& open(const std::string& name) = 0;
    virtual void close() = 0;
    virtual bool save() = 0;
private:
    std::string m_name;
    Document& doc;
};

class SVGFile: public File
{
    ;
};

class PDFFile: public File
{
    ;
};

class FileCreator
{
public:
    std::unique_ptr<File> create(FileFormat fmt);
    std::unique_ptr<File> create(FileFormat fmt, const std::string& name);
};


