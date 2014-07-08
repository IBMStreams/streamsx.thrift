// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNIT_SYSTEMS_METRIC_KNOT_HPP_INCLUDED
#define STREAMS_BOOST_UNIT_SYSTEMS_METRIC_KNOT_HPP_INCLUDED

#include <streams_boost/units/conversion.hpp>
#include <streams_boost/units/systems/si/velocity.hpp>

STREAMS_BOOST_UNITS_DEFINE_BASE_UNIT_WITH_CONVERSIONS(metric, knot, "knot", "kt", 1852./3600., streams_boost::units::si::velocity, -403);

#endif // STREAMS_BOOST_UNIT_SYSTEMS_METRIC_KNOT_HPP_INCLUDED
