// Copyright (C) 2000 Stephen Cleary
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org for updates, documentation, and revision history.

#ifndef STREAMS_BOOST_POOL_GUARD_HPP
#define STREAMS_BOOST_POOL_GUARD_HPP

// Extremely Light-Weight guard glass

namespace streams_boost {

namespace details {
namespace pool {

template <typename Mutex>
class guard
{
  private:
    Mutex & mtx;

    guard(const guard &);
    void operator=(const guard &);

  public:
    explicit guard(Mutex & nmtx)
    :mtx(nmtx) { mtx.lock(); }

    ~guard() { mtx.unlock(); }
};

} // namespace pool
} // namespace details

} // namespace streams_boost

#endif
