//
//  streams_boost/signals2/mutex.hpp - header-only mutex
//
//  Copyright (c) 2002, 2003 Peter Dimov and Multi Media Ltd.
//  Copyright (c) 2008 Frank Mori Hess
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  streams_boost::signals2::mutex is a modification of
//  streams_boost::detail::lightweight_mutex to follow the newer Lockable
//  concept of Boost.Thread.
//

#ifndef STREAMS_BOOST_SIGNALS2_MUTEX_HPP
#define STREAMS_BOOST_SIGNALS2_MUTEX_HPP

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/config.hpp>

#if !defined(STREAMS_BOOST_HAS_THREADS)
# include <streams_boost/signals2/detail/lwm_nop.hpp>
#elif defined(STREAMS_BOOST_HAS_PTHREADS)
#  include <streams_boost/signals2/detail/lwm_pthreads.hpp>
#elif defined(STREAMS_BOOST_HAS_WINTHREADS)
#  include <streams_boost/signals2/detail/lwm_win32_cs.hpp>
#else
// Use #define STREAMS_BOOST_DISABLE_THREADS to avoid the error
#  error Unrecognized threading platform
#endif

#endif // #ifndef STREAMS_BOOST_SIGNALS2_MUTEX_HPP
