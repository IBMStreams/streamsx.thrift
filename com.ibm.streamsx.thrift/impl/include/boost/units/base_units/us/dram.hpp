// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNIT_BASE_UNITS_US_DRAM_HPP_INCLUDED
#define STREAMS_BOOST_UNIT_BASE_UNITS_US_DRAM_HPP_INCLUDED

#include <streams_boost/units/scaled_base_unit.hpp>
#include <streams_boost/units/static_rational.hpp>
#include <streams_boost/units/scale.hpp>
#include <streams_boost/units/base_units/us/pound.hpp>

namespace streams_boost {

namespace units {

namespace us {

typedef scaled_base_unit<pound_base_unit, scale<16, static_rational<-2> > > dram_base_unit;

} // namespace us

template<>
struct base_unit_info<us::dram_base_unit> {
    static const char* name()   { return("dram (U.S.)"); }
    static const char* symbol() { return("dr"); }
};

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNIT_BASE_UNITS_US_DRAM_HPP_INCLUDED