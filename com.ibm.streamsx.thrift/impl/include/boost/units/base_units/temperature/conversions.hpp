// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// No include guards.  This header is intended to be included
// multiple times.

// units of temperature

#if defined(STREAMS_BOOST_UNITS_SI_KELVIN_BASE_UNIT_HPP) && defined(STREAMS_BOOST_UNITS_TEMPERATURE_CELSIUS_BASE_UNIT_HPP) &&\
    !defined(STREAMS_BOOST_UNITS_SYSTEMS_KELVIN_TO_CELSIUS_CONVERSION_DEFINED)
    #define STREAMS_BOOST_UNITS_SYSTEMS_KELVIN_TO_CELSIUS_CONVERSION_DEFINED
    #include <streams_boost/units/conversion.hpp>
    #include <streams_boost/units/absolute.hpp>
    STREAMS_BOOST_UNITS_DEFINE_CONVERSION_FACTOR(streams_boost::units::si::kelvin_base_unit, streams_boost::units::temperature::celsius_base_unit, one, make_one());
    STREAMS_BOOST_UNITS_DEFINE_CONVERSION_OFFSET(streams_boost::units::si::kelvin_base_unit, streams_boost::units::temperature::celsius_base_unit, double, -273.15);
#endif

#if defined(STREAMS_BOOST_UNITS_SI_KELVIN_BASE_UNIT_HPP) && defined(STREAMS_BOOST_UNITS_TEMPERATURE_FAHRENHEIT_BASE_UNIT_HPP) &&\
    !defined(STREAMS_BOOST_UNITS_SYSTEMS_KELVIN_TO_FAHRENHEIT_CONVERSION_DEFINED)
    #define STREAMS_BOOST_UNITS_SYSTEMS_KELVIN_TO_FAHRENHEIT_CONVERSION_DEFINED
    #include <streams_boost/units/conversion.hpp>
    #include <streams_boost/units/absolute.hpp>
    STREAMS_BOOST_UNITS_DEFINE_CONVERSION_FACTOR(streams_boost::units::si::kelvin_base_unit, streams_boost::units::temperature::fahrenheit_base_unit, double, 9.0/5.0);
    STREAMS_BOOST_UNITS_DEFINE_CONVERSION_OFFSET(streams_boost::units::si::kelvin_base_unit, streams_boost::units::temperature::fahrenheit_base_unit, double, -273.15 * 9.0 / 5.0 + 32.0);
#endif

#if defined(STREAMS_BOOST_UNITS_TEMPERATURE_CELSIUS_BASE_UNIT_HPP) && defined(STREAMS_BOOST_UNITS_TEMPERATURE_FAHRENHEIT_BASE_UNIT_HPP) &&\
    !defined(STREAMS_BOOST_UNITS_SYSTEMS_CELSUIS_TO_FAHRENHEIT_CONVERSION_DEFINED)
    #define STREAMS_BOOST_UNITS_SYSTEMS_CELSUIS_TO_FAHRENHEIT_CONVERSION_DEFINED
    #include <streams_boost/units/conversion.hpp>
    #include <streams_boost/units/absolute.hpp>
    STREAMS_BOOST_UNITS_DEFINE_CONVERSION_FACTOR(streams_boost::units::temperature::celsius_base_unit, streams_boost::units::temperature::fahrenheit_base_unit, double, 9.0/5.0);
    STREAMS_BOOST_UNITS_DEFINE_CONVERSION_OFFSET(streams_boost::units::temperature::celsius_base_unit, streams_boost::units::temperature::fahrenheit_base_unit, double, 32.0);
#endif

