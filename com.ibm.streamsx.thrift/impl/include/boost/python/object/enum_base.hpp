// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef ENUM_BASE_DWA200298_STREAMS_HPP
# define ENUM_BASE_DWA200298_STREAMS_HPP

# include <streams_boost/python/object_core.hpp>
# include <streams_boost/python/type_id.hpp>
# include <streams_boost/python/converter/to_python_function_type.hpp>
# include <streams_boost/python/converter/convertible_function.hpp>
# include <streams_boost/python/converter/constructor_function.hpp>

namespace streams_boost { namespace python { namespace objects { 

struct STREAMS_BOOST_PYTHON_DECL enum_base : python::api::object
{
 protected:
    enum_base(
        char const* name
        , converter::to_python_function_t
        , converter::convertible_function
        , converter::constructor_function
        , type_info
        , const char *doc = 0
        );

    void add_value(char const* name, long value);
    void export_values();
    
    static PyObject* to_python(PyTypeObject* type, long x);
};

}}} // namespace streams_boost::python::object

#endif // ENUM_BASE_DWA200298_STREAMS_HPP
