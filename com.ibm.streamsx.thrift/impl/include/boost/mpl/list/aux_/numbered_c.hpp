
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: numbered_c.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if defined(STREAMS_BOOST_PP_IS_ITERATING)

#include <streams_boost/preprocessor/enum_params.hpp>
#include <streams_boost/preprocessor/enum_shifted_params.hpp>
#include <streams_boost/preprocessor/dec.hpp>
#include <streams_boost/preprocessor/cat.hpp>

#define i STREAMS_BOOST_PP_FRAME_ITERATION(1)

#if i == 1

template<
      typename T
    , STREAMS_BOOST_PP_ENUM_PARAMS(i, T C)
    >
struct list1_c
    : l_item<
          long_<1>
        , integral_c<T,C0>
        , l_end
        >
{
    typedef list1_c type;
    typedef T value_type;
};

#else

#   define MPL_AUX_LIST_C_TAIL(list, i, C) \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(list,STREAMS_BOOST_PP_DEC(i)),_c)<T, \
      STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(i, C) \
    > \
    /**/
    
template<
      typename T
    , STREAMS_BOOST_PP_ENUM_PARAMS(i, T C)
    >
struct STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(list,i),_c)
    : l_item<
          long_<i>
        , integral_c<T,C0>
        , MPL_AUX_LIST_C_TAIL(list,i,C)
        >
{
    typedef STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(list,i),_c) type;
    typedef T value_type;
};

#   undef MPL_AUX_LIST_C_TAIL

#endif // i == 1

#undef i

#endif // STREAMS_BOOST_PP_IS_ITERATING
