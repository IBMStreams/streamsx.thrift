// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_IS_UNIT_OF_SYSTEM_HPP
#define STREAMS_BOOST_UNITS_IS_UNIT_OF_SYSTEM_HPP

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/units/units_fwd.hpp>

namespace streams_boost {

namespace units {

/// check that a type is a unit in a specified system
template<class T,class System>
struct is_unit_of_system :
    public mpl::false_
{ };
    
template<class Dim,class System>
struct is_unit_of_system< unit<Dim,System>,System > :
    public mpl::true_
{ };
    
template<class Dim,class System>
struct is_unit_of_system< absolute<unit<Dim,System> >,System > :
    public mpl::true_
{ };

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_IS_UNIT_OF_SYSTEM_HPP
