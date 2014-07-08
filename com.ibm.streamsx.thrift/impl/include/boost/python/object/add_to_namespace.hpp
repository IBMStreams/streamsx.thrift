// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef ADD_TO_NAMESPACE_DWA200286_STREAMS_HPP
# define ADD_TO_NAMESPACE_DWA200286_STREAMS_HPP

# include <streams_boost/python/object_fwd.hpp>

namespace streams_boost { namespace python { namespace objects { 

//
// A setattr that's "smart" about function overloading (and docstrings).
//
STREAMS_BOOST_PYTHON_DECL void add_to_namespace(
    object const& name_space, char const* name, object const& attribute);

STREAMS_BOOST_PYTHON_DECL void add_to_namespace(
    object const& name_space, char const* name, object const& attribute, char const* doc);

}}} // namespace streams_boost::python::objects

#endif // ADD_TO_NAMESPACE_DWA200286_STREAMS_HPP
