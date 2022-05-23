// homework #4: vector graphics editor

#include "model.hpp"

namespace vge_gui
{

class Object
{
public: // mouse events
    virtual void on_mouse_move(Event& ev) = 0;
    virtual void on_mouse_press(Event& ev) = 0;
    virtual void on_mouse_release(Event& ev) = 0;
    virtual void on_mouse_click(Event& ev) = 0;
};

class Shape: public Object
{
public:
    virtual void draw() = 0;

    void on_mouse_move(Event& ev) override;
    void on_mouse_press(Event& ev) override;
    void on_mouse_release(Event& ev) override;
    void on_mouse_click(Event& ev) override;
};

class MenuBar: public Object
{
public:
    void on_mouse_move(Event& ev) override;
    void on_mouse_press(Event& ev) override;
    void on_mouse_release(Event& ev) override;
    void on_mouse_click(Event& ev) override;
    
private:
    // set of items: file, settings etc
};

class MainWindow: public Object
{
public:
    void on_mouse_move(Event& ev) override;
    void on_mouse_press(Event& ev) override;
    void on_mouse_release(Event& ev) override;
    void on_mouse_click(Event& ev) override;
    
private:
    MenuBar m_menu_bar;
    // tool bar: new doc, open doc, save doc
    // draw instruments: create line, create rectangle, circle etc.
    std::vector<Document> m_documents;
    std::unique_ptr<Controller> controller;
};

}

int main()
{
    vge_gui::MainWindow window;
    vge_model::Document doc;
    vge_controller::Controller controller{window};
    while1(1);
    return 0;
}
