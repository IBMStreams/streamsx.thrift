// Copyright (C) 2004 Arkadiy Vertleyb
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#include <streams_boost/typeof/encode_decode_params.hpp>

#define n STREAMS_BOOST_PP_ITERATION()

// function pointers

template<class V, class R STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(n, class P)>
struct encode_type_impl<V, R(*)(STREAMS_BOOST_PP_ENUM_PARAMS(n, P))>
{
    typedef R STREAMS_BOOST_PP_CAT(P, n);
    typedef STREAMS_BOOST_TYPEOF_ENCODE_PARAMS(STREAMS_BOOST_PP_INC(n), FUN_PTR_ID + n) type;
};

template<class Iter>
struct decode_type_impl<streams_boost::mpl::size_t<FUN_PTR_ID + n>, Iter>
{
    typedef Iter iter0;
    STREAMS_BOOST_TYPEOF_DECODE_PARAMS(STREAMS_BOOST_PP_INC(n))
    typedef STREAMS_BOOST_PP_CAT(p, n)(*type)(STREAMS_BOOST_PP_ENUM_PARAMS(n, p));
    typedef STREAMS_BOOST_PP_CAT(iter, STREAMS_BOOST_PP_INC(n)) iter;
};

#ifndef STREAMS_BOOST_TYPEOF_NO_FUNCTION_TYPES

    // function references

    template<class V, class R STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(n, class P)>
    struct encode_type_impl<V, R(&)(STREAMS_BOOST_PP_ENUM_PARAMS(n, P))>
    {
        typedef R STREAMS_BOOST_PP_CAT(P, n);
        typedef STREAMS_BOOST_TYPEOF_ENCODE_PARAMS(STREAMS_BOOST_PP_INC(n), FUN_REF_ID + n) type;
    };

    template<class Iter>
    struct decode_type_impl<streams_boost::mpl::size_t<FUN_REF_ID + n>, Iter>
    {
        typedef Iter iter0;
        STREAMS_BOOST_TYPEOF_DECODE_PARAMS(STREAMS_BOOST_PP_INC(n))
        typedef STREAMS_BOOST_PP_CAT(p, n)(&type)(STREAMS_BOOST_PP_ENUM_PARAMS(n, p));
        typedef STREAMS_BOOST_PP_CAT(iter, STREAMS_BOOST_PP_INC(n)) iter;
    };

    // functions

    template<class V, class R STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(n, class P)>
    struct encode_type_impl<V, R(STREAMS_BOOST_PP_ENUM_PARAMS(n, P))>
    {
        typedef R STREAMS_BOOST_PP_CAT(P, n);
        typedef STREAMS_BOOST_TYPEOF_ENCODE_PARAMS(STREAMS_BOOST_PP_INC(n), FUN_ID + n) type;
    };

    template<class Iter>
    struct decode_type_impl<streams_boost::mpl::size_t<FUN_ID + n>, Iter>
    {
        typedef Iter iter0;
        STREAMS_BOOST_TYPEOF_DECODE_PARAMS(STREAMS_BOOST_PP_INC(n))
        typedef STREAMS_BOOST_PP_CAT(p, n)(type)(STREAMS_BOOST_PP_ENUM_PARAMS(n, p));
        typedef STREAMS_BOOST_PP_CAT(iter, STREAMS_BOOST_PP_INC(n)) iter;
    };

#endif//STREAMS_BOOST_TYPEOF_NO_FUNCTION_TYPES

#ifndef STREAMS_BOOST_TYPEOF_NO_MEMBER_FUNCTION_TYPES
// member functions

#define STREAMS_BOOST_TYPEOF_qualifier
#define STREAMS_BOOST_TYPEOF_id MEM_FUN_ID
#include <streams_boost/typeof/register_mem_functions.hpp>

#define STREAMS_BOOST_TYPEOF_qualifier const
#define STREAMS_BOOST_TYPEOF_id CONST_MEM_FUN_ID
#include <streams_boost/typeof/register_mem_functions.hpp>

#define STREAMS_BOOST_TYPEOF_qualifier volatile
#define STREAMS_BOOST_TYPEOF_id VOLATILE_MEM_FUN_ID
#include <streams_boost/typeof/register_mem_functions.hpp>

#define STREAMS_BOOST_TYPEOF_qualifier volatile const
#define STREAMS_BOOST_TYPEOF_id VOLATILE_CONST_MEM_FUN_ID
#include <streams_boost/typeof/register_mem_functions.hpp>

#undef n
#endif
