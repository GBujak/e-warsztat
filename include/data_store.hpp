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
    std::vector<appointment_t> appointments;

    int get_max_customer_id();
    int get_max_employee_id();
    int get_max_appointment_id();

    public:
    customer_t* get_customer(int);
    employee_t* get_employee(int);
    appointment_t* get_appointment(int);

    void add(employee_t);
    void add(customer_t);
    void add(appointment_t);

    void save(std::ostream& output);
    void load(std::istream& input);
};

#endif