#include "../include/data_button.hpp"

data_button::data_button(data_interface* data, wxWindow* parent) {
    this->data = data;
    Create(parent, wxNewId(), data->display_name());
    Bind(wxEVT_BUTTON, [this] (wxEvent& event) {
        g_detail_view->set_data(this->data);
    });
}

data_interface* data_button::get_data() {
    return this->data;
}