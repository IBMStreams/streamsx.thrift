
#ifndef STREAMS_BOOST_MPL_MULTIPLIES_HPP_INCLUDED
#define STREAMS_BOOST_MPL_MULTIPLIES_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: multiplies.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/times.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/mpl/aux_/preprocessor/default_params.hpp>
#include <streams_boost/mpl/aux_/preprocessor/params.hpp>
#include <streams_boost/mpl/aux_/config/ctps.hpp>

// backward compatibility header, deprecated

namespace streams_boost { namespace mpl {

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
#   define AUX778076_OP_ARITY STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY
#else
#   define AUX778076_OP_ARITY 2
#endif

template<
      STREAMS_BOOST_MPL_PP_DEFAULT_PARAMS(AUX778076_OP_ARITY, typename N, na)
    >
struct multiplies
    : times< STREAMS_BOOST_MPL_PP_PARAMS(AUX778076_OP_ARITY, N) >
{
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(
          AUX778076_OP_ARITY
        , multiplies
        , ( STREAMS_BOOST_MPL_PP_PARAMS(AUX778076_OP_ARITY, N) )
        )
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(AUX778076_OP_ARITY, multiplies)

#undef AUX778076_OP_ARITY

}}

#endif // STREAMS_BOOST_MPL_MULTIPLIES_HPP_INCLUDED
