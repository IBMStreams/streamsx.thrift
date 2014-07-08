// Copyright Daniel Wallin 2005. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/dec.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>

#define N STREAMS_BOOST_PP_ITERATION()

#define STREAMS_BOOST_PARAMETER_PY_ARG_TYPES(z, n, _) \
    typedef typename mpl::next< \
        STREAMS_BOOST_PP_CAT(iter,STREAMS_BOOST_PP_DEC(n)) \
    >::type STREAMS_BOOST_PP_CAT(iter,n); \
    \
    typedef typename mpl::deref<STREAMS_BOOST_PP_CAT(iter,n)>::type STREAMS_BOOST_PP_CAT(spec,n); \
    typedef typename mpl::if_< \
        mpl::and_< \
            mpl::not_<typename STREAMS_BOOST_PP_CAT(spec,n)::required> \
          , typename STREAMS_BOOST_PP_CAT(spec,n)::optimized_default \
        > \
      , parameter::aux::maybe<typename STREAMS_BOOST_PP_CAT(spec,n)::type> \
      , typename STREAMS_BOOST_PP_CAT(spec,n)::type \
    >::type STREAMS_BOOST_PP_CAT(arg,n); \
    typedef typename STREAMS_BOOST_PP_CAT(spec,n)::keyword STREAMS_BOOST_PP_CAT(kw,n);

#if STREAMS_BOOST_PP_ITERATION_FLAGS() == 1
template <class M, class R, class Args>
struct invoker<N, M, R, Args>
#elif STREAMS_BOOST_PP_ITERATION_FLAGS() == 2
template <class T, class R, class Args>
struct call_invoker<N, T, R, Args>
#elif STREAMS_BOOST_PP_ITERATION_FLAGS() == 3
template <class T, class Args>
struct init_invoker<N, T, Args>
#elif STREAMS_BOOST_PP_ITERATION_FLAGS() == 4
template <class M, class R, class T, class Args>
struct member_invoker<N, M, R, T, Args>
#endif
{
    typedef typename mpl::begin<Args>::type iter0;
    typedef typename mpl::deref<iter0>::type spec0;
    typedef typename mpl::if_<
        mpl::and_<
            mpl::not_<typename spec0::required>
          , typename spec0::optimized_default
        >
      , parameter::aux::maybe<typename spec0::type>
      , typename spec0::type
    >::type arg0;
    typedef typename spec0::keyword kw0;

    STREAMS_BOOST_PP_REPEAT_FROM_TO(1, N, STREAMS_BOOST_PARAMETER_PY_ARG_TYPES, ~)

    static
#if STREAMS_BOOST_PP_ITERATION_FLAGS() == 3
    T*
#else
    R
#endif 
    execute(
#if STREAMS_BOOST_PP_ITERATION_FLAGS() == 2 || STREAMS_BOOST_PP_ITERATION_FLAGS() == 4
        T& self
      ,
#endif
        STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, arg, a)
    )
    {
        return
#if STREAMS_BOOST_PP_ITERATION_FLAGS() == 1 || STREAMS_BOOST_PP_ITERATION_FLAGS() == 4
         M()(
              streams_boost::type<R>()
# if STREAMS_BOOST_PP_ITERATION_FLAGS() == 4
            , self
# endif
            , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, parameter::keyword<kw, >::get() = a)
         );
#elif STREAMS_BOOST_PP_ITERATION_FLAGS() == 2
         self(
            STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, parameter::keyword<kw, >::get() = a)
         );
#elif STREAMS_BOOST_PP_ITERATION_FLAGS() == 3
         new T(
             STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, parameter::keyword<kw, >::get() = a)
         );
#endif
    }
};

#undef STREAMS_BOOST_PARAMETER_PY_ARG_TYPES
#undef N

