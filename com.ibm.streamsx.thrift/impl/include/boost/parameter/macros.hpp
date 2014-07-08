// Copyright David Abrahams, Daniel Wallin 2003. Use, modification and 
// distribution is subject to the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PARAMETER_MACROS_050412_HPP
#define STREAMS_BOOST_PARAMETER_MACROS_050412_HPP

#include <streams_boost/preprocessor/tuple/elem.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/preprocessor/arithmetic/inc.hpp>
#include <streams_boost/preprocessor/logical/bool.hpp>
#include <streams_boost/preprocessor/punctuation/comma_if.hpp>
#include <streams_boost/preprocessor/control/expr_if.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/detail/workaround.hpp>

#define STREAMS_BOOST_PARAMETER_FUN_TEMPLATE_HEAD1(n) \
    template<STREAMS_BOOST_PP_ENUM_PARAMS(n, class T)>

#define STREAMS_BOOST_PARAMETER_FUN_TEMPLATE_HEAD0(n)

#if ! defined(STREAMS_BOOST_NO_SFINAE) && ! STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x592)) 

# define STREAMS_BOOST_PARAMETER_MATCH_TYPE(n, param)           \
            STREAMS_BOOST_PP_EXPR_IF(n, typename) param::match  \
            <                                           \
                STREAMS_BOOST_PP_ENUM_PARAMS(n, T)              \
            >::type 

#else

# define STREAMS_BOOST_PARAMETER_MATCH_TYPE(n, param) param

#endif

#define STREAMS_BOOST_PARAMETER_FUN_DECL(z, n, params)                                      \
                                                                                    \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PARAMETER_FUN_TEMPLATE_HEAD, STREAMS_BOOST_PP_BOOL(n))(n)            \
                                                                                    \
    STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, params)                                               \
        STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, params)(                                          \
            STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(n, T, const& p)                             \
            STREAMS_BOOST_PP_COMMA_IF(n)                                                    \
            STREAMS_BOOST_PARAMETER_MATCH_TYPE(n,STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, params))         \
            kw = STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, params)()                                \
        )                                                                           \
    {                                                                               \
        return STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, params), _with_named_params)( \
            kw(STREAMS_BOOST_PP_ENUM_PARAMS(n, p))                                          \
        );                                                                          \
    }

// Generates:
//
// template<class Params>
// ret name ## _with_named_params(Params const&);
//
// template<class T0>
// ret name(T0 const& p0, typename parameters::match<T0>::type kw = parameters())
// {
//     return name ## _with_named_params(kw(p0));
// }
//
// template<class T0, ..., class TN>
// ret name(T0 const& p0, ..., TN const& PN
//    , typename parameters::match<T0, ..., TN>::type kw = parameters())
// {
//     return name ## _with_named_params(kw(p0, ..., pN));
// }
//
// template<class Params>
// ret name ## _with_named_params(Params const&)
//
// lo and hi determines the min and max arity of the generated functions.

#define STREAMS_BOOST_PARAMETER_FUN(ret, name, lo, hi, parameters)                          \
                                                                                    \
    template<class Params>                                                          \
    ret STREAMS_BOOST_PP_CAT(name, _with_named_params)(Params const& p);                    \
                                                                                    \
    STREAMS_BOOST_PP_REPEAT_FROM_TO(                                                        \
        lo, STREAMS_BOOST_PP_INC(hi), STREAMS_BOOST_PARAMETER_FUN_DECL, (ret, name, parameters))    \
                                                                                    \
    template<class Params>                                                          \
    ret STREAMS_BOOST_PP_CAT(name, _with_named_params)(Params const& p)

#define STREAMS_BOOST_PARAMETER_MEMFUN(ret, name, lo, hi, parameters)                       \
                                                                                    \
    STREAMS_BOOST_PP_REPEAT_FROM_TO(                                                        \
        lo, STREAMS_BOOST_PP_INC(hi), STREAMS_BOOST_PARAMETER_FUN_DECL, (ret, name, parameters))    \
                                                                                    \
    template<class Params>                                                          \
    ret STREAMS_BOOST_PP_CAT(name, _with_named_params)(Params const& p)

#endif // STREAMS_BOOST_PARAMETER_MACROS_050412_HPP

