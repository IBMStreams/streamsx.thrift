// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef FIND_FROM_PYTHON_DWA2002223_STREAMS_HPP
# define FIND_FROM_PYTHON_DWA2002223_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/python/converter/rvalue_from_python_data.hpp>

namespace streams_boost { namespace python { namespace converter { 

struct registration;


STREAMS_BOOST_PYTHON_DECL void* get_lvalue_from_python(
    PyObject* source, registration const&);

STREAMS_BOOST_PYTHON_DECL bool implicit_rvalue_convertible_from_python(
    PyObject* source, registration const&);

STREAMS_BOOST_PYTHON_DECL rvalue_from_python_stage1_data rvalue_from_python_stage1(
    PyObject* source, registration const&);

STREAMS_BOOST_PYTHON_DECL void* rvalue_from_python_stage2(
    PyObject* source, rvalue_from_python_stage1_data&, registration const&);

STREAMS_BOOST_PYTHON_DECL void* rvalue_result_from_python(
    PyObject*, rvalue_from_python_stage1_data&);

STREAMS_BOOST_PYTHON_DECL void* reference_result_from_python(PyObject*, registration const&);
STREAMS_BOOST_PYTHON_DECL void* pointer_result_from_python(PyObject*, registration const&);

STREAMS_BOOST_PYTHON_DECL void void_result_from_python(PyObject*);

STREAMS_BOOST_PYTHON_DECL void throw_no_pointer_from_python(PyObject*, registration const&);
STREAMS_BOOST_PYTHON_DECL void throw_no_reference_from_python(PyObject*, registration const&);

}}} // namespace streams_boost::python::converter

#endif // FIND_FROM_PYTHON_DWA2002223_STREAMS_HPP
