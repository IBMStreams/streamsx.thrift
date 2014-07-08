//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TR1_TUPLE_HPP_INCLUDED
#  define STREAMS_BOOST_TR1_TUPLE_HPP_INCLUDED
#  include <streams_boost/tr1/detail/config.hpp>

#ifdef STREAMS_BOOST_HAS_TR1_TUPLE

#  ifdef STREAMS_BOOST_HAS_INCLUDE_NEXT
#     include_next STREAMS_BOOST_TR1_HEADER(tuple)
#  else
#     include <streams_boost/tr1/detail/config_all.hpp>
#     include STREAMS_BOOST_TR1_STD_HEADER(STREAMS_BOOST_TR1_PATH(tuple))
#  endif

#else

#if defined(STREAMS_BOOST_TR1_USE_OLD_TUPLE)

#include <streams_boost/tuple/tuple.hpp>
#include <streams_boost/tuple/tuple_comparison.hpp>
#include <streams_boost/type_traits/integral_constant.hpp>

namespace std{ namespace tr1{

using ::streams_boost::tuple;

// [6.1.3.2] Tuple creation functions
using ::streams_boost::tuples::ignore;
using ::streams_boost::make_tuple;
using ::streams_boost::tie;

// [6.1.3.3] Tuple helper classes
template <class T> 
struct tuple_size 
   : public ::streams_boost::integral_constant
   < ::std::size_t, ::streams_boost::tuples::length<T>::value>
{};

template < int I, class T>
struct tuple_element
{
   typedef typename streams_boost::tuples::element<I,T>::type type;
};

#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x0582)
// [6.1.3.4] Element access
using ::streams_boost::get;
#endif

} } // namespaces

#else

#include <streams_boost/fusion/include/tuple.hpp>
#include <streams_boost/fusion/include/std_pair.hpp>

namespace std{ namespace tr1{

using ::streams_boost::fusion::tuple;

// [6.1.3.2] Tuple creation functions
using ::streams_boost::fusion::ignore;
using ::streams_boost::fusion::make_tuple;
using ::streams_boost::fusion::tie;
using ::streams_boost::fusion::get;

// [6.1.3.3] Tuple helper classes
using ::streams_boost::fusion::tuple_size;
using ::streams_boost::fusion::tuple_element;

}}

#endif

#endif

#endif

