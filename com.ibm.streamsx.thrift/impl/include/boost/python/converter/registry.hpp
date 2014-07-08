//  Copyright David Abrahams 2001.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef REGISTRY_DWA20011127_STREAMS_HPP
# define REGISTRY_DWA20011127_STREAMS_HPP
# include <streams_boost/python/type_id.hpp>
# include <streams_boost/python/converter/to_python_function_type.hpp>
# include <streams_boost/python/converter/rvalue_from_python_data.hpp>
# include <streams_boost/python/converter/constructor_function.hpp>
# include <streams_boost/python/converter/convertible_function.hpp>

namespace streams_boost { namespace python { namespace converter {

struct registration;

// This namespace acts as a sort of singleton
namespace registry
{
  // Get the registration corresponding to the type, creating it if necessary
  STREAMS_BOOST_PYTHON_DECL registration const& lookup(type_info);

  // Get the registration corresponding to the type, creating it if
  // necessary.  Use this first when the type is a shared_ptr.
  STREAMS_BOOST_PYTHON_DECL registration const& lookup_shared_ptr(type_info);

  // Return a pointer to the corresponding registration, if one exists
  STREAMS_BOOST_PYTHON_DECL registration const* query(type_info);
  
  STREAMS_BOOST_PYTHON_DECL void insert(to_python_function_t, type_info, PyTypeObject const* (*to_python_target_type)() = 0);

  // Insert an lvalue from_python converter
  STREAMS_BOOST_PYTHON_DECL void insert(void* (*convert)(PyObject*), type_info, PyTypeObject const* (*expected_pytype)() = 0);

  // Insert an rvalue from_python converter
  STREAMS_BOOST_PYTHON_DECL void insert(
      convertible_function
      , constructor_function
      , type_info
      , PyTypeObject const* (*expected_pytype)()  = 0
      );
  
  // Insert an rvalue from_python converter at the tail of the
  // chain. Used for implicit conversions
  STREAMS_BOOST_PYTHON_DECL void push_back(
      convertible_function
      , constructor_function
      , type_info
      , PyTypeObject const* (*expected_pytype)()  = 0
      );
}

}}} // namespace streams_boost::python::converter

#endif // REGISTRY_DWA20011127_STREAMS_HPP
