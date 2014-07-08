//-----------------------------------------------------------------------------
// streams_boost variant/detail/apply_visitor_unary.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_DETAIL_APPLY_VISITOR_UNARY_HPP
#define STREAMS_BOOST_VARIANT_DETAIL_APPLY_VISITOR_UNARY_HPP

#include "streams_boost/config.hpp"
#include "streams_boost/detail/workaround.hpp"
#include "streams_boost/variant/detail/generic_result_type.hpp"

#include "streams_boost/utility/enable_if.hpp"

namespace streams_boost {

//////////////////////////////////////////////////////////////////////////
// function template apply_visitor(visitor, visitable)
//
// Visits visitable with visitor.
//

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

template <typename Visitor, typename Visitable>
inline
    STREAMS_BOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE(Visitor)
apply_visitor(Visitor& visitor, Visitable& visitable)
{
    return visitable.apply_visitor(visitor);
}

#undef STREAMS_BOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE

//
// const-visitor version:
//

#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)

template <typename Visitor, typename Visitable>
inline
    STREAMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename Visitor::result_type)
apply_visitor(const Visitor& visitor, Visitable& visitable)
{
    return visitable.apply_visitor(visitor);
}

#endif // MSVC7 and below exclusion

} // namespace streams_boost

#endif // STREAMS_BOOST_VARIANT_DETAIL_APPLY_VISITOR_UNARY_HPP
