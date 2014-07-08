//
// thread.hpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_THREAD_HPP
#define STREAMS_BOOST_ASIO_DETAIL_THREAD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if !defined(STREAMS_BOOST_HAS_THREADS)
# include <streams_boost/asio/detail/null_thread.hpp>
#elif defined(STREAMS_BOOST_WINDOWS)
# if defined(UNDER_CE)
#  include <streams_boost/asio/detail/wince_thread.hpp>
# else
#  include <streams_boost/asio/detail/win_thread.hpp>
# endif
#elif defined(STREAMS_BOOST_HAS_PTHREADS)
# include <streams_boost/asio/detail/posix_thread.hpp>
#else
# error Only Windows and POSIX are supported!
#endif

namespace streams_boost {
namespace asio {
namespace detail {

#if !defined(STREAMS_BOOST_HAS_THREADS)
typedef null_thread thread;
#elif defined(STREAMS_BOOST_WINDOWS)
# if defined(UNDER_CE)
typedef wince_thread thread;
# else
typedef win_thread thread;
# endif
#elif defined(STREAMS_BOOST_HAS_PTHREADS)
typedef posix_thread thread;
#endif

} // namespace detail
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_THREAD_HPP
