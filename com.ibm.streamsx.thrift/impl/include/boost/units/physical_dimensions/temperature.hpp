// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_TEMPERATURE_BASE_DIMENSION_HPP
#define STREAMS_BOOST_UNITS_TEMPERATURE_BASE_DIMENSION_HPP

#include <streams_boost/units/config.hpp>
#include <streams_boost/units/base_dimension.hpp>

namespace streams_boost {

namespace units { 

/// base dimension of temperature
struct temperature_base_dimension : 
    streams_boost::units::base_dimension<temperature_base_dimension,-5> 
{ };               

} // namespace units

} // namespace streams_boost

#if STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::units::temperature_base_dimension)

#endif

namespace streams_boost {

namespace units {

/// dimension of temperature (Theta)
typedef temperature_base_dimension::dimension_type temperature_dimension;

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_TEMPERATURE_BASE_DIMENSION_HPP
