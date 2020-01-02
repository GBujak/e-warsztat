#pragma once
#ifndef GLOBALS_HPP
#define GLOBALS_HPP

typedef std::function<void(wxEvent&)> event_functor_t;

#include "data_store.hpp"
extern datastore_t g_datastore;

#endif