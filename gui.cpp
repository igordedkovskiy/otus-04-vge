#include <algorithm>
#include "view.hpp"

namespace vge_gui
{

void Notifier::add_observer(Observer *o)
{
    m_observers.emplace_back(o);
}

void Notifier::rm_observer(Observer *o)
{
    auto el = std::find(std::begin(m_observers), std::end(m_observers), o);
    if(el != std::end(m_observers))
        m_observers.erase(el);
}

}
