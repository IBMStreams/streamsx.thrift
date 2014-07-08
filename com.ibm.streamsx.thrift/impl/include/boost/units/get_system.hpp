// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_GET_SYSTEM_HPP
#define STREAMS_BOOST_UNITS_GET_SYSTEM_HPP

#include <streams_boost/units/units_fwd.hpp>

namespace streams_boost {

namespace units {

template<class T>
struct get_system {};

/// get the system of a unit
template<class Dim,class System>
struct get_system< unit<Dim,System> >
{
    typedef System type;
};

/// get the system of an absolute unit
template<class Unit>
struct get_system< absolute<Unit> >
{
    typedef typename get_system<Unit>::type type;
};

/// get the system of a quantity
template<class Unit,class Y>
struct get_system< quantity<Unit,Y> >
{
    typedef typename get_system<Unit>::type     type;
};

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_GET_SYSTEM_HPP
