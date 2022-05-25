#include <memory>
#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"

int main()
{
    auto mod = std::make_unique<vge_model::Model>();
    auto view = std::make_unique<vge_view::View>();
    vge_controller::MainWindow controller{std::move(mod), std::move(view)};
    controller.show();
    return 0;
}
