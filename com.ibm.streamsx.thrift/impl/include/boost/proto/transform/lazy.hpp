#ifndef STREAMS_BOOST_PP_IS_ITERATING
    ///////////////////////////////////////////////////////////////////////////////
    /// \file lazy.hpp
    /// Contains definition of the lazy<> transform.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

    #ifndef STREAMS_BOOST_PROTO_TRANSFORM_LAZY_HPP_EAN_12_02_2007
    #define STREAMS_BOOST_PROTO_TRANSFORM_LAZY_HPP_EAN_12_02_2007

    #include <streams_boost/preprocessor/iteration/iterate.hpp>
    #include <streams_boost/preprocessor/repetition/enum_params.hpp>
    #include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>
    #include <streams_boost/proto/proto_fwd.hpp>
    #include <streams_boost/proto/transform/make.hpp>
    #include <streams_boost/proto/transform/call.hpp>
    #include <streams_boost/proto/transform/impl.hpp>

    namespace streams_boost { namespace proto
    {
        /// \brief A PrimitiveTransform that uses <tt>make\<\></tt> to build
        /// a CallableTransform, and then uses <tt>call\<\></tt> to apply it.
        ///
        /// <tt>lazy\<\></tt> is useful as a higher-order transform, when the
        /// transform to be applied depends on the current state of the
        /// transformation. The invocation of the <tt>make\<\></tt> transform
        /// evaluates any nested transforms, and the resulting type is treated
        /// as a CallableTransform, which is evaluated with <tt>call\<\></tt>.
        template<typename Object>
        struct lazy : transform<lazy<Object> >
        {
            template<typename Expr, typename State, typename Data>
            struct impl
              : call<
                    typename make<Object>::template impl<Expr, State, Data>::result_type
                >::template impl<Expr, State, Data>
            {};
        };

    #define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (3, (0, STREAMS_BOOST_PROTO_MAX_ARITY, <streams_boost/proto/transform/lazy.hpp>))
    #include STREAMS_BOOST_PP_ITERATE()

        /// INTERNAL ONLY
        ///
        template<typename Object>
        struct is_callable<lazy<Object> >
          : mpl::true_
        {};

    }}

    #endif

#else

    #define N STREAMS_BOOST_PP_ITERATION()

        /// \brief A PrimitiveTransform that uses <tt>make\<\></tt> to build
        /// a CallableTransform, and then uses <tt>call\<\></tt> to apply it.
        ///
        /// <tt>lazy\<\></tt> is useful as a higher-order transform, when the
        /// transform to be applied depends on the current state of the
        /// transformation. The invocation of the <tt>make\<\></tt> transform
        /// evaluates any nested transforms, and the resulting type is treated
        /// as a CallableTransform, which is evaluated with <tt>call\<\></tt>.
        template<typename Object STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        struct lazy<Object(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))>
          : transform<lazy<Object(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))> >
        {
            template<typename Expr, typename State, typename Data>
            struct impl
              : call<
                    typename make<Object>::template impl<Expr, State, Data>::result_type
                    (STREAMS_BOOST_PP_ENUM_PARAMS(N, A))
                >::template impl<Expr, State, Data>
            {};
        };

    #undef N

#endif
