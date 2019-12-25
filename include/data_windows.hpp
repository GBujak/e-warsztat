#include <wx/wx.h>
#include "data_classes.hpp"

template <typename T>
class data_window_t : public wxWindow {
    T* data;
    public:
    data_window_t(T* data): data(data) {}
    T* get_data_ptr() { return data; }
};

data_window_t<customer_t>* make_data_window(wxWindow* parent, customer_t* customer) {
    auto window = new data_window_t<customer_t>{customer};
    window->Create(parent, wxNewId());
    return window;
}

data_window_t<customer_t>* make_data_window(wxWindow* parent, customer_t* customer) {
    auto window = new data_window_t<customer_t>{customer};
    window->Create(parent, wxNewId());
    return window;
}

