
#ifndef STREAMS_BOOST_MPL_AUX_FILTER_ITER_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_FILTER_ITER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: filter_iter.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/find_if.hpp>
#include <streams_boost/mpl/iterator_range.hpp>
#include <streams_boost/mpl/iterator_tags.hpp>
#include <streams_boost/mpl/deref.hpp>
#include <streams_boost/mpl/aux_/lambda_spec.hpp>
#include <streams_boost/mpl/aux_/config/ctps.hpp>
#include <streams_boost/type_traits/is_same.hpp>

namespace streams_boost { namespace mpl {

namespace aux {

template<
      typename Iterator
    , typename LastIterator
    , typename Predicate
    > 
struct filter_iter;

template<
      typename Iterator
    , typename LastIterator
    , typename Predicate
    >
struct next_filter_iter
{
    typedef typename find_if<
          iterator_range<Iterator,LastIterator>
        , Predicate
        >::type base_iter_;
 
    typedef filter_iter<base_iter_,LastIterator,Predicate> type;
};

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template<
      typename Iterator
    , typename LastIterator
    , typename Predicate
    >
struct filter_iter
{
    typedef Iterator base;
    typedef forward_iterator_tag category;
    typedef typename aux::next_filter_iter<
          typename mpl::next<base>::type
        , LastIterator
        , Predicate
        >::type next;
    
    typedef typename deref<base>::type type;
};

template<
      typename LastIterator
    , typename Predicate
    >
struct filter_iter< LastIterator,LastIterator,Predicate >
{
    typedef LastIterator base;
    typedef forward_iterator_tag category;
};

#else

template< bool >
struct filter_iter_impl
{
    template<
          typename Iterator
        , typename LastIterator
        , typename Predicate
        >
    struct result_
    {
        typedef Iterator base;
        typedef forward_iterator_tag category;
        typedef typename next_filter_iter<
              typename mpl::next<Iterator>::type
            , LastIterator
            , Predicate
            >::type next;
        
        typedef typename deref<base>::type type;
    };
};

template<>
struct filter_iter_impl< true >
{
    template<
          typename Iterator
        , typename LastIterator
        , typename Predicate
        >
    struct result_
    {
        typedef Iterator base;
        typedef forward_iterator_tag category;
    };
};

template<
      typename Iterator
    , typename LastIterator
    , typename Predicate
    >
struct filter_iter
    : filter_iter_impl<
          ::streams_boost::is_same<Iterator,LastIterator>::value
        >::template result_< Iterator,LastIterator,Predicate >
{
};

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

} // namespace aux

STREAMS_BOOST_MPL_AUX_PASS_THROUGH_LAMBDA_SPEC(3, aux::filter_iter)

}}

#endif // STREAMS_BOOST_MPL_AUX_FILTER_ITER_HPP_INCLUDED
