#ifndef STREAMS_BOOST_PP_IS_ITERATING
// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
# ifndef TYPE_LIST_IMPL_DWA2002913_STREAMS_HPP
#  define TYPE_LIST_IMPL_DWA2002913_STREAMS_HPP

#  include <streams_boost/python/detail/type_list.hpp>

#  include <streams_boost/preprocessor/enum_params.hpp>
#  include <streams_boost/preprocessor/enum_params_with_a_default.hpp>
#  include <streams_boost/preprocessor/repetition/enum.hpp>
#  include <streams_boost/preprocessor/comma_if.hpp>
#  include <streams_boost/preprocessor/arithmetic/sub.hpp>
#  include <streams_boost/preprocessor/iterate.hpp>
#  include <streams_boost/preprocessor/repetition/enum_trailing.hpp>

namespace streams_boost { namespace python { namespace detail { 

template <STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(STREAMS_BOOST_PYTHON_LIST_SIZE, class T, mpl::void_)>
struct type_list
    : STREAMS_BOOST_PP_CAT(mpl::vector,STREAMS_BOOST_PYTHON_LIST_SIZE)<STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, STREAMS_BOOST_PYTHON_LIST_SIZE, T)>
{
};

#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                                                   \
        (3, (0, STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PYTHON_LIST_SIZE), <streams_boost/python/detail/type_list_impl.hpp>))
#  include STREAMS_BOOST_PP_ITERATE()


}}} // namespace streams_boost::python::detail

# endif // TYPE_LIST_IMPL_DWA2002913_STREAMS_HPP

#else // STREAMS_BOOST_PP_IS_ITERATING

# define N STREAMS_BOOST_PP_ITERATION()
# define STREAMS_BOOST_PYTHON_VOID_ARGS STREAMS_BOOST_PP_SUB_D(1,STREAMS_BOOST_PYTHON_LIST_SIZE,N)

template <
    STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, class T)
    >
struct type_list<
    STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, T)
    STREAMS_BOOST_PP_COMMA_IF(N)
    STREAMS_BOOST_PP_ENUM(
        STREAMS_BOOST_PYTHON_VOID_ARGS, STREAMS_BOOST_PYTHON_FIXED, mpl::void_)
    >
   : STREAMS_BOOST_PP_CAT(mpl::vector,N)<STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, T)>
{
};

# undef STREAMS_BOOST_PYTHON_VOID_ARGS
# undef N

#endif // STREAMS_BOOST_PP_IS_ITERATING 
