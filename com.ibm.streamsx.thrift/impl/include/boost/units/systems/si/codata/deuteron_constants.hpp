// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_CODATA_DEUTERON_CONSTANTS_HPP
#define STREAMS_BOOST_UNITS_CODATA_DEUTERON_CONSTANTS_HPP

#include <streams_boost/units/static_constant.hpp>

#include <streams_boost/units/systems/detail/constants.hpp>
#include <streams_boost/units/systems/si/amount.hpp>
#include <streams_boost/units/systems/si/area.hpp>
#include <streams_boost/units/systems/si/electric_charge.hpp>
#include <streams_boost/units/systems/si/energy.hpp>
#include <streams_boost/units/systems/si/frequency.hpp>
#include <streams_boost/units/systems/si/length.hpp>
#include <streams_boost/units/systems/si/mass.hpp>
#include <streams_boost/units/systems/si/magnetic_flux_density.hpp>
#include <streams_boost/units/systems/si/time.hpp>
#include <streams_boost/units/systems/si/wavenumber.hpp>

#include <streams_boost/units/systems/si/codata/typedefs.hpp>

/// \file
/// CODATA recommended values of fundamental atomic and nuclear constants
/// CODATA 2006 values as of 2007/03/30

namespace streams_boost {

namespace units { 

namespace si {
                            
namespace constants {

namespace codata {

/// CODATA recommended values of the fundamental physical constants: NIST SP 961

/// deuteron mass
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(m_d,quantity<mass>,3.34358320e-27*kilograms,1.7e-34*kilograms);
/// deuteron-electron mass ratio
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(m_d_over_m_e,quantity<dimensionless>,3670.4829654*dimensionless(),1.6e-6*dimensionless());
/// deuteron-proton mass ratio
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(m_d_over_m_p,quantity<dimensionless>,1.99900750108*dimensionless(),2.2e-10*dimensionless());
/// deuteron molar mass
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(M_d,quantity<mass_over_amount>,2.013553212724e-3*kilograms/mole,7.8e-14*kilograms/mole);
/// deuteron rms charge radius
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(R_d,quantity<length>,2.1402e-15*meters,2.8e-18*meters);
/// deuteron magnetic moment
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(mu_d,quantity<energy_over_magnetic_flux_density>,0.433073465e-26*joules/tesla,1.1e-34*joules/tesla);
/// deuteron-Bohr magneton ratio
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_B,quantity<dimensionless>,0.4669754556e-3*dimensionless(),3.9e-12*dimensionless());
/// deuteron-nuclear magneton ratio
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_N,quantity<dimensionless>,0.8574382308*dimensionless(),7.2e-9*dimensionless());
/// deuteron g-factor
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(g_d,quantity<dimensionless>,0.8574382308*dimensionless(),7.2e-9*dimensionless());
/// deuteron-electron magnetic moment ratio
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_e,quantity<dimensionless>,-4.664345537e-4*dimensionless(),3.9e-12*dimensionless());
/// deuteron-proton magnetic moment ratio
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_p,quantity<dimensionless>,0.3070122070*dimensionless(),2.4e-9*dimensionless());
/// deuteron-neutron magnetic moment ratio
STREAMS_BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_n,quantity<dimensionless>,-0.44820652*dimensionless(),1.1e-7*dimensionless());

} // namespace codata

} // namespace constants    

} // namespace si

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_CODATA_DEUTERON_CONSTANTS_HPP
