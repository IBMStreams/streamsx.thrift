
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusions

#ifdef __WAVE__
// this file has been generated from the master.hpp file in the same directory
#   pragma wave option(preserve: 0)
#endif


#if !STREAMS_BOOST_PP_IS_ITERATING

#   ifndef STREAMS_BOOST_FT_DETAIL_CC_LOOP_MASTER_HPP_INCLUDED
#   define STREAMS_BOOST_FT_DETAIL_CC_LOOP_MASTER_HPP_INCLUDED
#     include <streams_boost/function_types/config/cc_names.hpp>

#     include <streams_boost/preprocessor/cat.hpp>
#     include <streams_boost/preprocessor/seq/size.hpp>
#     include <streams_boost/preprocessor/seq/elem.hpp>
#     include <streams_boost/preprocessor/tuple/elem.hpp>
#     include <streams_boost/preprocessor/iteration/iterate.hpp>
#     include <streams_boost/preprocessor/facilities/expand.hpp>
#     include <streams_boost/preprocessor/arithmetic/inc.hpp>
#   endif

#   include <streams_boost/function_types/detail/encoding/def.hpp>
#   include <streams_boost/function_types/detail/encoding/aliases_def.hpp>

#   define  STREAMS_BOOST_PP_FILENAME_1 \
        <streams_boost/function_types/detail/pp_cc_loop/master.hpp>
#   define  STREAMS_BOOST_PP_ITERATION_LIMITS \
        (0,STREAMS_BOOST_PP_SEQ_SIZE(STREAMS_BOOST_FT_CC_NAMES_SEQ)-1)
