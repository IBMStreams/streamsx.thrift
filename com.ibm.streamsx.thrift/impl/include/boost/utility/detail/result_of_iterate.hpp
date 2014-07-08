// Boost result_of library

//  Copyright Douglas Gregor 2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org/libs/utility
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)
# error Boost result_of - do not include this file!
#endif

// CWPro8 requires an argument in a function type specialization
#if STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3002)) && STREAMS_BOOST_PP_ITERATION() == 0
# define STREAMS_BOOST_RESULT_OF_ARGS void
#else
# define STREAMS_BOOST_RESULT_OF_ARGS STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_ITERATION(),T)
#endif

#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x551))
template<typename F STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_ITERATION())
         STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_ITERATION(),typename T)>
struct result_of<F(STREAMS_BOOST_RESULT_OF_ARGS)>
    : streams_boost::detail::result_of_impl<F, F(STREAMS_BOOST_RESULT_OF_ARGS), (streams_boost::detail::has_result_type<F>::value)> {};
#endif

#undef STREAMS_BOOST_RESULT_OF_ARGS

#if STREAMS_BOOST_PP_ITERATION() >= 1 

namespace detail {

template<typename R,  typename FArgs STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_ITERATION())
         STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_ITERATION(),typename T)>
struct result_of_impl<R (*)(STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_ITERATION(),T)), FArgs, false>
{
  typedef R type;
};

template<typename R,  typename FArgs STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_ITERATION())
         STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_ITERATION(),typename T)>
struct result_of_impl<R (&)(STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_ITERATION(),T)), FArgs, false>
{
  typedef R type;
};

#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x551))
template<typename R, typename FArgs STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_ITERATION())
         STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_ITERATION(),typename T)>
struct result_of_impl<R (T0::*)
                     (STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_PP_ITERATION(),T)),
                 FArgs, false>
{
  typedef R type;
};

template<typename R, typename FArgs STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_ITERATION())
         STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_ITERATION(),typename T)>
struct result_of_impl<R (T0::*)
                     (STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_PP_ITERATION(),T))
                     const,
                 FArgs, false>
{
  typedef R type;
};

template<typename R, typename FArgs STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_ITERATION())
         STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_ITERATION(),typename T)>
struct result_of_impl<R (T0::*)
                     (STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_PP_ITERATION(),T))
                     volatile,
                 FArgs, false>
{
  typedef R type;
};

template<typename R, typename FArgs STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_ITERATION())
         STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_ITERATION(),typename T)>
struct result_of_impl<R (T0::*)
                     (STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_PP_ITERATION(),T))
                     const volatile,
                 FArgs, false>
{
  typedef R type;
};
#endif

}
#endif
