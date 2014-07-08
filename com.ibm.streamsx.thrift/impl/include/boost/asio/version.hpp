//
// version.hpp
// ~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_VERSION_HPP
#define STREAMS_BOOST_ASIO_VERSION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

// STREAMS_BOOST_ASIO_VERSION % 100 is the sub-minor version
// STREAMS_BOOST_ASIO_VERSION / 100 % 1000 is the minor version
// STREAMS_BOOST_ASIO_VERSION / 100000 is the major version
#define STREAMS_BOOST_ASIO_VERSION 100404 // 1.4.4

#endif // STREAMS_BOOST_ASIO_VERSION_HPP
