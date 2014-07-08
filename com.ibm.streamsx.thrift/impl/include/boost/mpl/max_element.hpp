
#ifndef STREAMS_BOOST_MPL_MAX_ELEMENT_HPP_INCLUDED
#define STREAMS_BOOST_MPL_MAX_ELEMENT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: max_element.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/less.hpp>
#include <streams_boost/mpl/iter_fold.hpp>
#include <streams_boost/mpl/begin_end.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/deref.hpp>
#include <streams_boost/mpl/apply.hpp>
#include <streams_boost/mpl/aux_/common_name_wknd.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>

namespace streams_boost { namespace mpl {

STREAMS_BOOST_MPL_AUX_COMMON_NAME_WKND(max_element)

namespace aux {

template< typename Predicate >
struct select_max
{
    template< typename OldIterator, typename Iterator >
    struct apply
    {
        typedef typename apply2<
              Predicate
            , typename deref<OldIterator>::type
            , typename deref<Iterator>::type
            >::type condition_;

        typedef typename if_<
              condition_
            , Iterator
            , OldIterator
            >::type type;
    };
};

} // namespace aux 


template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename Predicate = less<_,_>
    >
struct max_element
    : iter_fold<
          Sequence
        , typename begin<Sequence>::type
        , protect< aux::select_max<Predicate> >
        >
{
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(1, max_element)

}}

#endif // STREAMS_BOOST_MPL_MAX_ELEMENT_HPP_INCLUDED
