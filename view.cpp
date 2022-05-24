#include <iostream>
#include "view.hpp"

namespace vge_view
{

void View::draw(ViewType *vt)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    for(auto& it:m_shapes)
        it->draw(vt);
}

Object::~Object(){}

}
