
#ifndef STREAMS_BOOST_MPL_UPPER_BOUND_HPP_INCLUDED
#define STREAMS_BOOST_MPL_UPPER_BOUND_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: upper_bound.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/less.hpp>
#include <streams_boost/mpl/lambda.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x610))
#   define STREAMS_BOOST_MPL_CFG_STRIPPED_DOWN_UPPER_BOUND_IMPL
#endif

#if !defined(STREAMS_BOOST_MPL_CFG_STRIPPED_DOWN_UPPER_BOUND_IMPL)
#   include <streams_boost/mpl/minus.hpp>
#   include <streams_boost/mpl/divides.hpp>
#   include <streams_boost/mpl/size.hpp>
#   include <streams_boost/mpl/advance.hpp>
#   include <streams_boost/mpl/begin_end.hpp>
#   include <streams_boost/mpl/long.hpp>
#   include <streams_boost/mpl/eval_if.hpp>
#   include <streams_boost/mpl/prior.hpp>
#   include <streams_boost/mpl/deref.hpp>
#   include <streams_boost/mpl/apply.hpp>
#   include <streams_boost/mpl/aux_/value_wknd.hpp>
#else
#   include <streams_boost/mpl/find.hpp>
#   include <streams_boost/mpl/bind.hpp>
#endif

#include <streams_boost/config.hpp>

namespace streams_boost { namespace mpl {

#if defined(STREAMS_BOOST_MPL_CFG_STRIPPED_DOWN_UPPER_BOUND_IMPL)

// agurt 23/oct/02: has a wrong complexity etc., but at least it works;
// feel free to contribute a better implementation!
template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(T)
    , typename Predicate = less<>
    , typename pred_ = typename lambda<Predicate>::type
    >
struct upper_bound
    : find_if< Sequence, bind2<pred_,T,_> >
{
};

#else

namespace aux {

template<
      typename Distance
    , typename Predicate
    , typename T
    , typename DeferredIterator
    >
struct upper_bound_step_impl;

template< 
      typename Distance
    , typename Predicate
    , typename T
    , typename DeferredIterator
    >
struct upper_bound_step
{
    typedef typename eval_if<
          Distance
        , upper_bound_step_impl<Distance,Predicate,T,DeferredIterator>
        , DeferredIterator
        >::type type;
};
    
template<
      typename Distance
    , typename Predicate
    , typename T
    , typename DeferredIterator
    >
struct upper_bound_step_impl
{
    typedef typename divides< Distance, long_<2> >::type offset_;
    typedef typename DeferredIterator::type iter_;
    typedef typename advance< iter_,offset_ >::type middle_;
    typedef typename apply2<
              Predicate
            , T
            , typename deref<middle_>::type
            >::type cond_;

    typedef typename prior< minus< Distance, offset_ > >::type step_;
    typedef upper_bound_step< offset_,Predicate,T,DeferredIterator > step_forward_;
    typedef upper_bound_step< step_,Predicate,T,next<middle_> > step_backward_;
    typedef typename eval_if<
          cond_
        , step_forward_
        , step_backward_
        >::type type;
};

} // namespace aux

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(T)
    , typename Predicate = less<>
    >
struct upper_bound
{
 private:
    typedef typename lambda<Predicate>::type pred_;
    typedef typename size<Sequence>::type size_;

 public:
    typedef typename aux::upper_bound_step<
        size_,pred_,T,begin<Sequence>
        >::type type;
};

#endif // STREAMS_BOOST_MPL_CFG_STRIPPED_DOWN_UPPER_BOUND_IMPL

STREAMS_BOOST_MPL_AUX_NA_SPEC(2, upper_bound)

}}

#endif // STREAMS_BOOST_MPL_UPPER_BOUND_HPP_INCLUDED
