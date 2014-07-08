// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_CGS_KINEMATIC_VISCOSITY_HPP
#define STREAMS_BOOST_UNITS_CGS_KINEMATIC_VISCOSITY_HPP

#include <streams_boost/units/systems/cgs/base.hpp>
#include <streams_boost/units/physical_dimensions/kinematic_viscosity.hpp>

namespace streams_boost {

namespace units { 

namespace cgs {

typedef unit<kinematic_viscosity_dimension,cgs::system>     kinematic_viscosity;
 
STREAMS_BOOST_UNITS_STATIC_CONSTANT(stoke,kinematic_viscosity);           
STREAMS_BOOST_UNITS_STATIC_CONSTANT(stokes,kinematic_viscosity);    

} // namespace cgs

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_CGS_KINEMATIC_VISCOSITY_HPP
