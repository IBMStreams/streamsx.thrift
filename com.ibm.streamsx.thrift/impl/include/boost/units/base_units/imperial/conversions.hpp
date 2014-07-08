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

// imperial units

#if 0

#if defined(STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_HPP_INCLUDED) && defined(STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_GALLON_HPP_INCLUDED) &&\
    !defined(STREAMS_BOOST_STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_TO_GALLON_CONVERSION_DEFINED)
    #define STREAMS_BOOST_STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_TO_GALLON_CONVERSION_DEFINED
    #include <streams_boost/units/conversion.hpp>
    STREAMS_BOOST_UNITS_DEFINE_CONVERSION_FACTOR(streams_boost::units::imperial::pint_base_unit,streams_boost::units::imperial::gallon_base_unit, double, 1./8.);
#endif

#if defined(STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_HPP_INCLUDED) && defined(STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_QUART_HPP_INCLUDED) &&\
    !defined(STREAMS_BOOST_STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_TO_QUART_CONVERSION_DEFINED)
    #define STREAMS_BOOST_STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_TO_QUART_CONVERSION_DEFINED
    #include <streams_boost/units/conversion.hpp>
    STREAMS_BOOST_UNITS_DEFINE_CONVERSION_FACTOR(streams_boost::units::imperial::pint_base_unit,streams_boost::units::imperial::quart_base_unit, double, 1./2.);
#endif

#if defined(STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_HPP_INCLUDED) && defined(STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_GILL_HPP_INCLUDED) &&\
    !defined(STREAMS_BOOST_STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_TO_GILL_CONVERSION_DEFINED)
    #define STREAMS_BOOST_STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_TO_GILL_CONVERSION_DEFINED
    #include <streams_boost/units/conversion.hpp>
    STREAMS_BOOST_UNITS_DEFINE_CONVERSION_FACTOR(streams_boost::units::imperial::pint_base_unit,streams_boost::units::imperial::gill_base_unit, double, 4.);
#endif

#if defined(STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_HPP_INCLUDED) && defined(STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_FLUID_OUNCE_HPP_INCLUDED) &&\
    !defined(STREAMS_BOOST_STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_TO_FLUID_OUNCE_CONVERSION_DEFINED)
    #define STREAMS_BOOST_STREAMS_BOOST_UNITS_BASE_UNITS_IMPERIAL_PINT_TO_FLUID_OUNCE_CONVERSION_DEFINED
    #include <streams_boost/units/conversion.hpp>
    STREAMS_BOOST_UNITS_DEFINE_CONVERSION_FACTOR(streams_boost::units::imperial::pint_base_unit,streams_boost::units::imperial::fluid_ounce_base_unit, double, 20.);
#endif

#endif
