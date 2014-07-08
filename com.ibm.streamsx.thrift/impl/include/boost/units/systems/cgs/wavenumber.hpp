// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_CGS_WAVENUMBER_HPP
#define STREAMS_BOOST_UNITS_CGS_WAVENUMBER_HPP

#include <streams_boost/units/systems/cgs/base.hpp>
#include <streams_boost/units/physical_dimensions/wavenumber.hpp>

namespace streams_boost {

namespace units { 

namespace cgs {

typedef unit<wavenumber_dimension,cgs::system>   wavenumber;
    
STREAMS_BOOST_UNITS_STATIC_CONSTANT(kayser,wavenumber); 
STREAMS_BOOST_UNITS_STATIC_CONSTANT(kaysers,wavenumber);    
STREAMS_BOOST_UNITS_STATIC_CONSTANT(reciprocal_centimeter,wavenumber);  
STREAMS_BOOST_UNITS_STATIC_CONSTANT(reciprocal_centimeters,wavenumber); 
STREAMS_BOOST_UNITS_STATIC_CONSTANT(reciprocal_centimetre,wavenumber);  
STREAMS_BOOST_UNITS_STATIC_CONSTANT(reciprocal_centimetres,wavenumber); 

} // namespace cgs

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_CGS_WAVENUMBER_HPP
