//-----------------------------------------------------------------------------
// streams_boost/variant/detail/bool_trait_def.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// Needed until move-related traits incorporated into type_traits library.
// no include guards, the header is intended for multiple inclusion!

// should be the last #include
#include "streams_boost/type_traits/detail/bool_trait_def.hpp"

#define STREAMS_BOOST_VARIANT_TT_AUX_BOOL_TRAIT_DEF1(trait,T,C) \
template< typename T > struct trait \
    STREAMS_BOOST_TT_AUX_BOOL_C_BASE(C) \
{ \
    STREAMS_BOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(C) \
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,trait,(T)) \
}; \
/**/

#define STREAMS_BOOST_VARIANT_TT_AUX_TRAIT_SUFFIX(arity, name) \
STREAMS_BOOST_TT_AUX_TEMPLATE_ARITY_SPEC(arity, name) \
/**/
