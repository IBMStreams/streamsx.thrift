// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNIT_SYSTEMS_ASTRONOMICAL_LIGHT_HOUR_HPP_INCLUDED
#define STREAMS_BOOST_UNIT_SYSTEMS_ASTRONOMICAL_LIGHT_HOUR_HPP_INCLUDED

#include <streams_boost/units/scaled_base_unit.hpp>
#include <streams_boost/units/static_rational.hpp>
#include <streams_boost/units/scale.hpp>
#include <streams_boost/units/base_units/astronomical/light_second.hpp>

namespace streams_boost {

namespace units {

namespace astronomical {

typedef scaled_base_unit<streams_boost::units::astronomical::light_second_base_unit, scale<3600, static_rational<1> > > light_hour_base_unit;

} // namespace astronomical

template<>
struct base_unit_info<astronomical::light_hour_base_unit> {
    static const char* name()   { return("light hour"); }
    static const char* symbol() { return("lhr"); }
};

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNIT_SYSTEMS_ASTRONOMICAL_LIGHT_HOUR_HPP_INCLUDED