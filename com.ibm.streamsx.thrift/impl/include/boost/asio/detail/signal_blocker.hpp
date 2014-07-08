//
// signal_blocker.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_SIGNAL_BLOCKER_HPP
#define STREAMS_BOOST_ASIO_DETAIL_SIGNAL_BLOCKER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if !defined(STREAMS_BOOST_HAS_THREADS)
# include <streams_boost/asio/detail/null_signal_blocker.hpp>
#elif defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)
# include <streams_boost/asio/detail/win_signal_blocker.hpp>
#elif defined(STREAMS_BOOST_HAS_PTHREADS)
# include <streams_boost/asio/detail/posix_signal_blocker.hpp>
#else
# error Only Windows and POSIX are supported!
#endif

namespace streams_boost {
namespace asio {
namespace detail {

#if !defined(STREAMS_BOOST_HAS_THREADS)
typedef null_signal_blocker signal_blocker;
#elif defined(STREAMS_BOOST_WINDOWS) || defined(__CYGWIN__)
typedef win_signal_blocker signal_blocker;
#elif defined(STREAMS_BOOST_HAS_PTHREADS)
typedef posix_signal_blocker signal_blocker;
#endif

} // namespace detail
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_SIGNAL_BLOCKER_HPP
