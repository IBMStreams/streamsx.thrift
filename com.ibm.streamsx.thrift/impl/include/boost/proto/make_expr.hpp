#ifndef STREAMS_BOOST_PP_IS_ITERATING
    ///////////////////////////////////////////////////////////////////////////////
    /// \file make_expr.hpp
    /// Definition of the \c make_expr() and \c unpack_expr() utilities for
    /// building Proto expression nodes from child nodes or from a Fusion
    /// sequence of child nodes, respectively.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

    #ifndef STREAMS_BOOST_PROTO_MAKE_EXPR_HPP_EAN_04_01_2005
    #define STREAMS_BOOST_PROTO_MAKE_EXPR_HPP_EAN_04_01_2005

    #include <streams_boost/config.hpp>
    #include <streams_boost/detail/workaround.hpp>
    #include <streams_boost/preprocessor/cat.hpp>
    #include <streams_boost/preprocessor/arithmetic/inc.hpp>
    #include <streams_boost/preprocessor/arithmetic/dec.hpp>
    #include <streams_boost/preprocessor/arithmetic/sub.hpp>
    #include <streams_boost/preprocessor/punctuation/comma_if.hpp>
    #include <streams_boost/preprocessor/iteration/iterate.hpp>
    #include <streams_boost/preprocessor/facilities/intercept.hpp>
    #include <streams_boost/preprocessor/repetition/enum.hpp>
    #include <streams_boost/preprocessor/repetition/enum_params.hpp>
    #include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
    #include <streams_boost/preprocessor/repetition/enum_shifted_params.hpp>
    #include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>
    #include <streams_boost/preprocessor/repetition/enum_trailing_binary_params.hpp>
    #include <streams_boost/preprocessor/repetition/repeat.hpp>
    #include <streams_boost/ref.hpp>
    #include <streams_boost/mpl/if.hpp>
    #include <streams_boost/mpl/assert.hpp>
    #include <streams_boost/mpl/eval_if.hpp>
    #include <streams_boost/utility/enable_if.hpp>
    #include <streams_boost/type_traits/is_same.hpp>
    #include <streams_boost/type_traits/add_const.hpp>
    #include <streams_boost/type_traits/add_reference.hpp>
    #include <streams_boost/type_traits/remove_cv.hpp>
    #include <streams_boost/type_traits/remove_const.hpp>
    #include <streams_boost/type_traits/remove_reference.hpp>
    #include <streams_boost/proto/proto_fwd.hpp>
    #include <streams_boost/proto/traits.hpp>
    #include <streams_boost/proto/domain.hpp>
    #include <streams_boost/proto/generate.hpp>
    #include <streams_boost/fusion/include/begin.hpp>
    #include <streams_boost/fusion/include/next.hpp>
    #include <streams_boost/fusion/include/value_of.hpp>
    #include <streams_boost/fusion/include/size.hpp>
    #include <streams_boost/proto/detail/poly_function.hpp>
    #include <streams_boost/proto/detail/deprecated.hpp>

    #ifdef _MSC_VER
    # pragma warning(push)
    # pragma warning(disable: 4180) // qualifier applied to function type has no meaning; ignored
    #endif

    namespace streams_boost
    {
        /// INTERNAL ONLY
        ///
        namespace fusion
        {
            /// INTERNAL ONLY
            ///
            template<typename Function>
            class unfused_generic;
        }
    }

    namespace streams_boost { namespace proto
    {
    /// INTERNAL ONLY
    ///
    #define STREAMS_BOOST_PROTO_AS_CHILD_TYPE(Z, N, DATA)                                                   \
        typename streams_boost::proto::detail::protoify_<                                                   \
            STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, DATA), N)                                        \
          , STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, DATA)                                                         \
        >::type                                                                                     \
        /**/

    /// INTERNAL ONLY
    ///
    #define STREAMS_BOOST_PROTO_AS_CHILD(Z, N, DATA)                                                        \
        streams_boost::proto::detail::protoify_<                                                            \
            STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, DATA), N)                                        \
          , STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, DATA)                                                         \
        >::call(STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, DATA), N))                                   \
        /**/

    /// INTERNAL ONLY
    ///
    #define STREAMS_BOOST_PROTO_FUSION_NEXT_ITERATOR_TYPE(Z, N, DATA)                                       \
        typedef typename fusion::result_of::next<                                \
            STREAMS_BOOST_PP_CAT(fusion_iterator, N)>::type                                                 \
                STREAMS_BOOST_PP_CAT(fusion_iterator, STREAMS_BOOST_PP_INC(N));                                     \
        /**/

    /// INTERNAL ONLY
    ///
    #define STREAMS_BOOST_PROTO_FUSION_ITERATORS_TYPE(N)                                                    \
        typedef                                                                                     \
            typename fusion::result_of::begin<Sequence const>::type              \
        fusion_iterator0;                                                                           \
        STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_PP_DEC(N), STREAMS_BOOST_PROTO_FUSION_NEXT_ITERATOR_TYPE, fusion_iterator)    \
        /**/

    /// INTERNAL ONLY
    ///
    #define STREAMS_BOOST_PROTO_FUSION_AT_TYPE(Z, N, DATA)                                                  \
        typename add_const<                                                                         \
            typename fusion::result_of::value_of<                                \
                STREAMS_BOOST_PP_CAT(fusion_iterator, N)                                                    \
            >::type                                                                                 \
        >::type                                                                                     \
        /**/

    /// INTERNAL ONLY
    ///
    #define STREAMS_BOOST_PROTO_FUSION_NEXT_ITERATOR(Z, N, DATA)                                            \
        STREAMS_BOOST_PP_CAT(fusion_iterator, STREAMS_BOOST_PP_INC(N)) STREAMS_BOOST_PP_CAT(it, STREAMS_BOOST_PP_INC(N)) =          \
            fusion::next(STREAMS_BOOST_PP_CAT(it, N));                                                      \
        /**/

    /// INTERNAL ONLY
    ///
    #define STREAMS_BOOST_PROTO_FUSION_ITERATORS(N)                                                         \
        fusion_iterator0 it0 = fusion::begin(sequence);                                             \
        STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_PP_DEC(N), STREAMS_BOOST_PROTO_FUSION_NEXT_ITERATOR, fusion_iterator)         \
        /**/

    /// INTERNAL ONLY
    ///
    #define STREAMS_BOOST_PROTO_FUSION_AT(Z, N, DATA)                                                       \
        *STREAMS_BOOST_PP_CAT(it, N)                                                                        \
        /**/

    /// INTERNAL ONLY
    ///
    #define STREAMS_BOOST_PROTO_FUSION_AS_CHILD_AT_TYPE(Z, N, DATA)                                         \
        typename detail::protoify_<                                                                 \
            STREAMS_BOOST_PROTO_FUSION_AT_TYPE(Z, N, DATA)                                                  \
          , Domain                                                                                  \
        >::type                                                                                     \
        /**/

    /// INTERNAL ONLY
    ///
    #define STREAMS_BOOST_PROTO_FUSION_AS_CHILD_AT(Z, N, DATA)                                              \
        detail::protoify_<                                                                          \
            STREAMS_BOOST_PROTO_FUSION_AT_TYPE(Z, N, DATA)                                                  \
          , Domain                                                                                  \
        >::call(STREAMS_BOOST_PROTO_FUSION_AT(Z, N, DATA))                                                  \
        /**/

        namespace detail
        {
            template<typename T, typename Domain>
            struct protoify_
            {
                typedef
                    typename streams_boost::unwrap_reference<T>::type
                unref_type;

                typedef
                    typename mpl::eval_if_c<
                        streams_boost::is_reference_wrapper<T>::value
                      , proto::result_of::as_child<unref_type, Domain>
                      , proto::result_of::as_expr<unref_type, Domain>
                    >::type
                type;

                static type call(T &t)
                {
                    return typename mpl::if_c<
                        is_reference_wrapper<T>::value
                      , functional::as_child<Domain>
                      , functional::as_expr<Domain>
                    >::type()(static_cast<unref_type &>(t));
                }
            };

            template<typename T, typename Domain>
            struct protoify_<T &, Domain>
            {
                typedef
                    typename proto::result_of::as_child<T, Domain>::type
                type;

                static type call(T &t)
                {
                    return functional::as_child<Domain>()(t);
                }
            };

            template<
                int Index
                STREAMS_BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(
                    STREAMS_BOOST_PROTO_MAX_ARITY
                  , typename D
                  , = void STREAMS_BOOST_PP_INTERCEPT
                )
            >
            struct select_nth
            {
                STREAMS_BOOST_MPL_ASSERT_MSG((false), PROTO_DOMAIN_MISMATCH, (select_nth));
                typedef default_domain type;
            };

            template<typename Void = void>
            struct deduce_domain0
            {
                typedef default_domain type;
            };

            template<int I>
            struct sized
            {
                char buffer[I];
            };

            template<typename T>
            struct nondeduced_domain
            {
                typedef nondeduced_domain type;
                nondeduced_domain(T);
                nondeduced_domain(default_domain);
            };

            template<>
            struct nondeduced_domain<default_domain>
            {
                typedef nondeduced_domain type;
                nondeduced_domain(default_domain);
            };

            template<typename Tag, typename Domain, typename Sequence, std::size_t Size>
            struct unpack_expr_
            {};

            template<typename Domain, typename Sequence>
            struct unpack_expr_<tag::terminal, Domain, Sequence, 1u>
            {
                typedef
                    typename add_const<
                        typename fusion::result_of::value_of<
                            typename fusion::result_of::begin<Sequence>::type
                        >::type
                    >::type
                terminal_type;

                typedef
                    typename proto::detail::protoify_<
                        terminal_type
                      , Domain
                    >::type
                type;

                static type const call(Sequence const &sequence)
                {
                    return proto::detail::protoify_<terminal_type, Domain>::call(fusion::at_c<0>(sequence));
                }
            };

            template<typename Sequence>
            struct unpack_expr_<tag::terminal, deduce_domain, Sequence, 1u>
              : unpack_expr_<tag::terminal, default_domain, Sequence, 1u>
            {};

            template<
                typename Tag
              , typename Domain
                STREAMS_BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(
                    STREAMS_BOOST_PROTO_MAX_ARITY
                  , typename A
                  , = void STREAMS_BOOST_PP_INTERCEPT
                )
              , typename _ = void
            >
            struct make_expr_
            {};

            template<typename Domain, typename A>
            struct make_expr_<tag::terminal, Domain, A
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(STREAMS_BOOST_PROTO_MAX_ARITY, void STREAMS_BOOST_PP_INTERCEPT)>
            {
                typedef typename proto::detail::protoify_<A, Domain>::type result_type;

                result_type operator()(typename add_reference<A>::type a) const
                {
                    return proto::detail::protoify_<A, Domain>::call(a);
                }
            };

            template<typename A>
            struct make_expr_<tag::terminal, deduce_domain, A
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(STREAMS_BOOST_PROTO_MAX_ARITY, void STREAMS_BOOST_PP_INTERCEPT)>
              : make_expr_<tag::terminal, default_domain, A>
            {};

            template<typename Base, typename Expr>
            Expr implicit_expr_wrap(Base const &e, mpl::false_, Expr *)
            {
                return Expr(e);
            }

            template<typename Base, typename Expr>
            Expr implicit_expr_wrap(Base const &e, mpl::true_, Expr *)
            {
                Expr that = {e};
                return that;
            }

            template<typename A0, typename Void = void>
            struct implicit_expr_1
            {
                A0 &a0;

                template<typename Args>
                operator proto::expr<tag::terminal, Args, 0>() const
                {
                    proto::expr<tag::terminal, Args, 0> that = {this->a0};
                    return that;
                }

                template<typename Expr>
                operator Expr() const
                {
                    typename Expr::proto_base_expr that = *this;
                    return detail::implicit_expr_wrap(that, is_aggregate<Expr>(), static_cast<Expr *>(0));
                }
            };

            template<typename A0>
            struct implicit_expr_1<A0, typename A0::proto_is_expr_>
            {
                A0 &a0;

            #if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_INTEL_CXX_VERSION, STREAMS_BOOST_TESTED_AT(1010))
                typedef typename remove_cv<A0>::type uncv_a0_type;

                operator uncv_a0_type &() const
                {
                    return const_cast<uncv_a0_type &>(this->a0);
                }
            #else
                operator A0 &() const
                {
                    return this->a0;
                }
            #endif

                template<typename Tag, typename Args>
                operator proto::expr<Tag, Args, 1>() const
                {
                    proto::expr<Tag, Args, 1> that = {this->a0};
                    return that;
                }

                template<typename Expr>
                operator Expr() const
                {
                    typename Expr::proto_base_expr that = *this;
                    return detail::implicit_expr_wrap(that, is_aggregate<Expr>(), static_cast<Expr *>(0));
                }
            };

        #define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                                         \
            (4, (1, STREAMS_BOOST_PROTO_MAX_ARITY, <streams_boost/proto/make_expr.hpp>, 1))                         \
            /**/

        #include STREAMS_BOOST_PP_ITERATE()
        }

        namespace result_of
        {
            /// \brief Metafunction that computes the return type of the
            /// \c make_expr() function, with a domain deduced from the
            /// domains of the children.
            ///
            /// Use the <tt>result_of::make_expr\<\></tt> metafunction to
            /// compute the return type of the \c make_expr() function.
            ///
            /// In this specialization, the domain is deduced from the
            /// domains of the child types. (If
            /// <tt>is_domain\<A0\>::::value</tt> is \c true, then another
            /// specialization is selected.)
            template<
                typename Tag
              , STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PROTO_MAX_ARITY, typename A)
              , typename Void1  // = void
              , typename Void2  // = void
            >
            struct make_expr
            {
                /// Same as <tt>result_of::make_expr\<Tag, D, A0, ... AN\>::::type</tt>
                /// where \c D is the deduced domain, which is calculated as follows:
                ///
                /// For each \c x in <tt>[0,N)</tt> (proceeding in order beginning with
                /// <tt>x=0</tt>), if <tt>domain_of\<Ax\>::::type</tt> is not
                /// \c default_domain, then \c D is <tt>domain_of\<Ax\>::::type</tt>.
                /// Otherwise, \c D is \c default_domain.
                typedef
                    typename detail::make_expr_<
                        Tag
                      , deduce_domain
                        STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(STREAMS_BOOST_PROTO_MAX_ARITY, A)
                    >::result_type
                type;
            };

            /// \brief Metafunction that computes the return type of the
            /// \c make_expr() function, within the specified domain.
            ///
            /// Use the <tt>result_of::make_expr\<\></tt> metafunction to compute
            /// the return type of the \c make_expr() function.
            template<
                typename Tag
              , typename Domain
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(STREAMS_BOOST_PROTO_MAX_ARITY, typename A)
            >
            struct make_expr<
                Tag
              , Domain
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(STREAMS_BOOST_PROTO_MAX_ARITY, A)
              , typename Domain::proto_is_domain_
            >
            {
                /// If \c Tag is <tt>tag::terminal</tt>, then \c type is a
                /// typedef for <tt>streams_boost::result_of\<Domain(expr\<tag::terminal,
                /// term\<A0\> \>)\>::::type</tt>.
                ///
                /// Otherwise, \c type is a typedef for <tt>streams_boost::result_of\<Domain(expr\<Tag,
                /// listN\< as_child\<A0\>::::type, ... as_child\<AN\>::::type\>)
                /// \>::::type</tt>, where \c N is the number of non-void template
                /// arguments, and <tt>as_child\<A\>::::type</tt> is evaluated as
                /// follows:
                ///
                /// \li If <tt>is_expr\<A\>::::value</tt> is \c true, then the
                /// child type is \c A.
                /// \li If \c A is <tt>B &</tt> or <tt>cv streams_boost::reference_wrapper\<B\></tt>,
                /// and <tt>is_expr\<B\>::::value</tt> is \c true, then the
                /// child type is <tt>B &</tt>.
                /// \li If <tt>is_expr\<A\>::::value</tt> is \c false, then the
                /// child type is <tt>streams_boost::result_of\<Domain(expr\<tag::terminal, term\<A\> \>
                /// )\>::::type</tt>.
                /// \li If \c A is <tt>B &</tt> or <tt>cv streams_boost::reference_wrapper\<B\></tt>,
                /// and <tt>is_expr\<B\>::::value</tt> is \c false, then the
                /// child type is <tt>streams_boost::result_of\<Domain(expr\<tag::terminal, term\<B &\> \>
                /// )\>::::type</tt>.
                typedef
                    typename detail::make_expr_<
                        Tag
                      , Domain
                        STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(STREAMS_BOOST_PROTO_MAX_ARITY, A)
                    >::result_type
                type;
            };

            /// \brief Metafunction that computes the return type of the
            /// \c unpack_expr() function, with a domain deduced from the
            /// domains of the children.
            ///
            /// Use the <tt>result_of::unpack_expr\<\></tt> metafunction to
            /// compute the return type of the \c unpack_expr() function.
            ///
            /// \c Sequence is a Fusion Forward Sequence.
            ///
            /// In this specialization, the domain is deduced from the
            /// domains of the child types. (If
            /// <tt>is_domain\<Sequence>::::value</tt> is \c true, then another
            /// specialization is selected.)
            template<
                typename Tag
              , typename Sequence
              , typename Void1  // = void
              , typename Void2  // = void
            >
            struct unpack_expr
            {
                /// Let \c S be the type of a Fusion Random Access Sequence
                /// equivalent to \c Sequence. Then \c type is the
                /// same as <tt>result_of::make_expr\<Tag,
                /// fusion::result_of::value_at_c\<S, 0\>::::type, ...
                /// fusion::result_of::value_at_c\<S, N-1\>::::type\>::::type</tt>,
                /// where \c N is the size of \c S.
                typedef
                    typename detail::unpack_expr_<
                        Tag
                      , deduce_domain
                      , Sequence
                      , fusion::result_of::size<Sequence>::type::value
                    >::type
                type;
            };

            /// \brief Metafunction that computes the return type of the
            /// \c unpack_expr() function, within the specified domain.
            ///
            /// Use the <tt>result_of::make_expr\<\></tt> metafunction to compute
            /// the return type of the \c make_expr() function.
            template<typename Tag, typename Domain, typename Sequence>
            struct unpack_expr<Tag, Domain, Sequence, typename Domain::proto_is_domain_>
            {
                /// Let \c S be the type of a Fusion Random Access Sequence
                /// equivalent to \c Sequence. Then \c type is the
                /// same as <tt>result_of::make_expr\<Tag, Domain,
                /// fusion::result_of::value_at_c\<S, 0\>::::type, ...
                /// fusion::result_of::value_at_c\<S, N-1\>::::type\>::::type</tt>,
                /// where \c N is the size of \c S.
                typedef
                    typename detail::unpack_expr_<
                        Tag
                      , Domain
                      , Sequence
                      , fusion::result_of::size<Sequence>::type::value
                    >::type
                type;
            };
        }

        namespace functional
        {
            /// \brief A callable function object equivalent to the
            /// \c proto::make_expr() function.
            ///
            /// In all cases, <tt>functional::make_expr\<Tag, Domain\>()(a0, ... aN)</tt>
            /// is equivalent to <tt>proto::make_expr\<Tag, Domain\>(a0, ... aN)</tt>.
            ///
            /// <tt>functional::make_expr\<Tag\>()(a0, ... aN)</tt>
            /// is equivalent to <tt>proto::make_expr\<Tag\>(a0, ... aN)</tt>.
            template<typename Tag, typename Domain  /* = deduce_domain*/>
            struct make_expr
            {
                STREAMS_BOOST_PROTO_CALLABLE()
                STREAMS_BOOST_PROTO_POLY_FUNCTION()

                template<typename Sig>
                struct result;

                template<typename This, typename A0>
                struct result<This(A0)>
                {
                    typedef
                        typename result_of::make_expr<
                            Tag
                          , Domain
                          , A0
                        >::type
                    type;
                };

                /// Construct an expression node with tag type \c Tag
                /// and in the domain \c Domain.
                ///
                /// \return <tt>proto::make_expr\<Tag, Domain\>(a0,...aN)</tt>
                template<typename A0>
                typename result_of::make_expr<
                    Tag
                  , Domain
                  , A0 const
                >::type
                operator ()(A0 const &a0) const
                {
                    return proto::detail::make_expr_<
                        Tag
                      , Domain
                      , A0 const
                    >()(a0);
                }

                // Additional overloads generated by the preprocessor ...

            #define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                                     \
                (4, (2, STREAMS_BOOST_PROTO_MAX_ARITY, <streams_boost/proto/make_expr.hpp>, 2))                     \
                /**/

            #include STREAMS_BOOST_PP_ITERATE()

                /// INTERNAL ONLY
                ///
                template<
                    STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(
                        STREAMS_BOOST_PROTO_MAX_ARITY
                      , typename A
                      , = void STREAMS_BOOST_PP_INTERCEPT
                    )
                >
                struct impl
                  : detail::make_expr_<
                      Tag
                    , Domain
                      STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(STREAMS_BOOST_PROTO_MAX_ARITY, A)
                    >
                {};
            };

            /// \brief A callable function object equivalent to the
            /// \c proto::unpack_expr() function.
            ///
            /// In all cases, <tt>functional::unpack_expr\<Tag, Domain\>()(seq)</tt>
            /// is equivalent to <tt>proto::unpack_expr\<Tag, Domain\>(seq)</tt>.
            ///
            /// <tt>functional::unpack_expr\<Tag\>()(seq)</tt>
            /// is equivalent to <tt>proto::unpack_expr\<Tag\>(seq)</tt>.
            template<typename Tag, typename Domain /* = deduce_domain*/>
            struct unpack_expr
            {
                STREAMS_BOOST_PROTO_CALLABLE()

                template<typename Sig>
                struct result
                {};

                template<typename This, typename Sequence>
                struct result<This(Sequence)>
                {
                    typedef
                        typename result_of::unpack_expr<
                            Tag
                          , Domain
                          , typename remove_reference<Sequence>::type
                        >::type
                    type;
                };

                /// Construct an expression node with tag type \c Tag
                /// and in the domain \c Domain.
                ///
                /// \param sequence A Fusion Forward Sequence
                /// \return <tt>proto::unpack_expr\<Tag, Domain\>(sequence)</tt>
                template<typename Sequence>
                typename result_of::unpack_expr<Tag, Domain, Sequence const>::type
                operator ()(Sequence const &sequence) const
                {
                    return proto::detail::unpack_expr_<
                        Tag
                      , Domain
                      , Sequence const
                      , fusion::result_of::size<Sequence>::type::value
                    >::call(sequence);
                }
            };

            /// INTERNAL ONLY
            ///
            template<typename Tag, typename Domain>
            struct unfused_expr_fun
            {
                STREAMS_BOOST_PROTO_CALLABLE()

                template<typename Sig>
                struct result;

                template<typename This, typename Sequence>
                struct result<This(Sequence)>
                {
                    typedef
                        typename result_of::unpack_expr<
                            Tag
                          , Domain
                          , typename remove_reference<Sequence>::type
                        >::type
                    type;
                };

                template<typename Sequence>
                typename proto::result_of::unpack_expr<Tag, Domain, Sequence const>::type
                operator ()(Sequence const &sequence) const
                {
                    return proto::detail::unpack_expr_<
                        Tag
                      , Domain
                      , Sequence const
                      , fusion::result_of::size<Sequence>::type::value
                    >::call(sequence);
                }
            };

            /// INTERNAL ONLY
            ///
            template<typename Tag, typename Domain>
            struct unfused_expr
              : fusion::unfused_generic<unfused_expr_fun<Tag, Domain> >
            {
                STREAMS_BOOST_PROTO_CALLABLE()
            };

        } // namespace functional

        /// \brief Construct an expression of the requested tag type
        /// with a domain and with the specified arguments as children.
        ///
        /// This function template may be invoked either with or without
        /// specifying a \c Domain argument. If no domain is specified,
        /// the domain is deduced by examining in order the domains of
        /// the given arguments and taking the first that is not
        /// \c default_domain, if any such domain exists, or
        /// \c default_domain otherwise.
        ///
        /// Let \c wrap_(x) be defined such that:
        /// \li If \c x is a <tt>streams_boost::reference_wrapper\<\></tt>,
        /// \c wrap_(x) is equivalent to <tt>as_child\<Domain\>(x.get())</tt>.
        /// \li Otherwise, \c wrap_(x) is equivalent to
        /// <tt>as_expr\<Domain\>(x)</tt>.
        ///
        /// Let <tt>make_\<Tag\>(b0,...bN)</tt> be defined as
        /// <tt>expr\<Tag, listN\<C0,...CN\> \>::::make(c0,...cN)</tt>
        /// where \c Bx is the type of \c bx.
        ///
        /// \return <tt>Domain()(make_\<Tag\>(wrap_(a0),...wrap_(aN)))</tt>.
        template<typename Tag, typename A0>
        typename lazy_disable_if<
            is_domain<A0>
          , result_of::make_expr<
                Tag
              , A0 const
            >
        >::type const
        make_expr(A0 const &a0)
        {
            return proto::detail::make_expr_<
                Tag
              , deduce_domain
              , A0 const
            >()(a0);
        }

        /// \overload
        ///
        template<typename Tag, typename Domain, typename C0>
        typename result_of::make_expr<
            Tag
          , Domain
          , C0 const
        >::type const
        make_expr(C0 const &c0)
        {
            return proto::detail::make_expr_<
                Tag
              , Domain
              , C0 const
            >()(c0);
        }

        // Additional overloads generated by the preprocessor...

    #define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                                             \
        (4, (2, STREAMS_BOOST_PROTO_MAX_ARITY, <streams_boost/proto/make_expr.hpp>, 3))                             \
        /**/

    #include STREAMS_BOOST_PP_ITERATE()

        /// \brief Construct an expression of the requested tag type
        /// with a domain and with childres from the specified Fusion
        /// Forward Sequence.
        ///
        /// This function template may be invoked either with or without
        /// specifying a \c Domain argument. If no domain is specified,
        /// the domain is deduced by examining in order the domains of the
        /// elements of \c sequence and taking the first that is not
        /// \c default_domain, if any such domain exists, or
        /// \c default_domain otherwise.
        ///
        /// Let \c s be a Fusion Random Access Sequence equivalent to \c sequence.
        /// Let <tt>wrap_\<N\>(s)</tt>, where \c s has type \c S, be defined
        /// such that:
        /// \li If <tt>fusion::result_of::value_at_c\<S,N\>::::type</tt> is a reference,
        /// <tt>wrap_\<N\>(s)</tt> is equivalent to
        /// <tt>as_child\<Domain\>(fusion::at_c\<N\>(s))</tt>.
        /// \li Otherwise, <tt>wrap_\<N\>(s)</tt> is equivalent to
        /// <tt>as_expr\<Domain\>(fusion::at_c\<N\>(s))</tt>.
        ///
        /// Let <tt>make_\<Tag\>(b0,...bN)</tt> be defined as
        /// <tt>expr\<Tag, listN\<B0,...BN\> \>::::make(b0,...bN)</tt>
        /// where \c Bx is the type of \c bx.
        ///
        /// \param sequence a Fusion Forward Sequence.
        /// \return <tt>Domain()(make_\<Tag\>(wrap_\<0\>(s),...wrap_\<N-1\>(s)))</tt>,
        /// where N is the size of \c Sequence.
        template<typename Tag, typename Sequence>
        typename lazy_disable_if<
            is_domain<Sequence>
          , result_of::unpack_expr<Tag, Sequence const>
        >::type const
        unpack_expr(Sequence const &sequence)
        {
            return proto::detail::unpack_expr_<
                Tag
              , deduce_domain
              , Sequence const
              , fusion::result_of::size<Sequence>::type::value
            >::call(sequence);
        }

        /// \overload
        ///
        template<typename Tag, typename Domain, typename Sequence2>
        typename result_of::unpack_expr<Tag, Domain, Sequence2 const>::type const
        unpack_expr(Sequence2 const &sequence2)
        {
            return proto::detail::unpack_expr_<
                Tag
              , Domain
              , Sequence2 const
              , fusion::result_of::size<Sequence2>::type::value
            >::call(sequence2);
        }

        /// \brief Return a proxy object that holds its arguments by reference
        /// and is implicitly convertible to an expression.
        template<typename A0>
        detail::implicit_expr_1<A0> const
        implicit_expr(A0 &a0)
        {
            detail::implicit_expr_1<A0> that = {a0};
            return that;
        }

        // Additional overloads generated by the preprocessor...

    #define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                                             \
        (4, (2, STREAMS_BOOST_PROTO_MAX_ARITY, <streams_boost/proto/make_expr.hpp>, 4))                             \
        /**/

    #include STREAMS_BOOST_PP_ITERATE()

        /// INTERNAL ONLY
        ///
        template<typename Tag, typename Domain>
        struct is_callable<functional::make_expr<Tag, Domain> >
          : mpl::true_
        {};

        /// INTERNAL ONLY
        ///
        template<typename Tag, typename Domain>
        struct is_callable<functional::unpack_expr<Tag, Domain> >
          : mpl::true_
        {};

        /// INTERNAL ONLY
        ///
        template<typename Tag, typename Domain>
        struct is_callable<functional::unfused_expr<Tag, Domain> >
          : mpl::true_
        {};

    }}

    #ifdef _MSC_VER
    # pragma warning(pop)
    #endif

    #undef STREAMS_BOOST_PROTO_FUSION_AT
    #undef STREAMS_BOOST_PROTO_FUSION_AT_TYPE
    #undef STREAMS_BOOST_PROTO_FUSION_AS_CHILD_AT
    #undef STREAMS_BOOST_PROTO_FUSION_AS_CHILD_AT_TYPE
    #undef STREAMS_BOOST_PROTO_FUSION_NEXT_ITERATOR
    #undef STREAMS_BOOST_PROTO_FUSION_NEXT_ITERATOR_TYPE
    #undef STREAMS_BOOST_PROTO_FUSION_ITERATORS
    #undef STREAMS_BOOST_PROTO_FUSION_ITERATORS_TYPE

    #endif // STREAMS_BOOST_PROTO_MAKE_EXPR_HPP_EAN_04_01_2005

