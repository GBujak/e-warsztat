#include "../include/data_collector.hpp"
#include <cassert>
#include <string>

void
data_collector_t::set_sizer(wxBoxSizer* sizer) {
    this->sizer = sizer;
}

void
data_collector_t::add(int* data, const char* label) {
    assert(this->sizer != nullptr);
    auto ctrl = new_text_ctrl(label);
    ctrl->SetValue(std::to_string(*data));
    int_vec.push_back(
        std::pair<wxTextCtrl*, int*>{ctrl, data}
    );
}

void
data_collector_t::add(std::string* data, const char* label) {
    assert(this->sizer != nullptr);
    auto ctrl = new_text_ctrl(label);
    ctrl->SetValue(*data);
    str_vec.push_back(
        std::pair<wxTextCtrl*, std::string*>{ctrl, data}
    );
}

wxTextCtrl* 
data_collector_t::new_text_ctrl(const char* label) {
    auto ctrl = new wxTextCtrl {
        sizer->GetContainingWindow(),
        wxNewId()
    };
    sizer->Add(
        new wxStaticText{sizer->GetContainingWindow(), wxNewId(), label}
    );
    sizer->Add(ctrl, wxSizerFlags{1}.Expand());
    return ctrl;
}

bool
data_collector_t::collect() {
    assert(this->sizer != nullptr);
    bool ret = true;
    for (auto& i : str_vec) {
        *(i.second) = i.first->GetValue().ToStdString();
    }
    for (auto& i : int_vec) {
        int* dest = i.second;
        long tmp;
        if (!i.first->GetValue().ToLong(&tmp))
            ret = false;
        *dest = (int) tmp;
    }
    return ret;
}

void add(data_collector_t& collector, customer_t& customer) {
    collector.add(&customer.personal.name.name, "Imię");
    collector.add(&customer.personal.name.surname, "Nazwisko");
    collector.add(&customer.personal.address.country, "Kraj");
    collector.add(&customer.personal.address.city, "Miasto");
    collector.add(&customer.personal.address.street, "Ulica");
}

void add(data_collector_t& collector, employee_t& employee) {
    collector.add(&employee.salary, "Zarobki");
    collector.add(&employee.personal.name.name, "Imię");
    collector.add(&employee.personal.name.surname, "Nazwisko");
    collector.add(&employee.personal.address.country, "Kraj");
    collector.add(&employee.personal.address.city, "Miasto");
    collector.add(&employee.personal.address.street, "Ulica");
}

void add(data_collector_t& collector, appointment_t& appointment) {
    collector.add(&appointment.date, "Data");
    collector.add(&appointment.description, "Opis");
}