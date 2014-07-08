// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_LUMINOUS_FLUX_DERIVED_DIMENSION_HPP
#define STREAMS_BOOST_UNITS_LUMINOUS_FLUX_DERIVED_DIMENSION_HPP

#include <streams_boost/units/derived_dimension.hpp>
#include <streams_boost/units/physical_dimensions/luminous_intensity.hpp>
#include <streams_boost/units/physical_dimensions/solid_angle.hpp>

namespace streams_boost {

namespace units {

/// derived dimension for luminous flux : I QS
typedef derived_dimension<luminous_intensity_base_dimension,1,
                          solid_angle_base_dimension,1>::type luminous_flux_dimension;

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_LUMINOUS_FLUX_DERIVED_DIMENSION_HPP
