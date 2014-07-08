// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_TEMPERATURE_FAHRENHEIT_HPP
#define STREAMS_BOOST_UNITS_TEMPERATURE_FAHRENHEIT_HPP

#include <string>

#include <streams_boost/units/absolute.hpp>
#include <streams_boost/units/io.hpp>
#include <streams_boost/units/make_system.hpp>
#include <streams_boost/units/static_constant.hpp>
#include <streams_boost/units/base_units/temperature/fahrenheit.hpp>

namespace streams_boost {

namespace units {

namespace fahrenheit {

typedef make_system<streams_boost::units::temperature::fahrenheit_base_unit>::type system;

typedef unit<temperature_dimension,system>   temperature;

STREAMS_BOOST_UNITS_STATIC_CONSTANT(degree,temperature);
STREAMS_BOOST_UNITS_STATIC_CONSTANT(degrees,temperature);

} // namespace fahrenheit

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_TEMPERATURE_FAHRENHEIT_HPP
