// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_FLUID_OUNCE_HPP_INCLUDED
#define STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_FLUID_OUNCE_HPP_INCLUDED

#include <streams_boost/units/scaled_base_unit.hpp>
#include <streams_boost/units/static_rational.hpp>
#include <streams_boost/units/scale.hpp>
#include <streams_boost/units/base_units/imperial/pint.hpp>

namespace streams_boost {

namespace units {

namespace imperial {

typedef scaled_base_unit<pint_base_unit, scale<20, static_rational<-1> > > fluid_ounce_base_unit;

} // namespace imperial

template<>
struct base_unit_info<imperial::fluid_ounce_base_unit> {
    static const char* name()   { return("fluid ounce (imp.)"); }
    static const char* symbol() { return("fl oz"); }
};

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_FLUID_OUNCE_HPP_INCLUDED
