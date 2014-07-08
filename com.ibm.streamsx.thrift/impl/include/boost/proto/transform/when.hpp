#ifndef STREAMS_BOOST_PP_IS_ITERATING
    ///////////////////////////////////////////////////////////////////////////////
    /// \file when.hpp
    /// Definition of when transform.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

    #ifndef STREAMS_BOOST_PROTO_TRANSFORM_WHEN_HPP_EAN_10_29_2007
    #define STREAMS_BOOST_PROTO_TRANSFORM_WHEN_HPP_EAN_10_29_2007

    #include <streams_boost/preprocessor/cat.hpp>
    #include <streams_boost/preprocessor/repetition/enum_params.hpp>
    #include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>
    #include <streams_boost/preprocessor/iteration/iterate.hpp>
    #include <streams_boost/mpl/if.hpp>
    #include <streams_boost/proto/proto_fwd.hpp>
    #include <streams_boost/proto/traits.hpp>
    #include <streams_boost/proto/transform/call.hpp>
    #include <streams_boost/proto/transform/make.hpp>
    #include <streams_boost/proto/transform/impl.hpp>

    namespace streams_boost { namespace proto
    {
        /// \brief A grammar element and a PrimitiveTransform that associates
        /// a transform with the grammar.
        ///
        /// Use <tt>when\<\></tt> to override a grammar's default transform
        /// with a custom transform. It is for used when composing larger
        /// transforms by associating smaller transforms with individual
        /// rules in your grammar, as in the following transform which
        /// counts the number of terminals in an expression.
        ///
        /// \code
        /// // Count the terminals in an expression tree.
        /// // Must be invoked with initial state == mpl::int_<0>().
        /// struct CountLeaves
        ///   : or_<
        ///         when<terminal<_>, mpl::next<_state>()>
        ///       , otherwise<fold<_, _state, CountLeaves> >
        ///     >
        /// {};
        /// \endcode
        ///
        /// In <tt>when\<G, T\></tt>, when \c T is a class type it is a
        /// PrimitiveTransform and the following equivalencies hold:
        ///
        /// <tt>streams_boost::result_of\<when\<G,T\>(E,S,V)\>::::type</tt> is the same as
        /// <tt>streams_boost::result_of\<T(E,S,V)\>::::type</tt>.
        ///
        /// <tt>when\<G,T\>()(e,s,d)</tt> is the same as
        /// <tt>T()(e,s,d)</tt>.
        template<typename Grammar, typename PrimitiveTransform /*= Grammar*/>
        struct when
          : PrimitiveTransform
        {
            typedef typename Grammar::proto_base_expr proto_base_expr;
        };

        /// \brief A specialization that treats function pointer Transforms as
        /// if they were function type Transforms.
        ///
        /// This specialization requires that \c Fun is actually a function type.
        ///
        /// This specialization is required for nested transforms such as
        /// <tt>when\<G, T0(T1(_))\></tt>. In C++, functions that are used as
        /// parameters to other functions automatically decay to funtion
        /// pointer types. In other words, the type <tt>T0(T1(_))</tt> is
        /// indistinguishable from <tt>T0(T1(*)(_))</tt>. This specialization
        /// is required to handle these nested function pointer type transforms
        /// properly.
        template<typename Grammar, typename Fun>
        struct when<Grammar, Fun *>
          : when<Grammar, Fun>
        {};

        /// \brief Syntactic sugar for <tt>when\<_, Fun\></tt>, for use
        /// in grammars to handle all the cases not yet handled.
        ///
        /// Use <tt>otherwise\<T\></tt> in your grammars as a synonym for
        /// <tt>when\<_, T\></tt> as in the following transform which
        /// counts the number of terminals in an expression.
        ///
        /// \code
        /// // Count the terminals in an expression tree.
        /// // Must be invoked with initial state == mpl::int_<0>().
        /// struct CountLeaves
        ///   : or_<
        ///         when<terminal<_>, mpl::next<_state>()>
        ///       , otherwise<fold<_, _state, CountLeaves> >
        ///     >
        /// {};
        /// \endcode
        template<typename Fun>
        struct otherwise
          : when<_, Fun>
        {};

        #define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (3, (0, STREAMS_BOOST_PROTO_MAX_ARITY, <streams_boost/proto/transform/when.hpp>))
        #include STREAMS_BOOST_PP_ITERATE()

    }} // namespace streams_boost::proto

    #endif

#else

    #define N STREAMS_BOOST_PP_ITERATION()

        /// \brief A grammar element and a PrimitiveTransform that associates
        /// a transform with the grammar.
        ///
        /// Use <tt>when\<\></tt> to override a grammar's default transform
        /// with a custom transform. It is for used when composing larger
        /// transforms by associating smaller transforms with individual
        /// rules in your grammar, as in the following transform which
        /// counts the number of terminals in an expression.
        ///
        /// \code
        /// // Count the terminals in an expression tree.
        /// // Must be invoked with initial state == mpl::int_<0>().
        /// struct CountLeaves
        ///   : or_<
        ///         when<terminal<_>, mpl::next<_state>()>
        ///       , otherwise<fold<_, _state, CountLeaves> >
        ///     >
        /// {};
        /// \endcode
        ///
        /// The <tt>when\<G, R(A0,A1,...)\></tt> form accepts either a
        /// CallableTransform or an ObjectTransform as its second parameter.
        /// <tt>when\<\></tt> uses <tt>is_callable\<R\>::::value</tt> to
        /// distinguish between the two, and uses <tt>call\<\></tt> to
        /// evaluate CallableTransforms and <tt>make\<\></tt> to evaluate
        /// ObjectTransforms.
        template<typename Grammar, typename R STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        struct when<Grammar, R(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))>
          : transform<when<Grammar, R(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))> >
        {
            typedef typename Grammar::proto_base_expr proto_base_expr;

            // Note: do not evaluate is_callable<R> in this scope.
            // R may be an incomplete type at this point.

            template<typename Expr, typename State, typename Data>
            struct impl : transform_impl<Expr, State, Data>
            {
                // OK to evaluate is_callable<R> here. R should be compete by now.
                typedef
                    typename mpl::if_c<
                        is_callable<R>::value
                      , call<R(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))> // "R" is a function to call
                      , make<R(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))> // "R" is an object to construct
                    >::type
                which;

                typedef typename which::template impl<Expr, State, Data>::result_type result_type;

                /// Evaluate <tt>R(A0,A1,...)</tt> as a transform either with
                /// <tt>call\<\></tt> or with <tt>make\<\></tt> depending on
                /// whether <tt>is_callable\<R\>::::value</tt> is \c true or
                /// \c false.
                ///
                /// \param e The current expression
                /// \param s The current state
                /// \param d An arbitrary data
                /// \pre <tt>matches\<Expr, Grammar\>::::value</tt> is \c true
                /// \return <tt>which()(e, s, d)</tt>
                result_type operator ()(
                    typename impl::expr_param   e
                  , typename impl::state_param  s
                  , typename impl::data_param   d
                ) const
                {
                    return typename which::template impl<Expr, State, Data>()(e, s, d);
                }
            };
        };

    #undef N

#endif