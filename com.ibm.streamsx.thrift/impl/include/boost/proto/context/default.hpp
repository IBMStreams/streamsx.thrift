#ifndef STREAMS_BOOST_PP_IS_ITERATING
    ///////////////////////////////////////////////////////////////////////////////
    /// \file default.hpp
    /// Definintion of default_context, a default evaluation context for
    /// proto::eval() that uses Boost.Typeof to deduce return types
    /// of the built-in operators.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

    #ifndef STREAMS_BOOST_PROTO_CONTEXT_DEFAULT_HPP_EAN_01_08_2007
    #define STREAMS_BOOST_PROTO_CONTEXT_DEFAULT_HPP_EAN_01_08_2007

    #include <streams_boost/config.hpp>
    #include <streams_boost/preprocessor/iteration/iterate.hpp>
    #include <streams_boost/preprocessor/repetition/enum_shifted.hpp>
    #include <streams_boost/utility/result_of.hpp>
    #include <streams_boost/type_traits/is_const.hpp>
    #include <streams_boost/type_traits/is_function.hpp>
    #include <streams_boost/type_traits/remove_reference.hpp>
    #include <streams_boost/type_traits/is_member_pointer.hpp>
    #include <streams_boost/type_traits/is_member_object_pointer.hpp>
    #include <streams_boost/type_traits/is_member_function_pointer.hpp>
    #include <streams_boost/proto/proto_fwd.hpp>
    #include <streams_boost/proto/tags.hpp>
    #include <streams_boost/proto/eval.hpp>
    #include <streams_boost/proto/traits.hpp> // for proto::child_c()
    #include <streams_boost/proto/detail/decltype.hpp>

    namespace streams_boost { namespace proto
    {
    /// INTERNAL ONLY
    ///
    #define UNREF(x) typename streams_boost::remove_reference<x>::type

        namespace context
        {
            template<
                typename Expr
              , typename Context
              , typename Tag        // = typename Expr::proto_tag
              , long Arity          // = Expr::proto_arity_c
            >
            struct default_eval
            {};

            /// INTERNAL ONLY
            ///
        #define STREAMS_BOOST_PROTO_UNARY_OP_RESULT(OP, TAG, MAKE)                                          \
            template<typename Expr, typename Context>                                               \
            struct default_eval<Expr, Context, TAG, 1>                                              \
            {                                                                                       \
            private:                                                                                \
                typedef typename proto::result_of::child_c<Expr, 0>::type e0;                       \
                typedef typename proto::result_of::eval<UNREF(e0), Context>::type r0;               \
            public:                                                                                 \
                STREAMS_BOOST_PROTO_DECLTYPE_(OP proto::detail::MAKE<r0>(), result_type)                    \
                result_type operator ()(Expr &expr, Context &ctx) const                             \
                {                                                                                   \
                    return OP proto::eval(proto::child_c<0>(expr), ctx);                            \
                }                                                                                   \
            };                                                                                      \
            /**/

            /// INTERNAL ONLY
            ///
        #define STREAMS_BOOST_PROTO_BINARY_OP_RESULT(OP, TAG, LMAKE, RMAKE)                                 \
            template<typename Expr, typename Context>                                               \
            struct default_eval<Expr, Context, TAG, 2>                                              \
            {                                                                                       \
            private:                                                                                \
                typedef typename proto::result_of::child_c<Expr, 0>::type e0;                       \
                typedef typename proto::result_of::child_c<Expr, 1>::type e1;                       \
                typedef typename proto::result_of::eval<UNREF(e0), Context>::type r0;               \
                typedef typename proto::result_of::eval<UNREF(e1), Context>::type r1;               \
            public:                                                                                 \
                STREAMS_BOOST_PROTO_DECLTYPE_(                                                              \
                    proto::detail::LMAKE<r0>() OP proto::detail::RMAKE<r1>()                        \
                  , result_type                                                                     \
                )                                                                                   \
                result_type operator ()(Expr &expr, Context &ctx) const                             \
                {                                                                                   \
                    return proto::eval(                                                             \
                        proto::child_c<0>(expr), ctx) OP proto::eval(proto::child_c<1>(expr)        \
                      , ctx                                                                         \
                    );                                                                              \
                }                                                                                   \
            };                                                                                      \
            /**/

            STREAMS_BOOST_PROTO_UNARY_OP_RESULT(+, proto::tag::unary_plus, make)
            STREAMS_BOOST_PROTO_UNARY_OP_RESULT(-, proto::tag::negate, make)
            STREAMS_BOOST_PROTO_UNARY_OP_RESULT(*, proto::tag::dereference, make)
            STREAMS_BOOST_PROTO_UNARY_OP_RESULT(~, proto::tag::complement, make)
            STREAMS_BOOST_PROTO_UNARY_OP_RESULT(&, proto::tag::address_of, make)
            STREAMS_BOOST_PROTO_UNARY_OP_RESULT(!, proto::tag::logical_not, make)
            STREAMS_BOOST_PROTO_UNARY_OP_RESULT(++, proto::tag::pre_inc, make_mutable)
            STREAMS_BOOST_PROTO_UNARY_OP_RESULT(--, proto::tag::pre_dec, make_mutable)

            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(<<, proto::tag::shift_left, make_mutable, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(>>, proto::tag::shift_right, make_mutable, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(*, proto::tag::multiplies, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(/, proto::tag::divides, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(%, proto::tag::modulus, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(+, proto::tag::plus, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(-, proto::tag::minus, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(<, proto::tag::less, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(>, proto::tag::greater, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(<=, proto::tag::less_equal, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(>=, proto::tag::greater_equal, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(==, proto::tag::equal_to, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(!=, proto::tag::not_equal_to, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(||, proto::tag::logical_or, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(&&, proto::tag::logical_and, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(&, proto::tag::bitwise_and, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(|, proto::tag::bitwise_or, make, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(^, proto::tag::bitwise_xor, make, make)

            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(=, proto::tag::assign, make_mutable, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(<<=, proto::tag::shift_left_assign, make_mutable, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(>>=, proto::tag::shift_right_assign, make_mutable, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(*=, proto::tag::multiplies_assign, make_mutable, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(/=, proto::tag::divides_assign, make_mutable, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(%=, proto::tag::modulus_assign, make_mutable, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(+=, proto::tag::plus_assign, make_mutable, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(-=, proto::tag::minus_assign, make_mutable, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(&=, proto::tag::bitwise_and_assign, make_mutable, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(|=, proto::tag::bitwise_or_assign, make_mutable, make)
            STREAMS_BOOST_PROTO_BINARY_OP_RESULT(^=, proto::tag::bitwise_xor_assign, make_mutable, make)

        #undef STREAMS_BOOST_PROTO_UNARY_OP_RESULT
        #undef STREAMS_BOOST_PROTO_BINARY_OP_RESULT

            /// INTERNAL ONLY
            template<typename Expr, typename Context>
            struct is_member_function_eval
              : is_member_function_pointer<
                    typename remove_const<
                        typename remove_reference<
                            typename proto::result_of::eval<
                                typename remove_reference<
                                    typename proto::result_of::child_c<Expr, 1>::type
                                >::type
                              , Context
                            >::type
                        >::type
                    >::type
                >
            {};

            /// INTERNAL ONLY
            template<typename Expr, typename Context, bool IsMemFunCall>
            struct memfun_eval
            {
            private:
                typedef typename result_of::child_c<Expr, 0>::type e0;
                typedef typename result_of::child_c<Expr, 1>::type e1;
                typedef typename proto::result_of::eval<UNREF(e0), Context>::type r0;
                typedef typename proto::result_of::eval<UNREF(e1), Context>::type r1;
            public:
                typedef typename detail::mem_ptr_fun<r0, r1>::result_type result_type;
                result_type operator ()(Expr &expr, Context &ctx) const
                {
                    return detail::mem_ptr_fun<r0, r1>()(
                        proto::eval(proto::child_c<0>(expr), ctx)
                      , proto::eval(proto::child_c<1>(expr), ctx)
                    );
                }
            };

            /// INTERNAL ONLY
            template<typename Expr, typename Context>
            struct memfun_eval<Expr, Context, true>
            {
            private:
                typedef typename result_of::child_c<Expr, 0>::type e0;
                typedef typename result_of::child_c<Expr, 1>::type e1;
                typedef typename proto::result_of::eval<UNREF(e0), Context>::type r0;
                typedef typename proto::result_of::eval<UNREF(e1), Context>::type r1;
            public:
                typedef detail::memfun<r0, r1> result_type;
                result_type const operator ()(Expr &expr, Context &ctx) const
                {
                    return detail::memfun<r0, r1>(
                        proto::eval(proto::child_c<0>(expr), ctx)
                      , proto::eval(proto::child_c<1>(expr), ctx)
                    );
                }
            };

            template<typename Expr, typename Context>
            struct default_eval<Expr, Context, tag::mem_ptr, 2>
              : memfun_eval<Expr, Context, is_member_function_eval<Expr, Context>::value>
            {};

            template<typename Expr, typename Context, typename Tag>
            struct default_eval<Expr, Context, Tag, 0>
            {
                typedef
                    typename proto::result_of::value<Expr &>::type
                result_type;

                result_type operator ()(Expr &expr, Context &) const
                {
                    return proto::value(expr);
                }
            };

            // Handle post-increment specially.
            template<typename Expr, typename Context>
            struct default_eval<Expr, Context, proto::tag::post_inc, 1>
            {
            private:
                typedef typename proto::result_of::child_c<Expr, 0>::type e0;
                typedef typename proto::result_of::eval<UNREF(e0), Context>::type r0;
            public:
                STREAMS_BOOST_PROTO_DECLTYPE_(proto::detail::make_mutable<r0>() ++, result_type)
                result_type operator ()(Expr &expr, Context &ctx) const
                {
                    return proto::eval(proto::child_c<0>(expr), ctx) ++;
                }
            };

            // Handle post-decrement specially.
            template<typename Expr, typename Context>
            struct default_eval<Expr, Context, proto::tag::post_dec, 1>
            {
            private:
                typedef typename proto::result_of::child_c<Expr, 0>::type e0;
                typedef typename proto::result_of::eval<UNREF(e0), Context>::type r0;
            public:
                STREAMS_BOOST_PROTO_DECLTYPE_(proto::detail::make_mutable<r0>() --, result_type)
                result_type operator ()(Expr &expr, Context &ctx) const
                {
                    return proto::eval(proto::child_c<0>(expr), ctx) --;
                }
            };

            // Handle subscript specially.
            template<typename Expr, typename Context>
            struct default_eval<Expr, Context, proto::tag::subscript, 2>
            {
            private:
                typedef typename proto::result_of::child_c<Expr, 0>::type e0;
                typedef typename proto::result_of::child_c<Expr, 1>::type e1;
                typedef typename proto::result_of::eval<UNREF(e0), Context>::type r0;
                typedef typename proto::result_of::eval<UNREF(e1), Context>::type r1;
            public:
                STREAMS_BOOST_PROTO_DECLTYPE_(proto::detail::make_subscriptable<r0>()[proto::detail::make<r1>()], result_type)
                result_type operator ()(Expr &expr, Context &ctx) const
                {
                    return proto::eval(proto::child_c<0>(expr), ctx)[proto::eval(proto::child_c<1>(expr), ctx)];
                }
            };

            // Handle if_else_ specially.
            template<typename Expr, typename Context>
            struct default_eval<Expr, Context, proto::tag::if_else_, 3>
            {
            private:
                typedef typename proto::result_of::child_c<Expr, 0>::type e0;
                typedef typename proto::result_of::child_c<Expr, 1>::type e1;
                typedef typename proto::result_of::child_c<Expr, 2>::type e2;
                typedef typename proto::result_of::eval<UNREF(e0), Context>::type r0;
                typedef typename proto::result_of::eval<UNREF(e1), Context>::type r1;
                typedef typename proto::result_of::eval<UNREF(e2), Context>::type r2;
            public:
                STREAMS_BOOST_PROTO_DECLTYPE_(
                    proto::detail::make<r0>()
                  ? proto::detail::make<r1>()
                  : proto::detail::make<r2>()
                  , result_type
                )
                result_type operator ()(Expr &expr, Context &ctx) const
                {
                    return proto::eval(proto::child_c<0>(expr), ctx)
                         ? proto::eval(proto::child_c<1>(expr), ctx)
                         : proto::eval(proto::child_c<2>(expr), ctx);
                }
            };

            // Handle comma specially.
            template<typename Expr, typename Context>
            struct default_eval<Expr, Context, proto::tag::comma, 2>
            {
            private:
                typedef typename proto::result_of::child_c<Expr, 0>::type e0;
                typedef typename proto::result_of::child_c<Expr, 1>::type e1;
                typedef typename proto::result_of::eval<UNREF(e0), Context>::type r0;
                typedef typename proto::result_of::eval<UNREF(e1), Context>::type r1;
            public:
                typedef typename proto::detail::comma_result<r0, r1>::type result_type;
                result_type operator ()(Expr &expr, Context &ctx) const
                {
                    return proto::eval(proto::child_c<0>(expr), ctx), proto::eval(proto::child_c<1>(expr), ctx);
                }
            };

            // Handle function specially
            #define EVAL_TYPE(Z, N, DATA)                                                           \
                typename proto::result_of::eval<                                                    \
                    typename remove_reference<                                                      \
                        typename proto::result_of::child_c<DATA, N>::type                           \
                    >::type                                                                         \
                  , Context                                                                         \
                >::type                                                                             \
                /**/

            #define EVAL(Z, N, DATA)                                                                \
                proto::eval(proto::child_c<N>(DATA), context)                                       \
                /**/

            template<typename Expr, typename Context>
            struct default_eval<Expr, Context, proto::tag::function, 1>
            {
                typedef
                    typename proto::detail::result_of_fixup<EVAL_TYPE(~, 0, Expr)>::type
                function_type;

                typedef
                    typename streams_boost::result_of<function_type()>::type
                result_type;

                result_type operator ()(Expr &expr, Context &context) const
                {
                    return EVAL(~, 0, expr)();
                }
            };

            template<typename Expr, typename Context>
            struct default_eval<Expr, Context, proto::tag::function, 2>
            {
                typedef
                    typename proto::detail::result_of_fixup<EVAL_TYPE(~, 0, Expr)>::type
                function_type;

                typedef
                    typename detail::result_of_<function_type(EVAL_TYPE(~, 1, Expr))>::type
                result_type;

                result_type operator ()(Expr &expr, Context &context) const
                {
                    return this->invoke(
                        expr
                      , context
                      , is_member_function_pointer<function_type>()
                      , is_member_object_pointer<function_type>()
                    );
                }

            private:
                result_type invoke(Expr &expr, Context &context, mpl::false_, mpl::false_) const
                {
                    return EVAL(~, 0, expr)(EVAL(~, 1, expr));
                }

                result_type invoke(Expr &expr, Context &context, mpl::true_, mpl::false_) const
                {
                    STREAMS_BOOST_PROTO_USE_GET_POINTER();
                    typedef typename detail::classtypeof<function_type>::type class_type;
                    return (STREAMS_BOOST_PROTO_GET_POINTER(class_type, EVAL(~, 1, expr)) ->* EVAL(~, 0, expr))();
                }

                result_type invoke(Expr &expr, Context &context, mpl::false_, mpl::true_) const
                {
                    STREAMS_BOOST_PROTO_USE_GET_POINTER();
                    typedef typename detail::classtypeof<function_type>::type class_type;
                    return (STREAMS_BOOST_PROTO_GET_POINTER(class_type, EVAL(~, 1, expr)) ->* EVAL(~, 0, expr));
                }
            };

            #define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (3, (3, STREAMS_BOOST_PROTO_MAX_ARITY, <streams_boost/proto/context/default.hpp>))
            #include STREAMS_BOOST_PP_ITERATE()

            #undef EVAL_TYPE
            #undef EVAL

            /// default_context
            ///
            struct default_context
            {
                /// default_context::eval
                ///
                template<typename Expr, typename ThisContext = default_context const>
                struct eval
                  : default_eval<Expr, ThisContext>
                {};
            };

        } // namespace context

    }} // namespace streams_boost::proto

    #undef UNREF

    #endif

#else

    #define N STREAMS_BOOST_PP_ITERATION()

        template<typename Expr, typename Context>
        struct default_eval<Expr, Context, proto::tag::function, N>
        {
            typedef
                typename proto::detail::result_of_fixup<EVAL_TYPE(~, 0, Expr)>::type
            function_type;

            typedef
                typename streams_boost::result_of<
                    function_type(STREAMS_BOOST_PP_ENUM_SHIFTED(N, EVAL_TYPE, Expr))
                >::type
            result_type;

            result_type operator ()(Expr &expr, Context &context) const
            {
                return this->invoke(expr, context, is_member_function_pointer<function_type>());
            }

        private:
            result_type invoke(Expr &expr, Context &context, mpl::false_) const
            {
                return EVAL(~, 0, expr)(STREAMS_BOOST_PP_ENUM_SHIFTED(N, EVAL, expr));
            }

            result_type invoke(Expr &expr, Context &context, mpl::true_) const
            {
                #define M0(Z, M, expr) STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_SUB(M, 2)) EVAL(Z, M, expr)
                STREAMS_BOOST_PROTO_USE_GET_POINTER();
                typedef typename detail::classtypeof<function_type>::type class_type;
                return (STREAMS_BOOST_PROTO_GET_POINTER(class_type, EVAL(~, 1, expr)) ->* EVAL(~, 0, expr))(
                    STREAMS_BOOST_PP_REPEAT_FROM_TO(2, N, M0, expr)
                );
                #undef M0
            }
        };

    #undef N

#endif
