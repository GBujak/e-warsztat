#include "../include/new_appointment.hpp"
#include "../include/data_classes.hpp"
#include "../include/globals.hpp"

new_appointment::new_appointment(
    wxWindow* parent, customer_t* customer) {
    Create(parent, wxNewId(), "Nowa wizyta");

    auto sizer = new wxBoxSizer{wxVERTICAL};
    SetSizer(sizer);

    collector.set_sizer(sizer);
    add(collector, appointment);

    auto employees = g_datastore.get_employees();
    for (auto& empl : employees)
        options.Add(empl.display_name());
    
    radio = new wxRadioBox{
        this, wxNewId(), "Pracownik:",
        wxDefaultPosition, wxDefaultSize,
        options, 3
    };
    sizer->Add(radio, wxSizerFlags(1).Expand());

    auto commit = new wxButton{this, wxNewId(), "Dodaj"};
    sizer->Add(commit, wxSizerFlags(0).Expand());

    on_commit = [this, customer] (wxEvent& event) {
        if (!collector.collect()) return;
        auto empl_id = radio->GetSelection();
        if (empl_id == wxNOT_FOUND) return;
        appointment.employee_id = 
            g_datastore.get_employees()[empl_id].id;
        appointment.customer_id = customer->id;
        g_datastore.add(appointment);
        this->Close(true);
    };

    commit->Bind(wxEVT_BUTTON, on_commit);

    SetSizerAndFit(sizer);
}