// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_DETAIL_DIMENSIONLESS_UNIT_HPP
#define STREAMS_BOOST_UNITS_DETAIL_DIMENSIONLESS_UNIT_HPP

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/units/units_fwd.hpp>

namespace streams_boost {
namespace units {

template<class T>
struct heterogeneous_system;

template<class T>
struct homogeneous_system;

template<class T1, class T2, class Scale>
struct heterogeneous_system_impl;

namespace detail {

template<class System>
struct void_if_dimensionless {
    typedef int type;
};

template<class T>
struct void_if_dimensionless<streams_boost::units::homogeneous_system<T> > {
    typedef void type;
};

template<>
struct void_if_dimensionless<
   streams_boost::units::heterogeneous_system<
       streams_boost::units::heterogeneous_system_impl<
           streams_boost::units::dimensionless_type,
           streams_boost::units::dimensionless_type,
           streams_boost::units::dimensionless_type
       >
   >
> {
    typedef void type;
};

template<class System, class Test = void>
struct void_if_heterogeneous {
    typedef void type;
};

template<class System>
struct void_if_heterogeneous<System, typename void_if_dimensionless<System>::type> {
    typedef int type;
};

template<class System, class Enable=void>
struct is_dimensionless_system : mpl::false_ {};

template<class System>
struct is_dimensionless_system<System, typename void_if_dimensionless<System>::type> : mpl::true_ {};

#define STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(T)\
    streams_boost::units::unit<\
        streams_boost::units::dimensionless_type,\
        T,\
        typename ::streams_boost::units::detail::void_if_dimensionless<T>::type\
    >

#define STREAMS_BOOST_UNITS_HETEROGENEOUS_DIMENSIONLESS_UNIT(T)\
    streams_boost::units::unit<\
        streams_boost::units::dimensionless_type,\
        T,\
        typename ::streams_boost::units::detail::void_if_heterogeneous<T>::type\
    >

}
}
}

#endif
