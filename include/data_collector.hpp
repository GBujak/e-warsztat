#include <wx/wx.h>
#include <string>
#include <tuple>
#include <vector>
#include "data_classes.hpp"

/**
 * Klasa pomocnicza. Dostaje w konstruktorze sizer,
 * do którego dodaje pola wxTextCrtl, z których
 * zczytuje potem dane przy wywołaniu collect(),
 * zapisując je do odpowiednich miejsc, do których
 * wskaźniki dostanie przy wowołaniach funkcji add()
 */

class data_collector_t {
    wxBoxSizer* sizer;
    std::vector<
        std::pair<wxTextCtrl*, std::string*>
    > str_vec;
    std::vector<
        std::pair<wxTextCtrl*, int*>
    > int_vec;
    wxTextCtrl* new_text_ctrl(const char*);
    public:
    data_collector_t(wxBoxSizer*);
    void add(std::string*, const char*);
    void add(int*, const char*);
    bool collect();
};

void add(data_collector_t, customer_t);
void add(data_collector_t, employee_t);