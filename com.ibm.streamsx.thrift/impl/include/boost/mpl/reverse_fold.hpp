
#ifndef STREAMS_BOOST_MPL_REVERSE_FOLD_HPP_INCLUDED
#define STREAMS_BOOST_MPL_REVERSE_FOLD_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
// Copyright David Abrahams 2001-2002
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: reverse_fold.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/begin_end.hpp>
#include <streams_boost/mpl/O1_size.hpp>
#include <streams_boost/mpl/arg.hpp>
#include <streams_boost/mpl/aux_/reverse_fold_impl.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>

namespace streams_boost { namespace mpl {

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(State)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(BackwardOp)
    , typename ForwardOp = arg<1>
    >
struct reverse_fold
{
    typedef typename aux::reverse_fold_impl<
          ::streams_boost::mpl::O1_size<Sequence>::value
        , typename begin<Sequence>::type
        , typename end<Sequence>::type
        , State
        , BackwardOp
        , ForwardOp
        >::state type;

    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(3,reverse_fold,(Sequence,State,BackwardOp))
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(3, reverse_fold)

}}

#endif // STREAMS_BOOST_MPL_REVERSE_FOLD_HPP_INCLUDED
