// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_DETAIL_PREVENT_REDEFINITION_HPP
#define STREAMS_BOOST_UNITS_DETAIL_PREVENT_REDEFINITION_HPP

#include <streams_boost/mpl/long.hpp>

namespace streams_boost {

namespace units {

namespace detail {

struct no { no() {} char dummy; };
struct yes { no dummy[2]; };

template<bool> struct ordinal_has_already_been_defined;

template<>
struct ordinal_has_already_been_defined<true>   { };

template<>
struct ordinal_has_already_been_defined<false>  { typedef void type; };

}

/// This must be in namespace streams_boost::units so that ADL
/// will work.  we need a mangled name because it must
/// be found by ADL
/// INTERNAL ONLY
template<class T>
detail::no 
streams_boost_units_is_registered(const T&) 
{ detail::no result; return(result); }

/// INTERNAL ONLY
template<class T>
detail::no 
streams_boost_units_unit_is_registered(const T&) 
{ detail::no result; return(result); }

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_PREVENT_ORDINAL_REDEFINITION_IMPL_HPP
