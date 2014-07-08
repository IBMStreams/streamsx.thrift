// Boost.Function library

//  Copyright Douglas Gregor 2001-2003. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org/libs/function

// William Kempf, Jesse Jones and Karl Nelson were all very helpful in the
// design of this library.

#include <functional> // unary_function, binary_function

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/detail/workaround.hpp>

#ifndef STREAMS_BOOST_FUNCTION_MAX_ARGS
#  define STREAMS_BOOST_FUNCTION_MAX_ARGS 10
#endif // STREAMS_BOOST_FUNCTION_MAX_ARGS

// Include the prologue here so that the use of file-level iteration
// in anything that may be included by function_template.hpp doesn't break
#include <streams_boost/function/detail/prologue.hpp>

// Visual Age C++ doesn't handle the file iteration well
#if STREAMS_BOOST_WORKAROUND(__IBMCPP__, >= 500)
#  if STREAMS_BOOST_FUNCTION_MAX_ARGS >= 0
#    include <streams_boost/function/function0.hpp>
#  endif
#  if STREAMS_BOOST_FUNCTION_MAX_ARGS >= 1
#    include <streams_boost/function/function1.hpp>
#  endif
#  if STREAMS_BOOST_FUNCTION_MAX_ARGS >= 2
#    include <streams_boost/function/function2.hpp>
#  endif
#  if STREAMS_BOOST_FUNCTION_MAX_ARGS >= 3
#    include <streams_boost/function/function3.hpp>
#  endif
#  if STREAMS_BOOST_FUNCTION_MAX_ARGS >= 4
#    include <streams_boost/function/function4.hpp>
#  endif
#  if STREAMS_BOOST_FUNCTION_MAX_ARGS >= 5
#    include <streams_boost/function/function5.hpp>
#  endif
#  if STREAMS_BOOST_FUNCTION_MAX_ARGS >= 6
#    include <streams_boost/function/function6.hpp>
#  endif
#  if STREAMS_BOOST_FUNCTION_MAX_ARGS >= 7
#    include <streams_boost/function/function7.hpp>
#  endif
#  if STREAMS_BOOST_FUNCTION_MAX_ARGS >= 8
#    include <streams_boost/function/function8.hpp>
#  endif
#  if STREAMS_BOOST_FUNCTION_MAX_ARGS >= 9
#    include <streams_boost/function/function9.hpp>
#  endif
#  if STREAMS_BOOST_FUNCTION_MAX_ARGS >= 10
#    include <streams_boost/function/function10.hpp>
#  endif
#else
// What is the '3' for?
#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (3,(0,STREAMS_BOOST_FUNCTION_MAX_ARGS,<streams_boost/function/detail/function_iterate.hpp>))
#  include STREAMS_BOOST_PP_ITERATE()
#  undef STREAMS_BOOST_PP_ITERATION_PARAMS_1
#endif
