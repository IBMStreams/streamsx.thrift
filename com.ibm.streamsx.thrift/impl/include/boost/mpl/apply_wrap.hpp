
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

///// header body

#ifndef STREAMS_BOOST_MPL_APPLY_WRAP_HPP_INCLUDED
#define STREAMS_BOOST_MPL_APPLY_WRAP_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2008
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: apply_wrap.hpp 49272 2008-10-11 06:50:46Z agurtovoy $
// $Date: 2008-10-11 02:50:46 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49272 $

#if !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <streams_boost/mpl/aux_/arity.hpp>
#   include <streams_boost/mpl/aux_/has_apply.hpp>
#   include <streams_boost/mpl/aux_/na.hpp>
#   include <streams_boost/mpl/aux_/msvc_never_true.hpp>
#endif

#include <streams_boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)

#   define STREAMS_BOOST_MPL_PREPROCESSED_HEADER apply_wrap.hpp
#   include <streams_boost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <streams_boost/mpl/limits/arity.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/params.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/enum.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/add.hpp>
#   include <streams_boost/mpl/aux_/config/bcc.hpp>
#   include <streams_boost/mpl/aux_/config/ctps.hpp>
#   include <streams_boost/mpl/aux_/config/dtp.hpp>
#   include <streams_boost/mpl/aux_/config/eti.hpp>
#   include <streams_boost/mpl/aux_/config/msvc.hpp>
#   include <streams_boost/mpl/aux_/config/workaround.hpp>

#   include <streams_boost/preprocessor/comma_if.hpp>
#   include <streams_boost/preprocessor/logical/and.hpp>
#   include <streams_boost/preprocessor/inc.hpp>
#   include <streams_boost/preprocessor/iterate.hpp>


namespace streams_boost { namespace mpl {

// local macros, #undef-ined at the end of the header
#   define AUX778076_APPLY_WRAP_PARAMS(n, param) \
    STREAMS_BOOST_MPL_PP_PARAMS(n, param) \
    /**/

#   define AUX778076_APPLY_WRAP_SPEC_PARAMS(n, param) \
    STREAMS_BOOST_MPL_PP_ENUM(STREAMS_BOOST_PP_INC(n), param) \
    /**/


#define STREAMS_BOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY, <streams_boost/mpl/apply_wrap.hpp>))
#include STREAMS_BOOST_PP_ITERATE()


#   undef AUX778076_APPLY_WRAP_SPEC_PARAMS
#   undef AUX778076_APPLY_WRAP_PARAMS

}}

#endif // STREAMS_BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // STREAMS_BOOST_MPL_APPLY_WRAP_HPP_INCLUDED

///// iteration, depth == 1

// For gcc 4.4 compatability, we must include the
// STREAMS_BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // STREAMS_BOOST_PP_IS_ITERATING
#if STREAMS_BOOST_PP_ITERATION_DEPTH() == 1

#   define i_ STREAMS_BOOST_PP_FRAME_ITERATION(1)

#   if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
// MSVC version

#define AUX778076_MSVC_DTW_NAME STREAMS_BOOST_PP_CAT(msvc_apply,i_)
#define AUX778076_MSVC_DTW_ORIGINAL_NAME apply
#define AUX778076_MSVC_DTW_ARITY i_
#include <streams_boost/mpl/aux_/msvc_dtw.hpp>

template<
      typename F STREAMS_BOOST_PP_COMMA_IF(i_) AUX778076_APPLY_WRAP_PARAMS(i_, typename T)
    >
struct STREAMS_BOOST_PP_CAT(apply_wrap,i_)
{
    // Metafunction forwarding confuses vc6
    typedef typename STREAMS_BOOST_PP_CAT(msvc_apply,i_)<F>::template result_<
          AUX778076_APPLY_WRAP_PARAMS(i_, T)
        >::type type;
};

#   elif defined(STREAMS_BOOST_MPL_CFG_BROKEN_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
// MWCW/Borland version

template<
      int N, typename F STREAMS_BOOST_PP_COMMA_IF(i_) AUX778076_APPLY_WRAP_PARAMS(i_, typename T)
    >
struct STREAMS_BOOST_PP_CAT(apply_wrap_impl,i_);

#define STREAMS_BOOST_PP_ITERATION_PARAMS_2 \
    (3,(0, STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY - i_, <streams_boost/mpl/apply_wrap.hpp>))
