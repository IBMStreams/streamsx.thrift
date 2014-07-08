#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

# ifndef CALL_DWA2002411_STREAMS_HPP
#  define CALL_DWA2002411_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>

#  include <streams_boost/type.hpp>

#  include <streams_boost/python/converter/arg_to_python.hpp>
#  include <streams_boost/python/converter/return_from_python.hpp>
#  include <streams_boost/python/detail/preprocessor.hpp>
#  include <streams_boost/python/detail/void_return.hpp>

#  include <streams_boost/preprocessor/comma_if.hpp>
#  include <streams_boost/preprocessor/iterate.hpp>
#  include <streams_boost/preprocessor/repeat.hpp>
#  include <streams_boost/preprocessor/debug/line.hpp>
#  include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>
#  include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

namespace streams_boost { namespace python {

# define STREAMS_BOOST_PYTHON_FAST_ARG_TO_PYTHON_GET(z, n, _) \
    , converter::arg_to_python<A##n>(a##n).get()

#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (3, (0, STREAMS_BOOST_PYTHON_MAX_ARITY, <streams_boost/python/call.hpp>))
#  include STREAMS_BOOST_PP_ITERATE()

#  undef STREAMS_BOOST_PYTHON_FAST_ARG_TO_PYTHON_GET

}} // namespace streams_boost::python

# endif // CALL_DWA2002411_STREAMS_HPP

// For gcc 4.4 compatability, we must include the
// STREAMS_BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // STREAMS_BOOST_PP_IS_ITERATING
#if STREAMS_BOOST_PP_ITERATION_DEPTH() == 1
# if !(STREAMS_BOOST_WORKAROUND(__MWERKS__, > 0x3100)                      \
        && STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3201)))
#  line STREAMS_BOOST_PP_LINE(__LINE__, call.hpp)
# endif

# define N STREAMS_BOOST_PP_ITERATION()

template <
    class R
    STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, class A)
    >
typename detail::returnable<R>::type
call(PyObject* callable
    STREAMS_BOOST_PP_COMMA_IF(N) STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(1, N, A, const& a)
    , streams_boost::type<R>* = 0
    )
{
    PyObject* const result = 
        PyEval_CallFunction(
            callable
            , const_cast<char*>("(" STREAMS_BOOST_PP_REPEAT_1ST(N, STREAMS_BOOST_PYTHON_FIXED, "O") ")")
            STREAMS_BOOST_PP_REPEAT_1ST(N, STREAMS_BOOST_PYTHON_FAST_ARG_TO_PYTHON_GET, nil)
            );
    
    // This conversion *must not* be done in the same expression as
    // the call, because, in the special case where the result is a
    // reference a Python object which was created by converting a C++
    // argument for passing to PyEval_CallFunction, its reference
    // count will be 2 until the end of the full expression containing
    // the conversion, and that interferes with dangling
    // pointer/reference detection.
    converter::return_from_python<R> converter;
    return converter(result);
}

# undef N

#endif // STREAMS_BOOST_PP_ITERATION_DEPTH()
#endif
