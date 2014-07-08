// Copyright (C) 2004 Arkadiy Vertleyb
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#include <streams_boost/typeof/encode_decode_params.hpp>

// member functions

template<class V, class T, class R STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(n, class P)> 
struct encode_type_impl<V, R(T::*)(STREAMS_BOOST_PP_ENUM_PARAMS(n, P)) STREAMS_BOOST_TYPEOF_qualifier>
{
    typedef R STREAMS_BOOST_PP_CAT(P, n);
    typedef T STREAMS_BOOST_PP_CAT(P, STREAMS_BOOST_PP_INC(n));
    typedef STREAMS_BOOST_TYPEOF_ENCODE_PARAMS(STREAMS_BOOST_PP_ADD(n, 2), STREAMS_BOOST_TYPEOF_id + n) type;
};

template<class Iter>
struct decode_type_impl<streams_boost::mpl::size_t<STREAMS_BOOST_TYPEOF_id + n>, Iter>
{
    typedef Iter iter0;
    STREAMS_BOOST_TYPEOF_DECODE_PARAMS(STREAMS_BOOST_PP_ADD(n, 2))
    template<class T> struct workaround{
        typedef STREAMS_BOOST_PP_CAT(p, n)(T::*type)(STREAMS_BOOST_PP_ENUM_PARAMS(n, p)) STREAMS_BOOST_TYPEOF_qualifier;
    };
    typedef typename workaround<STREAMS_BOOST_PP_CAT(p, STREAMS_BOOST_PP_INC(n))>::type type;
    typedef STREAMS_BOOST_PP_CAT(iter, STREAMS_BOOST_PP_ADD(n, 2)) iter;
};

// undef parameters

#undef STREAMS_BOOST_TYPEOF_id
#undef STREAMS_BOOST_TYPEOF_qualifier
