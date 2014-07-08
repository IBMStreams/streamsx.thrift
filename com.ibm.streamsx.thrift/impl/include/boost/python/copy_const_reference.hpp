// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef COPY_CONST_REFERENCE_DWA2002131_STREAMS_HPP
# define COPY_CONST_REFERENCE_DWA2002131_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/python/detail/indirect_traits.hpp>
# include <streams_boost/mpl/if.hpp>
# include <streams_boost/python/to_python_value.hpp>

namespace streams_boost { namespace python { 

namespace detail
{
  template <class R>
  struct copy_const_reference_expects_a_const_reference_return_type
# if defined(__GNUC__) && __GNUC__ >= 3 || defined(__EDG__)
  {}
# endif
  ;
}

template <class T> struct to_python_value;

struct copy_const_reference
{
    template <class T>
    struct apply
    {
        typedef typename mpl::if_c<
            indirect_traits::is_reference_to_const<T>::value
          , to_python_value<T>
          , detail::copy_const_reference_expects_a_const_reference_return_type<T>
        >::type type;
    };
};


}} // namespace streams_boost::python

#endif // COPY_CONST_REFERENCE_DWA2002131_STREAMS_HPP
