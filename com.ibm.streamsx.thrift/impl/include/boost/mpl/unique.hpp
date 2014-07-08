
#ifndef STREAMS_BOOST_MPL_UNIQUE_HPP_INCLUDED
#define STREAMS_BOOST_MPL_UNIQUE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
// Copyright John R. Bandela 2000-2002
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: unique.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/fold.hpp>
#include <streams_boost/mpl/reverse_fold.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/and.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/pair.hpp>
#include <streams_boost/mpl/apply.hpp>
#include <streams_boost/mpl/aux_/inserter_algorithm.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_spec.hpp>

namespace streams_boost { namespace mpl {

namespace aux {

template< typename Predicate, typename Operation >
struct unique_op
{
    template< typename Pair, typename T > struct apply
    {
        typedef typename Pair::first seq_;
        typedef typename Pair::second prior_;
        typedef typename eval_if<
              and_< is_not_na<prior_>, apply2<Predicate,prior_,T> >
            , identity<seq_>
            , apply2<Operation,seq_,T>
            >::type new_seq_;

        typedef pair<new_seq_,T> type;
    };
};

template<
      typename Sequence
    , typename Predicate
    , typename Inserter
    >
struct unique_impl
    : first< typename fold<
          Sequence
        , pair< typename Inserter::state,na >
        , protect< aux::unique_op<Predicate,typename Inserter::operation> >
        >::type >
{
};

template<
      typename Sequence
    , typename Predicate
    , typename Inserter
    >
struct reverse_unique_impl
    : first< typename reverse_fold<
          Sequence
        , pair< typename Inserter::state,na >
        , protect< aux::unique_op<Predicate,typename Inserter::operation> >
        >::type >
{
};

} // namespace aux

STREAMS_BOOST_MPL_AUX_INSERTER_ALGORITHM_DEF(3, unique)

}}

#endif // STREAMS_BOOST_MPL_UNIQUE_HPP_INCLUDED
