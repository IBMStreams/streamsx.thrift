
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION

// Copyright Aleksey Gurtovoy 2001-2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: include_preprocessed.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/preprocessor.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/stringize.hpp>

#if !defined(STREAMS_BOOST_NEEDS_TOKEN_PASTING_OP_FOR_TOKENS_JUXTAPOSING)
#   define AUX778076_HEADER \
    plain/STREAMS_BOOST_MPL_PREPROCESSED_HEADER \
/**/
#else
#   define AUX778076_HEADER \
    STREAMS_BOOST_PP_CAT(plain,/)##STREAMS_BOOST_MPL_PREPROCESSED_HEADER \
/**/
#endif

#if STREAMS_BOOST_WORKAROUND(__IBMCPP__, STREAMS_BOOST_TESTED_AT(700))
#   define AUX778076_INCLUDE_STRING STREAMS_BOOST_PP_STRINGIZE(streams_boost/mpl/set/aux_/preprocessed/AUX778076_HEADER)
#   include AUX778076_INCLUDE_STRING
#   undef AUX778076_INCLUDE_STRING
#else
#   include STREAMS_BOOST_PP_STRINGIZE(streams_boost/mpl/set/aux_/preprocessed/AUX778076_HEADER)
#endif

#   undef AUX778076_HEADER

#undef STREAMS_BOOST_MPL_PREPROCESSED_HEADER
