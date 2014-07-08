
#ifndef STREAMS_BOOST_MPL_AUX_ARITY_SPEC_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_ARITY_SPEC_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: arity_spec.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/int.hpp>
#include <streams_boost/mpl/limits/arity.hpp>
#include <streams_boost/mpl/aux_/config/dtp.hpp>
#include <streams_boost/mpl/aux_/preprocessor/params.hpp>
#include <streams_boost/mpl/aux_/arity.hpp>
#include <streams_boost/mpl/aux_/template_arity_fwd.hpp>
#include <streams_boost/mpl/aux_/config/ttp.hpp>
#include <streams_boost/mpl/aux_/config/lambda.hpp>
#include <streams_boost/mpl/aux_/config/static_constant.hpp>

#if defined(STREAMS_BOOST_MPL_CFG_BROKEN_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#   define STREAMS_BOOST_MPL_AUX_NONTYPE_ARITY_SPEC(i,type,name) \
namespace aux { \
template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, N), STREAMS_BOOST_MPL_PP_PARAMS(i,type T) > \
struct arity< \
      name< STREAMS_BOOST_MPL_PP_PARAMS(i,T) > \
    , N \
    > \
{ \
    STREAMS_BOOST_STATIC_CONSTANT(int \
        , value = STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        ); \
}; \
} \
/**/
#else
#   define STREAMS_BOOST_MPL_AUX_NONTYPE_ARITY_SPEC(i,type,name) /**/
#endif

#   define STREAMS_BOOST_MPL_AUX_ARITY_SPEC(i,name) \
    STREAMS_BOOST_MPL_AUX_NONTYPE_ARITY_SPEC(i,typename,name) \
/**/


#if defined(STREAMS_BOOST_MPL_CFG_EXTENDED_TEMPLATE_PARAMETERS_MATCHING) \
    && !defined(STREAMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)
#   define STREAMS_BOOST_MPL_AUX_TEMPLATE_ARITY_SPEC(i, name) \
namespace aux { \
template< STREAMS_BOOST_MPL_PP_PARAMS(i,typename T) > \
struct template_arity< name<STREAMS_BOOST_MPL_PP_PARAMS(i,T)> > \
    : int_<i> \
{ \
}; \
} \
/**/
#else
#   define STREAMS_BOOST_MPL_AUX_TEMPLATE_ARITY_SPEC(i, name) /**/
#endif


#endif // STREAMS_BOOST_MPL_AUX_ARITY_SPEC_HPP_INCLUDED
