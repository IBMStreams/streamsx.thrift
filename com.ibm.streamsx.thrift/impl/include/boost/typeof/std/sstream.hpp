// Copyright (C) 2005 Arkadiy Vertleyb, Peder Holt.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_STD_sstream_hpp_INCLUDED
#define STREAMS_BOOST_TYPEOF_STD_sstream_hpp_INCLUDED

#include <sstream>
#include <streams_boost/typeof/typeof.hpp>
#include <streams_boost/typeof/std/string.hpp>
#include <streams_boost/typeof/std/memory.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_stringbuf, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_stringbuf, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_stringbuf, 3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_istringstream, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_istringstream, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_istringstream, 3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_ostringstream, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_ostringstream, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_ostringstream, 3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_stringstream, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_stringstream, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_stringstream, 3)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::stringbuf)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::istringstream)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::ostringstream)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::stringstream)

#endif//STREAMS_BOOST_TYPEOF_STD_sstream_hpp_INCLUDED
