#include <wx/wx.h>
#include "data_classes.hpp"
#include <string>
#include <functional>

typedef std::function<void(wxEvent&)> event_functor;

class data_display_t : public wxWindow {
    public:
    virtual void display() = 0;
    virtual ~data_display_t();
};

class customer_display_t : public data_display_t {
    customer_t* customer;
    event_functor on_delete;
    event_functor on_edit;
    public:
    void display();
    customer_display_t(wxBoxSizer*, customer_t*);
};

class employee_display_t : public data_display_t {
    employee_t* employee;
    event_functor on_delete;
    event_functor on_edit;
    public:
    void display();
    employee_display_t(wxBoxSizer*, employee_t*);
};