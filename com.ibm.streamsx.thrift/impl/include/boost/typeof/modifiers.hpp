// Copyright (C) 2004 Arkadiy Vertleyb
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_MODIFIERS_HPP_INCLUDED
#define STREAMS_BOOST_TYPEOF_MODIFIERS_HPP_INCLUDED

#include <streams_boost/typeof/encode_decode.hpp>
#include <streams_boost/preprocessor/facilities/identity.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

// modifiers

#define STREAMS_BOOST_TYPEOF_modifier_support(ID, Fun)\
    template<class V, class T> struct encode_type_impl<V, Fun(T)>\
    {\
        typedef\
            typename streams_boost::type_of::encode_type<\
            typename streams_boost::type_of::push_back<\
            V\
            , streams_boost::mpl::size_t<ID> >::type\
            , T>::type\
            type;\
    };\
    template<class Iter> struct decode_type_impl<streams_boost::mpl::size_t<ID>, Iter>\
    {\
        typedef streams_boost::type_of::decode_type<Iter> d1;\
        typedef Fun(typename d1::type) type;\
        typedef typename d1::iter iter;\
    }


#define STREAMS_BOOST_TYPEOF_const_fun(T) const T
#define STREAMS_BOOST_TYPEOF_volatile_fun(T) volatile T
#define STREAMS_BOOST_TYPEOF_volatile_const_fun(T) volatile const T
#define STREAMS_BOOST_TYPEOF_pointer_fun(T) T*
#define STREAMS_BOOST_TYPEOF_reference_fun(T) T&

#if defined(__BORLANDC__) && (__BORLANDC__ < 0x600)
//Borland incorrectly handles T const, T const volatile and T volatile.
//It drops the decoration no matter what, so we need to try to handle T* const etc. without loosing the top modifier.
#define STREAMS_BOOST_TYPEOF_const_pointer_fun(T) T const *
#define STREAMS_BOOST_TYPEOF_const_reference_fun(T) T const &
#define STREAMS_BOOST_TYPEOF_volatile_pointer_fun(T) T volatile*
#define STREAMS_BOOST_TYPEOF_volatile_reference_fun(T) T volatile&
#define STREAMS_BOOST_TYPEOF_volatile_const_pointer_fun(T) T volatile const *
#define STREAMS_BOOST_TYPEOF_volatile_const_reference_fun(T) T volatile const &
#endif

STREAMS_BOOST_TYPEOF_BEGIN_ENCODE_NS

STREAMS_BOOST_TYPEOF_modifier_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_TYPEOF_const_fun);
STREAMS_BOOST_TYPEOF_modifier_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_TYPEOF_volatile_fun);
STREAMS_BOOST_TYPEOF_modifier_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_TYPEOF_volatile_const_fun);
STREAMS_BOOST_TYPEOF_modifier_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_TYPEOF_pointer_fun);
STREAMS_BOOST_TYPEOF_modifier_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_TYPEOF_reference_fun);

#if defined(__BORLANDC__) && (__BORLANDC__ < 0x600)
STREAMS_BOOST_TYPEOF_modifier_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_TYPEOF_const_pointer_fun);
STREAMS_BOOST_TYPEOF_modifier_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_TYPEOF_const_reference_fun);
STREAMS_BOOST_TYPEOF_modifier_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_TYPEOF_volatile_pointer_fun);
STREAMS_BOOST_TYPEOF_modifier_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_TYPEOF_volatile_reference_fun);
STREAMS_BOOST_TYPEOF_modifier_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_TYPEOF_volatile_const_pointer_fun);
STREAMS_BOOST_TYPEOF_modifier_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_TYPEOF_volatile_const_reference_fun);
#endif

STREAMS_BOOST_TYPEOF_END_ENCODE_NS

#undef STREAMS_BOOST_TYPEOF_modifier_support
#undef STREAMS_BOOST_TYPEOF_const_fun
#undef STREAMS_BOOST_TYPEOF_volatile_fun
#undef STREAMS_BOOST_TYPEOF_volatile_const_fun
#undef STREAMS_BOOST_TYPEOF_pointer_fun
#undef STREAMS_BOOST_TYPEOF_reference_fun

#if defined(__BORLANDC__) && (__BORLANDC__ < 0x600)
#undef STREAMS_BOOST_TYPEOF_const_pointer_fun
#undef STREAMS_BOOST_TYPEOF_const_reference_fun
#undef STREAMS_BOOST_TYPEOF_volatile_pointer_fun
#undef STREAMS_BOOST_TYPEOF_volatile_reference_fun
#undef STREAMS_BOOST_TYPEOF_volatile_const_pointer_fun
#undef STREAMS_BOOST_TYPEOF_volatile_const_reference_fun
#endif

// arrays

#define STREAMS_BOOST_TYPEOF_array_support(ID, Qualifier)\
    template<class V, class T, int N>\
    struct encode_type_impl<V, Qualifier() T[N]>\
    {\
        typedef\
            typename streams_boost::type_of::encode_type<\
            typename streams_boost::type_of::push_back<\
            typename streams_boost::type_of::push_back<\
            V\
            , streams_boost::mpl::size_t<ID> >::type\
            , streams_boost::mpl::size_t<N> >::type\
            , T>::type\
        type;\
    };\
    template<class Iter>\
    struct decode_type_impl<streams_boost::mpl::size_t<ID>, Iter>\
    {\
        enum{n = Iter::type::value};\
        typedef streams_boost::type_of::decode_type<typename Iter::next> d;\
        typedef typename d::type Qualifier() type[n];\
        typedef typename d::iter iter;\
    }

STREAMS_BOOST_TYPEOF_BEGIN_ENCODE_NS

STREAMS_BOOST_TYPEOF_array_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_PP_EMPTY);
STREAMS_BOOST_TYPEOF_array_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_PP_IDENTITY(const));
STREAMS_BOOST_TYPEOF_array_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_PP_IDENTITY(volatile));
STREAMS_BOOST_TYPEOF_array_support(STREAMS_BOOST_TYPEOF_UNIQUE_ID(), STREAMS_BOOST_PP_IDENTITY(volatile const));
STREAMS_BOOST_TYPEOF_END_ENCODE_NS

#undef STREAMS_BOOST_TYPEOF_array_support

#endif//STREAMS_BOOST_TYPEOF_MODIFIERS_HPP_INCLUDED
