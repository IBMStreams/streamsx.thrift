// Copyright Nikolay Mladenov 2007.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_PYTHON_OBJECT_PYTHON_TYPE_H
#define STREAMS_BOOST_PYTHON_OBJECT_PYTHON_TYPE_H

#include <streams_boost/python/converter/registered.hpp>

namespace streams_boost {namespace python {namespace detail{


template <class T> struct python_class : PyObject
{
    typedef python_class<T> this_type;

    typedef T type;

    static void *converter (PyObject *p){
        return p;
    }

    static void register_()
    {
        static bool first_time = true;

        if ( !first_time ) return;

        first_time = false;
        converter::registry::insert(&converter, streams_boost::python::type_id<this_type>(), &converter::registered_pytype_direct<T>::get_pytype);
    }
};


}}} //namespace streams_boost :: python :: detail

#endif //STREAMS_BOOST_PYTHON_OBJECT_PYTHON_TYPE_H
