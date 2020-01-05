#include "../include/data_store.hpp"
#include <string>
#include <algorithm>

void datastore_t::save(std::ostream& output) {
    for (const customer_t& customer : customers) {
        output << "BEGIN CUSTOMER\n";
        output << customer << '\n';
    }
    for (const employee_t& employee : employees) {
        output << "BEGIN EMPLOYEE\n";
        output << employee << '\n';
    }
}

void datastore_t::load(std::istream& input) {
    std::string current_line;
    while (input) {
        std::getline(input, current_line);
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

int datastore_t::get_max_customer_id() {
    int max = -1;
    for (const auto& customer : customers)
        max = std::max(customer.id, max);
    return max;
}

int datastore_t::get_max_employee_id() {
    int max = -1;
    for (const auto& employee : employees)
        max = std::max(employee.id, max);
    return max;
}

int datastore_t::get_max_appointment_id() {
    int max = -1;
    for (const auto& appointment : appointments)
        max = std::max(appointment.id, max);
    return max;
}

void datastore_t::add(customer_t customer) {
    customer.id = this->get_max_customer_id() + 1;
    customers.push_back(customer);
}

void datastore_t::add(employee_t employee) {
    employee.id = this->get_max_employee_id() + 1;
    employees.push_back(employee);
}

void datastore_t::add(appointment_t appointment) {
    appointment.id = this->get_max_appointment_id() + 1;
    appointments.push_back(appointment);
}

customer_t* datastore_t::get_customer(int id) {
    for (auto& customer : customers)
        if (customer.id == id) return &customer;
    return nullptr;
}

customer_t* datastore_t::get_customer(int id) {
    for (auto& customer : customers)
        if (customer.id == id) return &customer;
    return nullptr;
}

appointment_t* datastore_t::get_appointment(int id) {
    for (auto& appointment : appointments)
        if (appointment.id == id) return &appointment;
    return nullptr;
}