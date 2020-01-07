#include "../include/detail_view.hpp"
#include "../include/display_list.hpp"
#include "../include/new_appointment.hpp"

detail_view::detail_view(wxWindow* parent) {
    this->data = nullptr;
    Create(parent, wxNewId());

    this->on_edit = [this] (wxEvent& event) {
        auto edit_window = new edit_window_t{nullptr, this->data};
        edit_window->ShowModal();
        g_display_list->display(0);
    };

    this->on_appointment = [this] (wxEvent& event) {
        auto appointment = new new_appointment{this, dynamic_cast<customer_t*>(this->data)};
        appointment->ShowModal();
    };

    this->on_delete = [this] (wxEvent& event) {
        if (this->data == nullptr) {
            std::cout << "deleting nullptr" << std::endl;
            return;
        }
        g_datastore.delete_data(this->data);
        g_display_list->display(0);
    };

    main_sizer = new wxBoxSizer{wxVERTICAL};
    main_sizer->Add(
        new wxStaticText{
            this, wxNewId(), "Widok szczegolowy"
        },
        wxSizerFlags(0).Expand()
    );

    this->text_widget = new wxStaticText{this, wxNewId(), "..."};
    main_sizer->Add(this->text_widget, wxSizerFlags(1).Expand());

    this->edit_button = new wxButton{this, wxNewId(), "Edytuj"};
    edit_button->Bind(wxEVT_BUTTON, on_edit);

    this->appointment_button = new wxButton{this, wxNewId(), "Stworz wizyte"};
    appointment_button->Bind(wxEVT_BUTTON, on_appointment);

    this->delete_button = new wxButton{this, wxNewId(), "Usun"};
    delete_button->Bind(wxEVT_BUTTON, on_delete);
    this->delete_button->SetBackgroundColour(wxColor{255, 200, 200});

    main_sizer->Add(edit_button, wxSizerFlags(0).Expand());
    main_sizer->Add(appointment_button, wxSizerFlags(0).Expand());
    main_sizer->Add(delete_button, wxSizerFlags(0).Expand());

    for (auto but : {edit_button, appointment_button, delete_button})
        but->Disable();

    SetSizerAndFit(main_sizer);
}

void detail_view::set_data(data_interface* data) {
    this->data = data;
    std::cout << data->to_str() << std::endl;
    show_data();
}

void detail_view::show_data() {
    if (this->data == nullptr) {
        std::cout << "showing data for nullptr" << std::endl;
        return;
    }

    this->text_widget->SetLabel(data->to_str());

    appointment_button->Disable();
    customer_t* ptr = dynamic_cast<customer_t*>(this->data);
    if (ptr != nullptr) appointment_button->Enable();

    edit_button->Enable();
    delete_button->Enable();
}