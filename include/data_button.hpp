#pragma once

#include "data_classes.hpp"
#include "globals.hpp"
#include <wx/wx.h>

class data_button : public wxButton {
    data_interface* data;
    public:
    data_button(data_interface*, wxWindow*);
    data_interface* get_data();
};