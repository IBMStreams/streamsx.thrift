// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_IS_QUANTITY_OF_DIMENSION_HPP
#define STREAMS_BOOST_UNITS_IS_QUANTITY_OF_DIMENSION_HPP

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/units/units_fwd.hpp>
#include <streams_boost/units/is_unit_of_dimension.hpp>

namespace streams_boost {

namespace units {

/// check that a type is a quantity of the specified dimension
template<class T,class Dim>
struct is_quantity_of_dimension :
    public mpl::false_
{ };

template<class Unit,class Y,class Dim>
struct is_quantity_of_dimension< quantity< Unit,Y>,Dim > :
    public is_unit_of_dimension<Unit, Dim>
{ };

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_IS_QUANTITY_OF_DIMENSION_HPP
