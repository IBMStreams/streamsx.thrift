// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_HOMOGENEOUS_SYSTEM_HPP_INCLUDED
#define STREAMS_BOOST_UNITS_HOMOGENEOUS_SYSTEM_HPP_INCLUDED

#include <streams_boost/mpl/bool.hpp>

#include <streams_boost/units/config.hpp>
#include <streams_boost/units/static_rational.hpp>

#ifdef STREAMS_BOOST_UNITS_CHECK_HOMOGENEOUS_UNITS

#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/mpl/not.hpp>

#include <streams_boost/units/detail/linear_algebra.hpp>

#endif

namespace streams_boost {

namespace units {

/// A system that can uniquely represent any unit
/// which can be composed from a linearly independent set
/// of base units.  It is safe to rebind a unit with
/// such a system to different dimensions.
///
/// Do not construct this template directly.  Use
/// make_system instead.
template<class L>
struct homogeneous_system {
    /// INTERNAL ONLY
    typedef L type;
};

template<class T, class E>
struct static_power;

template<class T, class R>
struct static_root;

/// INTERNAL ONLY
template<class L, long N, long D>
struct static_power<homogeneous_system<L>, static_rational<N,D> >
{
    typedef homogeneous_system<L> type;
};

/// INTERNAL ONLY
template<class L, long N, long D>
struct static_root<homogeneous_system<L>, static_rational<N,D> >
{
    typedef homogeneous_system<L> type;
};

namespace detail {

template<class System, class Dimensions>
struct check_system;

#ifdef STREAMS_BOOST_UNITS_CHECK_HOMOGENEOUS_UNITS

template<class L, class Dimensions>
struct check_system<homogeneous_system<L>, Dimensions> :
    streams_boost::mpl::not_<
        streams_boost::is_same<
            typename calculate_base_unit_exponents<
                L,
                Dimensions
            >::type,
            inconsistent
        >
    > {};

#else

template<class L, class Dimensions>
struct check_system<homogeneous_system<L>, Dimensions> : mpl::true_ {};

#endif

} // namespace detail

} // namespace units

} // namespace streams_boost

#if STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::units::homogeneous_system, (class))

#endif

#endif
