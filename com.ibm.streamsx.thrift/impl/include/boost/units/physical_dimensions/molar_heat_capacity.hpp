// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_MOLAR_HEAT_CAPACITY_DERIVED_DIMENSION_HPP
#define STREAMS_BOOST_UNITS_MOLAR_HEAT_CAPACITY_DERIVED_DIMENSION_HPP

#include <streams_boost/units/derived_dimension.hpp>
#include <streams_boost/units/physical_dimensions/length.hpp>
#include <streams_boost/units/physical_dimensions/mass.hpp>
#include <streams_boost/units/physical_dimensions/time.hpp>
#include <streams_boost/units/physical_dimensions/temperature.hpp>
#include <streams_boost/units/physical_dimensions/amount.hpp>

namespace streams_boost {

namespace units {

/// derived dimension for molar heat capacity : L^2 M T^-2 Theta^-1 N^-1
typedef derived_dimension<length_base_dimension,2,
                          mass_base_dimension,1,
                          time_base_dimension,-2,
                          temperature_base_dimension,-1,
                          amount_base_dimension,-1>::type molar_heat_capacity_dimension;                    

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_MOLAR_HEAT_CAPACITY_DERIVED_DIMENSION_HPP
