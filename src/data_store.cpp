#include "../include/data_store.hpp"
#include <string>

void datastore_t::save(std::ostream& output) {
    for (const customer_t& customer : customers) {
        output << "BEGIN CUSTOMER\n";
        output << customer;
    }
    for (const employee_t employee : employees) {
        output << "BEGIN EMPLOYEE\n";
        output << employee;
    }
}

void datastore_t::load(std::istream& input) {
    std::string current_line;
    while (input) {
        std::getline(input, current_line);
        if (current_line == "BEGIN CUSTOMER\n") {
            customer_t new_customer;
            input >> new_customer;
            customers.push_back(new_customer);
        } else if (current_line == "BEGIN EMPLOYEE\n") {
            employee_t new_employee;
            input >> new_employee;
            employees.push_back(new_employee);
        }
    }
}