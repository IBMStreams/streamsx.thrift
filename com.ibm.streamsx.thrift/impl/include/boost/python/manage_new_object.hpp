// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef MANAGE_NEW_OBJECT_DWA200222_STREAMS_HPP
# define MANAGE_NEW_OBJECT_DWA200222_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/python/detail/indirect_traits.hpp>
# include <streams_boost/mpl/if.hpp>
# include <streams_boost/python/to_python_indirect.hpp>
# include <streams_boost/type_traits/composite_traits.hpp>

namespace streams_boost { namespace python { 

namespace detail
{
  template <class R>
  struct manage_new_object_requires_a_pointer_return_type
# if defined(__GNUC__) && __GNUC__ >= 3 || defined(__EDG__)
  {}
# endif
  ;
}

struct manage_new_object
{
    template <class T>
    struct apply
    {
        typedef typename mpl::if_c<
            streams_boost::is_pointer<T>::value
            , to_python_indirect<T, detail::make_owning_holder>
            , detail::manage_new_object_requires_a_pointer_return_type<T>
        >::type type;
    };
};

}} // namespace streams_boost::python

#endif // MANAGE_NEW_OBJECT_DWA200222_STREAMS_HPP
