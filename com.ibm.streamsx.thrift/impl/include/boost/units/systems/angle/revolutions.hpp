// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_ANGLE_REVOLUTIONS_HPP
#define STREAMS_BOOST_UNITS_ANGLE_REVOLUTIONS_HPP

#include <streams_boost/config/no_tr1/cmath.hpp>

#include <streams_boost/units/conversion.hpp>
#include <streams_boost/units/io.hpp>
#include <streams_boost/units/quantity.hpp>
#include <streams_boost/units/static_constant.hpp>
#include <streams_boost/units/make_system.hpp>
#include <streams_boost/units/base_units/angle/revolution.hpp>

namespace streams_boost {

namespace units {

namespace revolution {

typedef make_system<streams_boost::units::angle::revolution_base_unit>::type system;

typedef unit<dimensionless_type,system>         dimensionless;
typedef unit<plane_angle_dimension,system>      plane_angle;          ///< angle revolution unit constant

STREAMS_BOOST_UNITS_STATIC_CONSTANT(revolution,plane_angle);
STREAMS_BOOST_UNITS_STATIC_CONSTANT(revolutions,plane_angle);

} // namespace revolution

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_ANGLE_REVOLUTIONS_HPP
