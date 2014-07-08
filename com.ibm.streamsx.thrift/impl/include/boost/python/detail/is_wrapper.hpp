// Copyright David Abrahams 2004. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef IS_WRAPPER_DWA2004723_STREAMS_HPP
# define IS_WRAPPER_DWA2004723_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/mpl/bool.hpp>

namespace streams_boost { namespace python {

template <class T> class wrapper;

namespace detail
{
  typedef char (&is_not_wrapper)[2];
  is_not_wrapper is_wrapper_helper(...);
  template <class T>
  char is_wrapper_helper(wrapper<T> const volatile*);

  // A metafunction returning true iff T is [derived from] wrapper<U> 
  template <class T>
  struct is_wrapper
    : mpl::bool_<(sizeof(detail::is_wrapper_helper((T*)0)) == 1)>
  {};

}}} // namespace streams_boost::python::detail

#endif // IS_WRAPPER_DWA2004723_STREAMS_HPP
