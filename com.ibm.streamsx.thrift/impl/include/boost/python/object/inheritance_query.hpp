// Copyright David Abrahams 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef INHERITANCE_QUERY_DWA2003520_STREAMS_HPP
# define INHERITANCE_QUERY_DWA2003520_STREAMS_HPP

# include <streams_boost/python/type_id.hpp>

namespace streams_boost { namespace python { namespace objects {

STREAMS_BOOST_PYTHON_DECL void* find_static_type(void* p, type_info src, type_info dst);
STREAMS_BOOST_PYTHON_DECL void* find_dynamic_type(void* p, type_info src, type_info dst);

}}} // namespace streams_boost::python::object

#endif // INHERITANCE_QUERY_DWA2003520_STREAMS_HPP
