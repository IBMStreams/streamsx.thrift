// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2009 Matthias Christian Schabel
// Copyright (C) 2007-2009 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNIT_SYSTEMS_US_POUND_FORCE_HPP_INCLUDED
#define STREAMS_BOOST_UNIT_SYSTEMS_US_POUND_FORCE_HPP_INCLUDED

#include <string>

#include <streams_boost/units/config.hpp>
#include <streams_boost/units/base_unit.hpp>
//#include <streams_boost/units/physical_dimensions/mass.hpp>
#include <streams_boost/units/systems/si/force.hpp>
#include <streams_boost/units/conversion.hpp>

STREAMS_BOOST_UNITS_DEFINE_BASE_UNIT_WITH_CONVERSIONS(us, pound_force, "pound-force", "lbf", 4.4482216152605, si::force, -600);    // exact conversion

#if STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::units::us::pound_force_base_unit)

#endif

#endif // STREAMS_BOOST_UNIT_SYSTEMS_US_POUND_FORCE_HPP_INCLUDED
