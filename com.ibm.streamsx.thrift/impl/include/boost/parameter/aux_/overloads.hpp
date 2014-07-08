// Copyright David Abrahams, Daniel Wallin 2003. Use, modification and 
// distribution is subject to the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)

// This file generates overloads in this format:
//
//     template<class A0, class A1>
//     typename mpl::apply_wrap1<
//         aux::make_arg_list<
//             PS0,A0
//           , aux::make_arg_list<
//                 PS1,A1
//               , mpl::identity<aux::empty_arg_list>
//             >
//         >
//      , unnamed_list
//     >::type
//     operator()(A0 const& a0, A1 const& a1) const
//     {
//         typedef typename mpl::apply_wrap1<
//             aux::make_arg_list<
//                 PS0,A0
//               , aux::make_arg_list<
//                     PS1,A1
//                   , mpl::identity<aux::empty_arg_list>
//                 >
//             >
//         >::type arg_tuple;
//
//         return arg_tuple(
//             a0
//           , a1
//           , aux::void_()
//             ...
//         );
//     }
//

#if !defined(STREAMS_BOOST_PP_IS_ITERATING)
# error Boost.Parameters - do not include this file!
#endif

#define N STREAMS_BOOST_PP_ITERATION()

#define STREAMS_BOOST_PARAMETER_open_list(z, n, text) \
    aux::item< \
        STREAMS_BOOST_PP_CAT(PS, n), STREAMS_BOOST_PP_CAT(A, n)

#define STREAMS_BOOST_PARAMETER_close_list(z, n, text) > 

#define STREAMS_BOOST_PARAMETER_arg_list(n) \
    aux::make_arg_list< \
        STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_PARAMETER_open_list, _) \
      , void_ \
        STREAMS_BOOST_PP_REPEAT(N, STREAMS_BOOST_PARAMETER_close_list, _) \
      , deduced_list \
      , aux::tag_keyword_arg \
    >

#define STREAMS_BOOST_PARAMETER_arg_pack_init(z, n, limit) \
    STREAMS_BOOST_PP_CAT(a, STREAMS_BOOST_PP_SUB(limit,n))

template<STREAMS_BOOST_PP_ENUM_PARAMS(N, class A)>
typename mpl::first<
    typename STREAMS_BOOST_PARAMETER_arg_list(N)::type
>::type
operator()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, & a)) const
{
    typedef typename STREAMS_BOOST_PARAMETER_arg_list(N)::type result;

    typedef typename mpl::first<result>::type result_type;
    typedef typename mpl::second<result>::type error;
    error();

    return result_type(
        STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_PARAMETER_arg_pack_init, STREAMS_BOOST_PP_DEC(N))
        STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(
            STREAMS_BOOST_PP_SUB(STREAMS_BOOST_PARAMETER_MAX_ARITY, N)
          , aux::void_reference() STREAMS_BOOST_PP_INTERCEPT
        ));
}

#undef STREAMS_BOOST_PARAMETER_arg_list
#undef STREAMS_BOOST_PARAMETER_open_list
#undef STREAMS_BOOST_PARAMETER_close_list
#undef N

