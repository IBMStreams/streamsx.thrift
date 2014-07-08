/* Copyright 2006-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/flyweight for library home page.
 */

#ifndef STREAMS_BOOST_FLYWEIGHT_DETAIL_PROCESS_ID_HPP
#define STREAMS_BOOST_FLYWEIGHT_DETAIL_PROCESS_ID_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#if defined(STREAMS_BOOST_WINDOWS)&&!defined(STREAMS_BOOST_DISABLE_WIN32)

#if defined(STREAMS_BOOST_USE_WINDOWS_H)
#include <windows.h>
#else
namespace streams_boost{
namespace flyweights{
namespace detail{

extern "C" __declspec(dllimport)
unsigned long __stdcall GetCurrentProcessId(void);

} /* namespace flyweights::detail */
} /* namespace flyweights */
} /* namespace streams_boost */
#endif

namespace streams_boost{

namespace flyweights{

namespace detail{

typedef unsigned long process_id_t;

inline process_id_t process_id()
{
  return GetCurrentProcessId();
}

} /* namespace flyweights::detail */

} /* namespace flyweights */

} /* namespace streams_boost */

#elif defined(STREAMS_BOOST_HAS_UNISTD_H)

#include <unistd.h>

namespace streams_boost{

namespace flyweights{

namespace detail{

typedef pid_t process_id_t;

inline process_id_t process_id()
{
  return ::getpid();
}

} /* namespace flyweights::detail */

} /* namespace flyweights */

} /* namespace streams_boost */

#else
#error Unknown platform
#endif

#endif
