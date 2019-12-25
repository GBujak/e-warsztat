#include <wx/wx.h>
#include <functional>
#include <vector>
#include <unordered_map>
#include "data_classes.hpp"

typedef std::function<void(wxEvent&)> event_functor_t;

constexpr int choice_num = 2;
const std::vector<wxString> common_fields {
    "Street", "City", "Country",
    "Name", "Surname"
};

class new_data_window_t : public wxFrame {

    std::unordered_map<wxString, wxTextCtrl*> input_fields;
    event_functor_t on_type_selected = [this] (wxEvent& event) {
        int selection = choice_widget->GetSelection();
        choice_widget->Disable();
        for (auto label : common_fields) {
            input_fields[label] = new wxTextCtrl {this, wxNewId()};
            main_sizer->Add(input_fields[label], wxSizerFlags{1});
        }
        if (selection == 1) {
            input_fields["Salary"] = new wxTextCtrl {this, wxNewId()};
            main_sizer->Add(input_fields["Salary"], wxSizerFlags{1});
        } // <-- TU KONIEC
    };

    const wxString choices[choice_num] = {"Customer", "Employee"};
    wxBoxSizer* main_sizer;
    wxChoice* choice_widget;
    public:
    new_data_window_t() {
        this->Create(nullptr, wxNewId(), "Create new data");
        main_sizer = new wxBoxSizer(wxVERTICAL);
        choice_widget = new wxChoice {
            this, wxNewId(),
            wxDefaultPosition, wxDefaultSize,
            2, choices
        };

        main_sizer->Add(choice_widget, wxSizerFlags{1});

        this->Bind(wxEVT_CHOICE, on_type_selected);

        SetSizerAndFit(main_sizer);
    }
};