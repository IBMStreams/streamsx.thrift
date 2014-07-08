//-----------------------------------------------------------------------------
// streams_boost variant/static_visitor.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_STATIC_VISITOR_HPP
#define STREAMS_BOOST_VARIANT_STATIC_VISITOR_HPP

#include "streams_boost/config.hpp"
#include "streams_boost/detail/workaround.hpp"

#include "streams_boost/mpl/if.hpp"
#include "streams_boost/type_traits/is_base_and_derived.hpp"

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
#   include "streams_boost/type_traits/is_same.hpp"
#endif

// should be the last #include
#include "streams_boost/type_traits/detail/bool_trait_def.hpp"

namespace streams_boost {

//////////////////////////////////////////////////////////////////////////
// class template static_visitor
//
// An empty base class that typedefs the return type of a deriving static
// visitor. The class is analogous to std::unary_function in this role.
//

namespace detail {

    struct is_static_visitor_tag { };

    typedef void static_visitor_default_return;

} // namespace detail

template <typename R = ::streams_boost::detail::static_visitor_default_return>
class static_visitor
    : public detail::is_static_visitor_tag
{
public: // typedefs

    typedef R result_type;

protected: // for use as base class only

    static_visitor() { }
    ~static_visitor() { }

};

//////////////////////////////////////////////////////////////////////////
// metafunction is_static_visitor
//
// Value metafunction indicates whether the specified type derives from
// static_visitor<...>.
//
// NOTE #1: This metafunction does NOT check whether the specified type
//  fulfills the requirements of the StaticVisitor concept.
//
// NOTE #2: This template never needs to be specialized!
//

namespace detail {

template <typename T>
struct is_static_visitor_impl
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
        (::streams_boost::is_base_and_derived< 
            detail::is_static_visitor_tag,
            T
        >::value));
};

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(
      is_static_visitor
    , T
    , (::streams_boost::detail::is_static_visitor_impl<T>::value)
    )

} // namespace streams_boost

#include "streams_boost/type_traits/detail/bool_trait_undef.hpp"

#endif // STREAMS_BOOST_VARIANT_STATIC_VISITOR_HPP
