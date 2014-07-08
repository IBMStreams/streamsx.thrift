#ifndef STREAMS_BOOST_SMART_PTR_DETAIL_LIGHTWEIGHT_MUTEX_HPP_INCLUDED
#define STREAMS_BOOST_SMART_PTR_DETAIL_LIGHTWEIGHT_MUTEX_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  streams_boost/detail/lightweight_mutex.hpp - lightweight mutex
//
//  Copyright (c) 2002, 2003 Peter Dimov and Multi Media Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  typedef <unspecified> streams_boost::detail::lightweight_mutex;
//
//  streams_boost::detail::lightweight_mutex is a header-only implementation of
//  a subset of the Mutex concept requirements:
//
//  http://www.streams_boost.org/doc/html/threads/concepts.html#threads.concepts.Mutex
//
//  It maps to a CRITICAL_SECTION on Windows or a pthread_mutex on POSIX.
//

#include <streams_boost/config.hpp>

#if !defined(STREAMS_BOOST_HAS_THREADS)
#  include <streams_boost/smart_ptr/detail/lwm_nop.hpp>
#elif defined(STREAMS_BOOST_HAS_PTHREADS)
#  include <streams_boost/smart_ptr/detail/lwm_pthreads.hpp>
#elif defined(STREAMS_BOOST_HAS_WINTHREADS) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#  include <streams_boost/smart_ptr/detail/lwm_win32_cs.hpp>
#else
// Use #define STREAMS_BOOST_DISABLE_THREADS to avoid the error
#  error Unrecognized threading platform
#endif

#endif // #ifndef STREAMS_BOOST_SMART_PTR_DETAIL_LIGHTWEIGHT_MUTEX_HPP_INCLUDED
