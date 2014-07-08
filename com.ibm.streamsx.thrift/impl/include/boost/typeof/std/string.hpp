// Copyright (C) 2005 Arkadiy Vertleyb, Peder Holt.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_STD_string_hpp_INCLUDED
#define STREAMS_BOOST_TYPEOF_STD_string_hpp_INCLUDED

#include <string>
#include <streams_boost/typeof/typeof.hpp>
#include <streams_boost/typeof/std/memory.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::char_traits, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_string, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_string, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_string, 3)

#ifndef __BORLANDC__
//Borland chokes on this "double definition" of string
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::string)
#endif

#endif//STREAMS_BOOST_TYPEOF_STD_string_hpp_INCLUDED
