//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_LOCK_OPTIONS_HPP
#define STREAMS_BOOST_INTERPROCESS_LOCK_OPTIONS_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>

//!\file
//!Describes the lock options with associated with interprocess_mutex lock constructors.

namespace streams_boost {

namespace posix_time
{  class ptime;   }

namespace interprocess {

//!Type to indicate to a mutex lock constructor that must not lock the mutex.
struct defer_lock_type{};
//!Type to indicate to a mutex lock constructor that must try to lock the mutex.
struct try_to_lock_type {};
//!Type to indicate to a mutex lock constructor that the mutex is already locked.
struct accept_ownership_type{};

//!An object indicating that the locking
//!must be deferred.
static const defer_lock_type      defer_lock      = defer_lock_type();

//!An object indicating that a try_lock()
//!operation must be executed.
static const try_to_lock_type     try_to_lock    = try_to_lock_type();

//!An object indicating that the ownership of lockable
//!object must be accepted by the new owner.
static const accept_ownership_type  accept_ownership = accept_ownership_type();

} // namespace interprocess {
} // namespace streams_boost{

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif // STREAMS_BOOST_INTERPROCESS_LOCK_OPTIONS_HPP
