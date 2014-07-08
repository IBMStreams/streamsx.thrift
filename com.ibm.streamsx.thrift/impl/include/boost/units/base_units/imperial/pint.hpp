// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_HPP_INCLUDED
#define STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_HPP_INCLUDED

#include <string>

#include <streams_boost/units/systems/si/volume.hpp>
#include <streams_boost/units/conversion.hpp>

STREAMS_BOOST_UNITS_DEFINE_BASE_UNIT_WITH_CONVERSIONS(imperial, pint, "pint (imp.)", "pt", 4.54609e-3/8., si::volume, -303);    // exact conversion

#if STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::units::imperial::pint_base_unit)

#endif

#endif // STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_HPP_INCLUDED
