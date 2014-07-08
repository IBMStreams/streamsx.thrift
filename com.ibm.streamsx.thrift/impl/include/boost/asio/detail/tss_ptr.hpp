//
// tss_ptr.hpp
// ~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_TSS_PTR_HPP
#define STREAMS_BOOST_ASIO_DETAIL_TSS_PTR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#if !defined(STREAMS_BOOST_HAS_THREADS)
# include <streams_boost/asio/detail/null_tss_ptr.hpp>
#elif defined(STREAMS_BOOST_WINDOWS)
# include <streams_boost/asio/detail/win_tss_ptr.hpp>
#elif defined(STREAMS_BOOST_HAS_PTHREADS)
# include <streams_boost/asio/detail/posix_tss_ptr.hpp>
#else
# error Only Windows and POSIX are supported!
#endif

namespace streams_boost {
namespace asio {
namespace detail {

template <typename T>
class tss_ptr
#if !defined(STREAMS_BOOST_HAS_THREADS)
  : public null_tss_ptr<T>
#elif defined(STREAMS_BOOST_WINDOWS)
  : public win_tss_ptr<T>
#elif defined(STREAMS_BOOST_HAS_PTHREADS)
  : public posix_tss_ptr<T>
#endif
{
public:
  void operator=(T* value)
  {
#if !defined(STREAMS_BOOST_HAS_THREADS)
    null_tss_ptr<T>::operator=(value);
#elif defined(STREAMS_BOOST_WINDOWS)
    win_tss_ptr<T>::operator=(value);
#elif defined(STREAMS_BOOST_HAS_PTHREADS)
    posix_tss_ptr<T>::operator=(value);
#endif
  }
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_TSS_PTR_HPP