#   include STREAMS_BOOST_PP_ITERATE()
#   if !defined(STREAMS_BOOST_FT_config_valid) && STREAMS_BOOST_FT_CC_PREPROCESSING
#     define STREAMS_BOOST_FT_cc_id 1
#     define STREAMS_BOOST_FT_cc_name implicit_cc
#     define STREAMS_BOOST_FT_cc STREAMS_BOOST_PP_EMPTY
#     define STREAMS_BOOST_FT_cond callable_builtin
#     include STREAMS_BOOST_FT_cc_file
#     undef STREAMS_BOOST_FT_cond
#     undef STREAMS_BOOST_FT_cc_name
#     undef STREAMS_BOOST_FT_cc
#     undef STREAMS_BOOST_FT_cc_id
#   elif !defined(STREAMS_BOOST_FT_config_valid) // and generating preprocessed file
STREAMS_BOOST_PP_EXPAND(#) ifndef STREAMS_BOOST_FT_config_valid
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_cc_id 1
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_cc_name implicit_cc
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_cc STREAMS_BOOST_PP_EMPTY
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_cond callable_builtin
#define _()
STREAMS_BOOST_PP_EXPAND(#)   include STREAMS_BOOST_FT_cc_file
#undef _
STREAMS_BOOST_PP_EXPAND(#)   undef STREAMS_BOOST_FT_cond
STREAMS_BOOST_PP_EXPAND(#)   undef STREAMS_BOOST_FT_cc_name
STREAMS_BOOST_PP_EXPAND(#)   undef STREAMS_BOOST_FT_cc
STREAMS_BOOST_PP_EXPAND(#)   undef STREAMS_BOOST_FT_cc_id
STREAMS_BOOST_PP_EXPAND(#) else
STREAMS_BOOST_PP_EXPAND(#)   undef STREAMS_BOOST_FT_config_valid
STREAMS_BOOST_PP_EXPAND(#) endif

#   else
#     undef STREAMS_BOOST_FT_config_valid
#   endif

#   include <streams_boost/function_types/detail/encoding/aliases_undef.hpp>
#   include <streams_boost/function_types/detail/encoding/undef.hpp>

#elif STREAMS_BOOST_FT_CC_PREPROCESSING

#   define STREAMS_BOOST_FT_cc_id  STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_FRAME_ITERATION(1))
#   define STREAMS_BOOST_FT_cc_inf \
        STREAMS_BOOST_PP_SEQ_ELEM(STREAMS_BOOST_PP_FRAME_ITERATION(1),STREAMS_BOOST_FT_CC_NAMES_SEQ)

#   define STREAMS_BOOST_FT_cc_pp_name STREAMS_BOOST_PP_TUPLE_ELEM(3,0,STREAMS_BOOST_FT_cc_inf)
#   define STREAMS_BOOST_FT_cc_name    STREAMS_BOOST_PP_TUPLE_ELEM(3,1,STREAMS_BOOST_FT_cc_inf)
#   define STREAMS_BOOST_FT_cc         STREAMS_BOOST_PP_TUPLE_ELEM(3,2,STREAMS_BOOST_FT_cc_inf)

#   define STREAMS_BOOST_FT_cond STREAMS_BOOST_PP_CAT(STREAMS_BOOST_FT_CC_,STREAMS_BOOST_FT_cc_pp_name)

#   if STREAMS_BOOST_FT_cond
#     define STREAMS_BOOST_FT_config_valid 1
#     include STREAMS_BOOST_FT_cc_file
#   endif

#   undef STREAMS_BOOST_FT_cond

#   undef STREAMS_BOOST_FT_cc_pp_name
#   undef STREAMS_BOOST_FT_cc_name
#   undef STREAMS_BOOST_FT_cc

#   undef STREAMS_BOOST_FT_cc_id
#   undef STREAMS_BOOST_FT_cc_inf

#else // if generating preprocessed file
STREAMS_BOOST_PP_EXPAND(#) define STREAMS_BOOST_FT_cc_id STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_ITERATION())

#   define STREAMS_BOOST_FT_cc_inf \
        STREAMS_BOOST_PP_SEQ_ELEM(STREAMS_BOOST_PP_ITERATION(),STREAMS_BOOST_FT_CC_NAMES_SEQ)

#   define STREAMS_BOOST_FT_cc_pp_name STREAMS_BOOST_PP_TUPLE_ELEM(3,0,STREAMS_BOOST_FT_cc_inf)

#   define STREAMS_BOOST_FT_CC_DEF(name,index) \
        name STREAMS_BOOST_PP_TUPLE_ELEM(3,index,STREAMS_BOOST_FT_cc_inf)
STREAMS_BOOST_PP_EXPAND(#) define STREAMS_BOOST_FT_CC_DEF(STREAMS_BOOST_FT_cc_name,1)
STREAMS_BOOST_PP_EXPAND(#) define STREAMS_BOOST_FT_CC_DEF(STREAMS_BOOST_FT_cc,2)
#   undef  STREAMS_BOOST_FT_CC_DEF

#   define STREAMS_BOOST_FT_cc_cond_v STREAMS_BOOST_PP_CAT(STREAMS_BOOST_FT_CC_,STREAMS_BOOST_FT_cc_pp_name)
STREAMS_BOOST_PP_EXPAND(#) define STREAMS_BOOST_FT_cond STREAMS_BOOST_FT_cc_cond_v
#   undef  STREAMS_BOOST_FT_cc_cond_v

#   undef STREAMS_BOOST_FT_cc_pp_name
#   undef STREAMS_BOOST_FT_cc_inf

STREAMS_BOOST_PP_EXPAND(#) if STREAMS_BOOST_FT_cond
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_config_valid 1
#define _()
STREAMS_BOOST_PP_EXPAND(#)   include STREAMS_BOOST_FT_cc_file
#undef _
STREAMS_BOOST_PP_EXPAND(#) endif

STREAMS_BOOST_PP_EXPAND(#) undef STREAMS_BOOST_FT_cond

STREAMS_BOOST_PP_EXPAND(#) undef STREAMS_BOOST_FT_cc_name
STREAMS_BOOST_PP_EXPAND(#) undef STREAMS_BOOST_FT_cc

STREAMS_BOOST_PP_EXPAND(#) undef STREAMS_BOOST_FT_cc_id

#endif

