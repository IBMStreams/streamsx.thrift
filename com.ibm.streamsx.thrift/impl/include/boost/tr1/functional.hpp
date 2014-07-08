//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TR1_FUNCTIONAL_HPP_INCLUDED
#  define STREAMS_BOOST_TR1_FUNCTIONAL_HPP_INCLUDED
#  include <streams_boost/tr1/detail/config.hpp>
#  include <functional>

#if defined(STREAMS_BOOST_HAS_TR1_REFERENCE_WRAPPER) \
   || defined(STREAMS_BOOST_HAS_TR1_RESULT_OF)\
   || defined(STREAMS_BOOST_HAS_TR1_MEM_FN)\
   || defined(STREAMS_BOOST_HAS_TR1_BIND)\
   || defined(STREAMS_BOOST_HAS_TR1_FUNCTION)\
   || defined(STREAMS_BOOST_HAS_TR1_HASH)
#  ifdef STREAMS_BOOST_HAS_INCLUDE_NEXT
#     include_next STREAMS_BOOST_TR1_HEADER(functional)
#  else
#     include <streams_boost/tr1/detail/config_all.hpp>
#     include STREAMS_BOOST_TR1_STD_HEADER(STREAMS_BOOST_TR1_PATH(functional))
#  endif
#endif

#ifndef STREAMS_BOOST_HAS_TR1_REFERENCE_WRAPPER

#include <streams_boost/ref.hpp>

namespace std{ namespace tr1{

   using ::streams_boost::reference_wrapper;
   using ::streams_boost::ref;
   using ::streams_boost::cref;

} }

#endif  // STREAMS_BOOST_HAS_TR1_REFERENCE_WRAPPER

#if !defined(STREAMS_BOOST_HAS_TR1_RESULT_OF)\
   && !defined(STREAMS_BOOST_NO_SFINAE) && \
   !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

//
// we can only actually include result_of.hpp if the compiler
// really does support it, otherwise we just get endless errors...
//
#include <streams_boost/utility/result_of.hpp>

namespace std{ namespace tr1{

   using ::streams_boost::result_of;

} }

#endif // STREAMS_BOOST_HAS_TR1_RESULT_OF

#ifndef STREAMS_BOOST_HAS_TR1_MEM_FN
// mem_fn:
#include <streams_boost/mem_fn.hpp>

namespace std{ namespace tr1{

using streams_boost::mem_fn;

} }

#endif // STREAMS_BOOST_HAS_TR1_MEM_FN


#ifndef STREAMS_BOOST_HAS_TR1_BIND
// Bind:
#include <streams_boost/bind.hpp>

namespace std{ namespace tr1{

   using ::streams_boost::is_bind_expression;
   using ::streams_boost::is_placeholder;
   using ::streams_boost::bind;
   namespace placeholders {
#ifndef STREAMS_BOOST_BIND_NO_PLACEHOLDERS
      using ::_1;
      using ::_2;
      using ::_3;
      using ::_4;
      using ::_5;
      using ::_6;
      using ::_7;
      using ::_8;
      using ::_9;
#endif
   } // placeholders

} }

#endif

#ifndef STREAMS_BOOST_HAS_TR1_FUNCTION
// polymorphic function object wrappers:
#include <streams_boost/function.hpp>
#include <streams_boost/detail/workaround.hpp>

#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x582) \
    && !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1310) \
    && !defined(STREAMS_BOOST_FUNCTION_NO_FUNCTION_TYPE_SYNTAX)
namespace std{ namespace tr1{

   using ::streams_boost::bad_function_call;
   using ::streams_boost::function;
   using ::streams_boost::swap;

}}
#endif

#endif // STREAMS_BOOST_HAS_TR1_FUNCTION

#ifndef STREAMS_BOOST_HAS_TR1_HASH
//
// This header can get included by streams_boost/hash.hpp
// leading to cyclic dependencies.  As a workaround
// we forward declare streams_boost::hash and include
// the actual header later.
//
namespace streams_boost{
template <class T> struct hash;
}

namespace std{ namespace tr1{
   using ::streams_boost::hash;

}}

#include <streams_boost/functional/hash.hpp>

#endif

#endif

