// Copyright David Abrahams 2003. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef IS_READABLE_ITERATOR_DWA2003112_STREAMS_HPP
# define IS_READABLE_ITERATOR_DWA2003112_STREAMS_HPP

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/detail/iterator.hpp>

#include <streams_boost/type_traits/detail/bool_trait_def.hpp>
#include <streams_boost/iterator/detail/any_conversion_eater.hpp>

// should be the last #include
#include <streams_boost/iterator/detail/config_def.hpp>

#ifndef STREAMS_BOOST_NO_IS_CONVERTIBLE

namespace streams_boost {
 
namespace detail
{
  // Guts of is_readable_iterator.  Value is the iterator's value_type
  // and the result is computed in the nested rebind template.
  template <class Value>
  struct is_readable_iterator_impl
  {
      static char tester(Value&, int);
      static char (& tester(any_conversion_eater, ...) )[2];
    
      template <class It>
      struct rebind
      {
          static It& x;
          
          STREAMS_BOOST_STATIC_CONSTANT(
              bool
            , value = (
                sizeof(
                    is_readable_iterator_impl<Value>::tester(*x, 1)
                ) == 1
            )
          );
      };
  };

#undef STREAMS_BOOST_READABLE_PRESERVER
  
  //
  // void specializations to handle std input and output iterators
  //
  template <>
  struct is_readable_iterator_impl<void>
  {
      template <class It>
      struct rebind : streams_boost::mpl::false_
      {};
  };

#ifndef STREAMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
  template <>
  struct is_readable_iterator_impl<const void>
  {
      template <class It>
      struct rebind : streams_boost::mpl::false_
      {};
  };

  template <>
  struct is_readable_iterator_impl<volatile void>
  {
      template <class It>
      struct rebind : streams_boost::mpl::false_
      {};
  };

  template <>
  struct is_readable_iterator_impl<const volatile void>
  {
      template <class It>
      struct rebind : streams_boost::mpl::false_
      {};
  };
#endif

  //
  // This level of dispatching is required for Borland.  We might save
  // an instantiation by removing it for others.
  //
  template <class It>
  struct is_readable_iterator_impl2
    : is_readable_iterator_impl<
          STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::detail::iterator_traits<It>::value_type const
      >::template rebind<It>
  {};
} // namespace detail

// Define the trait with full mpl lambda capability and various broken
// compiler workarounds
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(
    is_readable_iterator,T,::streams_boost::detail::is_readable_iterator_impl2<T>::value)
    
} // namespace streams_boost

#endif

#include <streams_boost/iterator/detail/config_undef.hpp>

#endif // IS_READABLE_ITERATOR_DWA2003112_STREAMS_HPP
