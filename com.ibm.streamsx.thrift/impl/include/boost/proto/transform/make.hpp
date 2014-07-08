#ifndef STREAMS_BOOST_PP_IS_ITERATING
    ///////////////////////////////////////////////////////////////////////////////
    /// \file make.hpp
    /// Contains definition of the make<> transform.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

    #ifndef STREAMS_BOOST_PROTO_TRANSFORM_MAKE_HPP_EAN_12_02_2007
    #define STREAMS_BOOST_PROTO_TRANSFORM_MAKE_HPP_EAN_12_02_2007

    #include <streams_boost/detail/workaround.hpp>
    #include <streams_boost/preprocessor/repetition/enum.hpp>
    #include <streams_boost/preprocessor/repetition/enum_params.hpp>
    #include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>
    #include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
    #include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
    #include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
    #include <streams_boost/preprocessor/facilities/intercept.hpp>
    #include <streams_boost/preprocessor/cat.hpp>
    #include <streams_boost/preprocessor/iteration/iterate.hpp>
    #include <streams_boost/preprocessor/selection/max.hpp>
    #include <streams_boost/preprocessor/arithmetic/inc.hpp>
    #include <streams_boost/mpl/aux_/has_type.hpp>
    #include <streams_boost/mpl/aux_/template_arity.hpp>
    #include <streams_boost/mpl/aux_/lambda_arity_param.hpp>
    #include <streams_boost/utility/result_of.hpp>
    #include <streams_boost/type_traits/remove_const.hpp>
    #include <streams_boost/type_traits/remove_reference.hpp>
    #include <streams_boost/proto/proto_fwd.hpp>
    #include <streams_boost/proto/traits.hpp>
    #include <streams_boost/proto/args.hpp>
    #include <streams_boost/proto/transform/impl.hpp>
    #include <streams_boost/proto/detail/as_lvalue.hpp>
    #include <streams_boost/proto/detail/ignore_unused.hpp>

    namespace streams_boost { namespace proto
    {
        namespace detail
        {
            template<STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(STREAMS_BOOST_PROTO_MAX_ARITY, typename A, void)>
            struct typelist
            {
                typedef void type;
            };

            template<typename T, bool HasType = mpl::aux::has_type<T>::value>
            struct nested_type
            {
                typedef typename T::type type;
            };

            template<typename T>
            struct nested_type<T, false>
            {
                typedef T type;
            };

            template<typename T, typename Args, typename Void = void>
            struct nested_type_if
              : nested_type<T>
            {};

            template<typename R, typename Expr, typename State, typename Data
                // BUGBUG this should be is_transform, but if R is a template instantiation
                // it will cause the template to be instantiated, whereas is_callable will not.
              , bool IsTransform = is_callable<R>::value
            >
            struct make_if_;

            template<typename R, typename Expr, typename State, typename Data
                STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(long Arity = mpl::aux::template_arity<R>::value)
            >
            struct make_
            {
                typedef R type;
                typedef void not_applied_;
            };

            template<typename R, typename Expr, typename State, typename Data>
            struct make_if_<R, Expr, State, Data, false>
              : make_<R, Expr, State, Data>
            {};

            #if STREAMS_BOOST_WORKAROUND(__GNUC__, == 3) || (__GNUC__ == 4 && __GNUC_MINOR__ == 0)
            // work around GCC bug
            template<typename Tag, typename Args, long N, typename Expr, typename State, typename Data>
            struct make_if_<proto::expr<Tag, Args, N>, Expr, State, Data, false>
            {
                typedef proto::expr<Tag, Args, N> type;
                typedef void not_applied_;
            };
            #endif

            // TODO could optimize this if R is a transform
            template<typename R, typename Expr, typename State, typename Data>
            struct make_if_<R, Expr, State, Data, true>
              : remove_const<
                    typename remove_reference<
                        typename R::template impl<Expr, State, Data>::result_type
                    >::type
                >
            {};

            template<typename Type, bool IsAggregate = is_aggregate<Type>::value>
            struct construct_
            {
                typedef Type result_type;

                Type operator ()() const
                {
                    return Type();
                }

                #define TMP(Z, N, DATA)                                                             \
                template<STREAMS_BOOST_PP_ENUM_PARAMS_Z(Z, N, typename A)>                                  \
                Type operator ()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(Z, N, A, &a)) const                  \
                {                                                                                   \
                    return Type(STREAMS_BOOST_PP_ENUM_PARAMS_Z(Z, N, a));                                   \
                }
                STREAMS_BOOST_PP_REPEAT_FROM_TO(1, STREAMS_BOOST_PP_INC(STREAMS_BOOST_PROTO_MAX_ARITY), TMP, ~)
                #undef TMP
            };

            template<typename Type>
            struct construct_<Type, true>
            {
                typedef Type result_type;

                Type operator ()() const
                {
                    return Type();
                }

                #define TMP(Z, N, DATA)                                                             \
                template<STREAMS_BOOST_PP_ENUM_PARAMS_Z(Z, N, typename A)>                                  \
                Type operator ()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(Z, N, A, &a)) const                  \
                {                                                                                   \
                    Type that = {STREAMS_BOOST_PP_ENUM_PARAMS_Z(Z, N, a)};                                  \
                    return that;                                                                    \
                }
                STREAMS_BOOST_PP_REPEAT_FROM_TO(1, STREAMS_BOOST_PP_INC(STREAMS_BOOST_PROTO_MAX_ARITY), TMP, ~)
                #undef TMP
            };

            #define TMP(Z, N, DATA)                                                                 \
            template<typename Type STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(Z, N, typename A)>               \
            Type construct(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(Z, N, A, &a))                              \
            {                                                                                       \
                return construct_<Type>()(STREAMS_BOOST_PP_ENUM_PARAMS_Z(Z, N, a));                         \
            }
            STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_PROTO_MAX_ARITY, TMP, ~)
            #undef TMP
        }

        /// \brief A PrimitiveTransform which prevents another PrimitiveTransform
        /// from being applied in an \c ObjectTransform.
        ///
        /// When building higher order transforms with <tt>make\<\></tt> or
        /// <tt>lazy\<\></tt>, you sometimes would like to build types that
        /// are parameterized with Proto transforms. In such lambda-style
        /// transforms, Proto will unhelpfully find all nested transforms
        /// and apply them, even if you don't want them to be applied. Consider
        /// the following transform, which will replace the \c _ in
        /// <tt>Bar<_>()</tt> with <tt>proto::terminal\<int\>::type</tt>:
        ///
        /// \code
        /// template<typename T>
        /// struct Bar
        /// {};
        /// 
        /// struct Foo
        ///   : proto::when<_, Bar<_>() >
        /// {};
        /// 
        /// proto::terminal<int>::type i = {0};
        /// 
        /// int main()
        /// {
        ///     Foo()(i);
        ///     std::cout << typeid(Foo()(i)).name() << std::endl;
        /// }
        /// \endcode
        ///
        /// If you actually wanted to default-construct an object of type
        /// <tt>Bar\<_\></tt>, you would have to protect the \c _ to prevent
        /// it from being applied. You can use <tt>proto::protect\<\></tt>
        /// as follows:
        ///
        /// \code
        /// // OK: replace anything with Bar<_>()
        /// struct Foo
        ///   : proto::when<_, Bar<protect<_> >() >
        /// {};
        /// \endcode
        template<typename PrimitiveTransform>
        struct protect : transform<protect<PrimitiveTransform> >
        {
            template<typename, typename, typename>
            struct impl
            {
                typedef PrimitiveTransform result_type;
            };
        };

        /// \brief A PrimitiveTransform which computes a type by evaluating any
        /// nested transforms and then constructs an object of that type.
        ///
        /// The <tt>make\<\></tt> transform checks to see if \c Object is a template.
        /// If it is, the template type is disassembled to find nested transforms.
        /// Proto considers the following types to represent transforms:
        ///
        /// \li Function types
        /// \li Function pointer types
        /// \li Types for which <tt>proto::is_callable\< type \>::::value</tt> is \c true
        ///
        /// <tt>streams_boost::result_of\<make\<T\<X0,X1,...\> \>(Expr, State, Data)\>::::type</tt>
        /// is evaluated as follows. For each \c X in <tt>X0,X1,...</tt>, do:
        ///
        /// \li If \c X is a template like <tt>U\<Y0,Y1,...\></tt>, then let <tt>X'</tt>
        ///     be <tt>streams_boost::result_of\<make\<U\<Y0,Y1,...\> \>(Expr, State, Data)\>::::type</tt>
        ///     (which evaluates this procedure recursively). Note whether any
        ///     substitutions took place during this operation.
        /// \li Otherwise, if \c X is a transform, then let <tt>X'</tt> be
        ///     <tt>streams_boost::result_of\<when\<_, X\>(Expr, State, Data)\>::::type</tt>.
        ///     Note that a substitution took place.
        /// \li Otherwise, let <tt>X'</tt> be \c X, and note that no substitution
        ///     took place.
        /// \li If any substitutions took place in any of the above steps and
        ///     <tt>T\<X0',X1',...\></tt> has a nested <tt>::type</tt> typedef,
        ///     the result type is <tt>T\<X0',X1',...\>::::type</tt>.
        /// \li Otherwise, the result type is <tt>T\<X0',X1',...\></tt>.
        ///
        /// Note that <tt>when\<\></tt> is implemented in terms of <tt>call\<\></tt>
        /// and <tt>make\<\></tt>, so the above procedure is evaluated recursively.
        template<typename Object>
        struct make : transform<make<Object> >
        {
            template<typename Expr, typename State, typename Data>
            struct impl : transform_impl<Expr, State, Data>
            {
                typedef typename detail::make_if_<Object, Expr, State, Data>::type result_type;

                /// \return <tt>result_type()</tt>
                result_type operator ()(
                    typename impl::expr_param
                  , typename impl::state_param
                  , typename impl::data_param
                ) const
                {
                    return result_type();
                }
            };
        };

        #define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (3, (0, STREAMS_BOOST_PROTO_MAX_ARITY, <streams_boost/proto/transform/make.hpp>))
        #include STREAMS_BOOST_PP_ITERATE()

        /// INTERNAL ONLY
        ///
        template<typename Object>
        struct is_callable<make<Object> >
          : mpl::true_
        {};

        /// INTERNAL ONLY
        ///
        template<typename PrimitiveTransform>
        struct is_callable<protect<PrimitiveTransform> >
          : mpl::true_
        {};
    }}

    #endif

