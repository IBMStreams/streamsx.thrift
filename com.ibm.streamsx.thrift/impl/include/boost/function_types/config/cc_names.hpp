
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef STREAMS_BOOST_FT_CONFIG_CC_NAMES_HPP_INCLUDED
#define STREAMS_BOOST_FT_CONFIG_CC_NAMES_HPP_INCLUDED

#define STREAMS_BOOST_FT_BUILTIN_CC_NAMES \
  (( IMPLICIT           , implicit_cc , STREAMS_BOOST_PP_EMPTY                ))\
  (( CDECL              , cdecl_cc    , STREAMS_BOOST_PP_IDENTITY(__cdecl   ) ))\
  (( STDCALL            , stdcall_cc  , STREAMS_BOOST_PP_IDENTITY(__stdcall ) ))\
  (( PASCAL             , pascal_cc   , STREAMS_BOOST_PP_IDENTITY(pascal    ) ))\
  (( FASTCALL           , fastcall_cc , STREAMS_BOOST_PP_IDENTITY(__fastcall) ))\
  (( CLRCALL            , clrcall_cc  , STREAMS_BOOST_PP_IDENTITY(__clrcall ) ))\
  (( THISCALL           , thiscall_cc , STREAMS_BOOST_PP_IDENTITY(__thiscall) ))\
  (( IMPLICIT_THISCALL  , thiscall_cc , STREAMS_BOOST_PP_EMPTY                )) 

// append user-defined cc names to builtin ones
#ifdef STREAMS_BOOST_FT_CC_NAMES 
#   define STREAMS_BOOST_FT_CC_NAMES_SEQ STREAMS_BOOST_FT_BUILTIN_CC_NAMES STREAMS_BOOST_FT_CC_NAMES
#   define STREAMS_BOOST_FT_CC_PREPROCESSING 1
#else
#   define STREAMS_BOOST_FT_CC_NAMES_SEQ STREAMS_BOOST_FT_BUILTIN_CC_NAMES
#endif

#endif

