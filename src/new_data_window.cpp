#include "../include/new_data_window.hpp"
#include "../include/frame.hpp"
#include "../include/app.hpp"
#include "../include/data_store.hpp"
#include "../include/globals.hpp"

new_data_window_t::new_data_window_t(wxWindow* parent) {
    this->Create(parent, wxNewId(), "Add new data");

    on_type_selected = [this] (wxEvent& event) {
        int selection = choice_widget->GetSelection();
        choice_widget->Disable();

        switch (selection) {
            case 0:
                add(collector, customer);
                break;
            case 1:
                add(collector, employee);
                break;
        }

        auto commit_button = new wxButton {this, wxNewId(), "commit"};
        main_sizer->Add(commit_button, wxSizerFlags{1}.Expand());

        SetSizerAndFit(main_sizer);

        this->Bind(wxEVT_BUTTON, this->on_commit);
    };

    on_commit = [this] (wxEvent& event) {
        if (!collector.collect()) return;
        int selection = choice_widget->GetSelection();
        switch (selection) {
            case 0:
                g_datastore.add(customer);
                break;
            case 1:
                g_datastore.add(employee);
                break;
        }
        this->Close(true);
    };

    main_sizer = new wxBoxSizer {wxVERTICAL};
    collector.set_sizer(main_sizer);
    choice_widget = new wxChoice {
                    this, wxNewId(),
                    wxDefaultPosition, wxDefaultSize,
                    CHOICE_NUMBER, this->choices };
    main_sizer->Add(choice_widget, wxSizerFlags{1});
    this->Bind(wxEVT_CHOICE, on_type_selected);

    SetSizerAndFit(main_sizer);
}

