#include "../include/data_store.hpp"
#include <string>

void datastore_t::save(std::ostream& output) {
    for (const customer_t& customer : customers) {
        output << "BEGIN CUSTOMER\n";
        output << customer << '\n';
    }
    for (const employee_t employee : employees) {
        output << "BEGIN EMPLOYEE\n";
        output << employee << '\n';
    }
}

void datastore_t::load(std::istream& input) {
    std::string current_line;
    while (input) {
        std::getline(input, current_line);
        std::cout << "Got line: |" << current_line << "| END" << std::endl;
        if (current_line == "BEGIN CUSTOMER") {
            customer_t new_customer;
            input >> new_customer;
            customers.push_back(new_customer);
        } else if (current_line == "BEGIN EMPLOYEE") {
            employee_t new_employee;
            input >> new_employee;
            employees.push_back(new_employee);
        }
    }
}

void datastore_t::add(customer_t customer) {
    customers.push_back(customer);
}

void datastore_t::add(employee_t employee) {
    employees.push_back(employee);
}