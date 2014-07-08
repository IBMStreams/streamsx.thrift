//  (C) Copyright John Maddock 2008.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TR1_UNORDERED_SET_HPP_INCLUDED
#  define STREAMS_BOOST_TR1_UNORDERED_SET_HPP_INCLUDED
#  include <streams_boost/tr1/detail/config.hpp>

#ifdef STREAMS_BOOST_HAS_TR1_UNORDERED_SET

#  ifdef STREAMS_BOOST_HAS_INCLUDE_NEXT
#     include_next STREAMS_BOOST_TR1_HEADER(unordered_set)
#  else
#     include <streams_boost/tr1/detail/config_all.hpp>
#     include STREAMS_BOOST_TR1_STD_HEADER(STREAMS_BOOST_TR1_PATH(unordered_set))
#  endif

#else

#include <streams_boost/unordered_set.hpp>

namespace std{ namespace tr1{

   using ::streams_boost::unordered_set;
   using ::streams_boost::unordered_multiset;
   using ::streams_boost::swap;

} } // namespaces

#endif

#endif
