#include "../include/data_classes.hpp"

std::string customer_t::display_name() {
    return personal.name.name + ' ' + personal.name.surname;
}

std::string employee_t::display_name() {
    return personal.name.name + ' ' + personal.name.surname;
}

std::string customer_t::to_str() {
    std::stringstream stream;
    
    stream << "Id: " << id << '\n';
    stream << "Imię: " << personal.name.name << '\n';
    stream << "Nazwisko: " << personal.name.name << '\n';
    stream << "Ulica: " << personal.address.street << '\n';
    stream << "Miasto: " << personal.address.city << '\n';
    stream << "Kraj: " << personal.address.country << '\n';

    return stream.str();
}

std::string employee_t::to_str() {
    std::stringstream stream;
    
    stream << "Id: " << id << '\n';
    stream << "Pensja: " << salary << '\n';
    stream << "Imię: " << personal.name.name << '\n';
    stream << "Nazwisko: " << personal.name.name << '\n';
    stream << "Ulica: " << personal.address.street << '\n';
    stream << "Miasto: " << personal.address.city << '\n';
    stream << "Kraj: " << personal.address.country << '\n';

    return stream.str();
}