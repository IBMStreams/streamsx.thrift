
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

///// header body

#ifndef STREAMS_BOOST_MPL_ARG_HPP_INCLUDED
#define STREAMS_BOOST_MPL_ARG_HPP_INCLUDED

// Copyright Peter Dimov 2001-2002
// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: arg.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#if !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <streams_boost/mpl/arg_fwd.hpp>
#   include <streams_boost/mpl/aux_/na.hpp>
#   include <streams_boost/mpl/aux_/na_assert.hpp>
#   include <streams_boost/mpl/aux_/arity_spec.hpp>
#   include <streams_boost/mpl/aux_/arg_typedef.hpp>
#endif

#include <streams_boost/mpl/aux_/config/static_constant.hpp>
#include <streams_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)

#   define STREAMS_BOOST_MPL_PREPROCESSED_HEADER arg.hpp
#   include <streams_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <streams_boost/mpl/limits/arity.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/default_params.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/params.hpp>
#   include <streams_boost/mpl/aux_/config/lambda.hpp>
#   include <streams_boost/mpl/aux_/config/dtp.hpp>
#   include <streams_boost/mpl/aux_/nttp_decl.hpp>

#   include <streams_boost/preprocessor/iterate.hpp>
#   include <streams_boost/preprocessor/inc.hpp>
#   include <streams_boost/preprocessor/cat.hpp>

STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN

// local macro, #undef-ined at the end of the header
#if !defined(STREAMS_BOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#   define AUX778076_ARG_N_DEFAULT_PARAMS(param,value) \
    STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS( \
          STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        , value \
        ) \
    /**/
#else
#   define AUX778076_ARG_N_DEFAULT_PARAMS(param,value) \
    STREAMS_BOOST_MPL_PP_PARAMS( \
          STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        ) \
    /**/
#endif

#define STREAMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY, <streams_boost/mpl/arg.hpp>))
#include STREAMS_BOOST_PP_ITERATE()


#   undef AUX778076_ARG_N_DEFAULT_PARAMS

STREAMS_BOOST_MPL_AUX_NONTYPE_ARITY_SPEC(1,int,arg)

STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE

#endif // STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // STREAMS_BOOST_MPL_ARG_HPP_INCLUDED

///// iteration

#else
#define i_ STREAMS_BOOST_PP_FRAME_ITERATION(1)

#if i_ > 0

template<> struct arg<i_>
{
    STREAMS_BOOST_STATIC_CONSTANT(int, value = i_);
    typedef arg<STREAMS_BOOST_PP_INC(i_)> next;
    STREAMS_BOOST_MPL_AUX_ARG_TYPEDEF(na, tag)
    STREAMS_BOOST_MPL_AUX_ARG_TYPEDEF(na, type)

    template<
          AUX778076_ARG_N_DEFAULT_PARAMS(typename U, na)
        >
    struct apply
    {
        typedef STREAMS_BOOST_PP_CAT(U,i_) type;
        STREAMS_BOOST_MPL_AUX_ASSERT_NOT_NA(type);
    };
};

#else

template<> struct arg<-1>
{
    STREAMS_BOOST_STATIC_CONSTANT(int, value = -1);
    STREAMS_BOOST_MPL_AUX_ARG_TYPEDEF(na, tag)
    STREAMS_BOOST_MPL_AUX_ARG_TYPEDEF(na, type)

    template<
          AUX778076_ARG_N_DEFAULT_PARAMS(typename U, na)
        >
    struct apply
    {
        typedef U1 type;
        STREAMS_BOOST_MPL_AUX_ASSERT_NOT_NA(type);
    };
};

#endif // i_ > 0

#undef i_
#endif // STREAMS_BOOST_PP_IS_ITERATING
