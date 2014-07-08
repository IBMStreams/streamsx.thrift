// Boost.Function library - Typeof support
//  Copyright (C) Douglas Gregor 2008
//
//  Use, modification and distribution is subject to the Boost
//  Software License, Version 1.0.  (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org
#ifndef STREAMS_BOOST_FUNCTION_TYPEOF_HPP
#define STREAMS_BOOST_FUNCTION_TYPEOF_HPP
#include <streams_boost/function/function_fwd.hpp>
#include <streams_boost/typeof/typeof.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::bad_function_call)

#if !defined(STREAMS_BOOST_FUNCTION_NO_FUNCTION_TYPE_SYNTAX)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::function, (typename))
#endif

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::function0, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::function1, (typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::function2, (typename)(typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::function3, 
  (typename)(typename)(typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::function4, 
  (typename)(typename)(typename)(typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::function5, 
  (typename)(typename)(typename)(typename)(typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::function6, 
  (typename)(typename)(typename)(typename)(typename)(typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::function7, 
  (typename)(typename)(typename)(typename)(typename)(typename)(typename)
  (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::function8, 
  (typename)(typename)(typename)(typename)(typename)(typename)(typename)
  (typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::function9, 
  (typename)(typename)(typename)(typename)(typename)(typename)(typename)
  (typename)(typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::function10, 
  (typename)(typename)(typename)(typename)(typename)(typename)(typename)
  (typename)(typename)(typename)(typename))
#endif
