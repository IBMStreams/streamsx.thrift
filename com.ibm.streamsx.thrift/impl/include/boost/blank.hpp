//-----------------------------------------------------------------------------
// streams_boost blank.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_BLANK_HPP
#define STREAMS_BOOST_BLANK_HPP

#include "streams_boost/blank_fwd.hpp"

#if !defined(STREAMS_BOOST_NO_IOSTREAM)
#include <iosfwd> // for std::basic_ostream forward declare
#include "streams_boost/detail/templated_streams.hpp"
#endif // STREAMS_BOOST_NO_IOSTREAM

#include "streams_boost/mpl/bool.hpp"
#include "streams_boost/type_traits/is_empty.hpp"
#include "streams_boost/type_traits/is_pod.hpp"
#include "streams_boost/type_traits/is_stateless.hpp"

namespace streams_boost {

struct blank
{
};

// type traits specializations
//

template <>
struct is_pod< blank >
    : mpl::true_
{
};

template <>
struct is_empty< blank >
    : mpl::true_
{
};

template <>
struct is_stateless< blank >
    : mpl::true_
{
};

// relational operators
//

inline bool operator==(const blank&, const blank&)
{
    return true;
}

inline bool operator<=(const blank&, const blank&)
{
    return true;
}

inline bool operator>=(const blank&, const blank&)
{
    return true;
}

inline bool operator!=(const blank&, const blank&)
{
    return false;
}

inline bool operator<(const blank&, const blank&)
{
    return false;
}

inline bool operator>(const blank&, const blank&)
{
    return false;
}

// streaming support
//
#if !defined(STREAMS_BOOST_NO_IOSTREAM)

STREAMS_BOOST_TEMPLATED_STREAM_TEMPLATE(E,T)
inline STREAMS_BOOST_TEMPLATED_STREAM(ostream, E,T)& operator<<(
      STREAMS_BOOST_TEMPLATED_STREAM(ostream, E,T)& out
    , const blank&
    )
{
    // (output nothing)
    return out;
}

#endif // STREAMS_BOOST_NO_IOSTREAM

} // namespace streams_boost

#endif // STREAMS_BOOST_BLANK_HPP
