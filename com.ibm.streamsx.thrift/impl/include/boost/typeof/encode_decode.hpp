// Copyright (C) 2004 Arkadiy Vertleyb

// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

// streams_boostinspect:nounnamed

#ifndef STREAMS_BOOST_TYPEOF_ENCODE_DECODE_HPP_INCLUDED
#define STREAMS_BOOST_TYPEOF_ENCODE_DECODE_HPP_INCLUDED

#include <streams_boost/mpl/deref.hpp>
#include <streams_boost/mpl/next.hpp>

#ifndef STREAMS_BOOST_TYPEOF_SUPPRESS_UNNAMED_NAMESPACE

#   define STREAMS_BOOST_TYPEOF_BEGIN_ENCODE_NS namespace { namespace streams_boost_typeof {
#   define STREAMS_BOOST_TYPEOF_END_ENCODE_NS }}
#   define STREAMS_BOOST_TYPEOF_ENCODE_NS_QUALIFIER streams_boost_typeof

#else

#   define STREAMS_BOOST_TYPEOF_BEGIN_ENCODE_NS namespace streams_boost { namespace type_of {
#   define STREAMS_BOOST_TYPEOF_END_ENCODE_NS }}
#   define STREAMS_BOOST_TYPEOF_ENCODE_NS_QUALIFIER streams_boost::type_of

#   define STREAMS_BOOST_TYPEOF_TEXT "unnamed namespace is off"
#   include <streams_boost/typeof/message.hpp>

#endif

STREAMS_BOOST_TYPEOF_BEGIN_ENCODE_NS

template<class V, class Type_Not_Registered_With_Typeof_System>
struct encode_type_impl;

template<class T, class Iter>
struct decode_type_impl
{
    typedef int type;  // MSVC ETI workaround
};

template<class T>
struct decode_nested_template_helper_impl;

STREAMS_BOOST_TYPEOF_END_ENCODE_NS

namespace streams_boost { namespace type_of {

    template<class V, class T>
    struct encode_type : STREAMS_BOOST_TYPEOF_ENCODE_NS_QUALIFIER::encode_type_impl<V, T>
    {};

    template<class Iter>
    struct decode_type : STREAMS_BOOST_TYPEOF_ENCODE_NS_QUALIFIER::decode_type_impl<
        typename Iter::type,
        typename Iter::next
    >
    {};
}}

#endif//STREAMS_BOOST_TYPEOF_ENCODE_DECODE_HPP_INCLUDED
