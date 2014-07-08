// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef INSTANCE_DWA200295_STREAMS_HPP
# define INSTANCE_DWA200295_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/type_traits/alignment_traits.hpp>
# include <cstddef>

namespace streams_boost { namespace python
{
  struct STREAMS_BOOST_PYTHON_DECL_FORWARD instance_holder;
}} // namespace streams_boost::python

namespace streams_boost { namespace python { namespace objects { 

// Each extension instance will be one of these
template <class Data = char>
struct instance
{
    PyObject_VAR_HEAD
    PyObject* dict;
    PyObject* weakrefs; 
    instance_holder* objects;

    typedef typename type_with_alignment<
        ::streams_boost::alignment_of<Data>::value
    >::type align_t;
          
    union
    {
        align_t align;
        char bytes[sizeof(Data)];
    } storage;
};

template <class Data>
struct additional_instance_size
{
    typedef instance<Data> instance_data;
    typedef instance<char> instance_char;
    STREAMS_BOOST_STATIC_CONSTANT(
        std::size_t, value = sizeof(instance_data)
                           - STREAMS_BOOST_PYTHON_OFFSETOF(instance_char,storage));
};

}}} // namespace streams_boost::python::object

#endif // INSTANCE_DWA200295_STREAMS_HPP
