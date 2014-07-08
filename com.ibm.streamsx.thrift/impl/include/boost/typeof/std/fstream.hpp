// Copyright (C) 2005 Arkadiy Vertleyb, Peder Holt.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_STD_fstream_hpp_INCLUDED
#define STREAMS_BOOST_TYPEOF_STD_fstream_hpp_INCLUDED

#include <fstream>
#include <streams_boost/typeof/typeof.hpp>
#include <streams_boost/typeof/std/string.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_filebuf, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_filebuf, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_ifstream, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_ifstream, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_ofstream, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_ofstream, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_fstream, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::basic_fstream, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::filebuf)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::ifstream)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::ofstream)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::fstream)

#endif//STREAMS_BOOST_TYPEOF_STD_fstream_hpp_INCLUDED
