#include "../include/data_store.hpp"
#include <string>
#include <algorithm>
#include <iostream>

void datastore_t::save(std::ostream& output) {
    for (const customer_t& customer : customers) {
        output << "BEGIN CUSTOMER\n";
        output << customer << '\n';
    }
    for (const employee_t& employee : employees) {
        output << "BEGIN EMPLOYEE\n";
        output << employee << '\n';
    }
    for (const appointment_t& app : appointments) {
        output << "BEGIN APPOINTMENT\n";
        output << app << '\n';
    }
}

void datastore_t::load(std::istream& input) {
    customers.clear();
    employees.clear();
    appointments.clear();

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
        } else if (current_line == "BEGIN APPOINTMENT") {
            appointment_t app;
            input >> app;
            appointments.push_back(app);
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

employee_t* datastore_t::get_employee(int id) {
    for (auto& employee : employees)
        if (employee.id == id) return &employee;
    return nullptr;
}

appointment_t* datastore_t::get_appointment(int id) {
    for (auto& appointment : appointments)
        if (appointment.id == id) return &appointment;
    return nullptr;
}

void datastore_t::delete_data(data_interface* data) {
    customer_t* customer = dynamic_cast<customer_t*>(data);
    employee_t* employee = dynamic_cast<employee_t*>(data);
    appointment_t* appointment = dynamic_cast<appointment_t*>(data);

    if (customer) {
        for (auto iter = customers.begin(); iter != customers.end(); iter++) {
            if (customer == &(*iter)) {
                customers.erase(iter);
                return;
            }
        }
    }

    if (employee) {
        for (auto iter = employees.begin(); iter != employees.end(); iter++) {
            if (employee == &(*iter)) {
                employees.erase(iter);
                return;
            }
        }
    }

    if (appointment) {
        for (auto iter = appointments.begin(); iter != appointments.end(); iter++) {
            if (appointment == &(*iter)) {
                appointments.erase(iter);
                return;
            }
        }
    }

    std::cout << "Nie usunięto elementu!!!" << std::endl;
}

std::vector<customer_t>& datastore_t::get_customers() {
    return customers;
};

std::vector<employee_t>& datastore_t::get_employees() {
    return employees;
};

std::vector<appointment_t>& datastore_t::get_appointments() {
    return appointments;
};