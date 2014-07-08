//-----------------------------------------------------------------------------
// streams_boost variant/detail/enable_recursive.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_DETAIL_ENABLE_RECURSIVE_HPP
#define STREAMS_BOOST_VARIANT_DETAIL_ENABLE_RECURSIVE_HPP

#include "streams_boost/variant/detail/enable_recursive_fwd.hpp"
#include "streams_boost/variant/variant_fwd.hpp"

#if !defined(STREAMS_BOOST_VARIANT_NO_FULL_RECURSIVE_VARIANT_SUPPORT)
#   include "streams_boost/mpl/apply.hpp"
#   include "streams_boost/mpl/eval_if.hpp"
#   include "streams_boost/mpl/lambda.hpp"
#endif

#include "streams_boost/variant/detail/substitute.hpp"
#include "streams_boost/mpl/aux_/config/ctps.hpp"
#include "streams_boost/mpl/bool_fwd.hpp"
#include "streams_boost/mpl/if.hpp"
#include "streams_boost/mpl/or.hpp"
#include "streams_boost/type_traits/is_pointer.hpp"
#include "streams_boost/type_traits/is_reference.hpp"
#include "streams_boost/type_traits/is_same.hpp"

#include "streams_boost/variant/recursive_wrapper.hpp"

namespace streams_boost {
namespace detail { namespace variant {

#if !defined(STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

#   define STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL(T,Dest,Source) \
    substitute< T , Dest , Source > \
    /**/

#else // defined(STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

///////////////////////////////////////////////////////////////////////////////
// (detail) class template rebind1
//
// Limited workaround in case 'substitute' metafunction unavailable.
//

template <typename T, typename U1>
struct rebind1
{
private:
    typedef typename mpl::lambda<
          mpl::identity<T>
        >::type le_;

public:
    typedef typename mpl::eval_if<
          is_same< le_, mpl::identity<T> >
        , le_ // identity<T>
        , mpl::apply1<le_, U1>
        >::type type;
};

#   define STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL(T,Dest,Source) \
    rebind1< T , Dest > \
    /**/

#endif // !defined(STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

///////////////////////////////////////////////////////////////////////////////
// (detail) metafunction enable_recursive
//
// See streams_boost/variant/detail/enable_recursive_fwd.hpp for more information.
//

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template <typename T, typename RecursiveVariant, typename NoWrapper>
struct enable_recursive
    : STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL(
          T, RecursiveVariant, ::streams_boost::recursive_variant_
        )
{
};

template <typename T, typename RecursiveVariant>
struct enable_recursive< T,RecursiveVariant,mpl::false_ >
{
private: // helpers, for metafunction result (below)

    typedef typename STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL(
          T, RecursiveVariant, ::streams_boost::recursive_variant_
        )::type t_;

public: // metafunction result

    // [Wrap with recursive_wrapper only if rebind really changed something:]
    typedef typename mpl::if_<
          mpl::or_<
              is_same< t_,T >
            , is_reference<t_>
            , is_pointer<t_>
            >
        , t_
        , streams_boost::recursive_wrapper<t_>
        >::type type;

};

#else // defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template <typename T, typename RecursiveVariant, typename NoWrapper>
struct enable_recursive
{
private: // helpers, for metafunction result (below)

    typedef typename STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL(
          T, RecursiveVariant, ::streams_boost::recursive_variant_
        )::type t_;

public: // metafunction result

    // [Wrap with recursive_wrapper only if rebind really changed something:]
    typedef typename mpl::if_<
          mpl::or_<
              NoWrapper
            , is_same< t_,T >
            , is_reference<t_>
            , is_pointer<t_>
            >
        , t_
        , streams_boost::recursive_wrapper<t_>
        >::type type;

};

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION workaround

///////////////////////////////////////////////////////////////////////////////
// (detail) metafunction class quoted_enable_recursive
//
// Same behavior as enable_recursive metafunction (see above).
//
template <typename RecursiveVariant, typename NoWrapper>
struct quoted_enable_recursive
{
    template <typename T>
    struct apply
        : enable_recursive<T, RecursiveVariant, NoWrapper>
    {
    };
};

}} // namespace detail::variant
} // namespace streams_boost

#endif // STREAMS_BOOST_VARIANT_DETAIL_ENABLE_RECURSIVE_HPP
