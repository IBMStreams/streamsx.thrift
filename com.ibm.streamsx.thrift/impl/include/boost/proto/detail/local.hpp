///////////////////////////////////////////////////////////////////////////////
/// \file local.hpp
/// Contains macros to ease the generation of repetitious code constructs
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PROTO_LOCAL_MACRO
# error "local iteration target macro is not defined"
#endif

#ifndef STREAMS_BOOST_PROTO_LOCAL_LIMITS
# define STREAMS_BOOST_PROTO_LOCAL_LIMITS (1, STREAMS_BOOST_PROTO_MAX_ARITY)
#endif

#ifndef STREAMS_BOOST_PROTO_LOCAL_typename_A
# define STREAMS_BOOST_PROTO_LOCAL_typename_A STREAMS_BOOST_PROTO_typename_A
#endif

#ifndef STREAMS_BOOST_PROTO_LOCAL_A
# define STREAMS_BOOST_PROTO_LOCAL_A STREAMS_BOOST_PROTO_A_const_ref
#endif

#ifndef STREAMS_BOOST_PROTO_LOCAL_A_a
# define STREAMS_BOOST_PROTO_LOCAL_A_a STREAMS_BOOST_PROTO_A_const_ref_a
#endif

#ifndef STREAMS_BOOST_PROTO_LOCAL_a
# define STREAMS_BOOST_PROTO_LOCAL_a STREAMS_BOOST_PROTO_ref_a
#endif

#define STREAMS_BOOST_PP_LOCAL_LIMITS STREAMS_BOOST_PROTO_LOCAL_LIMITS

#define STREAMS_BOOST_PP_LOCAL_MACRO(N)       \
  STREAMS_BOOST_PROTO_LOCAL_MACRO(            \
      N                               \
    , STREAMS_BOOST_PROTO_LOCAL_typename_A    \
    , STREAMS_BOOST_PROTO_LOCAL_A             \
    , STREAMS_BOOST_PROTO_LOCAL_A_a           \
    , STREAMS_BOOST_PROTO_LOCAL_a             \
  )                                   \
  /**/

#include STREAMS_BOOST_PP_LOCAL_ITERATE()

#undef STREAMS_BOOST_PROTO_LOCAL_MACRO
#undef STREAMS_BOOST_PROTO_LOCAL_LIMITS
#undef STREAMS_BOOST_PROTO_LOCAL_typename_A
#undef STREAMS_BOOST_PROTO_LOCAL_A
#undef STREAMS_BOOST_PROTO_LOCAL_A_a
#undef STREAMS_BOOST_PROTO_LOCAL_a
