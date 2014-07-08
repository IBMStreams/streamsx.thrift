
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

///// header body

#ifndef STREAMS_BOOST_MPL_AUX_TEMPLATE_ARITY_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_TEMPLATE_ARITY_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: template_arity.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/ttp.hpp>
#include <streams_boost/mpl/aux_/config/lambda.hpp>

#if !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <streams_boost/mpl/aux_/template_arity_fwd.hpp>
#   include <streams_boost/mpl/int.hpp>
#   if !defined(STREAMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)
#   if defined(STREAMS_BOOST_MPL_CFG_EXTENDED_TEMPLATE_PARAMETERS_MATCHING)
#       include <streams_boost/mpl/aux_/type_wrapper.hpp>
#   endif
#   else
#       include <streams_boost/mpl/aux_/has_rebind.hpp>
#   endif
#endif

#include <streams_boost/mpl/aux_/config/static_constant.hpp>
#include <streams_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)

#   define STREAMS_BOOST_MPL_PREPROCESSED_HEADER template_arity.hpp
#   include <streams_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   if !defined(STREAMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)
#   if defined(STREAMS_BOOST_MPL_CFG_EXTENDED_TEMPLATE_PARAMETERS_MATCHING)

#   include <streams_boost/mpl/limits/arity.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/range.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/repeat.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/params.hpp>
#   include <streams_boost/mpl/aux_/nttp_decl.hpp>

#   include <streams_boost/preprocessor/seq/fold_left.hpp>
#   include <streams_boost/preprocessor/comma_if.hpp>
#   include <streams_boost/preprocessor/iterate.hpp>
#   include <streams_boost/preprocessor/inc.hpp>
#   include <streams_boost/preprocessor/cat.hpp>

#   define AUX778076_ARITY STREAMS_BOOST_PP_INC(STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY)

namespace streams_boost { namespace mpl { namespace aux {

template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, N) > struct arity_tag
{
    typedef char (&type)[N + 1];
};

#   define AUX778076_MAX_ARITY_OP(unused, state, i_) \
    ( STREAMS_BOOST_PP_CAT(C,i_) > 0 ? STREAMS_BOOST_PP_CAT(C,i_) : state ) \
/**/

template<
      STREAMS_BOOST_MPL_PP_PARAMS(AUX778076_ARITY, STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, C))
    >
struct max_arity
{
    STREAMS_BOOST_STATIC_CONSTANT(int, value = 
          STREAMS_BOOST_PP_SEQ_FOLD_LEFT(
              AUX778076_MAX_ARITY_OP
            , -1
            , STREAMS_BOOST_MPL_PP_RANGE(1, AUX778076_ARITY)
            )
        );
};

#   undef AUX778076_MAX_ARITY_OP

arity_tag<0>::type arity_helper(...);

#   define STREAMS_BOOST_PP_ITERATION_LIMITS (1, AUX778076_ARITY)
#   define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/mpl/aux_/template_arity.hpp>
#   include STREAMS_BOOST_PP_ITERATE()

template< typename F, STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, N) >
struct template_arity_impl
{
    STREAMS_BOOST_STATIC_CONSTANT(int, value = 
          sizeof(arity_helper(type_wrapper<F>(),arity_tag<N>())) - 1
        );
};

#   define AUX778076_TEMPLATE_ARITY_IMPL_INVOCATION(unused, i_, F) \
    STREAMS_BOOST_PP_COMMA_IF(i_) template_arity_impl<F,STREAMS_BOOST_PP_INC(i_)>::value \
/**/

template< typename F >
struct template_arity
{
    STREAMS_BOOST_STATIC_CONSTANT(int, value = (
          max_arity< STREAMS_BOOST_MPL_PP_REPEAT(
              AUX778076_ARITY
            , AUX778076_TEMPLATE_ARITY_IMPL_INVOCATION
            , F
            ) >::value
        ));
        
    typedef mpl::int_<value> type;
};

#   undef AUX778076_TEMPLATE_ARITY_IMPL_INVOCATION

#   undef AUX778076_ARITY

}}}

#   endif // STREAMS_BOOST_MPL_CFG_EXTENDED_TEMPLATE_PARAMETERS_MATCHING
#   else // STREAMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT

#   include <streams_boost/mpl/aux_/config/eti.hpp>

namespace streams_boost { namespace mpl { namespace aux {

template< bool >
struct template_arity_impl
{
    template< typename F > struct result_
        : mpl::int_<-1>
    {
    };
};

template<>
struct template_arity_impl<true>
{
    template< typename F > struct result_
        : F::arity
    {
    };
};

template< typename F >
struct template_arity
    : template_arity_impl< ::streams_boost::mpl::aux::has_rebind<F>::value >
        ::template result_<F>
{
};

#if defined(STREAMS_BOOST_MPL_CFG_MSVC_ETI_BUG)
template<>
struct template_arity<int>
    : mpl::int_<-1>
{
};
#endif

}}}

#   endif // STREAMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT

#endif // STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // STREAMS_BOOST_MPL_AUX_TEMPLATE_ARITY_HPP_INCLUDED

///// iteration

#else
#define i_ STREAMS_BOOST_PP_FRAME_ITERATION(1)

template<
      template< STREAMS_BOOST_MPL_PP_PARAMS(i_, typename P) > class F
    , STREAMS_BOOST_MPL_PP_PARAMS(i_, typename T)
    >
typename arity_tag<i_>::type
arity_helper(type_wrapper< F<STREAMS_BOOST_MPL_PP_PARAMS(i_, T)> >, arity_tag<i_>);

#undef i_
#endif // STREAMS_BOOST_PP_IS_ITERATING
