#include "../include/display_list.hpp"

display_list_t::display_list_t(wxWindow* parent) {

    on_category = [this] (wxEvent& event) {
        auto button = (wxButton*) event.GetEventObject();
        for (auto& but : buttons) but.second->Enable();
        button->Disable();

        
    };

    main_sizer = new wxBoxSizer{wxVERTICAL};
    top_sizer = new wxBoxSizer{wxHORIZONTAL};

    buttons["customers"] = new wxButton{this, wxNewId(), "Klienci"};
    buttons["employees"] = new wxButton{this, wxNewId(), "Pracownicy"};
    buttons["appointments"] = new wxButton{this, wxNewId(), "Wizyty"};
    for (auto& button : buttons) button.second->Bind(wxEVT_BUTTON, on_category);

    main_sizer->Add(top_sizer, wxSizerFlags(1).Expand());

    Create(parent, wxNewId());
}