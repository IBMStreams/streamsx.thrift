// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_SI_SOLID_ANGLE_HPP
#define STREAMS_BOOST_UNITS_SI_SOLID_ANGLE_HPP

#include <streams_boost/units/systems/si/base.hpp>

namespace streams_boost {

namespace units { 

namespace si {

typedef unit<solid_angle_dimension,si::system>      solid_angle;
    
STREAMS_BOOST_UNITS_STATIC_CONSTANT(steradian,solid_angle); 
STREAMS_BOOST_UNITS_STATIC_CONSTANT(steradians,solid_angle);    

} // namespace si

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_SI_SOLID_ANGLE_HPP