#ifndef OTHER_DWA20020601_STREAMS_HPP
# define OTHER_DWA20020601_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

# if _MSC_VER+0 >= 1020
#  pragma once
# endif

# include <streams_boost/config.hpp>

namespace streams_boost { namespace python {

template<class T> struct other
{ 
    typedef T type;
};

# ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
namespace detail
{
  template<typename T>
  class is_other
  {
   public:
      STREAMS_BOOST_STATIC_CONSTANT(bool, value = false); 
  };

  template<typename T>
  class is_other<other<T> >
  {
   public:
      STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
  };

  template<typename T>
  class unwrap_other
  {
   public:
      typedef T type;
  };

  template<typename T>
  class unwrap_other<other<T> >
  {
   public:
      typedef T type;
  };
}
# else // no partial specialization

}} // namespace streams_boost::python

#include <streams_boost/type.hpp>

namespace streams_boost { namespace python {

namespace detail
{
  typedef char (&yes_other_t)[1];
  typedef char (&no_other_t)[2];
      
  no_other_t is_other_test(...);

  template<typename T>
  yes_other_t is_other_test(type< other<T> >);

  template<bool wrapped>
  struct other_unwrapper
  {
      template <class T>
      struct apply
      {
          typedef T type;
      };
  };

  template<>
  struct other_unwrapper<true>
  {
      template <class T>
      struct apply
      {
          typedef typename T::type type;
      };
  };

  template<typename T>
  class is_other
  {
   public:
      STREAMS_BOOST_STATIC_CONSTANT(
          bool, value = (
              sizeof(detail::is_other_test(type<T>()))
              == sizeof(detail::yes_other_t)));
  };

  template <typename T>
  class unwrap_other
      : public detail::other_unwrapper<
      is_other<T>::value
  >::template apply<T>
  {};
}

# endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

}} // namespace streams_boost::python

#endif // #ifndef OTHER_DWA20020601_STREAMS_HPP
