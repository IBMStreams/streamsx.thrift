// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_SI_PRESSURE_HPP
#define STREAMS_BOOST_UNITS_SI_PRESSURE_HPP

#include <streams_boost/units/systems/si/base.hpp>
#include <streams_boost/units/physical_dimensions/pressure.hpp>

namespace streams_boost {

namespace units { 

namespace si {

typedef unit<pressure_dimension,si::system>      pressure;

// windef.h #defines pascal on Metrowerks compilers
#if defined(__MWERKS__)
   #if !__option(only_std_keywords)
       #define STREAMS_BOOST_UNITS_NO_PASCAL 1
   #elif defined(pascal)
       #define STREAMS_BOOST_UNITS_NO_PASCAL 1
   #endif
#elif defined(pascal)
   #define STREAMS_BOOST_UNITS_NO_PASCAL 1
#elif STREAMS_BOOST_MSVC
   #define STREAMS_BOOST_UNITS_NO_PASCAL 1
#endif

#ifndef STREAMS_BOOST_UNITS_NO_PASCAL
STREAMS_BOOST_UNITS_STATIC_CONSTANT(pascal,pressure);   
#endif
STREAMS_BOOST_UNITS_STATIC_CONSTANT(pascals,pressure);  

} // namespace si

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_SI_PRESSURE_HPP
