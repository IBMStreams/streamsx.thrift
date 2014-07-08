
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: logical_op.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION!

#if !defined(STREAMS_BOOST_MPL_PREPROCESSING_MODE)
#   include <streams_boost/mpl/bool.hpp>
#   include <streams_boost/mpl/aux_/nested_type_wknd.hpp>
#   include <streams_boost/mpl/aux_/na_spec.hpp>
#   include <streams_boost/mpl/aux_/lambda_support.hpp>
#endif

#include <streams_boost/mpl/limits/arity.hpp>
#include <streams_boost/mpl/aux_/preprocessor/params.hpp>
#include <streams_boost/mpl/aux_/preprocessor/ext_params.hpp>
#include <streams_boost/mpl/aux_/preprocessor/def_params_tail.hpp>
#include <streams_boost/mpl/aux_/preprocessor/enum.hpp>
#include <streams_boost/mpl/aux_/preprocessor/sub.hpp>
#include <streams_boost/mpl/aux_/config/ctps.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

#include <streams_boost/preprocessor/dec.hpp>
#include <streams_boost/preprocessor/inc.hpp>
#include <streams_boost/preprocessor/cat.hpp>

namespace streams_boost { namespace mpl {

#   define AUX778076_PARAMS(param, sub) \
    STREAMS_BOOST_MPL_PP_PARAMS( \
          STREAMS_BOOST_MPL_PP_SUB(STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY, sub) \
        , param \
        ) \
    /**/

#   define AUX778076_SHIFTED_PARAMS(param, sub) \
    STREAMS_BOOST_MPL_PP_EXT_PARAMS( \
          2, STREAMS_BOOST_MPL_PP_SUB(STREAMS_BOOST_PP_INC(STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY), sub) \
        , param \
        ) \
    /**/

#   define AUX778076_SPEC_PARAMS(param) \
    STREAMS_BOOST_MPL_PP_ENUM( \
          STREAMS_BOOST_PP_DEC(STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY) \
        , param \
        ) \
    /**/

namespace aux {

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< bool C_, AUX778076_PARAMS(typename T, 1) >
struct STREAMS_BOOST_PP_CAT(AUX778076_OP_NAME,impl)
    : STREAMS_BOOST_PP_CAT(AUX778076_OP_VALUE1,_)
{
};

template< AUX778076_PARAMS(typename T, 1) >
struct STREAMS_BOOST_PP_CAT(AUX778076_OP_NAME,impl)< AUX778076_OP_VALUE2,AUX778076_PARAMS(T, 1) >
    : STREAMS_BOOST_PP_CAT(AUX778076_OP_NAME,impl)<
          STREAMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(T1)::value
        , AUX778076_SHIFTED_PARAMS(T, 1)
        , STREAMS_BOOST_PP_CAT(AUX778076_OP_VALUE2,_)
        >
{
};

template<>
struct STREAMS_BOOST_PP_CAT(AUX778076_OP_NAME,impl)<
          AUX778076_OP_VALUE2
        , AUX778076_SPEC_PARAMS(STREAMS_BOOST_PP_CAT(AUX778076_OP_VALUE2,_))
        >
    : STREAMS_BOOST_PP_CAT(AUX778076_OP_VALUE2,_)
{
};

#else

template< bool C_ > struct STREAMS_BOOST_PP_CAT(AUX778076_OP_NAME,impl)
{
    template< AUX778076_PARAMS(typename T, 1) > struct result_
        : STREAMS_BOOST_PP_CAT(AUX778076_OP_VALUE1,_)
    {
    };
};

template<> struct STREAMS_BOOST_PP_CAT(AUX778076_OP_NAME,impl)<AUX778076_OP_VALUE2>
{
    template< AUX778076_PARAMS(typename T, 1) > struct result_
        : STREAMS_BOOST_PP_CAT(AUX778076_OP_NAME,impl)< 
              STREAMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(T1)::value
            >::template result_< AUX778076_SHIFTED_PARAMS(T,1),STREAMS_BOOST_PP_CAT(AUX778076_OP_VALUE2,_) >
    {
    };

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1300)
    template<> struct result_<AUX778076_SPEC_PARAMS(STREAMS_BOOST_PP_CAT(AUX778076_OP_VALUE2,_))>
        : STREAMS_BOOST_PP_CAT(AUX778076_OP_VALUE2,_)
    {
    };
};
#else
};

template<>
struct STREAMS_BOOST_PP_CAT(AUX778076_OP_NAME,impl)<AUX778076_OP_VALUE2>
    ::result_< AUX778076_SPEC_PARAMS(STREAMS_BOOST_PP_CAT(AUX778076_OP_VALUE2,_)) >
        : STREAMS_BOOST_PP_CAT(AUX778076_OP_VALUE2,_)
{
};
#endif // STREAMS_BOOST_MSVC == 1300

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

} // namespace aux

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(T1)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(T2)
    STREAMS_BOOST_MPL_PP_DEF_PARAMS_TAIL(2, typename T, STREAMS_BOOST_PP_CAT(AUX778076_OP_VALUE2,_))
    >
struct AUX778076_OP_NAME
#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
    : aux::STREAMS_BOOST_PP_CAT(AUX778076_OP_NAME,impl)<
          STREAMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(T1)::value
        , AUX778076_SHIFTED_PARAMS(T,0)
        >
#else
    : aux::STREAMS_BOOST_PP_CAT(AUX778076_OP_NAME,impl)< 
          STREAMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(T1)::value
        >::template result_< AUX778076_SHIFTED_PARAMS(T,0) >
#endif
{
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(
          STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY
        , AUX778076_OP_NAME
        , (AUX778076_PARAMS(T, 0))
        )
};

STREAMS_BOOST_MPL_AUX_NA_SPEC2(
      2
    , STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY
    , AUX778076_OP_NAME
    )

}}

#undef AUX778076_SPEC_PARAMS
#undef AUX778076_SHIFTED_PARAMS
#undef AUX778076_PARAMS
#undef AUX778076_OP_NAME
#undef AUX778076_OP_VALUE1
#undef AUX778076_OP_VALUE2
