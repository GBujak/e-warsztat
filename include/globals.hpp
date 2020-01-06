#pragma once
#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <functional>
#include "data_store.hpp"

typedef std::function<void(wxEvent&)> event_functor_t;

extern datastore_t g_datastore;

#endif