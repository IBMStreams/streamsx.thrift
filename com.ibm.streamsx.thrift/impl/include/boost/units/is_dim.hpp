// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_IS_DIM_HPP
#define STREAMS_BOOST_UNITS_IS_DIM_HPP

#include <streams_boost/mpl/bool.hpp>

#include <streams_boost/units/units_fwd.hpp>

namespace streams_boost {

namespace units {

/// Check that a type is a valid @c dim.
template<typename T> 
struct is_dim :
    public mpl::false_
{ };

template<typename T,typename V>
struct is_dim< dim<T,V> > :
    public mpl::true_
{ };

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_IS_DIM_HPP
