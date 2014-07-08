//-----------------------------------------------------------------------------
// streams_boost detail/templated_streams.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_DETAIL_TEMPLATED_STREAMS_HPP
#define STREAMS_BOOST_DETAIL_TEMPLATED_STREAMS_HPP

#include "streams_boost/config.hpp"

///////////////////////////////////////////////////////////////////////////////
// (detail) STREAMS_BOOST_TEMPLATED_STREAM_* macros
//
// Provides workaround platforms without stream class templates.
//

#if !defined(STREAMS_BOOST_NO_STD_LOCALE)

#define STREAMS_BOOST_TEMPLATED_STREAM_TEMPLATE(E,T) \
    template < typename E , typename T >

#define STREAMS_BOOST_TEMPLATED_STREAM_TEMPLATE_ALLOC(E,T,A) \
    template < typename E , typename T , typename A >

#define STREAMS_BOOST_TEMPLATED_STREAM_ARGS(E,T) \
    typename E , typename T 

#define STREAMS_BOOST_TEMPLATED_STREAM_ARGS_ALLOC(E,T,A) \
    typename E , typename T , typename A 

#define STREAMS_BOOST_TEMPLATED_STREAM_COMMA        ,

#define STREAMS_BOOST_TEMPLATED_STREAM_ELEM(E)      E
#define STREAMS_BOOST_TEMPLATED_STREAM_TRAITS(T)    T
#define STREAMS_BOOST_TEMPLATED_STREAM_ALLOC(A)     A

#define STREAMS_BOOST_TEMPLATED_STREAM(X,E,T) \
    STREAMS_BOOST_JOIN(std::basic_,X)< E , T >

#define STREAMS_BOOST_TEMPLATED_STREAM_WITH_ALLOC(X,E,T,A) \
    STREAMS_BOOST_JOIN(std::basic_,X)< E , T , A >

#else // defined(STREAMS_BOOST_NO_STD_LOCALE)

#define STREAMS_BOOST_TEMPLATED_STREAM_TEMPLATE(E,T) /**/

#define STREAMS_BOOST_TEMPLATED_STREAM_TEMPLATE_ALLOC(E,T,A) /**/

#define STREAMS_BOOST_TEMPLATED_STREAM_ARGS(E,T) /**/

#define STREAMS_BOOST_TEMPLATED_STREAM_ARGS_ALLOC(E,T,A) /**/

#define STREAMS_BOOST_TEMPLATED_STREAM_COMMA        /**/

#define STREAMS_BOOST_TEMPLATED_STREAM_ELEM(E)      char
#define STREAMS_BOOST_TEMPLATED_STREAM_TRAITS(T)    std::char_traits<char>
#define STREAMS_BOOST_TEMPLATED_STREAM_ALLOC(A)     std::allocator<char>

#define STREAMS_BOOST_TEMPLATED_STREAM(X,E,T) \
    std::X

#define STREAMS_BOOST_TEMPLATED_STREAM_WITH_ALLOC(X,E,T,A) \
    std::X

#endif // STREAMS_BOOST_NO_STD_LOCALE

#endif // STREAMS_BOOST_DETAIL_TEMPLATED_STREAMS_HPP
