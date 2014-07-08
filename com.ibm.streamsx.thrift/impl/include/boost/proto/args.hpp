#ifndef STREAMS_BOOST_PP_IS_ITERATING
    ///////////////////////////////////////////////////////////////////////////////
    /// \file args.hpp
    /// Contains definition of \c term\<\>, \c list1\<\>, \c list2\<\>, ...
    /// class templates.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

    #ifndef STREAMS_BOOST_PROTO_ARGS_HPP_EAN_04_01_2005
    #define STREAMS_BOOST_PROTO_ARGS_HPP_EAN_04_01_2005

    #include <streams_boost/config.hpp>
    #include <streams_boost/detail/workaround.hpp>
    #include <streams_boost/preprocessor/cat.hpp>
    #include <streams_boost/preprocessor/arithmetic/dec.hpp>
    #include <streams_boost/preprocessor/iteration/iterate.hpp>
    #include <streams_boost/preprocessor/repetition/enum_params.hpp>
    #include <streams_boost/preprocessor/repetition/repeat.hpp>
    #include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
    #include <streams_boost/type_traits/is_function.hpp>
    #include <streams_boost/mpl/if.hpp>
    #include <streams_boost/mpl/void.hpp>
    #include <streams_boost/proto/proto_fwd.hpp>

    namespace streams_boost { namespace proto
    {
        namespace detail
        {
            /// INTERNAL ONLY
            template<typename Expr>
            struct expr_traits
            {
                typedef Expr value_type;
                typedef Expr &reference;
                typedef Expr const &const_reference;
            };

            /// INTERNAL ONLY
            template<typename Expr>
            struct expr_traits<Expr &>
            {
                typedef Expr value_type;
                typedef Expr &reference;
                typedef Expr &const_reference;
            };

            /// INTERNAL ONLY
            template<typename Expr>
            struct expr_traits<Expr const &>
            {
                typedef Expr value_type;
                typedef Expr const &reference;
                typedef Expr const &const_reference;
            };

            /// INTERNAL ONLY
            template<typename T>
            struct term_traits
            {
                typedef T value_type;
                typedef T &reference;
                typedef T const &const_reference;
            };

            /// INTERNAL ONLY
            template<typename T>
            struct term_traits<T &>
            {
                typedef typename mpl::if_c<is_function<T>::value, T &, T>::type value_type;
                typedef T &reference;
                typedef T &const_reference;
            };

            /// INTERNAL ONLY
            template<typename T>
            struct term_traits<T const &>
            {
                typedef T value_type;
                typedef T const &reference;
                typedef T const &const_reference;
            };

            /// INTERNAL ONLY
            template<typename T, std::size_t N>
            struct term_traits<T (&)[N]>
            {
                typedef T value_type[N];
                typedef T (&reference)[N];
                typedef T (&const_reference)[N];
            };

            /// INTERNAL ONLY
            template<typename T, std::size_t N>
            struct term_traits<T const (&)[N]>
            {
                typedef T value_type[N];
                typedef T const (&reference)[N];
                typedef T const (&const_reference)[N];
            };

            /// INTERNAL ONLY
            template<typename T, std::size_t N>
            struct term_traits<T[N]>
            {
                typedef T value_type[N];
                typedef T (&reference)[N];
                typedef T const (&const_reference)[N];
            };

            /// INTERNAL ONLY
            template<typename T, std::size_t N>
            struct term_traits<T const[N]>
            {
                typedef T value_type[N];
                typedef T const (&reference)[N];
                typedef T const (&const_reference)[N];
            };
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        namespace argsns_
        {

            #define STREAMS_BOOST_PROTO_DEFINE_CHILD_N(Z, N, DATA)                                              \
                typedef STREAMS_BOOST_PP_CAT(Arg, N) STREAMS_BOOST_PP_CAT(child, N);                                    \
                /**< INTERNAL ONLY */

            #define STREAMS_BOOST_PROTO_DEFINE_VOID_N(z, n, data)                                               \
                typedef mpl::void_ STREAMS_BOOST_PP_CAT(child, n);                                              \
                /**< INTERNAL ONLY */

            /// \brief A type sequence, for use as the 2nd parameter to the \c expr\<\> class template.
            ///
            /// A type sequence, for use as the 2nd parameter to the \c expr\<\> class template.
            /// The types in the sequence correspond to the children of a node in an expression tree.
            template< typename Arg0 >
            struct term
            {
                STREAMS_BOOST_STATIC_CONSTANT(long, arity = 0);
                typedef Arg0 child0;

                #if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, STREAMS_BOOST_TESTED_AT(1500))
                STREAMS_BOOST_PP_REPEAT_FROM_TO(1, STREAMS_BOOST_PROTO_MAX_ARITY, STREAMS_BOOST_PROTO_DEFINE_VOID_N, ~)
                #endif

                /// INTERNAL ONLY
                ///
                typedef Arg0 back_;
            };

            #define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (3, (1, STREAMS_BOOST_PROTO_MAX_ARITY, <streams_boost/proto/args.hpp>))
            #include STREAMS_BOOST_PP_ITERATE()

            #undef STREAMS_BOOST_PROTO_DEFINE_CHILD_N

        }
        ////////////////////////////////////////////////////////////////////////////////////////////
    }}
    #endif

#else

    #define N STREAMS_BOOST_PP_ITERATION()

        /// \brief A type sequence, for use as the 2nd parameter to the \c expr\<\> class template.
        ///
        /// A type sequence, for use as the 2nd parameter to the \c expr\<\> class template.
        /// The types in the sequence correspond to the children of a node in an expression tree.
        template< STREAMS_BOOST_PP_ENUM_PARAMS(N, typename Arg) >
        struct STREAMS_BOOST_PP_CAT(list, N)
        {
            STREAMS_BOOST_STATIC_CONSTANT(long, arity = N);
            STREAMS_BOOST_PP_REPEAT(N, STREAMS_BOOST_PROTO_DEFINE_CHILD_N, ~)

            #if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, STREAMS_BOOST_TESTED_AT(1500))
            STREAMS_BOOST_PP_REPEAT_FROM_TO(N, STREAMS_BOOST_PROTO_MAX_ARITY, STREAMS_BOOST_PROTO_DEFINE_VOID_N, ~)
            #endif

            /// INTERNAL ONLY
            ///
            typedef STREAMS_BOOST_PP_CAT(Arg, STREAMS_BOOST_PP_DEC(N)) back_;
        };

    #undef N

#endif
