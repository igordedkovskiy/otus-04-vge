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
    
Document read(FileFormat fmt, const std::string& name);
void write(FileFormat fmt, const std::string& name, Document& doc);

//class File
//{
//public:
//    File(const File& ws) = delete;
//    File(File&& ws) = delete;
//    File& operator=(const File& ws) = delete;
//    File& operator=(File&& ws) = delete;
//    
//    virtual ~File() = default;
//    virtual Document read() = 0;
//    virtual void write() = 0;
//    virtual bool save() = 0;
//
//protected:
//    std::string m_name;
//};
//
//class SVGFile: public File
//{
//public:
//    virtual ~SVGFile() = default;
//    virtual Document read() override;
//    virtual void write() override;
//    virtual bool save() override;
//};
//
//class PDFFile: public File
//{
//public:
//    virtual ~PDFFile() = default;
//    virtual Document read() override;
//    virtual void write() override;
//    virtual bool save() override;
//};
//
//enum class FileFormat
//{
//    svg,
//    wmf,
//    eps,
//    pdf,
//    cdr,
//    ai
//}
//
//std::unique_ptr<File> createFile(const std::string& fname);
//std::unique_ptr<File> createFile(FileFormat fmt);

}
