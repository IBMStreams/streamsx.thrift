#ifndef STREAMS_BOOST_PP_IS_ITERATING
    ///////////////////////////////////////////////////////////////////////////////
    /// \file generate.hpp
    /// Contains definition of generate\<\> class template, which end users can
    /// specialize for generating domain-specific expression wrappers.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

    #ifndef STREAMS_BOOST_PROTO_GENERATE_HPP_EAN_02_13_2007
    #define STREAMS_BOOST_PROTO_GENERATE_HPP_EAN_02_13_2007

    #include <streams_boost/config.hpp>
    #include <streams_boost/utility/result_of.hpp>
    #include <streams_boost/preprocessor/cat.hpp>
    #include <streams_boost/preprocessor/iteration/iterate.hpp>
    #include <streams_boost/preprocessor/repetition/enum.hpp>
    #include <streams_boost/utility/enable_if.hpp>
    #include <streams_boost/proto/proto_fwd.hpp>
    #include <streams_boost/proto/args.hpp>

    namespace streams_boost { namespace proto
    {

        namespace detail
        {
            template<typename Expr>
            struct expr_params;

            template<typename Tag, typename Args, long N>
            struct expr_params<proto::expr<Tag, Args, N> >
            {
                typedef Tag tag;
                typedef Args args;
                STREAMS_BOOST_STATIC_CONSTANT(long, arity = N);
            };

            template<typename Expr, long Arity = expr_params<Expr>::arity>
            struct by_value_generator_;

        #define STREAMS_BOOST_PROTO_DEFINE_BY_VALUE_TYPE(Z, N, Expr)                                        \
            typename uncvref<typename expr_params<Expr>::args::STREAMS_BOOST_PP_CAT(child, N)>::type        \
            /**/

        #define STREAMS_BOOST_PROTO_DEFINE_BY_VALUE(Z, N, expr)                                             \
            expr.STREAMS_BOOST_PP_CAT(child, N)                                                             \
            /**/

            template<typename Expr>
            struct by_value_generator_<Expr, 0>
            {
                typedef
                    proto::expr<
                        typename expr_params<Expr>::tag
                      , term<typename detail::term_traits<typename expr_params<Expr>::args::child0>::value_type>
                      , 0
                    >
                type;

                static type const make(Expr const &e)
                {
                    type that = {e.child0};
                    return that;
                }
            };

        #define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (3, (1, STREAMS_BOOST_PROTO_MAX_ARITY, <streams_boost/proto/generate.hpp>))
        #include STREAMS_BOOST_PP_ITERATE()

        #undef STREAMS_BOOST_PROTO_DEFINE_BY_VALUE
        #undef STREAMS_BOOST_PROTO_DEFINE_BY_VALUE_TYPE

        }

        namespace generatorns_
        {
            /// \brief A simple generator that passes an expression
            /// through unchanged.
            ///
            /// Generators are intended for use as the first template parameter
            /// to the \c domain\<\> class template and control if and how
            /// expressions within that domain are to be customized.
            /// The \c default_generator makes no modifications to the expressions
            /// passed to it.
            struct default_generator
            {
                STREAMS_BOOST_PROTO_CALLABLE()

                template<typename Sig>
                struct result;

                template<typename This, typename Expr>
                struct result<This(Expr)>
                {
                    typedef Expr type;
                };

                /// \param expr A Proto expression
                /// \return expr
                template<typename Expr>
                #ifdef STREAMS_BOOST_HAS_DECLTYPE
                Expr
                #else
                Expr const &
                #endif
                operator ()(Expr const &e) const
                {
                    return e;
                }
            };

            /// \brief A generator that wraps expressions passed
            /// to it in the specified extension wrapper.
            ///
            /// Generators are intended for use as the first template parameter
            /// to the \c domain\<\> class template and control if and how
            /// expressions within that domain are to be customized.
            /// \c generator\<\> wraps each expression passed to it in
            /// the \c Extends\<\> wrapper.
            template<template<typename> class Extends>
            struct generator
            {
                STREAMS_BOOST_PROTO_CALLABLE()

                template<typename Sig>
                struct result;

                template<typename This, typename Expr>
                struct result<This(Expr)>
                {
                    typedef Extends<Expr> type;
                };

                template<typename This, typename Expr>
                struct result<This(Expr &)>
                {
                    typedef Extends<Expr> type;
                };

                template<typename This, typename Expr>
                struct result<This(Expr const &)>
                {
                    typedef Extends<Expr> type;
                };

                /// \param expr A Proto expression
                /// \return Extends<Expr>(expr)
                template<typename Expr>
                Extends<Expr> operator ()(Expr const &e) const
                {
                    return Extends<Expr>(e);
                }
            };

            /// \brief A generator that wraps expressions passed
            /// to it in the specified extension wrapper and uses
            /// aggregate initialization for the wrapper.
            ///
            /// Generators are intended for use as the first template parameter
            /// to the \c domain\<\> class template and control if and how
            /// expressions within that domain are to be customized.
            /// \c pod_generator\<\> wraps each expression passed to it in
            /// the \c Extends\<\> wrapper, and uses aggregate initialzation
            /// for the wrapped object.
            template<template<typename> class Extends>
            struct pod_generator
            {
                STREAMS_BOOST_PROTO_CALLABLE()

                template<typename Sig>
                struct result;

                template<typename This, typename Expr>
                struct result<This(Expr)>
                {
                    typedef Extends<Expr> type;
                };

                template<typename This, typename Expr>
                struct result<This(Expr &)>
                {
                    typedef Extends<Expr> type;
                };

                template<typename This, typename Expr>
                struct result<This(Expr const &)>
                {
                    typedef Extends<Expr> type;
                };

                /// \param expr The expression to wrap
                /// \return <tt>Extends\<Expr\> that = {expr}; return that;</tt>
                template<typename Expr>
                Extends<Expr> operator ()(Expr const &e) const
                {
                    Extends<Expr> that = {e};
                    return that;
                }
            };

            /// \brief A generator that replaces child nodes held by
            /// reference with ones held by value. Use with
            /// \c compose_generators to forward that result to another
            /// generator.
            ///
            /// Generators are intended for use as the first template parameter
            /// to the \c domain\<\> class template and control if and how
            /// expressions within that domain are to be customized.
            /// \c by_value_generator ensures all child nodes are
            /// held by value. This generator is typically composed with a
            /// second generator for further processing, as
            /// <tt>compose_generators\<by_value_generator, MyGenerator\></tt>.
            struct by_value_generator
            {
                STREAMS_BOOST_PROTO_CALLABLE()

                template<typename Sig>
                struct result;

                template<typename This, typename Expr>
                struct result<This(Expr)>
                {
                    typedef
                        typename detail::by_value_generator_<Expr>::type
                    type;
                };

                template<typename This, typename Expr>
                struct result<This(Expr &)>
                {
                    typedef
                        typename detail::by_value_generator_<Expr>::type
                    type;
                };

                template<typename This, typename Expr>
                struct result<This(Expr const &)>
                {
                    typedef
                        typename detail::by_value_generator_<Expr>::type
                    type;
                };

                /// \param expr The expression to modify.
                /// \return <tt>deep_copy(expr)</tt>
                template<typename Expr>
                typename result<by_value_generator(Expr)>::type operator ()(Expr const &e) const
                {
                    return detail::by_value_generator_<Expr>::make(e);
                }
            };

            /// \brief A composite generator that first applies one
            /// transform to an expression and then forwards the result
            /// on to another generator for further transformation.
            ///
            /// Generators are intended for use as the first template parameter
            /// to the \c domain\<\> class template and control if and how
            /// expressions within that domain are to be customized.
            /// \c compose_generators\<\> is a composite generator that first
            /// applies one transform to an expression and then forwards the
            /// result on to another generator for further transformation.
            template<typename First, typename Second>
            struct compose_generators
            {
                STREAMS_BOOST_PROTO_CALLABLE()

                template<typename Sig>
                struct result;

                template<typename This, typename Expr>
                struct result<This(Expr)>
                {
                    typedef
                        typename Second::template result<
                            Second(typename First::template result<First(Expr)>::type)
                        >::type
                    type;
                };

                template<typename This, typename Expr>
                struct result<This(Expr &)>
                {
                    typedef
                        typename Second::template result<
                            Second(typename First::template result<First(Expr)>::type)
                        >::type
                    type;
                };

                template<typename This, typename Expr>
                struct result<This(Expr const &)>
                {
                    typedef
                        typename Second::template result<
                            Second(typename First::template result<First(Expr)>::type)
                        >::type
                    type;
                };

                /// \param expr The expression to modify.
                /// \return Second()(First()(expr))
                template<typename Expr>
                typename result<compose_generators(Expr)>::type operator ()(Expr const &e) const
                {
                    return Second()(First()(e));
                }
            };
        }

        /// INTERNAL ONLY
        template<>
        struct is_callable<default_generator>
          : mpl::true_
        {};

        /// INTERNAL ONLY
        template<template<typename> class Extends>
        struct is_callable<generator<Extends> >
          : mpl::true_
        {};

        /// INTERNAL ONLY
        template<template<typename> class Extends>
        struct is_callable<pod_generator<Extends> >
          : mpl::true_
        {};

        /// INTERNAL ONLY
        template<>
        struct is_callable<by_value_generator>
          : mpl::true_
        {};

        /// INTERNAL ONLY
        template<typename First, typename Second>
        struct is_callable<compose_generators<First, Second> >
          : mpl::true_
        {};

    }}

    // Specialization of streams_boost::result_of to eliminate some unnecessary template instantiations
    namespace streams_boost
    {
        template<typename Expr>
        struct result_of<proto::default_domain(Expr)>
        {
            typedef Expr type;
        };
    }

    #endif // STREAMS_BOOST_PROTO_GENERATE_HPP_EAN_02_13_2007

#else // STREAMS_BOOST_PP_IS_ITERATING

    #define N STREAMS_BOOST_PP_ITERATION()

            template<typename Expr>
            struct by_value_generator_<Expr, N>
            {
                typedef
                    proto::expr<
                        typename expr_params<Expr>::tag
                      , STREAMS_BOOST_PP_CAT(list, N)<
                            // typename uncvref<typename expr_params<Expr>::args::child0>::type, ...
                            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_PROTO_DEFINE_BY_VALUE_TYPE, Expr)
                        >
                      , N
                    >
                type;

                static type const make(Expr const &e)
                {
                    type that = {
                        // expr.child0, ...
                        STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_PROTO_DEFINE_BY_VALUE, e)
                    };
                    return that;
                }
            };

    #undef N

#endif
