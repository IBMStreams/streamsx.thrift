// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_SI_PREFIXES_HPP
#define STREAMS_BOOST_UNITS_SI_PREFIXES_HPP

#include <streams_boost/units/static_constant.hpp>

#include <streams_boost/units/make_scaled_unit.hpp>
#include <streams_boost/units/systems/si/dimensionless.hpp>

namespace streams_boost {

namespace units { 

namespace si {

#define STREAMS_BOOST_UNITS_METRIC_PREFIX(exponent, name)                                                       \
    typedef make_scaled_unit<dimensionless, scale<10, static_rational<exponent> > >::type name ## _type;\
    STREAMS_BOOST_UNITS_STATIC_CONSTANT(name, name ## _type)

STREAMS_BOOST_UNITS_METRIC_PREFIX(-24, yocto);
STREAMS_BOOST_UNITS_METRIC_PREFIX(-21, zepto);
STREAMS_BOOST_UNITS_METRIC_PREFIX(-18, atto);
STREAMS_BOOST_UNITS_METRIC_PREFIX(-15, femto);
STREAMS_BOOST_UNITS_METRIC_PREFIX(-12, pico);
STREAMS_BOOST_UNITS_METRIC_PREFIX(-9, nano);
STREAMS_BOOST_UNITS_METRIC_PREFIX(-6, micro);
STREAMS_BOOST_UNITS_METRIC_PREFIX(-3, milli);
STREAMS_BOOST_UNITS_METRIC_PREFIX(-2, centi);
STREAMS_BOOST_UNITS_METRIC_PREFIX(-1, deci);
STREAMS_BOOST_UNITS_METRIC_PREFIX(1, deka);
STREAMS_BOOST_UNITS_METRIC_PREFIX(2, hecto);
STREAMS_BOOST_UNITS_METRIC_PREFIX(3, kilo);
STREAMS_BOOST_UNITS_METRIC_PREFIX(6, mega);
STREAMS_BOOST_UNITS_METRIC_PREFIX(9, giga);
STREAMS_BOOST_UNITS_METRIC_PREFIX(12, tera);
STREAMS_BOOST_UNITS_METRIC_PREFIX(15, peta);
STREAMS_BOOST_UNITS_METRIC_PREFIX(18, exa);
STREAMS_BOOST_UNITS_METRIC_PREFIX(21, zetta);
STREAMS_BOOST_UNITS_METRIC_PREFIX(24, yotta);

/*STREAMS_BOOST_UNITS_STATIC_CONSTANT(yocto,long double) = (1e-24);       ///< metric prefix for 1.0e-24
STREAMS_BOOST_UNITS_STATIC_CONSTANT(zepto,long double) = (1e-21);       ///< metric prefix for 1.0e-21
STREAMS_BOOST_UNITS_STATIC_CONSTANT(atto,long double) = (1e-18);        ///< metric prefix for 1.0e-18
STREAMS_BOOST_UNITS_STATIC_CONSTANT(femto,long double) = (1e-15);       ///< metric prefix for 1.0e-15
STREAMS_BOOST_UNITS_STATIC_CONSTANT(pico,long double) = (1e-12);        ///< metric prefix for 1.0e-12
STREAMS_BOOST_UNITS_STATIC_CONSTANT(nano,long double) = (1e-9);         ///< metric prefix for 1.0e-9
STREAMS_BOOST_UNITS_STATIC_CONSTANT(micro,long double) = (1e-6);        ///< metric prefix for 1.0e-6
STREAMS_BOOST_UNITS_STATIC_CONSTANT(milli,long double) = (1e-3);        ///< metric prefix for 1.0e-3
STREAMS_BOOST_UNITS_STATIC_CONSTANT(centi,long double) = (1e-2);        ///< metric prefix for 1.0e-2
STREAMS_BOOST_UNITS_STATIC_CONSTANT(deci,long double) = (1e-1);         ///< metric prefix for 1.0e-1
STREAMS_BOOST_UNITS_STATIC_CONSTANT(deka,long double) = (1e1);          ///< metric prefix for 1.0e+1
STREAMS_BOOST_UNITS_STATIC_CONSTANT(hecto,long double) = (1e2);         ///< metric prefix for 1.0e+2
STREAMS_BOOST_UNITS_STATIC_CONSTANT(kilo,long double) = (1e3);          ///< metric prefix for 1.0e+3
STREAMS_BOOST_UNITS_STATIC_CONSTANT(mega,long double) = (1e6);          ///< metric prefix for 1.0e+6
STREAMS_BOOST_UNITS_STATIC_CONSTANT(giga,long double) = (1e9);          ///< metric prefix for 1.0e+9
STREAMS_BOOST_UNITS_STATIC_CONSTANT(tera,long double) = (1e12);         ///< metric prefix for 1.0e+12
STREAMS_BOOST_UNITS_STATIC_CONSTANT(peta,long double) = (1e15);         ///< metric prefix for 1.0e+15
STREAMS_BOOST_UNITS_STATIC_CONSTANT(exa,long double) = (1e18);          ///< metric prefix for 1.0e+18
STREAMS_BOOST_UNITS_STATIC_CONSTANT(zetta,long double) = (1e21);        ///< metric prefix for 1.0e+21
STREAMS_BOOST_UNITS_STATIC_CONSTANT(yotta,long double) = (1e24);        ///< metric prefix for 1.0e+24 */ 

} // namespace si

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_SI_PREFIXES_HPP
