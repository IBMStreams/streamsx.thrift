// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_IS_DIMENSIONLESS_HPP
#define STREAMS_BOOST_UNITS_IS_DIMENSIONLESS_HPP

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/units/units_fwd.hpp>

namespace streams_boost {

namespace units {

template<class T>
struct is_dimensionless :
    public mpl::false_
{ };

/// check if a unit is dimensionless
template<class System>
struct is_dimensionless< unit<dimensionless_type,System> > :
    public mpl::true_
{ };

/// check if a quantity is dimensionless
template<class Unit,class Y>
struct is_dimensionless< quantity<Unit,Y> > :
    public is_dimensionless<Unit>
{ };

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_IS_DIMENSIONLESS_HPP
