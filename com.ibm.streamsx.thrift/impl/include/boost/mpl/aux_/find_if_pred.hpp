
#ifndef STREAMS_BOOST_MPL_AUX_FIND_IF_PRED_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_FIND_IF_PRED_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
// Copyright Eric Friedman 2002
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

#include <streams_boost/mpl/aux_/iter_apply.hpp>
#include <streams_boost/mpl/not.hpp>

namespace streams_boost { namespace mpl { namespace aux {

template< typename Predicate >
struct find_if_pred
{
    template< typename Iterator >
    struct apply
    {
        typedef not_< aux::iter_apply1<Predicate,Iterator> > type;
    };
};

}}}

#endif // STREAMS_BOOST_MPL_AUX_FIND_IF_PRED_HPP_INCLUDED
