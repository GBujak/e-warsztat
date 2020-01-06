#include "../include/data_button.hpp"

data_button::data_button(data_interface* data, wxWindow* parent) {
    this->data = data;
    Create(parent, wxNewId(), data->display_name());
}

data_interface* data_button::get_data() {
    return this->data;
}