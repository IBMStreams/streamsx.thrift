///////////////////////////////////////////////////////////////////////////////
// funop.hpp
// Contains definition of funop[n]\<\> class template.
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PP_IS_ITERATING
#error Do not include this file directly
#endif

#define M0(Z, N, DATA)                                                                          \
    typename proto::result_of::as_child<STREAMS_BOOST_PP_CAT(A, N), Domain>::type                       \
    /**/

#define M1(Z, N, DATA)                                                                          \
    proto::as_child<Domain>(STREAMS_BOOST_PP_CAT(a, N))                                                 \
    /**/

    /// \brief A helper metafunction for computing the
    /// return type of \c proto::expr\<\>::operator().
    template<typename Expr, typename Domain STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(STREAMS_BOOST_PP_ITERATION(), typename A)>
    struct STREAMS_BOOST_PP_CAT(funop, STREAMS_BOOST_PP_ITERATION())
    {
        typedef proto::expr<
            tag::function
          , STREAMS_BOOST_PP_CAT(list, STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_ITERATION()))<
                Expr &
                STREAMS_BOOST_PP_ENUM_TRAILING(STREAMS_BOOST_PP_ITERATION(), M0, ~)
            >
          , STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_ITERATION())
        > type;

        static type const call(
            Expr &e
            STREAMS_BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(STREAMS_BOOST_PP_ITERATION(), A, &a)
        )
        {
            type that = {
                e
                STREAMS_BOOST_PP_ENUM_TRAILING(STREAMS_BOOST_PP_ITERATION(), M1, ~)
            };
            return that;
        }
    };

    /// \brief A helper metafunction for computing the
    /// return type of \c proto::expr\<\>::operator().
    template<typename Expr STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(STREAMS_BOOST_PP_ITERATION(), typename A), typename This, typename Domain>
    struct funop<Expr(STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_ITERATION(), A)), This, Domain>
      : STREAMS_BOOST_PP_CAT(funop, STREAMS_BOOST_PP_ITERATION())<
            typename detail::same_cv<Expr, This>::type
          , Domain
            STREAMS_BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(
                STREAMS_BOOST_PP_ITERATION()
              , typename remove_reference<A
              , >::type STREAMS_BOOST_PP_INTERCEPT
            )
        >
    {};

#undef M0
#undef M1
