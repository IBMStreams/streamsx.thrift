/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga  2009-2009.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTRUSIVE_DETAIL_IS_STATEFUL_VALUE_TRAITS_HPP
#define STREAMS_BOOST_INTRUSIVE_DETAIL_IS_STATEFUL_VALUE_TRAITS_HPP

#include <streams_boost/intrusive/detail/config_begin.hpp>

#if defined(_MSC_VER) && (_MSC_VER <= 1310)

#include <streams_boost/intrusive/detail/mpl.hpp>

namespace streams_boost {
namespace intrusive {
namespace detail {

template<class ValueTraits>
struct is_stateful_value_traits
{
   static const bool value = !detail::is_empty_class<ValueTraits>::value;
};

}}}

#else

#include <streams_boost/intrusive/detail/function_detector.hpp>

STREAMS_BOOST_INTRUSIVE_CREATE_FUNCTION_DETECTOR(to_node_ptr, streams_boost_intrusive)
STREAMS_BOOST_INTRUSIVE_CREATE_FUNCTION_DETECTOR(to_value_ptr, streams_boost_intrusive)

namespace streams_boost {
namespace intrusive {
namespace detail {

template<class ValueTraits>
struct is_stateful_value_traits
{
   typedef typename ValueTraits::node_ptr       node_ptr;
   typedef typename ValueTraits::pointer        pointer;
   typedef typename ValueTraits::value_type     value_type;
   typedef typename ValueTraits::const_node_ptr const_node_ptr;
   typedef typename ValueTraits::const_pointer  const_pointer;

   typedef ValueTraits value_traits;

   static const bool value =
      (streams_boost::intrusive::function_detector::NonStaticFunction ==
         (STREAMS_BOOST_INTRUSIVE_DETECT_FUNCTION(ValueTraits, streams_boost_intrusive, node_ptr, to_node_ptr, (value_type&) )))
      ||
      (streams_boost::intrusive::function_detector::NonStaticFunction ==
         (STREAMS_BOOST_INTRUSIVE_DETECT_FUNCTION(ValueTraits, streams_boost_intrusive, pointer, to_value_ptr, (node_ptr) )))
      ||
      (streams_boost::intrusive::function_detector::NonStaticFunction ==
         (STREAMS_BOOST_INTRUSIVE_DETECT_FUNCTION(ValueTraits, streams_boost_intrusive, const_node_ptr, to_node_ptr, (const value_type&) )))
      ||
      (streams_boost::intrusive::function_detector::NonStaticFunction ==
         (STREAMS_BOOST_INTRUSIVE_DETECT_FUNCTION(ValueTraits, streams_boost_intrusive, const_pointer, to_value_ptr, (const_node_ptr) )))
      ;
};

}}}

#endif

#include <streams_boost/intrusive/detail/config_end.hpp>

#endif   //@ifndef STREAMS_BOOST_INTRUSIVE_DETAIL_IS_STATEFUL_VALUE_TRAITS_HPP