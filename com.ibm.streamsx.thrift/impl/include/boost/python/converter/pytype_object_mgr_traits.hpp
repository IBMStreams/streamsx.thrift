// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef PYTYPE_OBJECT_MANAGER_TRAITS_DWA2002716_STREAMS_HPP
# define PYTYPE_OBJECT_MANAGER_TRAITS_DWA2002716_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/python/detail/raw_pyobject.hpp>
# include <streams_boost/python/cast.hpp>
# include <streams_boost/python/converter/pyobject_type.hpp>
# include <streams_boost/python/errors.hpp>

namespace streams_boost { namespace python { namespace converter { 

// Provide a forward declaration as a convenience for clients, who all
// need it.
template <class T> struct object_manager_traits;

// Derive specializations of object_manager_traits from this class
// when T is an object manager for a particular Python type hierarchy.
//
template <PyTypeObject* pytype, class T>
struct pytype_object_manager_traits
    : pyobject_type<T, pytype> // provides check()
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_specialized = true);
    static inline python::detail::new_reference adopt(PyObject*);
};

//
// implementations
//
template <PyTypeObject* pytype, class T>
inline python::detail::new_reference pytype_object_manager_traits<pytype,T>::adopt(PyObject* x)
{
    return python::detail::new_reference(python::pytype_check(pytype, x));
}

}}} // namespace streams_boost::python::converter

#endif // PYTYPE_OBJECT_MANAGER_TRAITS_DWA2002716_STREAMS_HPP
