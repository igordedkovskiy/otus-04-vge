#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"

int main()
{
    vge_model::Document doc;
    vge_view::View view{std::make_unique<vge_gui::ClassicView>()};
    vge_gui::MainWindow mwindow;
    vge_controller::Controller controller{doc, view};
    return 0;
}
