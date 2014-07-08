// (C) Copyright David Abrahams 2001.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPE_DWA20010120_STREAMS_HPP
# define STREAMS_BOOST_TYPE_DWA20010120_STREAMS_HPP

namespace streams_boost {

  // Just a simple "type envelope". Useful in various contexts, mostly to work
  // around some MSVC deficiencies.
  template <class T>
  struct type {};

}

#endif // STREAMS_BOOST_TYPE_DWA20010120_STREAMS_HPP
