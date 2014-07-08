#ifndef STREAMS_BOOST_THREAD_CONDITION_VARIABLE_HPP
#define STREAMS_BOOST_THREAD_CONDITION_VARIABLE_HPP

//  condition_variable.hpp
//
//  (C) Copyright 2007 Anthony Williams 
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

#include <streams_boost/thread/detail/platform.hpp>
#if defined(STREAMS_BOOST_THREAD_PLATFORM_WIN32)
#include <streams_boost/thread/win32/condition_variable.hpp>
#elif defined(STREAMS_BOOST_THREAD_PLATFORM_PTHREAD)
#include <streams_boost/thread/pthread/condition_variable.hpp>
#else
#error "Boost threads unavailable on this platform"
#endif

#endif
