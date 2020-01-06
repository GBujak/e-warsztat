#pragma once

#include <string>
#include <sstream>

struct data_interface {
    virtual std::string to_str() = 0;
    virtual std::string display_name() = 0;
};

struct address_t {
    std::string street, city, country;
};

inline std::ostream& operator<<(std::ostream& stream, const address_t& address) {
    stream << address.street  << ' '
           << address.city    << ' '
           << address.country;
    return stream;
}

inline std::istream& operator>>(std::istream& stream, address_t& address) {
    stream >> address.street
           >> address.city
           >> address.country;
    return stream;
}

struct name_t {
    std::string name, surname;
};

inline std::ostream& operator<<(std::ostream& stream, const name_t& name) {
    stream << name.name    << ' '
           << name.surname;
    return stream;
}

inline std::istream& operator>>(std::istream& stream, name_t& name) {
    stream >> name.name
           >> name.surname;
    return stream;
}

struct personal_t {
    name_t name;
    address_t address;
};

inline std::ostream& operator<<(std::ostream& stream, const personal_t& personal) {
    stream << personal.name    << ' '
           << personal.address;
    return stream;
}

inline std::istream& operator>>(std::istream& stream, personal_t& personal) {
    stream >> personal.name
           >> personal.address;
    return stream;
}

struct customer_t : public data_interface{
    int id = 0;
    personal_t personal;

    std::string display_name();
    std::string to_str();
};

inline std::ostream& operator<<(std::ostream& stream, const customer_t& customer) {
    stream << customer.id       << ' '
           << customer.personal;
    return stream;
}

inline std::istream& operator>>(std::istream& stream, customer_t& customer) {
    stream >> customer.id
           >> customer.personal;
    return stream;
}

struct employee_t : public data_interface {
    int id = 0;
    personal_t personal;
    int salary = 0;

    std::string display_name();
    std::string to_str();
};

inline std::ostream& operator<<(std::ostream& stream, const employee_t& employee) {
    stream << employee.id       << ' '
           << employee.personal << ' '
           << employee.salary;
    return stream;
}

inline std::istream& operator>>(std::istream& stream, employee_t& employee) {
    stream >> employee.id
           >> employee.personal
           >> employee.salary;
    return stream;
}

struct appointment_t : public data_interface {
    int id;
    int customer_id, employee_id;

    std::string date;
    std::string description;

    std::string to_str();
    std::string display_name();
};