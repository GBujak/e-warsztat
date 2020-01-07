#include "../include/edit_data_window.hpp"
#include "../include/display_list.hpp"

edit_window_t::edit_window_t(wxWindow* parent, data_interface* data) {
    this->data = data;
    Create(parent, wxNewId(), "Edytuj dane");

    main_sizer = new wxBoxSizer{wxVERTICAL};
    SetSizer(main_sizer);
    collector.set_sizer(main_sizer);

    this->on_commit = [this] (wxEvent& event) {
        if (!collector.collect()) return;
        g_display_list->display(0);
        this->Close(true);
    };

    customer_t* customer = dynamic_cast<customer_t*>(data);
    employee_t* employee = dynamic_cast<employee_t*>(data);
    appointment_t* appointment = dynamic_cast<appointment_t*>(data);

    if (customer)    add(collector, *customer);
    if (employee)    add(collector, *employee);
    if (appointment) add(collector, *appointment);

    auto button = new wxButton{this, wxNewId(), "Zatwierdz"};
    main_sizer->Add(button, wxSizerFlags(0).Expand());
    button->Bind(wxEVT_BUTTON, on_commit);

    SetSizerAndFit(main_sizer);
}