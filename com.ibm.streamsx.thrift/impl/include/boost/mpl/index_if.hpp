
#ifndef STREAMS_BOOST_MPL_INDEX_IF_HPP_INCLUDED
#define STREAMS_BOOST_MPL_INDEX_IF_HPP_INCLUDED

// Copyright Eric Friedman 2003
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: index_if.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/find_if_pred.hpp>
#include <streams_boost/mpl/begin_end.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/int.hpp>
#include <streams_boost/mpl/iter_fold_if.hpp>
#include <streams_boost/mpl/next.hpp>
#include <streams_boost/mpl/void.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/type_traits/is_same.hpp>

namespace streams_boost { namespace mpl {

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Predicate)
    >
struct index_if
{
    typedef typename iter_fold_if<
          Sequence
        , int_<0>
        , next<>
        , aux::find_if_pred<Predicate>
        >::type result_;

    typedef typename end<Sequence>::type not_found_;
    typedef typename first<result_>::type result_index_;
    typedef typename second<result_>::type result_iterator_;

    typedef typename if_<
          is_same< result_iterator_,not_found_ >
        , void_
        , result_index_
        >::type type;

    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2,index_if,(Sequence,Predicate))
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(2, index_if)

}}

#endif // STREAMS_BOOST_MPL_INDEX_IF_HPP_INCLUDED
