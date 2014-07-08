#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
# ifndef INVOKE_DWA20021122_STREAMS_HPP
#  define INVOKE_DWA20021122_STREAMS_HPP

#  include <streams_boost/python/detail/prefix.hpp>
#  include <streams_boost/python/detail/preprocessor.hpp>
#  include <streams_boost/python/detail/none.hpp>

#  include <streams_boost/type_traits/is_member_function_pointer.hpp>

#  include <streams_boost/preprocessor/iterate.hpp>
#  include <streams_boost/preprocessor/facilities/intercept.hpp>
#  include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>
#  include <streams_boost/preprocessor/repetition/enum_trailing_binary_params.hpp>
#  include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#  include <streams_boost/python/to_python_value.hpp>

// This file declares a series of overloaded invoke(...)  functions,
// used to invoke wrapped C++ function (object)s from Python. Each one
// accepts:
//
//   - a tag which identifies the invocation syntax (e.g. member
//   functions must be invoked with a different syntax from regular
//   functions)
//
//   - a pointer to a result converter type, used solely as a way of
//   transmitting the type of the result converter to the function (or
//   an int, if the return type is void).
//
//   - the "function", which may be a function object, a function or
//   member function pointer, or a defaulted_virtual_fn.
//
//   - The arg_from_python converters for each of the arguments to be
//   passed to the function being invoked.

namespace streams_boost { namespace python { namespace detail { 

// This "result converter" is really just used as a dispatch tag to
// invoke(...), selecting the appropriate implementation
typedef int void_result_to_python;

template <bool void_return, bool member>
struct invoke_tag_ {};

// A metafunction returning the appropriate tag type for invoking an
// object of type F with return type R.
template <class R, class F>
struct invoke_tag
  : invoke_tag_<
        is_same<R,void>::value
      , is_member_function_pointer<F>::value
    >
{
};

#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                            \
        (3, (0, STREAMS_BOOST_PYTHON_MAX_ARITY, <streams_boost/python/detail/invoke.hpp>))
#  include STREAMS_BOOST_PP_ITERATE()

}}} // namespace streams_boost::python::detail

# endif // INVOKE_DWA20021122_STREAMS_HPP
#else 

# define N STREAMS_BOOST_PP_ITERATION()

template <class RC, class F STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, class AC)>
inline PyObject* invoke(invoke_tag_<false,false>, RC const& rc, F& f STREAMS_BOOST_PP_ENUM_TRAILING_BINARY_PARAMS_Z(1, N, AC, & ac) )
{
    return rc(f( STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(1, N, ac, () STREAMS_BOOST_PP_INTERCEPT) ));
}
                 
template <class RC, class F STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, class AC)>
inline PyObject* invoke(invoke_tag_<true,false>, RC const&, F& f STREAMS_BOOST_PP_ENUM_TRAILING_BINARY_PARAMS_Z(1, N, AC, & ac) )
{
    f( STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(1, N, ac, () STREAMS_BOOST_PP_INTERCEPT) );
    return none();
}

template <class RC, class F, class TC STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, class AC)>
inline PyObject* invoke(invoke_tag_<false,true>, RC const& rc, F& f, TC& tc STREAMS_BOOST_PP_ENUM_TRAILING_BINARY_PARAMS_Z(1, N, AC, & ac) )
{
    return rc( (tc().*f)(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(1, N, ac, () STREAMS_BOOST_PP_INTERCEPT)) );
}
                 
template <class RC, class F, class TC STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, class AC)>
inline PyObject* invoke(invoke_tag_<true,true>, RC const&, F& f, TC& tc STREAMS_BOOST_PP_ENUM_TRAILING_BINARY_PARAMS_Z(1, N, AC, & ac) )
{
    (tc().*f)(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(1, N, ac, () STREAMS_BOOST_PP_INTERCEPT));
    return none();
}

# undef N

#endif // STREAMS_BOOST_PP_IS_ITERATING 
