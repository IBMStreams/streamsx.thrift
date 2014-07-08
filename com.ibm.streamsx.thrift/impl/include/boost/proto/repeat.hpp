///////////////////////////////////////////////////////////////////////////////
/// \file repeat.hpp
/// Contains macros to ease the generation of repetitious code constructs
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PROTO_REPEAT_HPP_EAN_11_24_2008
#define STREAMS_BOOST_PROTO_REPEAT_HPP_EAN_11_24_2008

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/facilities/intercept.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/iteration/local.hpp>
#include <streams_boost/preprocessor/tuple/elem.hpp>
#include <streams_boost/proto/proto_fwd.hpp> // for STREAMS_BOOST_PROTO_MAX_ARITY

////////////////////////////////////////////
/// INTERNAL ONLY
#define STREAMS_BOOST_PROTO_ref_a_aux(Z, N, DATA)\
  streams_boost::ref(STREAMS_BOOST_PP_CAT(proto_a, N))

/// \brief Generates a sequence like <tt>typename A0, typename A1, ...</tt>
///
#define STREAMS_BOOST_PROTO_typename_A(N)\
  STREAMS_BOOST_PP_ENUM_PARAMS(N, typename proto_A)

/// \brief Generates a sequence like <tt>A0 const &, A1 const &, ...</tt>
///
#define STREAMS_BOOST_PROTO_A_const_ref(N)\
  STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, proto_A, const & STREAMS_BOOST_PP_INTERCEPT)

/// \brief Generates a sequence like <tt>A0 &, A1 &, ...</tt>
///
#define STREAMS_BOOST_PROTO_A_ref(N)\
  STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, proto_A, & STREAMS_BOOST_PP_INTERCEPT)

/// \brief Generates a sequence like <tt>A0, A1, ...</tt>
///
#define STREAMS_BOOST_PROTO_A(N)\
  STREAMS_BOOST_PP_ENUM_PARAMS(N, proto_A)

/// \brief Generates a sequence like <tt>A0 const, A1 const, ...</tt>
///
#define STREAMS_BOOST_PROTO_A_const(N)\
  STREAMS_BOOST_PP_ENUM_PARAMS(N, const proto_A)

/// \brief Generates a sequence like <tt>A0 const &a0, A1 const &a0, ...</tt>
///
#define STREAMS_BOOST_PROTO_A_const_ref_a(N)\
  STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, proto_A, const &proto_a)

/// \brief Generates a sequence like <tt>A0 &a0, A1 &a0, ...</tt>
///
#define STREAMS_BOOST_PROTO_A_ref_a(N)\
  STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, proto_A, &proto_a)

/// \brief Generates a sequence like <tt>streams_boost::ref(a0), streams_boost::ref(a1), ...</tt>
///
#define STREAMS_BOOST_PROTO_ref_a(N)\
  STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_PROTO_ref_a_aux, ~)

/// \brief Generates a sequence like <tt>a0, a1, ...</tt>
///
#define STREAMS_BOOST_PROTO_a(N)\
  STREAMS_BOOST_PP_ENUM_PARAMS(N, proto_a)

////////////////////////////////////////////
/// INTERNAL ONLY
#define STREAMS_BOOST_PROTO_invoke(Z, N, DATA)\
  STREAMS_BOOST_PP_TUPLE_ELEM(5,0,DATA)(N, STREAMS_BOOST_PP_TUPLE_ELEM(5,1,DATA), STREAMS_BOOST_PP_TUPLE_ELEM(5,2,DATA), STREAMS_BOOST_PP_TUPLE_ELEM(5,3,DATA), STREAMS_BOOST_PP_TUPLE_ELEM(5,4,DATA))

