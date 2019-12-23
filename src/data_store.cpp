#include "../include/data_store.hpp"

void datastore_t::save(std::ostream output) {
    for (const customer_t& customer : customers) {
        output << "BEGIN CUSTOMER\n";
        output << "END CUSTOMER\n";
    }
}

void datastore_t::load(std::istream input) {

}