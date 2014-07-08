// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef ARG_FROM_PYTHON_DWA2002128_STREAMS_HPP
# define ARG_FROM_PYTHON_DWA2002128_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/python/converter/arg_from_python.hpp>
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, STREAMS_BOOST_TESTED_AT(1400)) \
    || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_INTEL_WIN, STREAMS_BOOST_TESTED_AT(800))
# include <streams_boost/type_traits/remove_cv.hpp>
#endif

namespace streams_boost { namespace python { 

template <class T>
struct arg_from_python
    : converter::select_arg_from_python<
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, STREAMS_BOOST_TESTED_AT(1400)) \
    || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_INTEL_WIN, STREAMS_BOOST_TESTED_AT(800))
          typename streams_boost::remove_cv<T>::type
# else
          T
# endif 
      >::type
{
    typedef typename converter::select_arg_from_python<
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, STREAMS_BOOST_TESTED_AT(1400)) \
    || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_INTEL_WIN, STREAMS_BOOST_TESTED_AT(800))
          typename streams_boost::remove_cv<T>::type
# else
          T
# endif 
        >::type base;
    
    arg_from_python(PyObject*);
};

// specialization for PyObject*
template <>
struct arg_from_python<PyObject*>
{
    typedef PyObject* result_type;
    
    arg_from_python(PyObject* p) : m_source(p) {}
    bool convertible() const { return true; }
    PyObject* operator()() const { return m_source; }
 private:
    PyObject* m_source;
};

template <>
struct arg_from_python<PyObject* const&>
{
    typedef PyObject* const& result_type;
    
    arg_from_python(PyObject* p) : m_source(p) {}
    bool convertible() const { return true; }
    PyObject*const& operator()() const { return m_source; }
 private:
    PyObject* m_source;
};

//
// implementations
//
template <class T>
inline arg_from_python<T>::arg_from_python(PyObject* source)
    : base(source)
{
}

}} // namespace streams_boost::python

#endif // ARG_FROM_PYTHON_DWA2002128_STREAMS_HPP
