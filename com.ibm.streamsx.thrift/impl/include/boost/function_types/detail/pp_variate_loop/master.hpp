
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifdef __WAVE__
// this file has been generated from the master.hpp file in the same directory
#   pragma wave option(preserve: 0)
#endif

#if !defined(STREAMS_BOOST_FT_PREPROCESSING_MODE)
#   error "this file is only for two-pass preprocessing"
#endif

#if !defined(STREAMS_BOOST_PP_VALUE)
#   include <streams_boost/preprocessor/slot/slot.hpp>
#   include <streams_boost/preprocessor/facilities/empty.hpp>
#   include <streams_boost/preprocessor/facilities/expand.hpp>
#   include <streams_boost/function_types/detail/encoding/def.hpp>

STREAMS_BOOST_PP_EXPAND(#) define STREAMS_BOOST_FT_mfp 0
STREAMS_BOOST_PP_EXPAND(#) define STREAMS_BOOST_FT_syntax STREAMS_BOOST_FT_type_function

#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_function|STREAMS_BOOST_FT_non_variadic
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_function|STREAMS_BOOST_FT_variadic
#   include __FILE__

STREAMS_BOOST_PP_EXPAND(#) if !STREAMS_BOOST_FT_NO_CV_FUNC_SUPPORT
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_function|STREAMS_BOOST_FT_non_variadic|STREAMS_BOOST_FT_const
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_function|STREAMS_BOOST_FT_variadic|STREAMS_BOOST_FT_const
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_function|STREAMS_BOOST_FT_non_variadic|STREAMS_BOOST_FT_volatile
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_function|STREAMS_BOOST_FT_variadic|STREAMS_BOOST_FT_volatile
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_function|STREAMS_BOOST_FT_non_variadic|STREAMS_BOOST_FT_const|STREAMS_BOOST_FT_volatile
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_function|STREAMS_BOOST_FT_variadic|STREAMS_BOOST_FT_const|STREAMS_BOOST_FT_volatile
#   include __FILE__
STREAMS_BOOST_PP_EXPAND(#) endif


STREAMS_BOOST_PP_EXPAND(#) undef  STREAMS_BOOST_FT_syntax
STREAMS_BOOST_PP_EXPAND(#) define STREAMS_BOOST_FT_syntax STREAMS_BOOST_FT_type_function_pointer

#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_pointer|STREAMS_BOOST_FT_non_variadic
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_pointer|STREAMS_BOOST_FT_variadic
#   include __FILE__

STREAMS_BOOST_PP_EXPAND(#) undef  STREAMS_BOOST_FT_syntax
STREAMS_BOOST_PP_EXPAND(#) define STREAMS_BOOST_FT_syntax STREAMS_BOOST_FT_type_function_reference

#   define STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_reference|STREAMS_BOOST_FT_non_variadic
#   include __FILE__
#   define STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_reference|STREAMS_BOOST_FT_variadic
#   include __FILE__

STREAMS_BOOST_PP_EXPAND(#) undef  STREAMS_BOOST_FT_syntax
STREAMS_BOOST_PP_EXPAND(#) undef  STREAMS_BOOST_FT_mfp

STREAMS_BOOST_PP_EXPAND(#) define STREAMS_BOOST_FT_mfp 1
STREAMS_BOOST_PP_EXPAND(#) define STREAMS_BOOST_FT_syntax STREAMS_BOOST_FT_type_member_function_pointer

#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_member_function_pointer|STREAMS_BOOST_FT_non_variadic
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_member_function_pointer|STREAMS_BOOST_FT_variadic
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_member_function_pointer|STREAMS_BOOST_FT_non_variadic|STREAMS_BOOST_FT_const
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_member_function_pointer|STREAMS_BOOST_FT_variadic|STREAMS_BOOST_FT_const
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_member_function_pointer|STREAMS_BOOST_FT_non_variadic|STREAMS_BOOST_FT_volatile
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_member_function_pointer|STREAMS_BOOST_FT_variadic|STREAMS_BOOST_FT_volatile
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_member_function_pointer|STREAMS_BOOST_FT_non_variadic|STREAMS_BOOST_FT_const|STREAMS_BOOST_FT_volatile
#   include __FILE__
#   define  STREAMS_BOOST_PP_VALUE \
      STREAMS_BOOST_FT_member_function_pointer|STREAMS_BOOST_FT_variadic|STREAMS_BOOST_FT_const|STREAMS_BOOST_FT_volatile
#   include __FILE__

STREAMS_BOOST_PP_EXPAND(#) undef  STREAMS_BOOST_FT_syntax
STREAMS_BOOST_PP_EXPAND(#) undef  STREAMS_BOOST_FT_mfp

#   include <streams_boost/function_types/detail/encoding/undef.hpp>
#else 

#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)

#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT(1) & STREAMS_BOOST_FT_kind_mask
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(2)

STREAMS_BOOST_PP_EXPAND(#) if !!(STREAMS_BOOST_PP_SLOT(2) & (STREAMS_BOOST_FT_variations))
STREAMS_BOOST_PP_EXPAND(#) if (STREAMS_BOOST_PP_SLOT(1) & (STREAMS_BOOST_FT_cond)) == (STREAMS_BOOST_FT_cond)

#   if ( STREAMS_BOOST_PP_SLOT(1) & (STREAMS_BOOST_FT_variadic) )
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_ell ...
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_nullary_param
#   else
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_ell
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_nullary_param STREAMS_BOOST_FT_NULLARY_PARAM
#   endif

#   if !( STREAMS_BOOST_PP_SLOT(1) & (STREAMS_BOOST_FT_volatile) )
#     if !( STREAMS_BOOST_PP_SLOT(1) & (STREAMS_BOOST_FT_const) )
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_cv 
#     else
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_cv const
#     endif
#   else
#     if !( STREAMS_BOOST_PP_SLOT(1) & (STREAMS_BOOST_FT_const) )
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_cv volatile
#     else
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_cv const volatile
#     endif
#   endif
STREAMS_BOOST_PP_EXPAND(#)   define STREAMS_BOOST_FT_flags STREAMS_BOOST_PP_SLOT(1)
STREAMS_BOOST_PP_EXPAND(#)   include STREAMS_BOOST_FT_variate_file

STREAMS_BOOST_PP_EXPAND(#)   undef STREAMS_BOOST_FT_cv
STREAMS_BOOST_PP_EXPAND(#)   undef STREAMS_BOOST_FT_ell
STREAMS_BOOST_PP_EXPAND(#)   undef STREAMS_BOOST_FT_nullary_param
STREAMS_BOOST_PP_EXPAND(#)   undef STREAMS_BOOST_FT_flags
STREAMS_BOOST_PP_EXPAND(#) endif
STREAMS_BOOST_PP_EXPAND(#) endif
#endif

