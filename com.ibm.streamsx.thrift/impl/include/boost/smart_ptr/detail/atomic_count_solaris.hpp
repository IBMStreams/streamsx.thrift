#ifndef STREAMS_BOOST_SMART_PTR_DETAIL_ATOMIC_COUNT_SOLARIS_HPP_INCLUDED
#define STREAMS_BOOST_SMART_PTR_DETAIL_ATOMIC_COUNT_SOLARIS_HPP_INCLUDED

//
//  streams_boost/detail/atomic_count_solaris.hpp
//   based on: streams_boost/detail/atomic_count_win32.hpp
//
//  Copyright (c) 2001-2005 Peter Dimov
//  Copyright (c) 2006 Michael van der Westhuizen
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//

#include <atomic.h>

namespace streams_boost
{

namespace detail
{

class atomic_count
{
public:

    explicit atomic_count( uint32_t v ): value_( v )
    {
    }

    long operator++()
    {
        return atomic_inc_32_nv( &value_ );
    }

    long operator--()
    {
        return atomic_dec_32_nv( &value_ );
    }

    operator uint32_t() const
    {
        return static_cast<uint32_t const volatile &>( value_ );
    }

private:

    atomic_count( atomic_count const & );
    atomic_count & operator=( atomic_count const & );

    uint32_t value_;
};

} // namespace detail

} // namespace streams_boost

#endif // #ifndef STREAMS_BOOST_SMART_PTR_DETAIL_ATOMIC_COUNT_SOLARIS_HPP_INCLUDED
