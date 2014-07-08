//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 49312 $
//
//  Description : optional internal tracing
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_TRACE_HPP_062604GER
#define STREAMS_BOOST_RT_TRACE_HPP_062604GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>

#ifdef STREAMS_BOOST_RT_PARAM_DEBUG

#include <iostream>

#  define STREAMS_BOOST_RT_PARAM_TRACE( str ) std::cerr << str << std::endl
#else
#  define STREAMS_BOOST_RT_PARAM_TRACE( str )
#endif

#endif // STREAMS_BOOST_RT_TRACE_HPP_062604GER
