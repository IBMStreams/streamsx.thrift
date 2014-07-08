// Copyright (C) 2004 Arkadiy Vertleyb
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_REGISTER_FUNCTIONS_HPP_INCLUDED
#define STREAMS_BOOST_TYPEOF_REGISTER_FUNCTIONS_HPP_INCLUDED

#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/inc.hpp>
#include <streams_boost/preprocessor/dec.hpp>
#include <streams_boost/preprocessor/if.hpp>
#include <streams_boost/preprocessor/arithmetic/add.hpp>
#include <streams_boost/preprocessor/iteration/iterate.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

#ifndef STREAMS_BOOST_TYPEOF_LIMIT_FUNCTION_ARITY
#define STREAMS_BOOST_TYPEOF_LIMIT_FUNCTION_ARITY 10
#endif

enum 
{
    FUN_ID                          = STREAMS_BOOST_TYPEOF_UNIQUE_ID(),
    FUN_PTR_ID                      = FUN_ID + 1 * STREAMS_BOOST_PP_INC(STREAMS_BOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    FUN_REF_ID                      = FUN_ID + 2 * STREAMS_BOOST_PP_INC(STREAMS_BOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    MEM_FUN_ID                      = FUN_ID + 3 * STREAMS_BOOST_PP_INC(STREAMS_BOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    CONST_MEM_FUN_ID                = FUN_ID + 4 * STREAMS_BOOST_PP_INC(STREAMS_BOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    VOLATILE_MEM_FUN_ID             = FUN_ID + 5 * STREAMS_BOOST_PP_INC(STREAMS_BOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    VOLATILE_CONST_MEM_FUN_ID       = FUN_ID + 6 * STREAMS_BOOST_PP_INC(STREAMS_BOOST_TYPEOF_LIMIT_FUNCTION_ARITY)
};

STREAMS_BOOST_TYPEOF_BEGIN_ENCODE_NS

# define STREAMS_BOOST_PP_ITERATION_LIMITS (0, STREAMS_BOOST_TYPEOF_LIMIT_FUNCTION_ARITY)
# define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/typeof/register_functions_iterate.hpp>
# include STREAMS_BOOST_PP_ITERATE()

STREAMS_BOOST_TYPEOF_END_ENCODE_NS

#endif//STREAMS_BOOST_TYPEOF_REGISTER_FUNCTIONS_HPP_INCLUDED
