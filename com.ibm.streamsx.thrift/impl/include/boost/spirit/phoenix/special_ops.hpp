/*=============================================================================
  Copyright (c) 2001-2008 Joel de Guzman
  Copyright (c) 2001-2008 Hartmut Kaiser
  http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef STREAMS_BOOST_SPIRIT_DEPRECATED_INCLUDE_SPECIAL_OPS
#define STREAMS_BOOST_SPIRIT_DEPRECATED_INCLUDE_SPECIAL_OPS

#include <streams_boost/version.hpp>

#if STREAMS_BOOST_VERSION >= 103800
#if defined(_MSC_VER) || defined(__BORLANDC__) || defined(__DMC__)
#  pragma message ("Warning: This header is deprecated. Please use: streams_boost/spirit/include/phoenix1_special_ops.hpp")
#elif defined(__GNUC__) || defined(__HP_aCC) || defined(__SUNPRO_CC) || defined(__IBMCPP__)
#  warning "This header is deprecated. Please use: streams_boost/spirit/include/phoenix1_special_ops.hpp"
#endif
#endif

#include <streams_boost/spirit/include/phoenix1_special_ops.hpp>

#endif
