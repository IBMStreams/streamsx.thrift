//-----------------------------------------------------------------------------
// streams_boost variant/recursive_variant.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_RECURSIVE_VARIANT_HPP
#define STREAMS_BOOST_VARIANT_RECURSIVE_VARIANT_HPP

#include "streams_boost/variant/variant_fwd.hpp"
#include "streams_boost/variant/detail/enable_recursive.hpp"
#include "streams_boost/variant/detail/substitute_fwd.hpp"
#include "streams_boost/variant/detail/make_variant_list.hpp"
#include "streams_boost/variant/detail/over_sequence.hpp"

#include "streams_boost/mpl/aux_/lambda_arity_param.hpp"

#if !defined(STREAMS_BOOST_VARIANT_NO_TYPE_SEQUENCE_SUPPORT)
#   include "streams_boost/mpl/eval_if.hpp"
#   include "streams_boost/mpl/identity.hpp"
#   include "streams_boost/mpl/protect.hpp"
#   include "streams_boost/mpl/transform.hpp"
#else
#   include "streams_boost/preprocessor/cat.hpp"
#   include "streams_boost/preprocessor/repeat.hpp"
#endif

#include "streams_boost/mpl/bool.hpp"
#include "streams_boost/mpl/is_sequence.hpp"
#include "streams_boost/variant/variant.hpp"

namespace streams_boost {

namespace detail { namespace variant {

///////////////////////////////////////////////////////////////////////////////
// (detail) metafunction specialization substitute
//
// Handles embedded variant types when substituting for recursive_variant_.
//

#if !defined(STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

template <
      STREAMS_BOOST_VARIANT_ENUM_PARAMS(typename T)
    , typename RecursiveVariant
      STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(typename Arity)
    >
struct substitute<
      ::streams_boost::variant<
          recursive_flag< T0 >
        , STREAMS_BOOST_VARIANT_ENUM_SHIFTED_PARAMS(T)
        >
    , RecursiveVariant
    , ::streams_boost::recursive_variant_
      STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(Arity)
    >
{
    typedef ::streams_boost::variant<
          recursive_flag< T0 >
        , STREAMS_BOOST_VARIANT_ENUM_SHIFTED_PARAMS(T)
        > type;
};

template <
      STREAMS_BOOST_VARIANT_ENUM_PARAMS(typename T)
    , typename RecursiveVariant
      STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(typename Arity)
    >
struct substitute<
      ::streams_boost::variant< STREAMS_BOOST_VARIANT_ENUM_PARAMS(T) >
    , RecursiveVariant
    , ::streams_boost::recursive_variant_
      STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(Arity)
    >
{

#if !defined(STREAMS_BOOST_VARIANT_NO_TYPE_SEQUENCE_SUPPORT)

private: // helpers, for metafunction result (below)

    typedef typename mpl::eval_if<
          ::streams_boost::detail::variant::is_over_sequence<T0>
        , mpl::identity< T0 >
        , make_variant_list< STREAMS_BOOST_VARIANT_ENUM_PARAMS(T) >
        >::type initial_types;

    typedef typename mpl::transform<
          initial_types
        , mpl::protect< quoted_enable_recursive<RecursiveVariant,mpl::true_> >
        >::type types;

public: // metafunction result

    typedef ::streams_boost::variant< types > type;

#else // defined(STREAMS_BOOST_VARIANT_NO_TYPE_SEQUENCE_SUPPORT)

private: // helpers, for metafunction result (below)

    #define STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_TYPEDEFS(z,N,_)  \
        typedef typename enable_recursive<   \
              STREAMS_BOOST_PP_CAT(T,N)              \
            , RecursiveVariant               \
            , mpl::true_                     \
            >::type STREAMS_BOOST_PP_CAT(wknd_T,N);  \
        /**/

    STREAMS_BOOST_PP_REPEAT(
          STREAMS_BOOST_VARIANT_LIMIT_TYPES
        , STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_TYPEDEFS
        , _
        )

    #undef STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_TYPEDEFS

public: // metafunction result

    typedef ::streams_boost::variant< STREAMS_BOOST_VARIANT_ENUM_PARAMS(wknd_T) > type;

#endif // STREAMS_BOOST_VARIANT_NO_TYPE_SEQUENCE_SUPPORT workaround

};

#else // defined(STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

//
// no specializations: embedded variants unsupported on these compilers!
//

#endif // !defined(STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

}} // namespace detail::variant

///////////////////////////////////////////////////////////////////////////////
// metafunction make_recursive_variant
//
// See docs and streams_boost/variant/variant_fwd.hpp for more information.
//
template < STREAMS_BOOST_VARIANT_ENUM_PARAMS(typename T) >
struct make_recursive_variant
{
public: // metafunction result

    typedef streams_boost::variant<
          detail::variant::recursive_flag< T0 >
        , STREAMS_BOOST_VARIANT_ENUM_SHIFTED_PARAMS(T)
        > type;

};

///////////////////////////////////////////////////////////////////////////////
// metafunction make_recursive_variant_over
//
// See docs and streams_boost/variant/variant_fwd.hpp for more information.
//
template <typename Types>
struct make_recursive_variant_over
{
private: // precondition assertions

#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)
    STREAMS_BOOST_STATIC_ASSERT(( ::streams_boost::mpl::is_sequence<Types>::value ));
#endif

public: // metafunction result

    typedef typename make_recursive_variant<
          detail::variant::over_sequence< Types >
        >::type type;

};

} // namespace streams_boost

#endif // STREAMS_BOOST_VARIANT_RECURSIVE_VARIANT_HPP
