#pragma once

#include <wx/wx.h>
#include "data_classes.hpp"
#include <string>
#include <functional>

typedef std::function<void(wxEvent&)> event_functor;

class data_display_t : public wxWindow {
    public:
    virtual void update() = 0;
};

class customer_display_t : public data_display_t {
    wxStaticText* text;
    wxBoxSizer* containing_sizer;
    customer_t* customer;
    event_functor on_delete;
    event_functor on_edit;
    public:
    void update();
    customer_display_t(wxBoxSizer*, customer_t*);
};

class employee_display_t : public data_display_t {
    wxStaticText* text;
    wxBoxSizer* containing_sizer;
    employee_t* employee;
    event_functor on_delete;
    event_functor on_edit;
    public:
    void update();
    employee_display_t(wxBoxSizer*, employee_t*);
};