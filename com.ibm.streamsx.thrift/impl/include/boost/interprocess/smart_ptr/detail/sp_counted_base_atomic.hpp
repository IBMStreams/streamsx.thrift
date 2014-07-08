#ifndef STREAMS_BOOST_INTERPROCESS_DETAIL_SP_COUNTED_BASE_ATOMIC_HPP_INCLUDED
#define STREAMS_BOOST_INTERPROCESS_DETAIL_SP_COUNTED_BASE_ATOMIC_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//  Copyright (c) 2001, 2002, 2003 Peter Dimov and Multi Media Ltd.
//  Copyright 2004-2005 Peter Dimov
//  Copyright 2007-2009 Ion Gaztanaga
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
//
//  Lock-free algorithm by Alexander Terekhov
//
//  Thanks to Ben Hitchings for the #weak + (#shared != 0)
//  formulation
//

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>

#include <streams_boost/interprocess/detail/atomic.hpp>
#include <typeinfo>

namespace streams_boost {

namespace interprocess {

namespace detail {

class sp_counted_base
{
private:

    sp_counted_base( sp_counted_base const & );
    sp_counted_base & operator= ( sp_counted_base const & );

    streams_boost::uint32_t use_count_;        // #shared
    streams_boost::uint32_t weak_count_;       // #weak + (#shared != 0)

public:

    sp_counted_base(): use_count_( 1 ), weak_count_( 1 )
    {}

    ~sp_counted_base() // nothrow
    {}

    void add_ref_copy()
    {
        detail::atomic_inc32( &use_count_ );
    }

    bool add_ref_lock() // true on success
    {
        for( ;; )
        {
            streams_boost::uint32_t tmp = static_cast< streams_boost::uint32_t const volatile& >( use_count_ );
            if( tmp == 0 ) return false;
            if( detail::atomic_cas32( &use_count_, tmp + 1, tmp ) == tmp )
               return true;
        }
    }

   bool ref_release() // nothrow
   { return 1 == detail::atomic_dec32( &use_count_ );  }

   void weak_add_ref() // nothrow
   { detail::atomic_inc32( &weak_count_ ); }

   bool weak_release() // nothrow
   { return 1 == detail::atomic_dec32( &weak_count_ ); }

   long use_count() const // nothrow
   { return (long)static_cast<streams_boost::uint32_t const volatile &>( use_count_ ); }
};

} // namespace detail

} // namespace interprocess

} // namespace streams_boost

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif  // #ifndef STREAMS_BOOST_INTERPROCESS_DETAIL_SP_COUNTED_BASE_ATOMIC_HPP_INCLUDED
