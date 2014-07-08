
#ifndef STREAMS_BOOST_MPL_VECTOR_AUX_AT_HPP_INCLUDED
#define STREAMS_BOOST_MPL_VECTOR_AUX_AT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: at.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/at_fwd.hpp>
#include <streams_boost/mpl/vector/aux_/tag.hpp>
#include <streams_boost/mpl/long.hpp>
#include <streams_boost/mpl/void.hpp>
#include <streams_boost/mpl/aux_/nttp_decl.hpp>
#include <streams_boost/mpl/aux_/type_wrapper.hpp>
#include <streams_boost/mpl/aux_/value_wknd.hpp>
#include <streams_boost/mpl/aux_/config/typeof.hpp>
#include <streams_boost/mpl/aux_/config/ctps.hpp>

namespace streams_boost { namespace mpl {

#if defined(STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)

template< typename Vector, long n_ >
struct v_at_impl
{
    typedef long_< (Vector::lower_bound_::value + n_) > index_;
    typedef __typeof__( Vector::item_(index_()) ) type;
};


template< typename Vector, long n_ >
struct v_at
    : aux::wrapped_type< typename v_at_impl<Vector,n_>::type >
{
};

template<>
struct at_impl< aux::vector_tag >
{
    template< typename Vector, typename N > struct apply
        : v_at<
              Vector
            , STREAMS_BOOST_MPL_AUX_VALUE_WKND(N)::value
            >
    {
    };
};

#else

#   if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
    && !defined(STREAMS_BOOST_MPL_CFG_NO_NONTYPE_TEMPLATE_PARTIAL_SPEC)

template< typename Vector, STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, n_) > struct v_at;

template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, n_) >
struct at_impl< aux::vector_tag<n_> >
{
    template< typename Vector, typename N > struct apply
#if !defined(__BORLANDC__)
        : v_at<
              Vector
            , STREAMS_BOOST_MPL_AUX_VALUE_WKND(N)::value
            >
    {
#else
    {
        typedef typename v_at<
              Vector
            , STREAMS_BOOST_MPL_AUX_VALUE_WKND(N)::value
            >::type type;
#endif
    };
};

#   else

namespace aux {

template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, n_) > struct v_at_impl
{
    template< typename V > struct result_;
};

// to work around ETI, etc.
template<> struct v_at_impl<-1>
{
    template< typename V > struct result_
    {
        typedef void_ type;
    };
};

} // namespace aux

template< typename T, STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, n_) >
struct v_at
    : aux::v_at_impl<n_>::template result_<T>
{
};

#   endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#endif // STREAMS_BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

}}

#endif // STREAMS_BOOST_MPL_VECTOR_AUX_AT_HPP_INCLUDED
