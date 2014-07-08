// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNIT_SYSTEMS_ANGLE_ARCSECOND_HPP_INCLUDED
#define STREAMS_BOOST_UNIT_SYSTEMS_ANGLE_ARCSECOND_HPP_INCLUDED

#include <streams_boost/units/scaled_base_unit.hpp>
#include <streams_boost/units/static_rational.hpp>
#include <streams_boost/units/scale.hpp>
#include <streams_boost/units/base_units/angle/degree.hpp>

namespace streams_boost {
namespace units {
namespace angle {

//typedef scaled_base_unit<degree_base_unit, scale<60, static_rational<-2> > >  arcsecond_base_unit;
typedef scaled_base_unit<degree_base_unit, scale<3600, static_rational<-1> > >  arcsecond_base_unit;

}

template<>
struct base_unit_info<angle::arcsecond_base_unit> {
    static const char* name()   { return("arcsecond"); }
    static const char* symbol() { return("\""); }
};

}
}

#endif // STREAMS_BOOST_UNIT_SYSTEMS_ANGLE_ARCSECOND_HPP_INCLUDED
