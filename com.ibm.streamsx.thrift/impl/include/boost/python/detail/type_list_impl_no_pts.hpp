#ifndef STREAMS_BOOST_PP_IS_ITERATING
// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
# ifndef TYPE_LIST_IMPL_NO_PTS_DWA2002913_STREAMS_HPP
#  define TYPE_LIST_IMPL_NO_PTS_DWA2002913_STREAMS_HPP

#  include <streams_boost/python/detail/type_list.hpp>

#  include <streams_boost/preprocessor/enum_params.hpp>
#  include <streams_boost/preprocessor/enum_params_with_a_default.hpp>
#  include <streams_boost/preprocessor/cat.hpp>
#  include <streams_boost/preprocessor/repeat.hpp>
#  include <streams_boost/preprocessor/empty.hpp>
#  include <streams_boost/preprocessor/iterate.hpp>
#  include <streams_boost/mpl/void.hpp>

namespace streams_boost { namespace python { namespace detail { 

template< typename T >
struct is_list_arg
{
    enum { value = true };
};

template<>
struct is_list_arg<mpl::void_>
{
    enum { value = false };
};

template<int> struct type_list_impl_chooser;

#  define STREAMS_BOOST_PYTHON_LIST_ACTUAL_PARAMS STREAMS_BOOST_PP_ENUM_PARAMS_Z(1,STREAMS_BOOST_PYTHON_LIST_SIZE,T)
#  define STREAMS_BOOST_PYTHON_LIST_FORMAL_PARAMS STREAMS_BOOST_PP_ENUM_PARAMS_Z(1,STREAMS_BOOST_PYTHON_LIST_SIZE,class T)

#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                                           \
        (3, (0, STREAMS_BOOST_PYTHON_LIST_SIZE, <streams_boost/python/detail/type_list_impl_no_pts.hpp>))
#  include STREAMS_BOOST_PP_ITERATE()

#  define STREAMS_BOOST_PYTHON_PLUS() +
#  define STREAMS_BOOST_PYTHON_IS_LIST_ARG(z, n, data)          \
    STREAMS_BOOST_PP_IF(n, STREAMS_BOOST_PYTHON_PLUS, STREAMS_BOOST_PP_EMPTY)() \
    is_list_arg< STREAMS_BOOST_PP_CAT(T,n) >::value
    
template<
    STREAMS_BOOST_PYTHON_LIST_FORMAL_PARAMS
    >
struct type_list_count_args
{
    enum { value =
           STREAMS_BOOST_PP_REPEAT_1(STREAMS_BOOST_PYTHON_LIST_SIZE, STREAMS_BOOST_PYTHON_IS_LIST_ARG, _)
    };
};

template<
    STREAMS_BOOST_PYTHON_LIST_FORMAL_PARAMS
    >
struct type_list_impl
{
    typedef type_list_count_args< STREAMS_BOOST_PYTHON_LIST_ACTUAL_PARAMS > arg_num_;
    typedef typename detail::type_list_impl_chooser< arg_num_::value >
    ::template result_< STREAMS_BOOST_PYTHON_LIST_ACTUAL_PARAMS >::type type;
};

template<
    STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(STREAMS_BOOST_PYTHON_LIST_SIZE, class T, mpl::void_)
    >
struct type_list
    : detail::type_list_impl< STREAMS_BOOST_PYTHON_LIST_ACTUAL_PARAMS >::type
{
    typedef typename detail::type_list_impl<
        STREAMS_BOOST_PYTHON_LIST_ACTUAL_PARAMS
        >::type type;
};

#  undef STREAMS_BOOST_PYTHON_IS_LIST_ARG
#  undef STREAMS_BOOST_PYTHON_PLUS
#  undef STREAMS_BOOST_PYTHON_LIST_FORMAL_PARAMS
#  undef STREAMS_BOOST_PYTHON_LIST_ACTUAL_PARAMS

}}} // namespace streams_boost::python::detail

# endif // TYPE_LIST_IMPL_NO_PTS_DWA2002913_STREAMS_HPP

#else // STREAMS_BOOST_PP_IS_ITERATING

# define N STREAMS_BOOST_PP_ITERATION()

template<>
struct type_list_impl_chooser<N>
{
    template<
        STREAMS_BOOST_PYTHON_LIST_FORMAL_PARAMS
        >
    struct result_
    {
        typedef typename STREAMS_BOOST_PP_CAT(mpl::vector,N)<
            STREAMS_BOOST_PP_ENUM_PARAMS(N, T)
            >::type type;
    };
};

# undef N

#endif // STREAMS_BOOST_PP_IS_ITERATING 
