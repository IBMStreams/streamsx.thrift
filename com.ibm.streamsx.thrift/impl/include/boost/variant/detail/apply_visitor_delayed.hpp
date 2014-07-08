//-----------------------------------------------------------------------------
// streams_boost variant/detail/apply_visitor_delayed.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_DETAIL_APPLY_VISITOR_DELAYED_HPP
#define STREAMS_BOOST_VARIANT_DETAIL_APPLY_VISITOR_DELAYED_HPP

#include "streams_boost/variant/detail/generic_result_type.hpp"

#include "streams_boost/variant/detail/apply_visitor_unary.hpp"
#include "streams_boost/variant/detail/apply_visitor_binary.hpp"

namespace streams_boost {

//////////////////////////////////////////////////////////////////////////
// function template apply_visitor(visitor)
//
// Returns a function object, overloaded for unary and binary usage, that
// visits its arguments using visitor (or a copy of visitor) via
//  * apply_visitor( visitor, [argument] )
// under unary invocation, or
//  * apply_visitor( visitor, [argument1], [argument2] )
// under binary invocation.
//
// NOTE: Unlike other apply_visitor forms, the visitor object must be
//   non-const; this prevents user from giving temporary, to disastrous
//   effect (i.e., returned function object would have dead reference).
//

template <typename Visitor>
class apply_visitor_delayed_t
{
public: // visitor typedefs

    typedef typename Visitor::result_type
        result_type;

private: // representation

    Visitor& visitor_;

public: // structors

    explicit apply_visitor_delayed_t(Visitor& visitor)
      : visitor_(visitor)
    {
    }

public: // unary visitor interface

    template <typename Visitable>
        STREAMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(result_type)
    operator()(Visitable& visitable)
    {
        return apply_visitor(visitor_, visitable);
    }

public: // binary visitor interface

    template <typename Visitable1, typename Visitable2>
        STREAMS_BOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(result_type)
    operator()(Visitable1& visitable1, Visitable2& visitable2)
    {
        return apply_visitor(visitor_, visitable1, visitable2);
    }

};

template <typename Visitor>
inline apply_visitor_delayed_t<Visitor> apply_visitor(Visitor& visitor)
{
    return apply_visitor_delayed_t<Visitor>(visitor);
}

} // namespace streams_boost

#endif // STREAMS_BOOST_VARIANT_DETAIL_APPLY_VISITOR_DELAYED_HPP
