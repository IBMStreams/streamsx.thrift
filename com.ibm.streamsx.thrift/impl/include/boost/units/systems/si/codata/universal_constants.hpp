// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_CODATA_UNIVERSAL_CONSTANTS_HPP
#define STREAMS_BOOST_UNITS_CODATA_UNIVERSAL_CONSTANTS_HPP

#include <streams_boost/units/static_constant.hpp>

#include <streams_boost/units/systems/detail/constants.hpp>
#include <streams_boost/units/systems/si/capacitance.hpp>
#include <streams_boost/units/systems/si/current.hpp>
#include <streams_boost/units/systems/si/energy.hpp>
#include <streams_boost/units/systems/si/force.hpp>
#include <streams_boost/units/systems/si/length.hpp>
#include <streams_boost/units/systems/si/mass.hpp>
#include <streams_boost/units/systems/si/resistance.hpp>
#include <streams_boost/units/systems/si/temperature.hpp>
#include <streams_boost/units/systems/si/time.hpp>
#include <streams_boost/units/systems/si/velocity.hpp>
#include <streams_boost/units/systems/si/volume.hpp>
#include <streams_boost/units/systems/si/codata/typedefs.hpp>

/// \file
/// CODATA recommended values of fundamental universal constants
/// using CODATA 2006 values as of 2007/03/30

namespace streams_boost {

namespace units { 

namespace si {
                            
namespace constants {

namespace codata {

/// CODATA recommended values of the fundamental physical constants: NIST SP 961

// UNIVERSAL
/// speed of light
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(c,quantity<velocity>,299792458.0*meters/second,0.0*meters/second);
/// magnetic constant (exactly 4 pi x 10^(-7) - error is due to finite precision of pi)
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(mu_0,quantity<force_over_current_squared>,12.56637061435917295385057353311801153679e-7*newtons/ampere/ampere,0.0*newtons/ampere/ampere);
/// electric constant
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(epsilon_0,quantity<capacitance_over_length>,8.854187817620389850536563031710750260608e-12*farad/meter,0.0*farad/meter);
/// characteristic impedance of vacuum
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(Z_0,quantity<resistance>,376.7303134617706554681984004203193082686*ohm,0.0*ohm);
/// Newtonian constant of gravitation
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(G,quantity<volume_over_mass_time_squared>,6.67428e-11*cubic_meters/kilogram/second/second,6.7e-15*cubic_meters/kilogram/second/second);
/// Planck constant
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(h,quantity<energy_time>,6.62606896e-34*joule*seconds,3.3e-41*joule*seconds);
/// Dirac constant
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(hbar,quantity<energy_time>,1.054571628e-34*joule*seconds,5.3e-42*joule*seconds);
/// Planck mass
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(m_P,quantity<mass>,2.17644e-8*kilograms,1.1e-12*kilograms);
/// Planck temperature
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(T_P,quantity<temperature>,1.416785e32*kelvin,7.1e27*kelvin);
/// Planck length
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(l_P,quantity<length>,1.616252e-35*meters,8.1e-40*meters);
/// Planck time
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(t_P,quantity<time>,5.39124e-44*seconds,2.7e-48*seconds);

} // namespace codata

} // namespace constants    

} // namespace si

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_CODATA_UNIVERSAL_CONSTANTS_HPP
