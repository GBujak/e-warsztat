#include "../include/data_display.hpp"

customer_display_t::customer_display_t(wxBoxSizer* sizer, customer_t* customer)
    : customer(customer) {
    
    Create(sizer->GetContainingWindow(), wxNewId());

}

employee_display_t::employee_display_t(wxBoxSizer* sizer, employee_t* employee)
    : employee(employee) {

    Create(sizer->GetContainingWindow(), wxNewId());
    auto inner_sizer = new wxBoxSizer{wxVERTICAL};
    sizer->Add(new wxStaticText{
        GetParent(), wxNewId(), std::to_string(employee->id)},
        wxSizerFlags{1}.Expand());
    sizer->Add(new wxStaticText{
        GetParent(), wxNewId(), employee->personal.name.name},
        wxSizerFlags{1}.Expand());
    sizer->Add(new wxStaticText{
        GetParent(), wxNewId(), employee->personal.name.surname},
        wxSizerFlags{1}.Expand());
    sizer->Add(new wxStaticText{
        GetParent(), wxNewId(), employee->personal.address.country},
        wxSizerFlags{1}.Expand());
    sizer->Add(new wxStaticText{
        GetParent(), wxNewId(), employee->personal.address.city},
        wxSizerFlags{1}.Expand());
    sizer->Add(new wxStaticText{
        GetParent(), wxNewId(), employee->personal.address.street},
        wxSizerFlags{1}.Expand());
    sizer->Add(new wxStaticText{
        GetParent(), wxNewId(), "Zarobki: " + std::to_string(employee->salary)},
        wxSizerFlags{1}.Expand());
    
    auto bottom_sizer = new wxBoxSizer{wxHORIZONTAL};
    bottom_sizer->Add
}

void customer_display_t::display() {
    
}