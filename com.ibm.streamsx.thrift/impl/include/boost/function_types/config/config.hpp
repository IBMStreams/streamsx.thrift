
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef STREAMS_BOOST_FT_CONFIG_HPP_INCLUDED
#define STREAMS_BOOST_FT_CONFIG_HPP_INCLUDED

#include <streams_boost/function_types/config/compiler.hpp>
#include <streams_boost/function_types/config/cc_names.hpp>

// maximum allowed arity
#ifndef STREAMS_BOOST_FT_MAX_ARITY
#define STREAMS_BOOST_FT_MAX_ARITY 20
#endif

// the most common calling conventions for x86 architecture can be enabled at
// once in the compiler config
#ifdef STREAMS_BOOST_FT_COMMON_X86_CCs
#   ifndef STREAMS_BOOST_FT_CC_CDECL
#   define STREAMS_BOOST_FT_CC_CDECL STREAMS_BOOST_FT_COMMON_X86_CCs
#   endif
#   ifndef STREAMS_BOOST_FT_CC_STDCALL
#   define STREAMS_BOOST_FT_CC_STDCALL non_variadic|STREAMS_BOOST_FT_COMMON_X86_CCs
#   endif
#   ifndef STREAMS_BOOST_FT_CC_FASTCALL
#   define STREAMS_BOOST_FT_CC_FASTCALL non_variadic|STREAMS_BOOST_FT_COMMON_X86_CCs
#   endif
#endif

// where to place the cc specifier (the common way)
#ifndef STREAMS_BOOST_FT_SYNTAX
#   define STREAMS_BOOST_FT_SYNTAX(result,lparen,cc_spec,type_mod,name,rparen) \
                        result() lparen() cc_spec() type_mod() name() rparen()
#endif

// param for nullary functions
// set to "void" for compilers that require nullary functions to read 
// "R (void)" in template partial specialization
#ifndef STREAMS_BOOST_FT_NULLARY_PARAM
#define STREAMS_BOOST_FT_NULLARY_PARAM 
#endif

// there is a pending defect report on cv qualified function types, so support
// for these types is disabled, unless for compilers where it's known to work
#ifndef STREAMS_BOOST_FT_NO_CV_FUNC_SUPPORT
#define STREAMS_BOOST_FT_NO_CV_FUNC_SUPPORT 1
#endif

// full preprocessing implies preprocessing of the ccs
#if defined(STREAMS_BOOST_FT_PREPROCESSING_MODE) && !defined(STREAMS_BOOST_FT_CC_PREPROCESSING)
#   define STREAMS_BOOST_FT_CC_PREPROCESSING 1
#endif

#endif

