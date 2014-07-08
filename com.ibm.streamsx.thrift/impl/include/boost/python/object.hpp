// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef OBJECT_DWA2002612_STREAMS_HPP
# define OBJECT_DWA2002612_STREAMS_HPP

# include <streams_boost/python/ssize_t.hpp>
# include <streams_boost/python/object_core.hpp>
# include <streams_boost/python/object_attributes.hpp>
# include <streams_boost/python/object_items.hpp>
# include <streams_boost/python/object_slices.hpp>
# include <streams_boost/python/object_operators.hpp>
# include <streams_boost/python/converter/arg_to_python.hpp>

namespace streams_boost { namespace python {

    inline ssize_t len(object const& obj)
    {
        ssize_t result = PyObject_Length(obj.ptr());
        if (PyErr_Occurred()) throw_error_already_set();
        return result;
    }

}} // namespace streams_boost::python

#endif // OBJECT_DWA2002612_STREAMS_HPP
