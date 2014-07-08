// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNIT_SYSTEMS_OTHER_YEAR_HPP_INCLUDED
#define STREAMS_BOOST_UNIT_SYSTEMS_OTHER_YEAR_HPP_INCLUDED

#include <streams_boost/units/scaled_base_unit.hpp>
#include <streams_boost/units/static_rational.hpp>
#include <streams_boost/units/scale.hpp>
#include <streams_boost/units/base_units/si/second.hpp>

// Julian year = 365.25 days exactly = 8766 hours exactly

namespace streams_boost {
namespace units {
namespace metric {

typedef scaled_base_unit<streams_boost::units::si::second_base_unit, scale<31557600, static_rational<1> > > year_base_unit;

}

template<>
struct base_unit_info<metric::year_base_unit> {
    static const char* name()   { return("Julian year"); }
    static const char* symbol() { return("yr"); }
};

}
}

#endif