/// \brief Repeatedly invoke the specified macro.
///
/// STREAMS_BOOST_PROTO_REPEAT_FROM_TO_EX() is used generate the kind of repetitive code that is typical
/// of DSELs built with Proto. STREAMS_BOOST_PROTO_REPEAT_FROM_TO_EX(FROM, TO, MACRO, typename_A, A, A_a, a)  is equivalent to:
///
/// \code
/// MACRO(FROM, typename_A, A, A_a, a)
/// MACRO(FROM+1, typename_A, A, A_a, a)
/// ...
/// MACRO(TO-1, typename_A, A, A_a, a)
/// \endcode
#define STREAMS_BOOST_PROTO_REPEAT_FROM_TO_EX(FROM, TO, MACRO, typename_A, A, A_a, a)\
  STREAMS_BOOST_PP_REPEAT_FROM_TO(FROM, TO, STREAMS_BOOST_PROTO_invoke, (MACRO, typename_A, A, A_a, a))

/// \brief Repeatedly invoke the specified macro.
///
/// STREAMS_BOOST_PROTO_REPEAT_FROM_TO() is used generate the kind of repetitive code that is typical
/// of DSELs built with Proto. STREAMS_BOOST_PROTO_REPEAT_FROM_TO(FROM, TO, MACRO)  is equivalent to: 
///
/// \code
/// MACRO(FROM, STREAMS_BOOST_PROTO_typename_A, STREAMS_BOOST_PROTO_A_const_ref, STREAMS_BOOST_PROTO_A_const_ref_a, STREAMS_BOOST_PROTO_ref_a)
/// MACRO(FROM+1, STREAMS_BOOST_PROTO_typename_A, STREAMS_BOOST_PROTO_A_const_ref, STREAMS_BOOST_PROTO_A_const_ref_a, STREAMS_BOOST_PROTO_ref_a)
/// ...
/// MACRO(TO-1, STREAMS_BOOST_PROTO_typename_A, STREAMS_BOOST_PROTO_A_const_ref, STREAMS_BOOST_PROTO_A_const_ref_a, STREAMS_BOOST_PROTO_ref_a)
/// \endcode
///
/// Example:
///
/** \code

// Generate STREAMS_BOOST_PROTO_MAX_ARITY-1 overloads of the
// following construct() function template.
#define M0(N, typename_A, A_const_ref, A_const_ref_a, ref_a)      \ 
template<typename T, typename_A(N)>                               \ 
typename proto::result_of::make_expr<                             \ 
    proto::tag::function                                          \ 
  , construct_helper<T>                                           \ 
  , A_const_ref(N)                                                \ 
>::type const                                                     \ 
construct(A_const_ref_a(N))                                       \ 
{                                                                 \ 
    return proto::make_expr<                                      \ 
        proto::tag::function                                      \ 
    >(                                                            \ 
        construct_helper<T>()                                     \ 
      , ref_a(N)                                                  \ 
    );                                                            \ 
}
STREAMS_BOOST_PROTO_REPEAT_FROM_TO(1, STREAMS_BOOST_PROTO_MAX_ARITY, M0)
#undef M0

\endcode
**/
/// The above invocation of STREAMS_BOOST_PROTO_REPEAT_FROM_TO()  will generate
/// the following code: 
///
/// \code
/// template<typename T, typename A0>
/// typename proto::result_of::make_expr<
///     proto::tag::function
///   , construct_helper<T>
///  , A0 const &
/// >::type const
/// construct(A0 const & a0)
/// {
///     return proto::make_expr<
///         proto::tag::function
///     >(
///         construct_helper<T>()
///       , streams_boost::ref(a0)
///     );
/// }
/// 
/// template<typename T, typename A0, typename A1>
/// typename proto::result_of::make_expr<
///     proto::tag::function
///   , construct_helper<T>
///   , A0 const &
///   , A1 const &
/// >::type const
/// construct(A0 const & a0, A1 const & a1)
/// {
///     return proto::make_expr<
///         proto::tag::function
///     >(
///         construct_helper<T>()
///       , streams_boost::ref(a0)
///       , streams_boost::ref(a1)
///     );
/// }
/// 
/// // ... and so on, up to STREAMS_BOOST_PROTO_MAX_ARITY-1 arguments ...
/// \endcode
#define STREAMS_BOOST_PROTO_REPEAT_FROM_TO(FROM, TO, MACRO)\
  STREAMS_BOOST_PROTO_REPEAT_FROM_TO_EX(FROM, TO, MACRO, STREAMS_BOOST_PROTO_typename_A, STREAMS_BOOST_PROTO_A_const_ref, STREAMS_BOOST_PROTO_A_const_ref_a, STREAMS_BOOST_PROTO_ref_a)

