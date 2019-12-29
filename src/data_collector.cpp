#include "../include/data_collector.hpp"

data_collector_t::data_collector_t(wxBoxSizer* sizer)
    : sizer(sizer) {}

void
data_collector_t::add(int* data, const char* label) {
    auto ctrl = new_text_ctrl(label);
    int_vec.push_back(
        std::pair<wxTextCtrl*, int*>{ctrl, data}
    );
}

void
data_collector_t::add(std::string* data, const char* label) {
    auto ctrl = new_text_ctrl(label);
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
    ctrl->SetLabel(label);
    sizer->Add(ctrl, wxSizerFlags{1}.Expand());
    return ctrl;
}

bool
data_collector_t::collect() {
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
    collector.add(&customer.id, "id");
    collector.add(&customer.personal.name.name, "name");
    collector.add(&customer.personal.name.surname, "surname");
    collector.add(&customer.personal.address.city, "city");
    collector.add(&customer.personal.address.country, "country");
    collector.add(&customer.personal.address.street, "street");
}

void add(data_collector_t& collector, employee_t& employee) {
    collector.add(&employee.id, "id");
    collector.add(&employee.salary, "salary");
    collector.add(&employee.personal.name.name, "name");
    collector.add(&employee.personal.name.surname, "surname");
    collector.add(&employee.personal.address.city, "city");
    collector.add(&employee.personal.address.country, "country");
    collector.add(&employee.personal.address.street, "street");
}