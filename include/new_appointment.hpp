#pragma once

#include <wx/wx.h>
#include <functional>
#include "data_classes.hpp"
#include "data_collector.hpp"

class new_appointment : public wxDialog {
    std::function<void(wxEvent&)> on_commit;
    wxRadioBox* radio;
    appointment_t appointment;
    data_collector_t collector;
    wxArrayString options;
    public:
    new_appointment(wxWindow*, customer_t*);
};