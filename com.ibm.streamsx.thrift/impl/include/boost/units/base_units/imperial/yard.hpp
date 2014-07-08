// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_SYSTEMS_IMPERIAL_YARD_BASE_UNIT_HPP
#define STREAMS_BOOST_UNITS_SYSTEMS_IMPERIAL_YARD_BASE_UNIT_HPP

#include <string>

#include <streams_boost/units/config.hpp>
#include <streams_boost/units/base_unit.hpp>
#include <streams_boost/units/physical_dimensions/length.hpp>
#include <streams_boost/units/base_units/si/meter.hpp>
#include <streams_boost/units/conversion.hpp>

STREAMS_BOOST_UNITS_DEFINE_BASE_UNIT_WITH_CONVERSIONS(imperial, yard, "yard", "yd", 0.9144, si::meter_base_unit, -301);    // exact conversion

#if STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::units::imperial::yard_base_unit)

#endif

#endif // STREAMS_BOOST_UNITS_SYSTEMS_IMPERIAL_YARD_BASE_UNIT_HPP
