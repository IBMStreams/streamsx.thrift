// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef IMPLICIT_DWA2002326_STREAMS_HPP
# define IMPLICIT_DWA2002326_STREAMS_HPP

# include <streams_boost/python/converter/rvalue_from_python_data.hpp>
# include <streams_boost/python/converter/registrations.hpp>
# include <streams_boost/python/converter/registered.hpp>

# include <streams_boost/python/extract.hpp>

namespace streams_boost { namespace python { namespace converter { 

template <class Source, class Target>
struct implicit
{
    static void* convertible(PyObject* obj)
    {
        // Find a converter which can produce a Source instance from
        // obj. The user has told us that Source can be converted to
        // Target, and instantiating construct() below, ensures that
        // at compile-time.
        return implicit_rvalue_convertible_from_python(obj, registered<Source>::converters)
            ? obj : 0;
    }
      
    static void construct(PyObject* obj, rvalue_from_python_stage1_data* data)
    {
        void* storage = ((rvalue_from_python_storage<Target>*)data)->storage.bytes;

        arg_from_python<Source> get_source(obj);
        bool convertible = get_source.convertible();
        STREAMS_BOOST_VERIFY(convertible);
        
        new (storage) Target(get_source());
        
        // record successful construction
        data->convertible = storage;
    }
};

}}} // namespace streams_boost::python::converter

#endif // IMPLICIT_DWA2002326_STREAMS_HPP
