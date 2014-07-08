// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef MODULE_INIT_DWA20020722_STREAMS_HPP
# define MODULE_INIT_DWA20020722_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>

# ifndef STREAMS_BOOST_PYTHON_MODULE_INIT

namespace streams_boost { namespace python { namespace detail {

STREAMS_BOOST_PYTHON_DECL PyObject* init_module(char const* name, void(*)());

}}}

#  if PY_VERSION_HEX >= 0x03000000

#   define _STREAMS_BOOST_PYTHON_MODULE_INIT(name)              \
PyObject* PyInit_##name()      \
{                                                       \
    return streams_boost::python::detail::init_module(          \
            #name,&init_module_##name);                 \
}                                                       \
void init_module_##name()

#  else

#   define _STREAMS_BOOST_PYTHON_MODULE_INIT(name)              \
void init##name()                                       \
{                                                       \
    streams_boost::python::detail::init_module(                 \
        #name,&init_module_##name);                     \
}                                                       \
void init_module_##name()

#  endif

#  if (defined(_WIN32) || defined(__CYGWIN__)) && !defined(STREAMS_BOOST_PYTHON_STATIC_MODULE)

#   define STREAMS_BOOST_PYTHON_MODULE_INIT(name)                           \
void init_module_##name();                                          \
extern "C" __declspec(dllexport) _STREAMS_BOOST_PYTHON_MODULE_INIT(name)

#  elif STREAMS_BOOST_PYTHON_USE_GCC_SYMBOL_VISIBILITY

#   define STREAMS_BOOST_PYTHON_MODULE_INIT(name)                               \
void init_module_##name();                                              \
extern "C" __attribute__ ((visibility("default"))) _STREAMS_BOOST_PYTHON_MODULE_INIT(name)

#  else

#   define STREAMS_BOOST_PYTHON_MODULE_INIT(name)                               \
void init_module_##name();                                              \
extern "C" _STREAMS_BOOST_PYTHON_MODULE_INIT(name)

#  endif

# endif 

#endif // MODULE_INIT_DWA20020722_STREAMS_HPP