#elif STREAMS_BOOST_PP_ITERATION_FLAGS() == 1

    #define N STREAMS_BOOST_PP_ITERATION()
    #define M STREAMS_BOOST_PP_SUB(STREAMS_BOOST_PROTO_MAX_ARITY, N)

    #if N > 1
        template<STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
        struct STREAMS_BOOST_PP_CAT(implicit_expr_, N)
        {
            #define M0(Z, N, DATA) STREAMS_BOOST_PP_CAT(A, N) &STREAMS_BOOST_PP_CAT(a, N);
            STREAMS_BOOST_PP_REPEAT(N, M0, ~)
            #undef M0

            template<typename Tag, typename Args>
            operator proto::expr<Tag, Args, N>() const
            {
                #define M0(Z, N, DATA)                                                              \
                    implicit_expr_1<STREAMS_BOOST_PP_CAT(A, N)> STREAMS_BOOST_PP_CAT(b, N)                          \
                        = {this->STREAMS_BOOST_PP_CAT(a, N)};                                               \
                    typename Args::STREAMS_BOOST_PP_CAT(child, N) STREAMS_BOOST_PP_CAT(c, N) = STREAMS_BOOST_PP_CAT(b, N);  \
                    /**/
                STREAMS_BOOST_PP_REPEAT(N, M0, ~)
                #undef M0
                proto::expr<Tag, Args, N> that = {STREAMS_BOOST_PP_ENUM_PARAMS(N, c)};
                return that;
            }

            template<typename Expr>
            operator Expr() const
            {
                typename Expr::proto_base_expr that = *this;
                return detail::implicit_expr_wrap(that, is_aggregate<Expr>(), static_cast<Expr *>(0));
            }
        };
    #endif

        template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PROTO_MAX_ARITY, typename T)>
        struct select_nth<STREAMS_BOOST_PP_DEC(N), STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PROTO_MAX_ARITY, T)>
        {
            typedef STREAMS_BOOST_PP_CAT(T, STREAMS_BOOST_PP_DEC(N)) type;
        };

        // Use function overloading as an efficient mechanism for
        // calculating the domain shared by a bunch of proto expressions
        // (or non-expressions, assumed to be in the default_domain).
        // The domain of a set of domains S is deduced as follows:
        // - If S contains only default_domain, the deduced domain is
        //   default_domain.
        // - If S contains only X and default_domain, the deduced domain
        //   is X.
        // - If S contains different domains X and Y, neither of which is
        //   default_domain, it is an error.
        template<STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
        struct STREAMS_BOOST_PP_CAT(deduce_domain, N)
        {
            #if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1310)
            // The function overloading trick doesn't work on MSVC-7.1, so
            // do it the hard (expensive) way.
            typedef
                typename mpl::eval_if_c<
                    is_same<typename domain_of<A0>::type, default_domain>::value
                  , STREAMS_BOOST_PP_CAT(deduce_domain, STREAMS_BOOST_PP_DEC(N))<STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(N, A)>
                  , domain_of<A0>
                >::type
            type;
            #else
            #define M0(N, F) char (&F)[STREAMS_BOOST_PP_INC(N)]
            static M0(STREAMS_BOOST_PROTO_MAX_ARITY, deducer(...));
            #define M1(Z, X, DATA)                                                                  \
            typedef typename domain_of<STREAMS_BOOST_PP_CAT(A, X)>::type STREAMS_BOOST_PP_CAT(D, X);                \
            static STREAMS_BOOST_PP_CAT(D, X) &STREAMS_BOOST_PP_CAT(d, X);                                          \
            template<typename T>                                                                    \
            static M0(X, deducer(                                                                   \
                STREAMS_BOOST_PP_ENUM_PARAMS_Z(Z, X, default_domain STREAMS_BOOST_PP_INTERCEPT)                     \
                STREAMS_BOOST_PP_COMMA_IF(X) T                                                              \
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(                                                    \
                    Z                                                                               \
                  , STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_SUB(N, X))                                                \
                  , typename nondeduced_domain<T>::type STREAMS_BOOST_PP_INTERCEPT                          \
                )                                                                                   \
            ));
            STREAMS_BOOST_PP_REPEAT(N, M1, ~)
            #undef M0
            #undef M1
            STREAMS_BOOST_STATIC_CONSTANT(int, value = sizeof(deducer(STREAMS_BOOST_PP_ENUM_PARAMS(N, d))) - 1);
            typedef typename select_nth<value, STREAMS_BOOST_PP_ENUM_PARAMS(N, D)>::type type;
            #endif
        };

        template<typename Tag, typename Domain STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        struct make_expr_<Tag, Domain STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, A)
            STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(M, void STREAMS_BOOST_PP_INTERCEPT), void>
        {
            typedef proto::expr<
                Tag
              , STREAMS_BOOST_PP_CAT(list, N)<STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_PROTO_AS_CHILD_TYPE, (A, ~, Domain)) >
              , N
            > expr_type;

            typedef typename Domain::template result<Domain(expr_type)>::type result_type;

            result_type operator()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, typename add_reference<A, >::type a)) const
            {
                expr_type that = {
                    STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_PROTO_AS_CHILD, (A, a, Domain))
                };
                return Domain()(that);
            }
        };

        template<typename Tag STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        struct make_expr_<Tag, deduce_domain STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, A)
            STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(M, void STREAMS_BOOST_PP_INTERCEPT), void>
          : make_expr_<
                Tag
              , typename STREAMS_BOOST_PP_CAT(deduce_domain, N)<STREAMS_BOOST_PP_ENUM_PARAMS(N, A)>::type
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, A)
            >
        {};

        template<typename Tag, typename Domain, typename Sequence>
        struct unpack_expr_<Tag, Domain, Sequence, N>
        {
            STREAMS_BOOST_PROTO_FUSION_ITERATORS_TYPE(N)

            typedef proto::expr<
                Tag
              , STREAMS_BOOST_PP_CAT(list, N)<
                    STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_PROTO_FUSION_AS_CHILD_AT_TYPE, ~)
                >
              , N
            > expr_type;

            typedef typename Domain::template result<Domain(expr_type)>::type type;

            static type const call(Sequence const &sequence)
            {
                STREAMS_BOOST_PROTO_FUSION_ITERATORS(N)
                expr_type that = {
                    STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_PROTO_FUSION_AS_CHILD_AT, ~)
                };
                return Domain()(that);
            }
        };

        template<typename Tag, typename Sequence>
        struct unpack_expr_<Tag, deduce_domain, Sequence, N>
        {
            STREAMS_BOOST_PROTO_FUSION_ITERATORS_TYPE(N)

            typedef
                unpack_expr_<
                    Tag
                  , typename STREAMS_BOOST_PP_CAT(deduce_domain, N)<
                        STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_PROTO_FUSION_AT_TYPE, ~)
                    >::type
                  , Sequence
                  , N
                >
            other;

            typedef typename other::type type;

            static type const call(Sequence const &sequence)
            {
                return other::call(sequence);
            }
        };

    #undef N
    #undef M

