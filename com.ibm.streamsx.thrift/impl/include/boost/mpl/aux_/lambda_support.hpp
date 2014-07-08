
#ifndef STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: lambda_support.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/lambda.hpp>

#if !defined(STREAMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)

#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) /**/
#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(i,name,params) /**/

#else

#   include <streams_boost/mpl/int_fwd.hpp>
#   include <streams_boost/mpl/aux_/yes_no.hpp>
#   include <streams_boost/mpl/aux_/na_fwd.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/params.hpp>
#   include <streams_boost/mpl/aux_/preprocessor/enum.hpp>
#   include <streams_boost/mpl/aux_/config/msvc.hpp>
#   include <streams_boost/mpl/aux_/config/workaround.hpp>

#   include <streams_boost/preprocessor/tuple/to_list.hpp>
#   include <streams_boost/preprocessor/list/for_each_i.hpp>
#   include <streams_boost/preprocessor/inc.hpp>
#   include <streams_boost/preprocessor/cat.hpp>

#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_ARG_TYPEDEF_FUNC(R,typedef_,i,param) \
    typedef_ param STREAMS_BOOST_PP_CAT(arg,STREAMS_BOOST_PP_INC(i)); \
    /**/

// agurt, 07/mar/03: restore an old revision for the sake of SGI MIPSpro C++
#if STREAMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 238) 

#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    typedef STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::int_<i> arity; \
    STREAMS_BOOST_PP_LIST_FOR_EACH_I_R( \
          1 \
        , STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_ARG_TYPEDEF_FUNC \
        , typedef \
        , STREAMS_BOOST_PP_TUPLE_TO_LIST(i,params) \
        ) \
    struct rebind \
    { \
        template< STREAMS_BOOST_MPL_PP_PARAMS(i,typename U) > struct apply \
            : name< STREAMS_BOOST_MPL_PP_PARAMS(i,U) > \
        { \
        }; \
    }; \
    /**/

#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    /**/

#elif STREAMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 244) && !defined(STREAMS_BOOST_INTEL_CXX_VERSION)
// agurt, 18/jan/03: old EDG-based compilers actually enforce 11.4 para 9
// (in strict mode), so we have to provide an alternative to the 
// MSVC-optimized implementation

#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
    typedef STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::int_<i> arity; \
    STREAMS_BOOST_PP_LIST_FOR_EACH_I_R( \
          1 \
        , STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_ARG_TYPEDEF_FUNC \
        , typedef \
        , STREAMS_BOOST_PP_TUPLE_TO_LIST(i,params) \
        ) \
    struct rebind; \
/**/

#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
}; \
template< STREAMS_BOOST_MPL_PP_PARAMS(i,typename T) > \
struct name<STREAMS_BOOST_MPL_PP_PARAMS(i,T)>::rebind \
{ \
    template< STREAMS_BOOST_MPL_PP_PARAMS(i,typename U) > struct apply \
        : name< STREAMS_BOOST_MPL_PP_PARAMS(i,U) > \
    { \
    }; \
/**/

#else // __EDG_VERSION__

namespace streams_boost { namespace mpl { namespace aux {
template< typename T > struct has_rebind_tag;
}}}

#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
    typedef STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::int_<i> arity; \
    STREAMS_BOOST_PP_LIST_FOR_EACH_I_R( \
          1 \
        , STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_ARG_TYPEDEF_FUNC \
        , typedef \
        , STREAMS_BOOST_PP_TUPLE_TO_LIST(i,params) \
        ) \
    friend class STREAMS_BOOST_PP_CAT(name,_rebind); \
    typedef STREAMS_BOOST_PP_CAT(name,_rebind) rebind; \
/**/

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x610))
#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) \
template< STREAMS_BOOST_MPL_PP_PARAMS(i,typename T) > \
::streams_boost::mpl::aux::yes_tag operator|( \
      ::streams_boost::mpl::aux::has_rebind_tag<int> \
    , name<STREAMS_BOOST_MPL_PP_PARAMS(i,T)>* \
    ); \
::streams_boost::mpl::aux::no_tag operator|( \
      ::streams_boost::mpl::aux::has_rebind_tag<int> \
    , name< STREAMS_BOOST_MPL_PP_ENUM(i,::streams_boost::mpl::na) >* \
    ); \
/**/
#elif !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) \
template< STREAMS_BOOST_MPL_PP_PARAMS(i,typename T) > \
::streams_boost::mpl::aux::yes_tag operator|( \
      ::streams_boost::mpl::aux::has_rebind_tag<int> \
    , ::streams_boost::mpl::aux::has_rebind_tag< name<STREAMS_BOOST_MPL_PP_PARAMS(i,T)> >* \
    ); \
/**/
#else
#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) /**/
#endif

#   if !defined(__BORLANDC__)
#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
}; \
STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) \
class STREAMS_BOOST_PP_CAT(name,_rebind) \
{ \
 public: \
    template< STREAMS_BOOST_MPL_PP_PARAMS(i,typename U) > struct apply \
        : name< STREAMS_BOOST_MPL_PP_PARAMS(i,U) > \
    { \
    }; \
/**/
#   else
#   define STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
}; \
STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) \
class STREAMS_BOOST_PP_CAT(name,_rebind) \
{ \
 public: \
    template< STREAMS_BOOST_MPL_PP_PARAMS(i,typename U) > struct apply \
    { \
        typedef typename name< STREAMS_BOOST_MPL_PP_PARAMS(i,U) >::type type; \
    }; \
/**/
#   endif // __BORLANDC__

#endif // __EDG_VERSION__

#endif // STREAMS_BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT

#endif // STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_HPP_INCLUDED
