#ifndef STREAMS_BOOST_THREAD_ONCE_HPP
#define STREAMS_BOOST_THREAD_ONCE_HPP

//  once.hpp
//
//  (C) Copyright 2006-7 Anthony Williams 
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

#include <streams_boost/thread/detail/platform.hpp>
#if defined(STREAMS_BOOST_THREAD_PLATFORM_WIN32)
#include <streams_boost/thread/win32/once.hpp>
#elif defined(STREAMS_BOOST_THREAD_PLATFORM_PTHREAD)
#include <streams_boost/thread/pthread/once.hpp>
#else
#error "Boost threads unavailable on this platform"
#endif

#include <streams_boost/config/abi_prefix.hpp>

namespace streams_boost
{
    inline void call_once(void (*func)(),once_flag& flag)
    {
        call_once(flag,func);
    }
}

#include <streams_boost/config/abi_suffix.hpp>

#endif
