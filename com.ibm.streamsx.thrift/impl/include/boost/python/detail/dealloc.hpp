// Copyright Gottfried Ganﬂauge 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

# ifndef STREAMS_BOOST_PYTHON_DETAIL_DEALLOC_HPP_
# define STREAMS_BOOST_PYTHON_DETAIL_DEALLOC_HPP_
namespace streams_boost { namespace python { namespace detail {
    extern "C"
    {
        inline void dealloc(PyObject* self)
        {
          PyObject_Del(self);
        }
    }
}}} // namespace streams_boost::python::detail
# endif    // STREAMS_BOOST_PYTHON_DETAIL_DEALLOC_HPP_
