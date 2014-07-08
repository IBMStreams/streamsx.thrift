
// (C) Copyright Eric Friedman 2002-2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org for most recent version including documentation.

#ifndef STREAMS_BOOST_VARIANT_DETAIL_HAS_TRIVIAL_MOVE_HPP_INCLUDED
#define STREAMS_BOOST_VARIANT_DETAIL_HAS_TRIVIAL_MOVE_HPP_INCLUDED

#include "streams_boost/config.hpp" // for STATIC_CONSTANT
#include "streams_boost/type_traits/has_trivial_copy.hpp"
#include "streams_boost/type_traits/has_trivial_assign.hpp"

#include "streams_boost/mpl/and.hpp"
#include "streams_boost/mpl/or.hpp"

// should be the last #include
#include "streams_boost/variant/detail/bool_trait_def.hpp"

namespace streams_boost {
namespace detail { namespace variant {

// TRAIT: has_trivial_move

template <typename T>
struct has_trivial_move_impl
{
    STREAMS_BOOST_STATIC_CONSTANT(
        bool, value = (
            ::streams_boost::mpl::and_<
              has_trivial_copy<T>
            , has_trivial_assign<T>
            >::type::value
            )
        );
};

STREAMS_BOOST_VARIANT_TT_AUX_BOOL_TRAIT_DEF1(
      has_trivial_move
    , T
    , (::streams_boost::detail::variant::has_trivial_move_impl<T>::value)
    )


// TRAIT: has_trivial_move_constructor

template <typename T>
struct has_trivial_move_constructor_impl
{
    STREAMS_BOOST_STATIC_CONSTANT(
        bool, value = (
            ::streams_boost::mpl::or_<
              has_trivial_move<T>
            , has_trivial_copy<T>
            >::type::value
            )
        );
};

STREAMS_BOOST_VARIANT_TT_AUX_BOOL_TRAIT_DEF1(
      has_trivial_move_constructor
    , T
    , (::streams_boost::detail::variant::has_trivial_move_constructor_impl<T>::value)
    )


// TRAIT: has_trivial_move_assign

template <typename T>
struct has_trivial_move_assign_impl
{
    STREAMS_BOOST_STATIC_CONSTANT(
        bool, value = (
            ::streams_boost::mpl::or_<
              has_trivial_move<T>
            , has_trivial_assign<T>
            >::type::value
            )
        );
};

STREAMS_BOOST_VARIANT_TT_AUX_BOOL_TRAIT_DEF1(
      has_trivial_move_assign
    , T
    , (::streams_boost::detail::variant::has_trivial_move_assign_impl<T>::value)
    )

}} // namespace detail::variant

STREAMS_BOOST_VARIANT_TT_AUX_TRAIT_SUFFIX(1,::streams_boost::detail::variant::has_trivial_move)
STREAMS_BOOST_VARIANT_TT_AUX_TRAIT_SUFFIX(1,::streams_boost::detail::variant::has_trivial_move_constructor)
STREAMS_BOOST_VARIANT_TT_AUX_TRAIT_SUFFIX(1,::streams_boost::detail::variant::has_trivial_move_assign)

} // namespace streams_boost

#include "streams_boost/variant/detail/bool_trait_undef.hpp"

#endif // STREAMS_BOOST_VARIANT_DETAIL_HAS_TRIVIAL_MOVE_HPP_INCLUDED