#include STREAMS_BOOST_PP_ITERATE()

template<
      typename F STREAMS_BOOST_PP_COMMA_IF(i_) AUX778076_APPLY_WRAP_PARAMS(i_, typename T)
    >
struct STREAMS_BOOST_PP_CAT(apply_wrap,i_)
    : STREAMS_BOOST_PP_CAT(apply_wrap_impl,i_)<
          ::streams_boost::mpl::aux::arity<F,i_>::value
        , F
        STREAMS_BOOST_PP_COMMA_IF(i_) AUX778076_APPLY_WRAP_PARAMS(i_, T)
        >::type
{
};

#   else
// ISO98 C++, with minor concession to vc7

template<
      typename F STREAMS_BOOST_PP_COMMA_IF(i_) AUX778076_APPLY_WRAP_PARAMS(i_, typename T)
#if i_ == 0
    , typename has_apply_ = typename aux::has_apply<F>::type
#endif
    >
struct STREAMS_BOOST_PP_CAT(apply_wrap,i_)
// metafunction forwarding confuses MSVC 7.0
#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1300)
    : F::template apply< AUX778076_APPLY_WRAP_PARAMS(i_, T) >
{
#else
{    
    typedef typename F::template apply<
         AUX778076_APPLY_WRAP_PARAMS(i_, T)
        >::type type;
#endif
};

#if i_ == 0 && !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
template< typename F >
struct STREAMS_BOOST_PP_CAT(apply_wrap,i_)<F,true_>
    : F::apply
{
};
#endif

#   endif // workarounds

#if defined(STREAMS_BOOST_MPL_CFG_MSVC_ETI_BUG)
/// workaround for ETI bug
template<>
struct STREAMS_BOOST_PP_CAT(apply_wrap,i_)<AUX778076_APPLY_WRAP_SPEC_PARAMS(i_, int)>
{
    typedef int type;
};
#endif

#   undef i_

///// iteration, depth == 2

#elif STREAMS_BOOST_PP_ITERATION_DEPTH() == 2

#   define j_ STREAMS_BOOST_PP_FRAME_ITERATION(2)

#if i_ == 0 && j_ == 0 \
    && defined(STREAMS_BOOST_MPL_CFG_BCC590_WORKAROUNDS) \
    && !defined(STREAMS_BOOST_MPL_CFG_NO_HAS_APPLY)

template< typename F, bool F_has_apply >
struct apply_wrap_impl0_bcb {
    typedef typename F::template apply< na > type;
};

template< typename F >
struct apply_wrap_impl0_bcb< F, true > {
    typedef typename F::apply type;
};

template<
      typename F STREAMS_BOOST_PP_COMMA_IF(i_) AUX778076_APPLY_WRAP_PARAMS(i_, typename T)
    >
struct STREAMS_BOOST_PP_CAT(apply_wrap_impl,i_)<
          STREAMS_BOOST_MPL_PP_ADD(i_, j_)
        , F
        STREAMS_BOOST_PP_COMMA_IF(i_) AUX778076_APPLY_WRAP_PARAMS(i_, T)
        >
{
    typedef apply_wrap_impl0_bcb< F, aux::has_apply< F >::value >::type type;
};
#else

template<
      typename F STREAMS_BOOST_PP_COMMA_IF(i_) AUX778076_APPLY_WRAP_PARAMS(i_, typename T)
    >
struct STREAMS_BOOST_PP_CAT(apply_wrap_impl,i_)<
          STREAMS_BOOST_MPL_PP_ADD(i_, j_)
        , F
        STREAMS_BOOST_PP_COMMA_IF(i_) AUX778076_APPLY_WRAP_PARAMS(i_, T)
        >
{
    typedef typename F::template apply<
          AUX778076_APPLY_WRAP_PARAMS(i_, T)
#if i_ == 0 && j_ == 0
/// since the defaults are "lost", we have to pass *something* even for nullary
/// metafunction classes
        na
#else
        STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_AND(i_, j_)) STREAMS_BOOST_MPL_PP_ENUM(j_, na)
#endif
        > type;
};

#endif

#   undef j_

#endif // STREAMS_BOOST_PP_ITERATION_DEPTH()
#endif // STREAMS_BOOST_PP_IS_ITERATING
