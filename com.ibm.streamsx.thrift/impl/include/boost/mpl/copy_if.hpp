
#ifndef STREAMS_BOOST_MPL_COPY_IF_HPP_INCLUDED
#define STREAMS_BOOST_MPL_COPY_IF_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: copy_if.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/fold.hpp>
#include <streams_boost/mpl/reverse_fold.hpp>
#include <streams_boost/mpl/apply.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/protect.hpp>
#include <streams_boost/mpl/aux_/inserter_algorithm.hpp>
#include <streams_boost/mpl/aux_/config/forwarding.hpp>

namespace streams_boost { namespace mpl {

namespace aux {

template<
      typename Operation
    , typename Predicate
    >
struct copy_if_op
{
    template< typename Sequence, typename T > struct apply
#if !defined(STREAMS_BOOST_MPL_CFG_NO_NESTED_FORWARDING)
        : eval_if<
              typename apply1<Predicate,T>::type
            , apply2<Operation,Sequence,T>
            , identity<Sequence>
            >
    {
#else
    {
        typedef typename eval_if<
              typename apply1<Predicate,T>::type
            , apply2<Operation,Sequence,T>
            , identity<Sequence>
            >::type type;
#endif
    };
};

template<
      typename Sequence
    , typename Predicate
    , typename Inserter
    >
struct copy_if_impl
    : fold<
          Sequence
        , typename Inserter::state
        , protect< aux::copy_if_op<
              typename Inserter::operation
            , Predicate
            > >
        >
{
};

template<
      typename Sequence
    , typename Predicate
    , typename Inserter
    >
struct reverse_copy_if_impl
    : reverse_fold<
          Sequence
        , typename Inserter::state
        , protect< aux::copy_if_op<
              typename Inserter::operation
            , Predicate
            > >
        >
{
};

} // namespace aux

STREAMS_BOOST_MPL_AUX_INSERTER_ALGORITHM_DEF(3, copy_if)

}}

#endif // STREAMS_BOOST_MPL_COPY_IF_HPP_INCLUDED
