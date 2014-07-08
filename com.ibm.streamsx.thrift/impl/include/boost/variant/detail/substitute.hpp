
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

///// header body

//-----------------------------------------------------------------------------
// streams_boost variant/detail/substitute.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_DETAIL_SUBSTITUTE_HPP
#define STREAMS_BOOST_VARIANT_DETAIL_SUBSTITUTE_HPP

#include "streams_boost/mpl/aux_/config/ctps.hpp"

#include "streams_boost/variant/detail/substitute_fwd.hpp"
#include "streams_boost/mpl/aux_/lambda_arity_param.hpp"
#include "streams_boost/mpl/aux_/preprocessor/params.hpp"
#include "streams_boost/mpl/aux_/preprocessor/repeat.hpp"
#include "streams_boost/mpl/int_fwd.hpp"
#include "streams_boost/mpl/limits/arity.hpp"
#include "streams_boost/preprocessor/cat.hpp"
#include "streams_boost/preprocessor/empty.hpp"
#include "streams_boost/preprocessor/arithmetic/inc.hpp"
#include "streams_boost/preprocessor/iterate.hpp"

namespace streams_boost {
namespace detail { namespace variant {

#if !defined(STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

///////////////////////////////////////////////////////////////////////////////
// (detail) metafunction substitute
//
// Substitutes one type for another in the given type expression.
//

//
// primary template
//
template <
      typename T, typename Dest, typename Source
      STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(
          typename Arity /* = ... (see substitute_fwd.hpp) */
        )
    >
struct substitute
{
    typedef T type;
};

//
// tag substitution specializations
//

#define STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG(CV_) \
    template <typename Dest, typename Source> \
    struct substitute< \
          CV_ Source \
        , Dest \
        , Source \
          STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>) \
        > \
    { \
        typedef CV_ Dest type; \
    }; \
    /**/

STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG( STREAMS_BOOST_PP_EMPTY() )
STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG(const)
STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG(volatile)
STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG(const volatile)

#undef STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG

//
// pointer specializations
//
#define STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER(CV_) \
    template <typename T, typename Dest, typename Source> \
    struct substitute< \
          T * CV_ \
        , Dest \
        , Source \
          STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>) \
        > \
    { \
        typedef typename substitute< \
              T, Dest, Source \
            >::type * CV_ type; \
    }; \
    /**/

STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER( STREAMS_BOOST_PP_EMPTY() )
STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER(const)
STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER(volatile)
STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER(const volatile)

#undef STREAMS_BOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER

//
// reference specializations
//
template <typename T, typename Dest, typename Source>
struct substitute<
      T&
    , Dest
    , Source
      STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>)
    >
{
    typedef typename substitute<
          T, Dest, Source
        >::type & type;
};

//
// template expression (i.e., F<...>) specializations
//

#define STREAMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF_IMPL(N) \
    typedef typename substitute< \
          STREAMS_BOOST_PP_CAT(U,N), Dest, Source \
        >::type STREAMS_BOOST_PP_CAT(u,N); \
    /**/

#define STREAMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF(z, N, _) \
    STREAMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF_IMPL( STREAMS_BOOST_PP_INC(N) ) \
    /**/

#define STREAMS_BOOST_PP_ITERATION_LIMITS (0,STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY)
#define STREAMS_BOOST_PP_FILENAME_1 "streams_boost/variant/detail/substitute.hpp"
#include STREAMS_BOOST_PP_ITERATE()

#undef STREAMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF_IMPL
#undef STREAMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF

#endif // !defined(STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

}} // namespace detail::variant
} // namespace streams_boost

#endif // STREAMS_BOOST_VARIANT_DETAIL_SUBSTITUTE_HPP

///// iteration, depth == 1

#elif STREAMS_BOOST_PP_ITERATION_DEPTH() == 1
#define i STREAMS_BOOST_PP_FRAME_ITERATION(1)

#if i > 0

//
// template specializations
//
template <
      template < STREAMS_BOOST_MPL_PP_PARAMS(i,typename P) > class T
    , STREAMS_BOOST_MPL_PP_PARAMS(i,typename U)
    , typename Dest
    , typename Source
    >
struct substitute<
      T< STREAMS_BOOST_MPL_PP_PARAMS(i,U) >
    , Dest
    , Source
      STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<( i )>)
    >
{
private:
    STREAMS_BOOST_MPL_PP_REPEAT(i, STREAMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF, _)

public:
    typedef T< STREAMS_BOOST_MPL_PP_PARAMS(i,u) > type;
};

//
// function specializations
//
template <
      typename R
    , STREAMS_BOOST_MPL_PP_PARAMS(i,typename U)
    , typename Dest
    , typename Source
    >
struct substitute<
      R (*)( STREAMS_BOOST_MPL_PP_PARAMS(i,U) )
    , Dest
    , Source
      STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>)
    >
{
private:
    typedef typename substitute< R, Dest, Source >::type r;
    STREAMS_BOOST_MPL_PP_REPEAT(i, STREAMS_BOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF, _)

public:
    typedef r (*type)( STREAMS_BOOST_MPL_PP_PARAMS(i,u) );
};

#elif i == 0

//
// zero-arg function specialization
//
template <
      typename R, typename Dest, typename Source
    >
struct substitute<
      R (*)( void )
    , Dest
    , Source
      STREAMS_BOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>)
    >
{
private:
    typedef typename substitute< R, Dest, Source >::type r;

public:
    typedef r (*type)( void );
};

#endif // i

#undef i
#endif // STREAMS_BOOST_PP_IS_ITERATING
