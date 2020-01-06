#pragma once

#include <wx/wx.h>
#include <map>
#include <string>
#include "data_classes.hpp"
#include "buttons_list.hpp"
#include "globals.hpp"

#include <functional>
typedef std::function<void(wxEvent&)> event_functor_t;

class display_list_t : public wxWindow {
    wxBoxSizer* main_sizer;
    wxBoxSizer* top_sizer;
    std::map<std::string, wxButton*> buttons;

    button_list* butlist;

    event_functor_t on_category;
    event_functor_t on_detail;

    void clear_items();

    public:
    display_list_t(wxWindow*);
    void display(int type);
};