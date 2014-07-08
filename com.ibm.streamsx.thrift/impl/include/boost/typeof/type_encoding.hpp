// Copyright (C) 2004 Arkadiy Vertleyb
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_TYPE_ENCODING_HPP_INCLUDED
#define STREAMS_BOOST_TYPEOF_TYPE_ENCODING_HPP_INCLUDED

#define STREAMS_BOOST_TYPEOF_REGISTER_TYPE_IMPL(T, Id)                          \
                                                                        \
    template<class V> struct encode_type_impl<V, T >                    \
        : streams_boost::type_of::push_back<V, streams_boost::mpl::size_t<Id> >         \
    {};                                                                 \
    template<class Iter> struct decode_type_impl<streams_boost::mpl::size_t<Id>, Iter> \
    {                                                                   \
        typedef T type;                                                 \
        typedef Iter iter;                                              \
    };

#define STREAMS_BOOST_TYPEOF_REGISTER_TYPE_EXPLICIT_ID(Type, Id)                \
    STREAMS_BOOST_TYPEOF_BEGIN_ENCODE_NS                                        \
    STREAMS_BOOST_TYPEOF_REGISTER_TYPE_IMPL(Type, Id)                           \
    STREAMS_BOOST_TYPEOF_END_ENCODE_NS

#define STREAMS_BOOST_TYPEOF_REGISTER_TYPE(Type)                                \
    STREAMS_BOOST_TYPEOF_REGISTER_TYPE_EXPLICIT_ID(Type, STREAMS_BOOST_TYPEOF_UNIQUE_ID())

#endif//STREAMS_BOOST_TYPEOF_TYPE_ENCODING_HPP_INCLUDED
