
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef STREAMS_BOOST_FT_DETAIL_TO_SEQUENCE_HPP_INCLUDED
#define STREAMS_BOOST_FT_DETAIL_TO_SEQUENCE_HPP_INCLUDED

#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/is_sequence.hpp>
#include <streams_boost/mpl/placeholders.hpp>
#include <streams_boost/type_traits/add_reference.hpp>

#include <streams_boost/function_types/is_callable_builtin.hpp>

namespace streams_boost { namespace function_types { namespace detail {

// wrap first arguments in components, if callable builtin type
template<typename T>
struct to_sequence
{
  typedef typename
   mpl::eval_if
   < is_callable_builtin<T>
   , to_sequence< components<T> >
   , mpl::identity< T >
   >::type
  type;
};

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
// reduce template instantiations, if possible
template<typename T, typename U>
struct to_sequence< components<T,U> > 
{
  typedef typename components<T,U>::types type;
};
#endif

} } } // namespace ::streams_boost::function_types::detail

#endif

