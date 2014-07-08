// Copyright (C) 2001-2003
// Mac Murrett
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org for most recent version including documentation.

#ifndef STREAMS_BOOST_FORCE_CAST_MJM012402_HPP
#define STREAMS_BOOST_FORCE_CAST_MJM012402_HPP

#include <streams_boost/thread/detail/config.hpp>

namespace streams_boost {
namespace detail {
namespace thread {

// force_cast will convert anything to anything.

// general case
template<class Return_Type, class Argument_Type>
inline Return_Type &force_cast(Argument_Type &rSrc)
{
    return(*reinterpret_cast<Return_Type *>(&rSrc));
}

// specialization for const
template<class Return_Type, class Argument_Type>
inline const Return_Type &force_cast(const Argument_Type &rSrc)
{
    return(*reinterpret_cast<const Return_Type *>(&rSrc));
}

} // namespace thread
} // namespace detail
} // namespace streams_boost

#endif // STREAMS_BOOST_FORCE_CAST_MJM012402_HPP
