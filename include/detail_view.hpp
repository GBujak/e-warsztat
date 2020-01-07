#pragma once

#include "globals.hpp"
#include "data_classes.hpp"
#include "edit_data_window.hpp"
#include <wx/wx.h>

class detail_view : public wxWindow {
    event_functor_t on_edit;
    event_functor_t on_appointment;
    event_functor_t on_delete;

    wxBoxSizer* main_sizer;
    data_interface* data;
    wxStaticText* text_widget;

    wxButton* appointment_button;
    wxButton* edit_button;
    wxButton* delete_button;

    public:
    detail_view(wxWindow*);
    void set_data(data_interface*);
    void show_data();
};  
