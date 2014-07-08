// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_SI_ACTIVITY_HPP
#define STREAMS_BOOST_UNITS_SI_ACTIVITY_HPP

#include <streams_boost/units/systems/si/base.hpp>
#include <streams_boost/units/physical_dimensions/activity.hpp>

namespace streams_boost {

namespace units { 

namespace si {

typedef unit<activity_dimension,si::system>  activity;

STREAMS_BOOST_UNITS_STATIC_CONSTANT(becquerel,activity);
STREAMS_BOOST_UNITS_STATIC_CONSTANT(becquerels,activity);

} // namespace si

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_SI_ACTIVITY_HPP
