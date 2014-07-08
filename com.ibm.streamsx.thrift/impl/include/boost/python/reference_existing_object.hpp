// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef REFERENCE_EXISTING_OBJECT_DWA200222_STREAMS_HPP
# define REFERENCE_EXISTING_OBJECT_DWA200222_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/python/detail/indirect_traits.hpp>
# include <streams_boost/mpl/if.hpp>
# include <streams_boost/python/to_python_indirect.hpp>
# include <streams_boost/type_traits/composite_traits.hpp>

namespace streams_boost { namespace python { 

namespace detail
{
  template <class R>
  struct reference_existing_object_requires_a_pointer_or_reference_return_type
# if defined(__GNUC__) && __GNUC__ >= 3 || defined(__EDG__)
  {}
# endif
  ;
}

template <class T> struct to_python_value;

struct reference_existing_object
{
    template <class T>
    struct apply
    {
        STREAMS_BOOST_STATIC_CONSTANT(
            bool, ok = is_pointer<T>::value || is_reference<T>::value);
        
        typedef typename mpl::if_c<
            ok
            , to_python_indirect<T, detail::make_reference_holder>
            , detail::reference_existing_object_requires_a_pointer_or_reference_return_type<T>
        >::type type;
    };
};

}} // namespace streams_boost::python

#endif // REFERENCE_EXISTING_OBJECT_DWA200222_STREAMS_HPP
