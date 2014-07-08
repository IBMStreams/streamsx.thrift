// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef REGISTERED_POINTEE_DWA2002710_STREAMS_HPP
# define REGISTERED_POINTEE_DWA2002710_STREAMS_HPP
# include <streams_boost/python/converter/registered.hpp>
# include <streams_boost/python/converter/pointer_type_id.hpp>
# include <streams_boost/python/converter/registry.hpp>
# include <streams_boost/type_traits/transform_traits.hpp>
# include <streams_boost/type_traits/cv_traits.hpp>

namespace streams_boost { namespace python { namespace converter { 

struct registration;

# ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
template <class T>
struct registered_pointee
    : registered<
        typename remove_pointer<
           typename remove_cv<
              typename remove_reference<T>::type
           >::type
        >::type
    >
{
};
# else
namespace detail
{
  template <class T>
  struct registered_pointee_base
  {
      static registration const& converters;
  };
}

template <class T>
struct registered_pointee
    : detail::registered_pointee_base<
        typename add_reference<
           typename add_cv<T>::type
        >::type
    >
{
};

//
// implementations
//
namespace detail
{
  template <class T>
  registration const& registered_pointee_base<T>::converters
     = registry::lookup(pointer_type_id<T>());
}

# endif 
}}} // namespace streams_boost::python::converter

#endif // REGISTERED_POINTEE_DWA2002710_STREAMS_HPP
