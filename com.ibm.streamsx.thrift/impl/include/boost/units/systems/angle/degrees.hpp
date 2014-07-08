// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_ANGLE_DEGREE_HPP
#define STREAMS_BOOST_UNITS_ANGLE_DEGREE_HPP

#include <streams_boost/config/no_tr1/cmath.hpp>

#include <streams_boost/units/conversion.hpp>
#include <streams_boost/units/io.hpp>
#include <streams_boost/units/static_constant.hpp>
#include <streams_boost/units/unit.hpp>
#include <streams_boost/units/make_system.hpp>
#include <streams_boost/units/base_units/angle/degree.hpp>

namespace streams_boost {

namespace units {

namespace degree {

typedef make_system<streams_boost::units::angle::degree_base_unit>::type system;

typedef unit<dimensionless_type,system>         dimensionless;
typedef unit<plane_angle_dimension,system>      plane_angle;           ///< angle degree unit constant

STREAMS_BOOST_UNITS_STATIC_CONSTANT(degree,plane_angle);
STREAMS_BOOST_UNITS_STATIC_CONSTANT(degrees,plane_angle);

} // namespace degree

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_ANGLE_DEGREE_HPP
