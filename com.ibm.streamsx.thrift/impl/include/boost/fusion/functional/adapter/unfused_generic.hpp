/*=============================================================================
    Copyright (c) 2006-2007 Tobias Schwinger
  
    Use modification and distribution are subject to the Boost Software 
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.streams_boost.org/LICENSE_1_0.txt).
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_FUNCTIONAL_ADAPTER_UNFUSED_GENERIC_HPP_INCLUDED)
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/iteration/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/facilities/intercept.hpp>

#include <streams_boost/fusion/container/vector/vector.hpp>

#include <streams_boost/fusion/functional/adapter/limits.hpp>
#include <streams_boost/fusion/functional/adapter/detail/access.hpp>

#include <streams_boost/utility/result_of.hpp>

namespace streams_boost { namespace fusion
{
    template <class Function> class unfused_generic;

    //----- ---- --- -- - -  -   -

    template <class Function> 
    class unfused_generic
    {
        Function fnc_transformed;

        typedef typename detail::qf_c<Function>::type function_c;
        typedef typename detail::qf<Function>::type function;

        typedef typename detail::call_param<Function>::type func_const_fwd_t;

      public:

        inline explicit unfused_generic(func_const_fwd_t f = Function())
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
            function (fusion::vector0 &) >::type call_0_result;

        inline call_0_result operator()() 
        {
            fusion::vector0 arg;
            return this->fnc_transformed(arg);
        }

        #define STREAMS_BOOST_FUSION_CODE(tpl_params,arg_types,params,args)             \
        template <tpl_params>                                                  \
        inline typename streams_boost::result_of<function_c(                           \
            STREAMS_BOOST_PP_CAT(fusion::vector,N)<arg_types> & )>::type               \
        operator()(params) const                                               \
        {                                                                      \
            STREAMS_BOOST_PP_CAT(fusion::vector,N)<arg_types> arg(args);               \
            return this->fnc_transformed(arg);                                 \
        }                                                                      \
        template <tpl_params>                                                  \
        inline typename streams_boost::result_of<function(                             \
            STREAMS_BOOST_PP_CAT(fusion::vector,N)<arg_types> & )>::type               \
        operator()(params)                                                     \
        {                                                                      \
            STREAMS_BOOST_PP_CAT(fusion::vector,N)<arg_types> arg(args);               \
            return this->fnc_transformed(arg);                                 \
        }

        #define  STREAMS_BOOST_PP_INDIRECT_SELF                                        \
            <streams_boost/fusion/functional/adapter/unfused_generic.hpp>
        #define  STREAMS_BOOST_PP_FILENAME_1                                           \
            <streams_boost/fusion/functional/adapter/detail/pow2_explode.hpp>
        #define  STREAMS_BOOST_PP_ITERATION_LIMITS                                     \
            (1,STREAMS_BOOST_FUSION_UNFUSED_GENERIC_MAX_ARITY)
        #define  N STREAMS_BOOST_PP_ITERATION_1
        #include STREAMS_BOOST_PP_ITERATE()
        #undef   N

        #undef STREAMS_BOOST_FUSION_CODE
    };
}}

namespace streams_boost 
{
    template<class F>
    struct result_of<streams_boost::fusion::unfused_generic<F> const ()>
    {
        typedef typename streams_boost::fusion::unfused_generic<F>::call_const_0_result type;
    };
    template<class F>
    struct result_of<streams_boost::fusion::unfused_generic<F>()>
    {
        typedef typename streams_boost::fusion::unfused_generic<F>::call_0_result type;
    };
}

#define STREAMS_BOOST_FUSION_FUNCTIONAL_ADAPTER_UNFUSED_GENERIC_HPP_INCLUDED
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)
///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////

#include <streams_boost/fusion/functional/adapter/detail/pt_def.hpp>

#if STREAMS_BOOST_PP_SLOT_1() == 0 
        template <class Self, STREAMS_BOOST_PP_ENUM_PARAMS(N,typename T)>
        struct result
            < Self const (STREAMS_BOOST_PP_ENUM_PARAMS(N,T)) >
            : streams_boost::result_of<function_c(
                STREAMS_BOOST_PP_CAT(fusion::vector,N)< STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,
                   typename detail::gref<T,>::type STREAMS_BOOST_PP_INTERCEPT) > & )>
        { };

        template <class Self, STREAMS_BOOST_PP_ENUM_PARAMS(N,typename T)>
        struct result
            < Self(STREAMS_BOOST_PP_ENUM_PARAMS(N,T)) >
            : streams_boost::result_of<function(
                STREAMS_BOOST_PP_CAT(fusion::vector,N)< STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,
                   typename detail::gref<T,>::type STREAMS_BOOST_PP_INTERCEPT) > & )>
        { };
#endif

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,STREAMS_BOOST_TESTED_AT(1400)) 
        template <STREAMS_BOOST_PP_ENUM_PARAMS(N,typename T)>
        inline typename streams_boost::result_of<function_c(
            STREAMS_BOOST_PP_CAT(fusion::vector,N)<STREAMS_BOOST_PP_ENUM_PARAMS(N,PT)> & )>::type
        operator()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,PT,a)) const
        {
            STREAMS_BOOST_PP_CAT(fusion::vector,N)<STREAMS_BOOST_PP_ENUM_PARAMS(N,PT)>
                arg(STREAMS_BOOST_PP_ENUM_PARAMS(N,a));
            return this->fnc_transformed(arg);
        }
        template <STREAMS_BOOST_PP_ENUM_PARAMS(N,typename T)>
        inline typename streams_boost::result_of<function(
            STREAMS_BOOST_PP_CAT(fusion::vector,N)<STREAMS_BOOST_PP_ENUM_PARAMS(N,PT)> & )>::type
        operator()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,PT,a))
        {
            STREAMS_BOOST_PP_CAT(fusion::vector,N)<STREAMS_BOOST_PP_ENUM_PARAMS(N,PT)>
                arg(STREAMS_BOOST_PP_ENUM_PARAMS(N,a));
            return this->fnc_transformed(arg);
        }
#else
        STREAMS_BOOST_FUSION_CODE(STREAMS_BOOST_PP_ENUM_PARAMS(N,typename T),
            STREAMS_BOOST_PP_ENUM_PARAMS(N,PT), STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,PT,a),
            STREAMS_BOOST_PP_ENUM_PARAMS(N,a) )
        // ...generates uglier code but is faster - it caches ENUM_*
#endif

#include <streams_boost/fusion/functional/adapter/detail/pt_undef.hpp>

#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)
#endif

