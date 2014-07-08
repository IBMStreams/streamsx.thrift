
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

///// header body

#ifndef STREAMS_BOOST_MPL_INHERIT_HPP_INCLUDED
#define STREAMS_BOOST_MPL_INHERIT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: inherit.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <streams_boost/mpl/empty_base.hpp>
#   include <streams_boost/mpl/aux_/na_spec.hpp>
#   include <streams_boost/mpl/aux_/lambda_support.hpp>
#endif

#include <streams_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)

#   define STREAMS_BOOST_MPL_PREPROCESSED_HEADER inherit.hpp
#   include <streams_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <streams_boost/mpl/limits/arity.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/params.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/default_params.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/enum.hpp>
#   include <streams_boost/mpl/aux_/config/ctps.hpp>
#   include <streams_boost/mpl/aux_/config/dtp.hpp>

#   include <streams_boost/preprocessor/iterate.hpp>
#   include <streams_boost/preprocessor/dec.hpp>
#   include <streams_boost/preprocessor/cat.hpp>

namespace streams_boost { namespace mpl {

// 'inherit<T1,T2,..,Tn>' metafunction; returns an unspecified class type
// produced by public derivation from all metafunction's parameters 
// (T1,T2,..,Tn), except the parameters of 'empty_base' class type; 
// regardless the position and number of 'empty_base' parameters in the 
// metafunction's argument list, derivation from them is always a no-op;
// for instance:
//      inherit<her>::type == her
//      inherit<her,my>::type == struct unspecified : her, my {};
//      inherit<empty_base,her>::type == her
//      inherit<empty_base,her,empty_base,empty_base>::type == her
//      inherit<her,empty_base,my>::type == struct unspecified : her, my {};
//      inherit<empty_base,empty_base>::type == empty_base

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< 
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(T1)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(T2)
    > 
struct inherit2
    : T1, T2
{
    typedef inherit2 type;
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2, inherit2, (T1,T2))
};

template< typename T1 > 
struct inherit2<T1,empty_base>
{
    typedef T1 type;
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(2, inherit2, (T1,empty_base))
};

template< typename T2 > 
struct inherit2<empty_base,T2>
{
    typedef T2 type;
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(2, inherit2, (empty_base,T2))
};

// needed to disambiguate the previous two in case when both 
// T1 and T2 == empty_base
template<> 
struct inherit2<empty_base,empty_base>
{
    typedef empty_base type;
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(2, inherit2, (empty_base,empty_base))
};

#else

namespace aux {

template< bool C1, bool C2 >
struct inherit2_impl
{
    template< typename Derived, typename T1, typename T2 > struct result_ 
        : T1, T2
    {
        typedef Derived type_;
    };
};

template<>
struct inherit2_impl<false,true>
{
    template< typename Derived, typename T1, typename T2 > struct result_
        : T1
    {
        typedef T1 type_;
    };
};

template<>
struct inherit2_impl<true,false>
{
    template< typename Derived, typename T1, typename T2 > struct result_
        : T2 
    {
        typedef T2 type_;
    };
};

template<>
struct inherit2_impl<true,true>
{
    template< typename Derived, typename T1, typename T2 > struct result_
    {
        typedef T1 type_;
    };
};

} // namespace aux

template< 
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(T1)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(T2)
    > 
struct inherit2
    : aux::inherit2_impl<
          is_empty_base<T1>::value
        , is_empty_base<T2>::value
        >::template result_< inherit2<T1,T2>,T1,T2 >
{
    typedef typename inherit2::type_ type;
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2, inherit2, (T1,T2))
};

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

STREAMS_BOOST_MPL_AUX_NA_SPEC(2, inherit2)

#define STREAMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(3, STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY, <streams_boost/mpl/inherit.hpp>))
#include STREAMS_BOOST_PP_ITERATE()

}}

#endif // STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // STREAMS_BOOST_MPL_INHERIT_HPP_INCLUDED

///// iteration

#else
#define n_ STREAMS_BOOST_PP_FRAME_ITERATION(1)

template<
      STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(n_, typename T, na)
    >
struct STREAMS_BOOST_PP_CAT(inherit,n_)
    : inherit2<
          typename STREAMS_BOOST_PP_CAT(inherit,STREAMS_BOOST_PP_DEC(n_))<
              STREAMS_BOOST_MPL_PP_PARAMS(STREAMS_BOOST_PP_DEC(n_), T)
            >::type
        , STREAMS_BOOST_PP_CAT(T,n_)
        >
{
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(
          n_
        , STREAMS_BOOST_PP_CAT(inherit,n_)
        , (STREAMS_BOOST_MPL_PP_PARAMS(n_, T))
        )
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(n_, STREAMS_BOOST_PP_CAT(inherit,n_))

#if n_ == STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY
/// primary template
template<
      STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(n_, typename T, empty_base)
    >
struct inherit
    : STREAMS_BOOST_PP_CAT(inherit,n_)<STREAMS_BOOST_MPL_PP_PARAMS(n_, T)>
{
};

// 'na' specialization
template<>
struct inherit< STREAMS_BOOST_MPL_PP_ENUM(5, na) >
{
    template<
#if !defined(STREAMS_BOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
          STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(n_, typename T, empty_base)
#else
          STREAMS_BOOST_MPL_PP_PARAMS(n_, typename T)
#endif
        >
    struct apply
        : inherit< STREAMS_BOOST_MPL_PP_PARAMS(n_, T) >
    {
    };
};

STREAMS_BOOST_MPL_AUX_NA_SPEC_LAMBDA(n_, inherit)
STREAMS_BOOST_MPL_AUX_NA_SPEC_ARITY(n_, inherit)
STREAMS_BOOST_MPL_AUX_NA_SPEC_TEMPLATE_ARITY(n_, n_, inherit)
#endif

#undef n_
#endif // STREAMS_BOOST_PP_IS_ITERATING
