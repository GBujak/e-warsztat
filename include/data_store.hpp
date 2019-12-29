#pragma once

#ifndef DATA_STORE_HPP
#define DATA_STORE_HPP

#include <vector>
#include <iostream>
#include <wx/wx.h>

#include "data_classes.hpp"

class datastore_t {
    std::vector<customer_t> customers;
    std::vector<employee_t> employees;

    public:
    void add(employee_t);
    void add(customer_t);
    void save(std::ostream& output);
    void load(std::istream& input);
};

#endif