#include "../include/data_classes.hpp"
#include "../include/globals.hpp"

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

std::string appointment_t::to_str() {
    std::stringstream stream;

    customer_t* customer = g_datastore.get_customer(customer_id);
    employee_t* employee = g_datastore.get_employee(employee_id);

    stream << "Wizyta o id " << this->id << '\n';
    stream << "Klient:\n"
        << ((customer) ? customer->to_str() 
                       : "Nie znaleziono klienta") << '\n';
    stream << "Pracownik:\n"
        << ((employee) ? employee->to_str() 
                       : "Nie znaleziono pracownika") << '\n';
    stream << "Opis:\n" << this->description;
    return stream.str();
}

std::string appointment_t::display_name() {
    return std::to_string(id) + ": " + date;
}