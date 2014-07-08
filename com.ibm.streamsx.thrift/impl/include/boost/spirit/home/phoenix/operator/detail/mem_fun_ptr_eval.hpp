/*=============================================================================
    Copyright (c) 2005-2007 Dan Marsden
    Copyright (c) 2005-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#ifndef PHOENIX_OPERATOR_DETAIL_MEM_FUN_PTR_EVAL_HPP
#define PHOENIX_OPERATOR_DETAIL_MEM_FUN_PTR_EVAL_HPP

#include <streams_boost/spirit/home/phoenix/core/limits.hpp>
#include <streams_boost/spirit/home/phoenix/core/actor.hpp>

#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/iteration/iterate.hpp>
#include <streams_boost/preprocessor/arithmetic/sub.hpp>
#include <streams_boost/preprocessor/arithmetic/dec.hpp>

#include <streams_boost/mpl/void.hpp>

#include <streams_boost/type_traits/function_traits.hpp>

#include <streams_boost/get_pointer.hpp>

#include <streams_boost/spirit/home/phoenix/operator/detail/mem_fun_ptr_return.hpp>

namespace streams_boost { namespace phoenix {

    struct mem_fun_ptr_eval
    {
        template<typename Env, typename PtrActor, typename MemFunPtrActor,
                 STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(STREAMS_BOOST_PP_SUB(PHOENIX_MEMBER_LIMIT, 2), typename Arg, mpl::void_)>

        struct result
            : detail::mem_fun_ptr_return<typename eval_result<MemFunPtrActor, Env>::type> { };

        template<typename Rt, typename Env, typename PtrActor, typename MemFunPtrActor>
        static typename result<Env,PtrActor,MemFunPtrActor>::type
        eval(const Env& env, PtrActor& ptrActor, MemFunPtrActor& memFunPtrActor)
        {
            return (get_pointer(ptrActor.eval(env))->*memFunPtrActor.eval(env))();
        }

#define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                                                                 \
        (3, (1, STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_DEC(PHOENIX_MEMBER_LIMIT)), "streams_boost/spirit/home/phoenix/operator/detail/mem_fun_ptr_eval.hpp"))

#include STREAMS_BOOST_PP_ITERATE()

    };
}}

#endif

#else

#define PHOENIX_ITERATION STREAMS_BOOST_PP_ITERATION()

#define PHOENIX_EVAL_ARG(z,n,_) arg ## n.eval(env)        

        template<typename Rt, typename Env, typename PtrActor, typename MemFunPtrActor,
                 STREAMS_BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, typename Arg)> 
        static typename result<Env,PtrActor,MemFunPtrActor, STREAMS_BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION,Arg)>::type
        eval(const Env& env, PtrActor& ptrActor, MemFunPtrActor& memFunPtrActor,
             STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, Arg, & arg))
        {
            return (get_pointer(ptrActor.eval(env))->*memFunPtrActor.eval(env))(
                STREAMS_BOOST_PP_ENUM(PHOENIX_ITERATION,PHOENIX_EVAL_ARG,_));
        }

#undef PHOENIX_EVAL_ARG
#undef PHOENIX_ITERATION

#endif
