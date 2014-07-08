// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef PYOBJECT_TRAITS_DWA2002720_STREAMS_HPP
# define PYOBJECT_TRAITS_DWA2002720_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/python/converter/pyobject_type.hpp>

namespace streams_boost { namespace python { namespace converter { 

template <class> struct pyobject_traits;

template <>
struct pyobject_traits<PyObject>
{
    // All objects are convertible to PyObject
    static bool check(PyObject*) { return true; }
    static PyObject* checked_downcast(PyObject* x) { return x; }
#ifndef STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES
    static PyTypeObject const* get_pytype() { return 0; }
#endif
};

//
// Specializations
//

# define STREAMS_BOOST_PYTHON_BUILTIN_OBJECT_TRAITS(T)                  \
    template <> struct pyobject_traits<Py##T##Object>           \
        : pyobject_type<Py##T##Object, &Py##T##_Type> {}

// This is not an exhaustive list; should be expanded.
STREAMS_BOOST_PYTHON_BUILTIN_OBJECT_TRAITS(Type);
STREAMS_BOOST_PYTHON_BUILTIN_OBJECT_TRAITS(List);
#if PY_VERSION_HEX < 0x03000000
STREAMS_BOOST_PYTHON_BUILTIN_OBJECT_TRAITS(Int);
#endif
STREAMS_BOOST_PYTHON_BUILTIN_OBJECT_TRAITS(Long);
STREAMS_BOOST_PYTHON_BUILTIN_OBJECT_TRAITS(Dict);
STREAMS_BOOST_PYTHON_BUILTIN_OBJECT_TRAITS(Tuple);

}}} // namespace streams_boost::python::converter

#endif // PYOBJECT_TRAITS_DWA2002720_STREAMS_HPP
