// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef CLASS_DETAIL_DWA200295_STREAMS_HPP
# define CLASS_DETAIL_DWA200295_STREAMS_HPP

# include <streams_boost/python/handle.hpp>
# include <streams_boost/python/type_id.hpp>

namespace streams_boost { namespace python { namespace objects { 

STREAMS_BOOST_PYTHON_DECL type_handle registered_class_object(type_info id);
STREAMS_BOOST_PYTHON_DECL type_handle class_metatype();
STREAMS_BOOST_PYTHON_DECL type_handle class_type();

}}} // namespace streams_boost::python::object

#endif // CLASS_DETAIL_DWA200295_STREAMS_HPP
