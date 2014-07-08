// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_IS_DIMENSIONLESS_QUANTITY_HPP
#define STREAMS_BOOST_UNITS_IS_DIMENSIONLESS_QUANTITY_HPP

#include <streams_boost/units/is_quantity_of_dimension.hpp>
#include <streams_boost/units/units_fwd.hpp>

namespace streams_boost {

namespace units {

/// check that a type is a dimensionless quantity
template<class T>
struct is_dimensionless_quantity :
    public is_quantity_of_dimension<T,dimensionless_type>
{ };

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_IS_DIMENSIONLESS_QUANTITY_HPP
