
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION

#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

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

#else

#include <streams_boost/mpl/aux_/config/typeof.hpp>
#include <streams_boost/mpl/aux_/config/ctps.hpp>
#include <streams_boost/preprocessor/enum_params.hpp>
#include <streams_boost/preprocessor/dec.hpp>
#include <streams_boost/preprocessor/cat.hpp>

#define i_ STREAMS_BOOST_PP_FRAME_ITERATION(1)

#   define AUX778076_MAP_TAIL(map, i_, P) \
    STREAMS_BOOST_PP_CAT(map,i_)< \
          STREAMS_BOOST_PP_ENUM_PARAMS(i_, P) \
        > \
    /**/


#if defined(STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)

template<
      STREAMS_BOOST_PP_ENUM_PARAMS(i_, typename P)
    >
struct STREAMS_BOOST_PP_CAT(map,i_)
    : m_item<
          typename STREAMS_BOOST_PP_CAT(P,STREAMS_BOOST_PP_DEC(i_))::first
        , typename STREAMS_BOOST_PP_CAT(P,STREAMS_BOOST_PP_DEC(i_))::second
        , AUX778076_MAP_TAIL(map,STREAMS_BOOST_PP_DEC(i_),P)
        >
{
    typedef STREAMS_BOOST_PP_CAT(map,i_) type;
};

#else // "brute force" implementation

#   if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< typename Map>
struct m_at<Map,STREAMS_BOOST_PP_DEC(i_)>
{
    typedef typename Map::STREAMS_BOOST_PP_CAT(item,STREAMS_BOOST_PP_DEC(i_)) type;
};

template< typename Key, typename T, typename Base >
struct m_item<i_,Key,T,Base>
    : m_item_<Key,T,Base>
{
    typedef pair<Key,T> STREAMS_BOOST_PP_CAT(item,STREAMS_BOOST_PP_DEC(i_));
};

#   else

template<>
struct m_at_impl<STREAMS_BOOST_PP_DEC(i_)>
{
    template< typename Map > struct result_
    {
        typedef typename Map::STREAMS_BOOST_PP_CAT(item,STREAMS_BOOST_PP_DEC(i_)) type;
    };
};

template<>
struct m_item_impl<i_>
{
    template< typename Key, typename T, typename Base > struct result_
        : m_item_<Key,T,Base>
    {
        typedef pair<Key,T> STREAMS_BOOST_PP_CAT(item,STREAMS_BOOST_PP_DEC(i_));
    };
};

#   endif

template<
      STREAMS_BOOST_PP_ENUM_PARAMS(i_, typename P)
    >
struct STREAMS_BOOST_PP_CAT(map,i_)
    : m_item<
          i_
        , typename STREAMS_BOOST_PP_CAT(P,STREAMS_BOOST_PP_DEC(i_))::first
        , typename STREAMS_BOOST_PP_CAT(P,STREAMS_BOOST_PP_DEC(i_))::second
        , AUX778076_MAP_TAIL(map,STREAMS_BOOST_PP_DEC(i_),P)
        >
{
    typedef STREAMS_BOOST_PP_CAT(map,i_) type;
};

#endif // STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

#   undef AUX778076_MAP_TAIL

#undef i_

#endif // STREAMS_BOOST_PP_IS_ITERATING
