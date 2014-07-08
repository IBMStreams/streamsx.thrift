// Copyright (C) 2005 Arkadiy Vertleyb, Peder Holt.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_STD_memory_hpp_INCLUDED
#define STREAMS_BOOST_TYPEOF_STD_memory_hpp_INCLUDED

#include <memory>
#include <streams_boost/typeof/typeof.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::allocator, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::raw_storage_iterator, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::auto_ptr, 1)

#endif//STREAMS_BOOST_TYPEOF_STD_memory_hpp_INCLUDED
