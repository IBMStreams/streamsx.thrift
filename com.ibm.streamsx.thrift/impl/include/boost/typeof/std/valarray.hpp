// Copyright (C) 2005 Arkadiy Vertleyb, Peder Holt.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_STD_valarray_hpp_INCLUDED
#define STREAMS_BOOST_TYPEOF_STD_valarray_hpp_INCLUDED

#include <valarray>
#include <streams_boost/typeof/typeof.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::valarray, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::slice)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::slice_array, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::gslice)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::gslice_array, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::mask_array, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::indirect_array, 1)

#endif//STREAMS_BOOST_TYPEOF_STD_valarray_hpp_INCLUDED
