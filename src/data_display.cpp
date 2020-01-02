#include "../include/data_display.hpp"

customer_display_t::customer_display_t(
    wxBoxSizer* containing_sizer, customer_t* customer)
    : customer(customer), containing_sizer(containing_sizer) {
    
    Create(containing_sizer->GetContainingWindow(), wxNewId());

    auto sizer = new wxBoxSizer{wxVERTICAL};
    text = new wxStaticText{
        containing_sizer->GetContainingWindow(),
        wxNewId(), ""
    };
    update();
    sizer->Add(text, wxSizerFlags{1}.Expand());
    
    auto bottom_sizer = new wxBoxSizer{wxHORIZONTAL};
    auto button = new wxButton{
        containing_sizer->GetContainingWindow(),
        wxNewId(), "Edytuj"
    };
    button->Bind(wxEVT_BUTTON, on_edit);
    bottom_sizer->Add(button, wxSizerFlags{1}.Expand());

    button = new wxButton{
        containing_sizer->GetContainingWindow(),
        wxNewId(), "Usuń"
    };
    button->Bind(wxEVT_BUTTON, on_delete);
    bottom_sizer->Add(button, wxSizerFlags{1}.Expand());

    sizer->Add(bottom_sizer, wxSizerFlags{1}.Expand());

    SetSizerAndFit(sizer);
}

void customer_display_t::update() {
    text->SetLabel(customer->display_name());
}

employee_display_t::employee_display_t(
    wxBoxSizer* containing_sizer, employee_t* employee)
    : employee(employee), containing_sizer(containing_sizer) {
    
    Create(containing_sizer->GetContainingWindow(), wxNewId());

    auto sizer = new wxBoxSizer{wxVERTICAL};
    text = new wxStaticText{
        containing_sizer->GetContainingWindow(),
        wxNewId(), ""
    };
    update();
    sizer->Add(text, wxSizerFlags{1}.Expand());
    
    auto bottom_sizer = new wxBoxSizer{wxHORIZONTAL};
    auto button = new wxButton{
        containing_sizer->GetContainingWindow(),
        wxNewId(), "Edytuj"
    };
    button->Bind(wxEVT_BUTTON, on_edit);
    bottom_sizer->Add(button, wxSizerFlags{1}.Expand());

    button = new wxButton{
        containing_sizer->GetContainingWindow(),
        wxNewId(), "Usuń"
    };
    button->Bind(wxEVT_BUTTON, on_delete);
    bottom_sizer->Add(button, wxSizerFlags{1}.Expand());

    sizer->Add(bottom_sizer, wxSizerFlags{1}.Expand());

    SetSizerAndFit(sizer);
}

void employee_display_t::update() {
    text->SetLabel(employee->display_name());
}