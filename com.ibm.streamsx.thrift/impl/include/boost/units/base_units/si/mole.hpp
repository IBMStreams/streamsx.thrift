// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_SI_MOLE_BASE_UNIT_HPP
#define STREAMS_BOOST_UNITS_SI_MOLE_BASE_UNIT_HPP

#include <string>

#include <streams_boost/units/config.hpp>
#include <streams_boost/units/base_unit.hpp>
#include <streams_boost/units/physical_dimensions/amount.hpp>

namespace streams_boost {

namespace units {

namespace si {

struct mole_base_unit : public base_unit<mole_base_unit, amount_dimension, -4>
{
    static std::string name()   { return("mole"); }
    static std::string symbol() { return("mol"); }
};

} // namespace si

} // namespace units

} // namespace streams_boost

#if STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::units::si::mole_base_unit)

#endif

//#include <streams_boost/units/base_units/detail/conversions.hpp>

#endif // STREAMS_BOOST_UNITS_SI_MOLE_BASE_UNIT_HPP
