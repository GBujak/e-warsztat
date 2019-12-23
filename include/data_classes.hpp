#include <string>

struct adres_t {
    std::string ulica, miasto, kraj;
};

struct personal_t {
    std::string name;
    adres_t address;
};

struct customer_t {
    int id;
    personal_t personal;
};

struct employee_t {
    int id;
    personal_t personal;
    unsigned salary;
};