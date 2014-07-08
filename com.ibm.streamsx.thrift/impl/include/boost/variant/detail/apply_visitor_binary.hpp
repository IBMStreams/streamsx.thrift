//-----------------------------------------------------------------------------
// streams_boost variant/detail/apply_visitor_binary.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_DETAIL_APPLY_VISITOR_BINARY_HPP
#define STREAMS_BOOST_VARIANT_DETAIL_APPLY_VISITOR_BINARY_HPP

#include "streams_boost/config.hpp"
#include "streams_boost/detail/workaround.hpp"
#include "streams_boost/variant/detail/generic_result_type.hpp"

#include "streams_boost/variant/detail/apply_visitor_unary.hpp"

#include "streams_boost/utility/enable_if.hpp"

namespace streams_boost {

//////////////////////////////////////////////////////////////////////////
// function template apply_visitor(visitor, visitable1, visitable2)
//
// Visits visitable1 and visitable2 such that their values (which we
// shall call x and y, respectively) are used as arguments in the
// expression visitor(x, y).
//

namespace detail { namespace variant {

template <typename Visitor, typename Value1>
class apply_visitor_binary_invoke
{
public: // visitor typedefs

    typedef typename Visitor::result_type
        result_type;

private: // representation

    Visitor& visitor_;
    Value1& value1_;

public: // structors

    apply_visitor_binary_invoke(Visitor& visitor, Value1& value1)
        : visitor_(visitor)
        , value1_(value1)
    {
    }

public: // visitor interfaces

    template <typename Value2>
        STREAMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(result_type)
    operator()(Value2& value2)
    {
        return visitor_(value1_, value2);
    }

};

template <typename Visitor, typename Visitable2>
class apply_visitor_binary_unwrap
{
public: // visitor typedefs

    typedef typename Visitor::result_type
        result_type;

private: // representation

    Visitor& visitor_;
    Visitable2& visitable2_;

public: // structors

    apply_visitor_binary_unwrap(Visitor& visitor, Visitable2& visitable2)
        : visitor_(visitor)
        , visitable2_(visitable2)
    {
    }

public: // visitor interfaces

    template <typename Value1>
        STREAMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(result_type)
    operator()(Value1& value1)
    {
        apply_visitor_binary_invoke<
              Visitor
            , Value1
            > invoker(visitor_, value1);

        return streams_boost::apply_visitor(invoker, visitable2_);
    }

};

}} // namespace detail::variant

//
// nonconst-visitor version:
//

#if !STREAMS_BOOST_WORKAROUND(__EDG__, STREAMS_BOOST_TESTED_AT(302))

#   define STREAMS_BOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE(V) \
    STREAMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename V::result_type) \
    /**/

#else // EDG-based compilers

#   define STREAMS_BOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE(V) \
    typename enable_if< \
          mpl::not_< is_const< V > > \
        , STREAMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename V::result_type) \
        >::type \
    /**/

#endif // EDG-based compilers workaround

template <typename Visitor, typename Visitable1, typename Visitable2>
inline
    STREAMS_BOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE(Visitor)
apply_visitor(
      Visitor& visitor
    , Visitable1& visitable1, Visitable2& visitable2
    )
{
    ::streams_boost::detail::variant::apply_visitor_binary_unwrap<
          Visitor, Visitable2
        > unwrapper(visitor, visitable2);

    return streams_boost::apply_visitor(unwrapper, visitable1);
}

#undef STREAMS_BOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE

//
// const-visitor version:
//

#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)

template <typename Visitor, typename Visitable1, typename Visitable2>
inline
    STREAMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(
          typename Visitor::result_type
        )
apply_visitor(
      const Visitor& visitor
    , Visitable1& visitable1, Visitable2& visitable2
    )
{
    ::streams_boost::detail::variant::apply_visitor_binary_unwrap<
          const Visitor, Visitable2
        > unwrapper(visitor, visitable2);

    return streams_boost::apply_visitor(unwrapper, visitable1);
}

#endif // MSVC7 and below exclusion

} // namespace streams_boost

#endif // STREAMS_BOOST_VARIANT_DETAIL_APPLY_VISITOR_BINARY_HPP
