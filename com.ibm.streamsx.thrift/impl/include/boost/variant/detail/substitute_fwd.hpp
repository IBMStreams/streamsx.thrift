//-----------------------------------------------------------------------------
// streams_boost variant/detail/substitute_fwd.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_DETAIL_SUBSTITUTE_FWD_HPP
#define STREAMS_BOOST_VARIANT_DETAIL_SUBSTITUTE_FWD_HPP

#include "streams_boost/mpl/aux_/lambda_arity_param.hpp"
#include "streams_boost/mpl/aux_/template_arity.hpp"
#include "streams_boost/mpl/int_fwd.hpp"


///////////////////////////////////////////////////////////////////////////////
// STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE
//
// Defined if 'substitute' is not implementable on the current compiler.
//

#include "streams_boost/mpl/aux_/config/ctps.hpp"
#include "streams_boost/mpl/aux_/config/ttp.hpp"

#if defined(STREAMS_BOOST_NO_TEMPLATE_TEMPLATE_PARAMETERS) \
 || defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
 && !defined(STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)
#   define STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE
#endif

namespace streams_boost {
namespace detail { namespace variant {

#if !defined(STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

///////////////////////////////////////////////////////////////////////////////
// metafunction substitute
//
// Substitutes one type for another in the given type expression.
//
template <
      typename T, typename Dest, typename Source
      STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(
          typename Arity = mpl::int_< mpl::aux::template_arity<T>::value >
        )
    >
struct substitute;

#endif // !defined(STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

}} // namespace detail::variant
} // namespace streams_boost

#endif // STREAMS_BOOST_VARIANT_DETAIL_SUBSTITUTE_FWD_HPP
