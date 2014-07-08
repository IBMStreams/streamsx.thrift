
#ifndef STREAMS_BOOST_MPL_EQUAL_HPP_INCLUDED
#define STREAMS_BOOST_MPL_EQUAL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: equal.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/iter_fold_if_impl.hpp>
#include <streams_boost/mpl/aux_/iter_apply.hpp>
#include <streams_boost/mpl/and.hpp>
#include <streams_boost/mpl/not.hpp>
#include <streams_boost/mpl/begin_end.hpp>
#include <streams_boost/mpl/next.hpp>
#include <streams_boost/mpl/always.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/lambda.hpp>
#include <streams_boost/mpl/bind.hpp>
#include <streams_boost/mpl/apply.hpp>
#include <streams_boost/mpl/void.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/mpl/aux_/msvc_eti_base.hpp>

#include <streams_boost/type_traits/is_same.hpp>

namespace streams_boost { namespace mpl {

namespace aux {

template<
      typename Predicate
    , typename LastIterator1
    , typename LastIterator2
    >
struct equal_pred
{
    template<
          typename Iterator2
        , typename Iterator1
        >
    struct apply
    {
        typedef typename and_< 
              not_< is_same<Iterator1,LastIterator1> >
            , not_< is_same<Iterator2,LastIterator2> >
            , aux::iter_apply2<Predicate,Iterator1,Iterator2>
            >::type type;
    };
};

template<
      typename Sequence1
    , typename Sequence2
    , typename Predicate
    >
struct equal_impl
{
    typedef typename begin<Sequence1>::type first1_;
    typedef typename begin<Sequence2>::type first2_;
    typedef typename end<Sequence1>::type last1_;
    typedef typename end<Sequence2>::type last2_;

    typedef aux::iter_fold_if_impl<
          first1_
        , first2_
        , next<>
        , protect< aux::equal_pred<Predicate,last1_,last2_> >
        , void_
        , always<false_>
        > fold_;

    typedef typename fold_::iterator iter1_;
    typedef typename fold_::state iter2_;
    typedef and_<
          is_same<iter1_,last1_>
        , is_same<iter2_,last2_>
        > result_;

    typedef typename result_::type type;
};


} // namespace aux


template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Sequence1)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Sequence2)
    , typename Predicate = is_same<_,_>
    >
struct equal
    : aux::msvc_eti_base< 
          typename aux::equal_impl<Sequence1,Sequence2,Predicate>::type
        >::type
{
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2,equal,(Sequence1,Sequence2))
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(2, equal)

}}

#endif // STREAMS_BOOST_MPL_EQUAL_HPP_INCLUDED