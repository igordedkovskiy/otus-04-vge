#include "view.hpp"

namespace vge_view
{

void View::draw()
{
    for(auto& it:m_shapes)
        it->draw(vt.get());
}


}
