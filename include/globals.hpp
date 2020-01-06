#pragma once

#include <functional>
#include "data_store.hpp"

class display_list_t;
class detail_view;

typedef std::function<void(wxEvent&)> event_functor_t;

extern datastore_t g_datastore;
extern display_list_t* g_display_list;
extern detail_view* g_detail_view;
