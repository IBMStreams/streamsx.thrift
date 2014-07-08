// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_MASS_DENSITY_DERIVED_DIMENSION_HPP
#define STREAMS_BOOST_UNITS_MASS_DENSITY_DERIVED_DIMENSION_HPP

#include <streams_boost/units/derived_dimension.hpp>
#include <streams_boost/units/physical_dimensions/length.hpp>
#include <streams_boost/units/physical_dimensions/mass.hpp>

namespace streams_boost {

namespace units {

/// derived dimension for mass density : L^-3 M
typedef derived_dimension<length_base_dimension,-3,
                          mass_base_dimension,1>::type mass_density_dimension;            

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_MASS_DENSITY_DERIVED_DIMENSION_HPP