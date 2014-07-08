// Copyright (C) 2005 Arkadiy Vertleyb, Peder Holt.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_STD_map_hpp_INCLUDED
#define STREAMS_BOOST_TYPEOF_STD_map_hpp_INCLUDED

#include <map>
#include <streams_boost/typeof/typeof.hpp>
#include <streams_boost/typeof/std/memory.hpp>
#include <streams_boost/typeof/std/functional.hpp>
#include <streams_boost/typeof/std/utility.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::map, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::map, 3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::map, 4)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::multimap, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::multimap, 3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::multimap, 4)

#endif//STREAMS_BOOST_TYPEOF_STD_map_hpp_INCLUDED
