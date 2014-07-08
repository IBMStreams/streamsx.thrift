// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_SCALED_BASE_UNIT_HPP_INCLUDED
#define STREAMS_BOOST_UNITS_SCALED_BASE_UNIT_HPP_INCLUDED

#include <string>

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/less.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/type_traits/detail/ice_and.hpp>
#include <streams_boost/type_traits/detail/ice_or.hpp>

#include <streams_boost/units/config.hpp>
#include <streams_boost/units/dimension.hpp>
#include <streams_boost/units/static_rational.hpp>
#include <streams_boost/units/units_fwd.hpp>

namespace streams_boost {

namespace units {

template<class T>
struct heterogeneous_system;

template<class T, class D, class Scale>
struct heterogeneous_system_impl;

template<class T, class E>
struct heterogeneous_system_dim;

template<class T>
struct base_unit_info;

/// INTERNAL ONLY
struct scaled_base_unit_tag {};

template<class S, class Scale>
struct scaled_base_unit
{
    /// INTERNAL ONLY
    typedef void streams_boost_units_is_base_unit_type;
    typedef scaled_base_unit type;
    typedef scaled_base_unit_tag tag;
    typedef S system_type;
    typedef Scale scale_type;
    typedef typename S::dimension_type dimension_type;

#ifdef STREAMS_BOOST_UNITS_DOXYGEN

    typedef detail::unspecified unit_type;

#else

    typedef unit<
        dimension_type,
        heterogeneous_system<
            heterogeneous_system_impl<
                list<
                    heterogeneous_system_dim<scaled_base_unit,static_rational<1> >,
                    dimensionless_type
                >,
                dimension_type,
                dimensionless_type
            >
        >
    > unit_type;

#endif

    static std::string symbol()
    {
        return(Scale::symbol() + base_unit_info<S>::symbol());
    }
    static std::string name()
    {
        return(Scale::name() + base_unit_info<S>::name());
    }
};

} // namespace units

} // namespace streams_boost

#if STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::units::scaled_base_unit, (class)(class))

#endif

namespace streams_boost {

#ifndef STREAMS_BOOST_UNITS_DOXYGEN

namespace mpl {

/// INTERNAL ONLY
template<class Tag>
struct less_impl<streams_boost::units::scaled_base_unit_tag, Tag>
{
    template<class T0, class T1>
    struct apply : mpl::bool_<
        streams_boost::type_traits::ice_or<(mpl::less<typename T0::system_type, T1>::value),
        (streams_boost::type_traits::ice_and<streams_boost::is_same<typename T0::system_type, T1>::value, (T0::scale_type::exponent::Numerator) < 0>::value)>::value> {};
};

/// INTERNAL ONLY
template<class Tag>
struct less_impl<Tag, streams_boost::units::scaled_base_unit_tag>
{
    template<class T0, class T1>
    struct apply : mpl::bool_<
        streams_boost::type_traits::ice_or<(mpl::less<T0, typename T1::system_type>::value),
        streams_boost::type_traits::ice_and<(streams_boost::is_same<T0, typename T1::system_type>::value), ((T1::scale_type::exponent::Numerator) > 0)>::value>::value> {};
};

/// INTERNAL ONLY
template<>
struct less_impl<streams_boost::units::scaled_base_unit_tag, streams_boost::units::scaled_base_unit_tag>
{
    template<class T0, class T1>
    struct apply : mpl::bool_<
        streams_boost::type_traits::ice_or<(mpl::less<typename T0::system_type, typename T1::system_type>::value),
        streams_boost::type_traits::ice_and<(streams_boost::is_same<typename T0::system_type, typename T1::system_type>::value),
        streams_boost::type_traits::ice_or<((T0::scale_type::base) < (T1::scale_type::base)),
        streams_boost::type_traits::ice_and<((T0::scale_type::base) == (T1::scale_type::base)),
        (mpl::less<typename T0::scale_type::exponent,typename T1::scale_type::exponent>::value)>::value>::value>::value>::value> {};
};

} // namespace mpl

#endif

} // namespace streams_boost

#endif
