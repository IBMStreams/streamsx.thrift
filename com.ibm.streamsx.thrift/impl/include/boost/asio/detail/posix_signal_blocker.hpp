//
// posix_signal_blocker.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_POSIX_SIGNAL_BLOCKER_STREAMS_HPP
#define STREAMS_BOOST_ASIO_DETAIL_POSIX_SIGNAL_BLOCKER_STREAMS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if defined(STREAMS_BOOST_HAS_PTHREADS)

#include <streams_boost/asio/detail/push_options.hpp>
#include <csignal>
#include <pthread.h>
#include <signal.h>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/detail/noncopyable.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

class posix_signal_blocker
  : private noncopyable
{
public:
  // Constructor blocks all signals for the calling thread.
  posix_signal_blocker()
    : blocked_(false)
  {
    sigset_t new_mask;
    sigfillset(&new_mask);
    blocked_ = (pthread_sigmask(SIG_BLOCK, &new_mask, &old_mask_) == 0);
  }

  // Destructor restores the previous signal mask.
  ~posix_signal_blocker()
  {
    if (blocked_)
      pthread_sigmask(SIG_SETMASK, &old_mask_, 0);
  }

  // Block all signals for the calling thread.
  void block()
  {
    if (!blocked_)
    {
      sigset_t new_mask;
      sigfillset(&new_mask);
      blocked_ = (pthread_sigmask(SIG_BLOCK, &new_mask, &old_mask_) == 0);
    }
  }

  // Restore the previous signal mask.
  void unblock()
  {
    if (blocked_)
      blocked_ = (pthread_sigmask(SIG_SETMASK, &old_mask_, 0) != 0);
  }

private:
  // Have signals been blocked.
  bool blocked_;

  // The previous signal mask.
  sigset_t old_mask_;
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#endif // defined(STREAMS_BOOST_HAS_PTHREADS)

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_POSIX_SIGNAL_BLOCKER_STREAMS_HPP