/// \brief Repeatedly invoke the specified macro.
///
/// STREAMS_BOOST_PROTO_REPEAT_EX() is used generate the kind of repetitive code that is typical
/// of DSELs built with Proto. STREAMS_BOOST_PROTO_REPEAT_EX(MACRO, typename_A, A, A_a, a)  is equivalent to:
///
/// \code
/// MACRO(1, typename_A, A, A_a, a)
/// MACRO(2, typename_A, A, A_a, a)
/// ...
/// MACRO(STREAMS_BOOST_PROTO_MAX_ARITY, typename_A, A, A_a, a)
/// \endcode
#define STREAMS_BOOST_PROTO_REPEAT_EX(MACRO, typename_A, A, A_a, a)\
  STREAMS_BOOST_PROTO_REPEAT_FROM_TO_EX(1, STREAMS_BOOST_PP_INC(STREAMS_BOOST_PROTO_MAX_ARITY), MACRO, STREAMS_BOOST_PROTO_typename_A, STREAMS_BOOST_PROTO_A_const_ref, STREAMS_BOOST_PROTO_A_const_ref_a, STREAMS_BOOST_PROTO_ref_a)

/// \brief Repeatedly invoke the specified macro.
///
/// STREAMS_BOOST_PROTO_REPEAT() is used generate the kind of repetitive code that is typical
/// of DSELs built with Proto. STREAMS_BOOST_PROTO_REPEAT(MACRO)  is equivalent to: 
///
/// \code
/// MACRO(1, STREAMS_BOOST_PROTO_typename_A, STREAMS_BOOST_PROTO_A_const_ref, STREAMS_BOOST_PROTO_A_const_ref_a, STREAMS_BOOST_PROTO_ref_a)
/// MACRO(2, STREAMS_BOOST_PROTO_typename_A, STREAMS_BOOST_PROTO_A_const_ref, STREAMS_BOOST_PROTO_A_const_ref_a, STREAMS_BOOST_PROTO_ref_a)
/// ...
/// MACRO(STREAMS_BOOST_PROTO_MAX_ARITY, STREAMS_BOOST_PROTO_typename_A, STREAMS_BOOST_PROTO_A_const_ref, STREAMS_BOOST_PROTO_A_const_ref_a, STREAMS_BOOST_PROTO_ref_a)
/// \endcode
#define STREAMS_BOOST_PROTO_REPEAT(MACRO)\
  STREAMS_BOOST_PROTO_REPEAT_FROM_TO(1, STREAMS_BOOST_PP_INC(STREAMS_BOOST_PROTO_MAX_ARITY), MACRO)