#elif STREAMS_BOOST_PP_ITERATION_FLAGS() == 2

    #define N STREAMS_BOOST_PP_ITERATION()

        template<typename This STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        struct result<This(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))>
        {
            typedef
                typename result_of::make_expr<
                    Tag
                  , Domain
                    STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, A)
                >::type
            type;
        };

        /// \overload
        ///
        template<STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
        typename result_of::make_expr<
            Tag
          , Domain
            STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, const A)
        >::type
        operator ()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, const A, &a)) const
        {
            return proto::detail::make_expr_<
                Tag
              , Domain
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, const A)
            >()(STREAMS_BOOST_PP_ENUM_PARAMS(N, a));
        }

    #undef N

#elif STREAMS_BOOST_PP_ITERATION_FLAGS() == 3

    #define N STREAMS_BOOST_PP_ITERATION()

        /// \overload
        ///
        template<typename Tag STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        typename lazy_disable_if<
            is_domain<A0>
          , result_of::make_expr<
                Tag
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, const A)
            >
        >::type const
        make_expr(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, const A, &a))
        {
            return proto::detail::make_expr_<
                Tag
              , deduce_domain
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, const A)
            >()(STREAMS_BOOST_PP_ENUM_PARAMS(N, a));
        }

        /// \overload
        ///
        template<typename Tag, typename Domain STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename C)>
        typename result_of::make_expr<
            Tag
          , Domain
            STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, const C)
        >::type const
        make_expr(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, const C, &c))
        {
            return proto::detail::make_expr_<
                Tag
              , Domain
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, const C)
            >()(STREAMS_BOOST_PP_ENUM_PARAMS(N, c));
        }

    #undef N

#elif STREAMS_BOOST_PP_ITERATION_FLAGS() == 4

    #define N STREAMS_BOOST_PP_ITERATION()

        /// \overload
        ///
        template<STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
        detail::STREAMS_BOOST_PP_CAT(implicit_expr_, N)<STREAMS_BOOST_PP_ENUM_PARAMS(N, A)> const
        implicit_expr(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, &a))
        {
            detail::STREAMS_BOOST_PP_CAT(implicit_expr_, N)<STREAMS_BOOST_PP_ENUM_PARAMS(N, A)> that
                = {STREAMS_BOOST_PP_ENUM_PARAMS(N, a)};
            return that;
        }

    #undef N

#endif // STREAMS_BOOST_PP_IS_ITERATING
