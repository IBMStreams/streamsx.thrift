/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)
#if !defined(PHOENIX_BIND_DETAIL_FUNCTION_PTR_HPP)
#define PHOENIX_BIND_DETAIL_FUNCTION_PTR_HPP

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/dec.hpp>

namespace streams_boost { namespace phoenix { namespace detail
{
    template <int N>
    struct function_ptr_impl
    {
        template <typename RT, typename FP>
        struct impl;
    };

    template <int N, typename RT, typename FP>
    struct function_ptr : function_ptr_impl<N>::template impl<RT, FP>
    {
        typedef typename function_ptr_impl<N>::template impl<RT, FP> base;
        function_ptr(FP fp)
            : base(fp) {}
    };

    template <>
    struct function_ptr_impl<0>
    {
        template <typename RT, typename FP>
        struct impl
        {
            typedef RT result_type;

            impl(FP fp)
                : fp(fp) {}

            RT operator()() const
            {
                return fp();
            }

            FP fp;
        };
    };

#define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                             \
    (3, (1, PHOENIX_COMPOSITE_LIMIT,                                            \
    "streams_boost/spirit/home/phoenix/bind/detail/function_ptr.hpp"))
#include STREAMS_BOOST_PP_ITERATE()

}}} // namespace streams_boost::phoenix::detail

#endif

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)

#define N STREAMS_BOOST_PP_ITERATION()

    template <>
    struct function_ptr_impl<N>
    {
        template <typename RT, typename FP>
        struct impl
        {
            template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename T)>
            struct result
            {
                typedef RT type;
            };

            impl(FP fp)
                : fp(fp) {}

            template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
            RT operator()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, & _)) const
            {
                return fp(STREAMS_BOOST_PP_ENUM_PARAMS(N, _));
            }

            FP fp;
        };
    };

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)


