#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

# ifndef RESULT_DWA2002521_STREAMS_HPP
#  define RESULT_DWA2002521_STREAMS_HPP

#  include <streams_boost/type.hpp>

#  include <streams_boost/python/detail/preprocessor.hpp>

#  include <streams_boost/type_traits/object_traits.hpp>
#  include <streams_boost/mpl/if.hpp>

#  include <streams_boost/preprocessor/comma_if.hpp>
#  include <streams_boost/preprocessor/iterate.hpp>
#  include <streams_boost/preprocessor/debug/line.hpp>
#  include <streams_boost/preprocessor/enum_params.hpp>
#  include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>

namespace streams_boost { namespace python { namespace detail {

// Defines a family of overloaded function which, given x, a function
// pointer, member [function] pointer, or an AdaptableFunction object,
// returns a pointer to type<R>*, where R is the result type of
// invoking the result of bind(x).
//
// In order to work around bugs in deficient compilers, if x might be
// an AdaptableFunction object, you must pass OL as a second argument
// to get this to work portably.

#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                                                   \
    (4, (0, STREAMS_BOOST_PYTHON_MAX_ARITY, <streams_boost/python/detail/result.hpp>, STREAMS_BOOST_PYTHON_FUNCTION_POINTER))
#  include STREAMS_BOOST_PP_ITERATE()

#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                                                     \
    (4, (0, STREAMS_BOOST_PYTHON_CV_COUNT - 1, <streams_boost/python/detail/result.hpp>, STREAMS_BOOST_PYTHON_POINTER_TO_MEMBER))
#  include STREAMS_BOOST_PP_ITERATE()

template <class R, class T>
streams_boost::type<R>* result(R (T::*), int = 0) { return 0; }

#  if (defined(STREAMS_BOOST_MSVC) && _MSC_FULL_VER <= 13102140)  \
   || (defined(__GNUC__) && __GNUC__ < 3)                 \
   || (defined(__MWERKS__) && __MWERKS__ < 0x3000)
// This code actually works on all implementations, but why use it when we don't have to?
template <class T>
struct get_result_type
{
    typedef streams_boost::type<typename T::result_type> type;
};

struct void_type
{
    typedef void type;
};

template <class T>
struct result_result
{
    typedef typename mpl::if_c<
        is_class<T>::value
        , get_result_type<T>
        , void_type
        >::type t1;

    typedef typename t1::type* type;
};

template <class X>
typename result_result<X>::type
result(X const&, short) { return 0; }

#  else // Simpler code for more-capable compilers
template <class X>
streams_boost::type<typename X::result_type>*
result(X const&, short = 0) { return 0; }

#  endif

}}} // namespace streams_boost::python::detail

# endif // RESULT_DWA2002521_STREAMS_HPP

/* --------------- function pointers --------------- */
// For gcc 4.4 compatability, we must include the
// STREAMS_BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // STREAMS_BOOST_PP_IS_ITERATING
#if STREAMS_BOOST_PP_ITERATION_DEPTH() == 1 && STREAMS_BOOST_PP_ITERATION_FLAGS() == STREAMS_BOOST_PYTHON_FUNCTION_POINTER
# if !(STREAMS_BOOST_WORKAROUND(__MWERKS__, > 0x3100)                      \
        && STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3201)))
#  line STREAMS_BOOST_PP_LINE(__LINE__, result.hpp(function pointers))
# endif

# define N STREAMS_BOOST_PP_ITERATION()

template <class R STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, class A)>
streams_boost::type<R>* result(R (*)(STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, A)), int = 0)
{
    return 0;
}

# undef N

/* --------------- pointers-to-members --------------- */
#elif STREAMS_BOOST_PP_ITERATION_DEPTH() == 1 && STREAMS_BOOST_PP_ITERATION_FLAGS() == STREAMS_BOOST_PYTHON_POINTER_TO_MEMBER
// Outer over cv-qualifiers

# define STREAMS_BOOST_PP_ITERATION_PARAMS_2 (3, (0, STREAMS_BOOST_PYTHON_MAX_ARITY, <streams_boost/python/detail/result.hpp>))
# include STREAMS_BOOST_PP_ITERATE()

#elif STREAMS_BOOST_PP_ITERATION_DEPTH() == 2
# if !(STREAMS_BOOST_WORKAROUND(__MWERKS__, > 0x3100)                      \
        && STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3201)))
#  line STREAMS_BOOST_PP_LINE(__LINE__, result.hpp(pointers-to-members))
# endif 
// Inner over arities

# define N STREAMS_BOOST_PP_ITERATION()
# define Q STREAMS_BOOST_PYTHON_CV_QUALIFIER(STREAMS_BOOST_PP_RELATIVE_ITERATION(1))

template <class R, class T STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, class A)>
streams_boost::type<R>* result(R (T::*)(STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, A)) Q, int = 0)
{
    return 0;
}

# undef N
# undef Q

#endif // STREAMS_BOOST_PP_ITERATION_DEPTH()
#endif