#else

    #define N STREAMS_BOOST_PP_ITERATION()

        namespace detail
        {
            #if N > 0
            template<typename T STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
            struct nested_type_if<
                T
              , typelist<STREAMS_BOOST_PP_ENUM_PARAMS(N, A)>
              , typename typelist<
                    STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, typename A, ::not_applied_ STREAMS_BOOST_PP_INTERCEPT)
                >::type
            >
            {
                typedef T type;
                typedef void not_applied_;
            };

            #define TMP0(Z, M, DATA) make_if_<STREAMS_BOOST_PP_CAT(A, M), Expr, State, Data>
            #define TMP1(Z, M, DATA) typename TMP0(Z, M, DATA) ::type

            template<
                template<STREAMS_BOOST_PP_ENUM_PARAMS(N, typename STREAMS_BOOST_PP_INTERCEPT)> class R
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)
              , typename Expr, typename State, typename Data
            >
            struct make_<R<STREAMS_BOOST_PP_ENUM_PARAMS(N, A)>, Expr, State, Data
                STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(N)
            >
              : nested_type_if<
                    R<STREAMS_BOOST_PP_ENUM(N, TMP1, ~)>
                  , typelist<STREAMS_BOOST_PP_ENUM(N, TMP0, ~) >
                >
            {};

            template<
                template<STREAMS_BOOST_PP_ENUM_PARAMS(N, typename STREAMS_BOOST_PP_INTERCEPT)> class R
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)
              , typename Expr, typename State, typename Data
            >
            struct make_<noinvoke<R<STREAMS_BOOST_PP_ENUM_PARAMS(N, A)> >, Expr, State, Data
                STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(N)
            >
            {
                typedef R<STREAMS_BOOST_PP_ENUM(N, TMP1, ~)> type;
            };

            #undef TMP0
            #undef TMP1
            #endif

            template<
                typename R
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)
              , typename Expr, typename State, typename Data
            >
            struct make_if_<R(STREAMS_BOOST_PP_ENUM_PARAMS(N, A)), Expr, State, Data, false>
            {
                typedef
                    typename remove_const<
                        typename remove_reference<
                            typename when<_, R(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))>
                                ::template impl<Expr, State, Data>::result_type
                        >::type
                    >::type
                type;
            };

            template<
                typename R
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)
              , typename Expr, typename State, typename Data
            >
            struct make_if_<R(*)(STREAMS_BOOST_PP_ENUM_PARAMS(N, A)), Expr, State, Data, false>
            {
                typedef
                    typename remove_const<
                        typename remove_reference<
                            typename when<_, R(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))>
                                ::template impl<Expr, State, Data>::result_type
                        >::type
                    >::type
                type;
            };

            template<typename T, typename A>
            struct construct_<proto::expr<T, A, N>, true>
            {
                typedef proto::expr<T, A, N> result_type;

                template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_MAX(N, 1), typename A)>
                result_type operator ()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(STREAMS_BOOST_PP_MAX(N, 1), A, &a)) const
                {
                    return result_type::make(STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_MAX(N, 1), a));
                }
            };
        }

        /// \brief A PrimitiveTransform which computes a type by evaluating any
        /// nested transforms and then constructs an object of that type with the
        /// current expression, state and data, transformed according
        /// to \c A0 through \c AN.
        template<typename Object STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        struct make<Object(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))>
          : transform<make<Object(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))> >
        {
            template<typename Expr, typename State, typename Data>
            struct impl : transform_impl<Expr, State, Data>
            {
                /// \brief <tt>streams_boost::result_of\<make\<Object\>(Expr, State, Data)\>::::type</tt>
                typedef typename detail::make_if_<Object, Expr, State, Data>::type result_type;
                //typedef typename detail::make_<Object, Expr, State, Data>::type result_type;

                /// Let \c ax be <tt>when\<_, Ax\>()(e, s, d)</tt>
                /// for each \c x in <tt>[0,N]</tt>.
                /// Return <tt>result_type(a0, a1,... aN)</tt>.
                ///
                /// \param e The current expression
                /// \param s The current state
                /// \param d An arbitrary data
                result_type operator ()(
                    typename impl::expr_param   e
                  , typename impl::state_param  s
                  , typename impl::data_param   d
                ) const
                {
                    proto::detail::ignore_unused(e);
                    proto::detail::ignore_unused(s);
                    proto::detail::ignore_unused(d);
                    return detail::construct<result_type>(
                        #define TMP(Z, M, DATA)                                                     \
                            detail::as_lvalue(                                                      \
                                typename when<_, STREAMS_BOOST_PP_CAT(A, M)>                                \
                                    ::template impl<Expr, State, Data>()(e, s, d)         \
                            )
                        STREAMS_BOOST_PP_ENUM(N, TMP, DATA)
                        #undef TMP
                    );
                }
            };
        };

        #if STREAMS_BOOST_WORKAROUND(__GNUC__, == 3) || (__GNUC__ == 4 && __GNUC_MINOR__ == 0)
        // work around GCC bug
        template<typename Tag, typename Args, long Arity STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        struct make<proto::expr<Tag, Args, Arity>(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))>
          : transform<make<proto::expr<Tag, Args, Arity>(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))> >
        {
            template<typename Expr, typename State, typename Data>
            struct impl : transform_impl<Expr, State, Data>
            {
                typedef proto::expr<Tag, Args, Arity> result_type;

                result_type operator ()(
                    typename impl::expr_param   e
                  , typename impl::state_param  s
                  , typename impl::data_param   d
                ) const
                {
                    return proto::expr<Tag, Args, Arity>::make(
                        #define TMP(Z, M, DATA)                                                     \
                            detail::as_lvalue(                                                      \
                                typename when<_, STREAMS_BOOST_PP_CAT(A, M)>                                \
                                    ::template impl<Expr, State, Data>()(e, s, d)         \
                            )
                        STREAMS_BOOST_PP_ENUM(N, TMP, DATA)
                        #undef TMP
                    );
                }
            };
        };
        #endif

    #undef N

#endif
