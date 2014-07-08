// Copyright (C) 2005 Arkadiy Vertleyb, Peder Holt.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_STD_istream_hpp_INCLUDED
#define STREAMS_BOOST_TYPEOF_STD_istream_hpp_INCLUDED

#include <istream>
#include <streams_boost/typeof/typeof.hpp>
#include <streams_boost/typeof/std/string.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_istream, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_istream, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_iostream, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_iostream, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::istream)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::iostream)

#endif//STREAMS_BOOST_TYPEOF_STD_istream_hpp_INCLUDED
