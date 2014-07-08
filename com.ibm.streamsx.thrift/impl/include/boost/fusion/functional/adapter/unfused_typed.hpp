/*=============================================================================
    Copyright (c) 2006-2007 Tobias Schwinger
  
    Use modification and distribution are subject to the Boost Software 
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.streams_boost.org/LICENSE_1_0.txt).
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_FUNCTIONAL_ADAPTER_UNFUSED_TYPED_HPP_INCLUDED)
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/iteration/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>

#include <streams_boost/config.hpp>

#include <streams_boost/utility/result_of.hpp>

#include <streams_boost/fusion/support/detail/access.hpp>
#include <streams_boost/fusion/sequence/intrinsic/value_at.hpp>
#include <streams_boost/fusion/sequence/intrinsic/size.hpp>
#include <streams_boost/fusion/container/vector/vector.hpp>
#include <streams_boost/fusion/container/vector/convert.hpp>

#include <streams_boost/fusion/functional/adapter/limits.hpp>
#include <streams_boost/fusion/functional/adapter/detail/access.hpp>


namespace streams_boost { namespace fusion
{

    template <class Function, class Sequence> class unfused_typed;

    //----- ---- --- -- - -  -   -

    namespace detail
    {
        template <class Derived, class Function, 
            class Sequence, long Arity>
        struct unfused_typed_impl;
    }

    template <class Function, class Sequence>
    class unfused_typed
        : public detail::unfused_typed_impl
          < unfused_typed<Function,Sequence>, Function, Sequence, 
            result_of::size<Sequence>::value > 
    {
        Function fnc_transformed;

        template <class D, class F, class S, long A>
        friend struct detail::unfused_typed_impl;

        typedef typename detail::call_param<Function>::type func_const_fwd_t;

    public:

        inline explicit unfused_typed(func_const_fwd_t f = Function())
            : fnc_transformed(f)
        { }
    }; 

    #define  STREAMS_BOOST_PP_FILENAME_1 <streams_boost/fusion/functional/adapter/unfused_typed.hpp>
    #define  STREAMS_BOOST_PP_ITERATION_LIMITS (0,STREAMS_BOOST_FUSION_UNFUSED_TYPED_MAX_ARITY)
    #include STREAMS_BOOST_PP_ITERATE() 

}}

namespace streams_boost 
{
    template<class F, class Seq>
    struct result_of< streams_boost::fusion::unfused_typed<F,Seq> const () >
        : streams_boost::fusion::unfused_typed<F,Seq>::template result< 
            streams_boost::fusion::unfused_typed<F,Seq> const () >
    { };
    template<class F, class Seq>
    struct result_of< streams_boost::fusion::unfused_typed<F,Seq>() >
        : streams_boost::fusion::unfused_typed<F,Seq>::template result< 
            streams_boost::fusion::unfused_typed<F,Seq> () >
    { };
}


#define STREAMS_BOOST_FUSION_FUNCTIONAL_ADAPTER_UNFUSED_TYPED_HPP_INCLUDED
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)
///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#define N STREAMS_BOOST_PP_ITERATION()

    namespace detail
    {

        template <class Derived, class Function, class Sequence>
        struct unfused_typed_impl<Derived,Function,Sequence,N>
        {
            typedef typename detail::qf_c<Function>::type function_c;
            typedef typename detail::qf<Function>::type function;
            typedef typename result_of::as_vector<Sequence>::type arg_vector_t;

        public:

#define M(z,i,s)                                                                \
    typename call_param<typename result_of::value_at_c<s,i>::type>::type a##i

            inline typename streams_boost::result_of< 
                function_c(arg_vector_t &) >::type
            operator()(STREAMS_BOOST_PP_ENUM(N,M,arg_vector_t)) const
            {
#if N > 0
                arg_vector_t arg(STREAMS_BOOST_PP_ENUM_PARAMS(N,a));
#else
                arg_vector_t arg;
#endif
                return static_cast<Derived const *>(this)->fnc_transformed(arg);
            }

            inline typename streams_boost::result_of<
                function(arg_vector_t &) >::type 
            operator()(STREAMS_BOOST_PP_ENUM(N,M,arg_vector_t)) 
            {
#if N > 0
                arg_vector_t arg(STREAMS_BOOST_PP_ENUM_PARAMS(N,a));
#else
                arg_vector_t arg;
#endif
                return static_cast<Derived *>(this)->fnc_transformed(arg);
            }

#undef M

            template <typename Sig> struct result { typedef void type; };

            template <class Self STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N,typename T)>
            struct result< Self const (STREAMS_BOOST_PP_ENUM_PARAMS(N,T)) >
                : streams_boost::result_of< function_c(arg_vector_t &) > 
            { };

            template <class Self STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N,typename T)>
            struct result< Self (STREAMS_BOOST_PP_ENUM_PARAMS(N,T)) >
                : streams_boost::result_of< function(arg_vector_t &) >
            { };
        };

    } // namespace detail

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)
#endif

