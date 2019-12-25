#include <string>

struct address_t {
    std::string street, city, country;
};

inline std::ostream& operator<<(std::ostream& stream, const address_t& address) {
    stream << address.street  << '\n'
           << address.city    << '\n'
           << address.country << '\n';
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
    stream << name.name    << '\n'
           << name.surname << '\n';
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
    stream << personal.name    << '\n'
           << personal.address << '\n';
    return stream;
}

inline std::istream& operator>>(std::istream& stream, personal_t& personal) {
    stream >> personal.name
           >> personal.address;
    return stream;
}

struct customer_t {
    unsigned id;
    personal_t personal;
};

inline std::ostream& operator<<(std::ostream& stream, const customer_t& customer) {
    stream << customer.id       << '\n'
           << customer.personal << '\n';
    return stream;
}

inline std::istream& operator>>(std::istream& stream, customer_t& customer) {
    stream >> customer.id
           >> customer.personal;
    return stream;
}

struct employee_t {
    unsigned id;
    personal_t personal;
    unsigned salary;
};

inline std::ostream& operator<<(std::ostream& stream, const employee_t& employee) {
    stream << employee.id       << '\n'
           << employee.personal << '\n'
           << employee.salary   << '\n';
    return stream;
}

inline std::istream& operator>>(std::istream& stream, employee_t& employee) {
    stream >> employee.id
           >> employee.personal
           >> employee.salary;
    return stream;
}