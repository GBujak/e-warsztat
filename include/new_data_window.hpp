#pragma once

#include <wx/wx.h>
#include <functional>
#include <vector>
#include <unordered_map>
#include <string>
#include "data_classes.hpp"
#include "data_collector.hpp"
#include "globals.hpp"

#define CHOICE_NUMBER 2

typedef std::function<void(wxEvent&)> event_functor_t;

class new_data_window_t : public wxDialog {

    std::unordered_map<std::string, wxTextCtrl*> input_fields;
    event_functor_t on_type_selected;
    event_functor_t on_commit;

    const wxString choices[CHOICE_NUMBER] = {"Customer", "Employee"};
    customer_t customer;
    employee_t employee;

    data_collector_t collector;
    
    wxBoxSizer* main_sizer;
    wxChoice* choice_widget;
    public:
    new_data_window_t(wxWindow*);
};