/// \brief Repeatedly invoke the specified macro.
///
/// STREAMS_BOOST_PROTO_LOCAL_ITERATE() is used generate the kind of repetitive code that is typical
/// of DSELs built with Proto. This macro causes the user-defined macro STREAMS_BOOST_PROTO_LOCAL_MACRO to
/// be expanded with values in the range specified by STREAMS_BOOST_PROTO_LOCAL_LIMITS.
///
/// Usage:
///
/// \code
/// #include STREAMS_BOOST_PROTO_LOCAL_ITERATE()
/// \endcode
///
/// Example:
///
/** \code

// Generate STREAMS_BOOST_PROTO_MAX_ARITY-1 overloads of the
// following construct() function template.
#define STREAMS_BOOST_PROTO_LOCAL_MACRO(N, typename_A, A_const_ref,       \ 
  A_const_ref_a, ref_a)                                           \ 
template<typename T, typename_A(N)>                               \ 
typename proto::result_of::make_expr<                             \ 
    proto::tag::function                                          \ 
  , construct_helper<T>                                           \ 
  , A_const_ref(N)                                                \ 
>::type const                                                     \ 
construct(A_const_ref_a(N))                                       \ 
{                                                                 \ 
    return proto::make_expr<                                      \ 
        proto::tag::function                                      \ 
    >(                                                            \ 
        construct_helper<T>()                                     \ 
      , ref_a(N)                                                  \ 
    );                                                            \ 
}
#define STREAMS_BOOST_PROTO_LOCAL_LIMITS (1, STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PROTO_MAX_ARITY))
#include STREAMS_BOOST_PROTO_LOCAL_ITERATE()

\endcode
**/
/// The above inclusion of STREAMS_BOOST_PROTO_LOCAL_ITERATE() will generate
/// the following code: 
///
/// \code
/// template<typename T, typename A0>
/// typename proto::result_of::make_expr<
///     proto::tag::function
///   , construct_helper<T>
///  , A0 const &
/// >::type const
/// construct(A0 const & a0)
/// {
///     return proto::make_expr<
///         proto::tag::function
///     >(
///         construct_helper<T>()
///       , streams_boost::ref(a0)
///     );
/// }
/// 
/// template<typename T, typename A0, typename A1>
/// typename proto::result_of::make_expr<
///     proto::tag::function
///   , construct_helper<T>
///   , A0 const &
///   , A1 const &
/// >::type const
/// construct(A0 const & a0, A1 const & a1)
/// {
///     return proto::make_expr<
///         proto::tag::function
///     >(
///         construct_helper<T>()
///       , streams_boost::ref(a0)
///       , streams_boost::ref(a1)
///     );
/// }
/// 
/// // ... and so on, up to STREAMS_BOOST_PROTO_MAX_ARITY-1 arguments ...
/// \endcode
///
/// If STREAMS_BOOST_PROTO_LOCAL_LIMITS is not defined by the user, it defaults
/// to (1, STREAMS_BOOST_PROTO_MAX_ARITY)
///
/// At each iteration, STREAMS_BOOST_PROTO_LOCAL_MACRO is invoked with the current
/// iteration number and the following 4 macro parameters:
///
/// \li STREAMS_BOOST_PROTO_LOCAL_typename_A
/// \li STREAMS_BOOST_PROTO_LOCAL_A
/// \li STREAMS_BOOST_PROTO_LOCAL_A_a
/// \li STREAMS_BOOST_PROTO_LOCAL_a
///
/// If these macros are not defined by the user, they default respectively to:
///
/// \li STREAMS_BOOST_PROTO_typename_A
/// \li STREAMS_BOOST_PROTO_A_const_ref
/// \li STREAMS_BOOST_PROTO_A_const_ref_a
/// \li STREAMS_BOOST_PROTO_ref_a
///
/// After including STREAMS_BOOST_PROTO_LOCAL_ITERATE(), the following macros are
/// automatically undefined:
///
/// \li STREAMS_BOOST_PROTO_LOCAL_MACRO
/// \li STREAMS_BOOST_PROTO_LOCAL_LIMITS
/// \li STREAMS_BOOST_PROTO_LOCAL_typename_A
/// \li STREAMS_BOOST_PROTO_LOCAL_A
/// \li STREAMS_BOOST_PROTO_LOCAL_A_a
/// \li STREAMS_BOOST_PROTO_LOCAL_a
#define STREAMS_BOOST_PROTO_LOCAL_ITERATE() <streams_boost/proto/detail/local.hpp>

#endif
