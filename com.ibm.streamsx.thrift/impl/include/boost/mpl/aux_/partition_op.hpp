
#ifndef STREAMS_BOOST_MPL_AUX_PARTITION_OP_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_PARTITION_OP_HPP_INCLUDED

// Copyright Eric Friedman 2003
// Copyright Aleksey Gurtovoy 2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: partition_op.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/apply.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/pair.hpp>
#include <streams_boost/mpl/aux_/lambda_spec.hpp>

namespace streams_boost { namespace mpl { 

namespace aux {

template< typename Pred, typename In1Op, typename In2Op >
struct partition_op
{
    template< typename State, typename T >
    struct apply
    {
        typedef typename State::first first_;
        typedef typename State::second second_;
        typedef typename apply1< Pred,T >::type pred_;

        typedef typename eval_if<
              pred_
            , apply2<In1Op,first_,T>
            , apply2<In2Op,second_,T>
            >::type result_;

        typedef typename if_<
              pred_
            , pair< result_,second_ >
            , pair< first_,result_ >
            >::type type;
    };
};

} // namespace aux

STREAMS_BOOST_MPL_AUX_PASS_THROUGH_LAMBDA_SPEC(3, aux::partition_op)

}}

#endif // STREAMS_BOOST_MPL_AUX_PARTITION_OP_HPP_INCLUDED
