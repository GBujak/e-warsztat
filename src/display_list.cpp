#include "../include/display_list.hpp"

display_list_t::display_list_t(wxWindow* parent) {
    Create(parent, wxNewId(), wxDefaultPosition, wxSize{500, 500});

    on_category = [this] (wxEvent& event) {
        auto button = (wxButton*) event.GetEventObject();
        for (auto& but : buttons) but.second->Enable();
        button->Disable();

        clear_items();
        if (button == buttons["customers"])    display(0);
        if (button == buttons["employees"])    display(1);
        if (button == buttons["appointments"]) display(2);      
    };

    main_sizer = new wxBoxSizer{wxVERTICAL};
    top_sizer = new wxBoxSizer{wxHORIZONTAL};

    buttons["customers"] = new wxButton{this, wxNewId(), "Klienci"};
    buttons["employees"] = new wxButton{this, wxNewId(), "Pracownicy"};
    buttons["appointments"] = new wxButton{this, wxNewId(), "Wizyty"};
    for (auto& button : buttons) {
        button.second->Bind(wxEVT_BUTTON, on_category);
        top_sizer->Add(button.second, wxSizerFlags(1).Expand());
    }

    butlist = new button_list{this};
    butlist->draw();

    main_sizer->Add(top_sizer, wxSizerFlags(0).Expand());
    main_sizer->Add(butlist, wxSizerFlags(1).Expand());

    SetSizerAndFit(main_sizer);
}

void display_list_t::clear_items() {
    butlist->clear_all();
}

void display_list_t::display(int type) {
    if (type == 0) buttons["customers"]->Disable();

    clear_items();

    if (type == 0) for (auto& cust : g_datastore.get_customers())
        butlist->add_button(&cust);
    if (type == 1) for (auto& empl : g_datastore.get_employees())
        butlist->add_button(&empl);
    if (type == 2) for (auto& appt : g_datastore.get_appointments())
        butlist->add_button(&appt);
    
    butlist->draw();
}