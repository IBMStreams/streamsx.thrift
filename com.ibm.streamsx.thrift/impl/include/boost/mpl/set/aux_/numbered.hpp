
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION

#if defined(STREAMS_BOOST_PP_IS_ITERATING)

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: numbered.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/preprocessor/enum_params.hpp>
#include <streams_boost/preprocessor/dec.hpp>
#include <streams_boost/preprocessor/cat.hpp>

#define i_ STREAMS_BOOST_PP_FRAME_ITERATION(1)

#   define AUX778076_SET_TAIL(set, i_, T) \
    typename STREAMS_BOOST_PP_CAT(set,i_)< \
          STREAMS_BOOST_PP_ENUM_PARAMS(i_, T) \
        >::item_                           \
    /**/

#if i_ > 0
template<
      STREAMS_BOOST_PP_ENUM_PARAMS(i_, typename T)
    >
struct STREAMS_BOOST_PP_CAT(set,i_)
    : s_item<
          STREAMS_BOOST_PP_CAT(T,STREAMS_BOOST_PP_DEC(i_))
        , AUX778076_SET_TAIL(set,STREAMS_BOOST_PP_DEC(i_),T)
        >
{
    typedef STREAMS_BOOST_PP_CAT(set,i_) type;
};
#endif

#   undef AUX778076_SET_TAIL

#undef i_

#endif // STREAMS_BOOST_PP_IS_ITERATING
