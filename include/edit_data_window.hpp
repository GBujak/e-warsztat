#pragma once

#include <wx/wx.h>
#include "globals.hpp"
#include "data_classes.hpp"
#include "data_collector.hpp"

class edit_window_t : public wxDialog {
    event_functor_t on_commit;
    data_interface* data;
    wxBoxSizer* main_sizer;
    data_collector_t collector;

    public:
    edit_window_t(wxWindow*, data_interface*);
};