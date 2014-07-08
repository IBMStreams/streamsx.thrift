// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_IMPERIAL_INCH_BASE_UNIT_HPP
#define STREAMS_BOOST_UNITS_IMPERIAL_INCH_BASE_UNIT_HPP

#include <streams_boost/units/scaled_base_unit.hpp>
#include <streams_boost/units/static_rational.hpp>
#include <streams_boost/units/scale.hpp>
#include <streams_boost/units/base_units/imperial/yard.hpp>

namespace streams_boost {

namespace units {

namespace imperial {

typedef scaled_base_unit<yard_base_unit, scale<36, static_rational<-1> > > inch_base_unit;

} // namespace imperial

template<>
struct base_unit_info<imperial::inch_base_unit> {
    static const char* name()   { return("inch"); }
    static const char* symbol() { return("in"); }
};

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_IMPERIAL_INCH_BASE_UNIT_HPP
