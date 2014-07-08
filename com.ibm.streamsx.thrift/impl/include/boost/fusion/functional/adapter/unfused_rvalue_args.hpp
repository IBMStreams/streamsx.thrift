/*=============================================================================
    Copyright (c) 2006-2007 Tobias Schwinger
  
    Use modification and distribution are subject to the Boost Software 
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.streams_boost.org/LICENSE_1_0.txt).
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_FUNCTIONAL_ADAPTER_UNFUSED_RVALUE_ARGS_HPP_INCLUDED)
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/iteration/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/facilities/intercept.hpp>

#include <streams_boost/utility/result_of.hpp>

#include <streams_boost/fusion/container/vector/vector.hpp>

#include <streams_boost/fusion/functional/adapter/limits.hpp>
#include <streams_boost/fusion/functional/adapter/detail/access.hpp>

namespace streams_boost { namespace fusion
{
    template <class Function> class unfused_rvalue_args;

    //----- ---- --- -- - -  -   -

    template <class Function> class unfused_rvalue_args
    {
        Function fnc_transformed;

        typedef typename detail::qf_c<Function>::type function_c;
        typedef typename detail::qf<Function>::type function;

        typedef typename detail::call_param<Function>::type func_const_fwd_t;

      public:

        inline explicit unfused_rvalue_args(func_const_fwd_t f = function())
            : fnc_transformed(f)
        { }

        template <typename Sig>
        struct result;

        typedef typename streams_boost::result_of<
            function_c(fusion::vector0 &) >::type call_const_0_result;

        inline call_const_0_result operator()() const
        {
            fusion::vector0 arg;
            return this->fnc_transformed(arg);
        }

        typedef typename streams_boost::result_of< 
            function(fusion::vector0 &) >::type call_0_result;

        inline call_0_result operator()() 
        {
            fusion::vector0 arg;
            return this->fnc_transformed(arg);
        }

        #define  STREAMS_BOOST_PP_FILENAME_1 \
            <streams_boost/fusion/functional/adapter/unfused_rvalue_args.hpp>
        #define  STREAMS_BOOST_PP_ITERATION_LIMITS \
            (1,STREAMS_BOOST_FUSION_UNFUSED_RVALUE_ARGS_MAX_ARITY)
        #include STREAMS_BOOST_PP_ITERATE()
    };
}}

namespace streams_boost 
{
    template<class F>
    struct result_of<streams_boost::fusion::unfused_rvalue_args<F> const ()>
    {
        typedef typename streams_boost::fusion::unfused_rvalue_args<F>::call_const_0_result type;
    };
    template<class F>
    struct result_of<streams_boost::fusion::unfused_rvalue_args<F>()>
    {
        typedef typename streams_boost::fusion::unfused_rvalue_args<F>::call_0_result type;
    };
}

#define STREAMS_BOOST_FUSION_FUNCTIONAL_ADAPTER_UNFUSED_RVALUE_ARGS_HPP_INCLUDED
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)
////////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
////////////////////////////////////////////////////////////////////////////////
#define N STREAMS_BOOST_PP_ITERATION()

        template <class Self, STREAMS_BOOST_PP_ENUM_PARAMS(N,typename T)>
        struct result< Self const (STREAMS_BOOST_PP_ENUM_PARAMS(N,T)) >
            : streams_boost::result_of< function_c(
                STREAMS_BOOST_PP_CAT(fusion::vector,N)< STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,
                    typename detail::cref<T,>::type STREAMS_BOOST_PP_INTERCEPT) > & )>
        { };

        template <class Self, STREAMS_BOOST_PP_ENUM_PARAMS(N,typename T)>
        struct result< Self (STREAMS_BOOST_PP_ENUM_PARAMS(N,T)) >
            : streams_boost::result_of< function(
                STREAMS_BOOST_PP_CAT(fusion::vector,N)< STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,
                    typename detail::cref<T,>::type STREAMS_BOOST_PP_INTERCEPT) > & )>
        { };

        template <STREAMS_BOOST_PP_ENUM_PARAMS(N,typename T)>
        inline typename streams_boost::result_of<function_c(STREAMS_BOOST_PP_CAT(fusion::vector,N)
            <STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,T,const& STREAMS_BOOST_PP_INTERCEPT)> & )>::type
        operator()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,T,const& a)) const
        {
            STREAMS_BOOST_PP_CAT(fusion::vector,N)<
                  STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,T,const& STREAMS_BOOST_PP_INTERCEPT) >
                arg(STREAMS_BOOST_PP_ENUM_PARAMS(N,a));
            return this->fnc_transformed(arg);
        }

        template <STREAMS_BOOST_PP_ENUM_PARAMS(N,typename T)>
        inline typename streams_boost::result_of<function(STREAMS_BOOST_PP_CAT(fusion::vector,N)
            <STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,T,const& STREAMS_BOOST_PP_INTERCEPT)> & )>::type
        operator()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,T,const& a)) 
        {
            STREAMS_BOOST_PP_CAT(fusion::vector,N)<
                  STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,T,const& STREAMS_BOOST_PP_INTERCEPT) >
                arg(STREAMS_BOOST_PP_ENUM_PARAMS(N,a));
            return this->fnc_transformed(arg);
        }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)
#endif

