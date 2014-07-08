// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_DIMENSIONLESS_TYPE_HPP
#define STREAMS_BOOST_UNITS_DIMENSIONLESS_TYPE_HPP

#include <streams_boost/mpl/long.hpp>
#include <streams_boost/mpl/deref.hpp>
#include <streams_boost/mpl/arithmetic.hpp>

#include <streams_boost/units/config.hpp>

namespace streams_boost {

namespace units {

namespace detail {

struct dimension_list_tag;

}

/// Dimension lists in which all exponents resolve to zero reduce to @c dimensionless_type.
struct dimensionless_type
{
    typedef dimensionless_type          type;
    typedef detail::dimension_list_tag  tag;
    typedef mpl::long_<0>               size;
};

} // namespace units

} // namespace streams_boost

#if STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::units::dimensionless_type)

#endif

#endif // STREAMS_BOOST_UNITS_DIMENSIONLESS_TYPE_HPP
