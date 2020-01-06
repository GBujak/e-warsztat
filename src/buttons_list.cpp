#include "../include/buttons_list.hpp"

button_list::button_list(wxWindow* parent) {
    Create(parent, wxNewId(), wxDefaultPosition, wxSize{400, 400});
    main_sizer = new wxBoxSizer{wxVERTICAL};
}

void button_list::add_button(data_interface* data) {
    auto button = new data_button{data, this};
    main_sizer->Add(button, wxSizerFlags(1).Expand());
}

void button_list::clear_all() {
    main_sizer->Clear(true);
}

void button_list::draw() {
    wxSize size = m_targetWindow->GetBestVirtualSize();
    m_win->SetVirtualSize( size );
    this->SetSizer(main_sizer);
    this->FitInside();
    this->SetScrollRate(5, 5);
}