// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_SI_KILOGRAM_BASE_UNIT_HPP
#define STREAMS_BOOST_UNITS_SI_KILOGRAM_BASE_UNIT_HPP

#include <streams_boost/units/scaled_base_unit.hpp>
#include <streams_boost/units/base_units/cgs/gram.hpp>

namespace streams_boost {

namespace units {

namespace si {

typedef scaled_base_unit<streams_boost::units::cgs::gram_base_unit, scale<10, static_rational<3> > > kilogram_base_unit;

} // namespace si

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_SI_KILOGRAM_BASE_UNIT_HPP
