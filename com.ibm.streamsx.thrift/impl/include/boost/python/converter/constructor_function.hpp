// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef CONSTRUCTOR_FUNCTION_DWA200278_STREAMS_HPP
# define CONSTRUCTOR_FUNCTION_DWA200278_STREAMS_HPP

namespace streams_boost { namespace python { namespace converter { 

// Declares the type of functions used to construct C++ objects for
// rvalue from_python conversions.
struct rvalue_from_python_stage1_data;
typedef void (*constructor_function)(PyObject* source, rvalue_from_python_stage1_data*);

}}} // namespace streams_boost::python::converter

#endif // CONSTRUCTOR_FUNCTION_DWA200278_STREAMS_HPP
