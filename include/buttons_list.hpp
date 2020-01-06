#pragma once

#include <wx/wx.h>
#include "data_classes.hpp"
#include "data_button.hpp"

class button_list : public wxScrolledWindow {
    wxBoxSizer* main_sizer;

    public:
    button_list(wxWindow*);
    void add_button(data_interface*);
    void clear_all();
    void draw();
};