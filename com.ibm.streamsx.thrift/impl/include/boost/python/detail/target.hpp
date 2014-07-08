#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

# ifndef TARGET_DWA2002521_STREAMS_HPP
#  define TARGET_DWA2002521_STREAMS_HPP

#  include <streams_boost/python/detail/preprocessor.hpp>

#  include <streams_boost/type.hpp>

#  include <streams_boost/preprocessor/comma_if.hpp>
#  include <streams_boost/preprocessor/if.hpp>
#  include <streams_boost/preprocessor/iterate.hpp>
#  include <streams_boost/preprocessor/debug/line.hpp>
#  include <streams_boost/preprocessor/enum_params.hpp>
#  include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>

namespace streams_boost { namespace python { namespace detail {

#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                                                   \
    (4, (0, STREAMS_BOOST_PYTHON_MAX_ARITY, <streams_boost/python/detail/target.hpp>, STREAMS_BOOST_PYTHON_FUNCTION_POINTER))
#  include STREAMS_BOOST_PP_ITERATE()

#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                                                    \
    (4, (0, STREAMS_BOOST_PYTHON_CV_COUNT - 1, <streams_boost/python/detail/target.hpp>, STREAMS_BOOST_PYTHON_POINTER_TO_MEMBER))
#  include STREAMS_BOOST_PP_ITERATE()

template <class R, class T>
T& (* target(R (T::*)) )() { return 0; }

}}} // namespace streams_boost::python::detail

# endif // TARGET_DWA2002521_STREAMS_HPP

/* --------------- function pointers --------------- */
// For gcc 4.4 compatability, we must include the
// STREAMS_BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // STREAMS_BOOST_PP_IS_ITERATING
#if STREAMS_BOOST_PP_ITERATION_DEPTH() == 1 && STREAMS_BOOST_PP_ITERATION_FLAGS() == STREAMS_BOOST_PYTHON_FUNCTION_POINTER
# if !(STREAMS_BOOST_WORKAROUND(__MWERKS__, > 0x3100)                      \
        && STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3201)))
#  line STREAMS_BOOST_PP_LINE(__LINE__, target.hpp(function_pointers))
# endif 

# define N STREAMS_BOOST_PP_ITERATION()

template <class R STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, class A)>
STREAMS_BOOST_PP_IF(N, A0, void)(* target(R (*)(STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, A))) )()
{
    return 0;
}

# undef N

/* --------------- pointers-to-members --------------- */
#elif STREAMS_BOOST_PP_ITERATION_DEPTH() == 1 && STREAMS_BOOST_PP_ITERATION_FLAGS() == STREAMS_BOOST_PYTHON_POINTER_TO_MEMBER
// Outer over cv-qualifiers

# define STREAMS_BOOST_PP_ITERATION_PARAMS_2 (3, (0, STREAMS_BOOST_PYTHON_MAX_ARITY, <streams_boost/python/detail/target.hpp>))
# include STREAMS_BOOST_PP_ITERATE()

#elif STREAMS_BOOST_PP_ITERATION_DEPTH() == 2
# if !(STREAMS_BOOST_WORKAROUND(__MWERKS__, > 0x3100)                      \
        && STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3201)))
#  line STREAMS_BOOST_PP_LINE(__LINE__, target.hpp(pointers-to-members))
# endif 
// Inner over arities

# define N STREAMS_BOOST_PP_ITERATION()
# define Q STREAMS_BOOST_PYTHON_CV_QUALIFIER(STREAMS_BOOST_PP_RELATIVE_ITERATION(1))

template <class R, class T STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, class A)>
T& (* target(R (T::*)(STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, A)) Q) )()
{
    return 0;
}

# undef N
# undef Q

#endif // STREAMS_BOOST_PP_ITERATION_DEPTH()
#endif
