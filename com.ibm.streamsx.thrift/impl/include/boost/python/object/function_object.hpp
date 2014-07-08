// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef FUNCTION_OBJECT_DWA2002725_STREAMS_HPP
# define FUNCTION_OBJECT_DWA2002725_STREAMS_HPP
# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/function/function2.hpp>
# include <streams_boost/python/object_core.hpp>
# include <streams_boost/python/args_fwd.hpp>
# include <streams_boost/python/object/py_function.hpp>

namespace streams_boost { namespace python {

namespace objects
{ 
  STREAMS_BOOST_PYTHON_DECL api::object function_object(
      py_function const& f
      , python::detail::keyword_range const&);

  STREAMS_BOOST_PYTHON_DECL api::object function_object(
      py_function const& f
      , python::detail::keyword_range const&);

  STREAMS_BOOST_PYTHON_DECL api::object function_object(py_function const& f);

  // Add an attribute to the name_space with the given name. If it is
  // a Boost.Python function object
  // (streams_boost/python/object/function.hpp), and an existing function is
  // already there, add it as an overload.
  STREAMS_BOOST_PYTHON_DECL void add_to_namespace(
      object const& name_space, char const* name, object const& attribute);

  STREAMS_BOOST_PYTHON_DECL void add_to_namespace(
      object const& name_space, char const* name, object const& attribute, char const* doc);
}

}} // namespace streams_boost::python::objects

#endif // FUNCTION_OBJECT_DWA2002725_STREAMS_HPP
