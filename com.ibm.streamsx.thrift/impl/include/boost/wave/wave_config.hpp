/*=============================================================================
    Boost.Wave: A Standard compliant C++ preprocessor library

    Global application configuration
    
    http://www.streams_boost.org/

    Copyright (c) 2001-2010 Hartmut Kaiser. Distributed under the Boost
    Software License, Version 1.0. (See accompanying file
    LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/

#if !defined(WAVE_CONFIG_HPP_F143F90A_A63F_4B27_AC41_9CA4F14F538D_INCLUDED)
#define WAVE_CONFIG_HPP_F143F90A_A63F_4B27_AC41_9CA4F14F538D_INCLUDED

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/version.hpp>
#include <streams_boost/spirit/include/classic_version.hpp>
#include <streams_boost/wave/wave_version.hpp>

///////////////////////////////////////////////////////////////////////////////
//  Define the maximal include nesting depth allowed. If this value isn't 
//  defined it defaults to 1024
//
//  To define a new initial include nesting define the following constant 
//  before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_MAX_INCLUDE_LEVEL_DEPTH)
#define STREAMS_BOOST_WAVE_MAX_INCLUDE_LEVEL_DEPTH 1024
#endif

///////////////////////////////////////////////////////////////////////////////
//  Decide, whether to support variadics and placemarkers
//
//  To implement support variadics and placemarkers define the following to 
//  something not equal to zero.
//
#if !defined(STREAMS_BOOST_WAVE_SUPPORT_VARIADICS_PLACEMARKERS)
#define STREAMS_BOOST_WAVE_SUPPORT_VARIADICS_PLACEMARKERS 1
#endif

///////////////////////////////////////////////////////////////////////////////
//  Decide, whether to implement a #warning directive as an extension to the 
//  C++ Standard (same as #error, but emits a warning, not an error)
//
//  To disable the implementation of #warning directives, define the following 
//  constant as zero before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_SUPPORT_WARNING_DIRECTIVE)
#define STREAMS_BOOST_WAVE_SUPPORT_WARNING_DIRECTIVE 1
#endif

///////////////////////////////////////////////////////////////////////////////
//  Decide, whether to implement #pragma once 
//
//  To disable the implementation of #pragma once, define the following 
//  constant as zero before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_SUPPORT_PRAGMA_ONCE)
#define STREAMS_BOOST_WAVE_SUPPORT_PRAGMA_ONCE 1
#endif

///////////////////////////////////////////////////////////////////////////////
//  Decide, whether to implement #pragma message("") 
//
//  To disable the implementation of #pragma message(""), define the following 
//  constant as zero before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_SUPPORT_PRAGMA_MESSAGE)
#define STREAMS_BOOST_WAVE_SUPPORT_PRAGMA_MESSAGE 1
#endif

///////////////////////////////////////////////////////////////////////////////
//  Decide, whether to implement #include_next
//  Please note, that this is an extension to the C++ Standard.
//
//  To disable the implementation of #include_next, define the following 
//  constant as zero before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_SUPPORT_INCLUDE_NEXT)
#define STREAMS_BOOST_WAVE_SUPPORT_INCLUDE_NEXT 1
#endif

///////////////////////////////////////////////////////////////////////////////
//  Undefine the following, to enable some MS specific language extensions:
//  __int8, __int16, __int32, __int64, __based, __declspec, __cdecl, 
//  __fastcall, __stdcall, __try, __except, __finally, __leave, __inline,
//  __asm, #region, #endregion
//
//  Note: By default this is enabled for Windows based systems, otherwise it's 
//        disabled.
#if !defined(STREAMS_BOOST_WAVE_SUPPORT_MS_EXTENSIONS)
#if defined(STREAMS_BOOST_WINDOWS)
#define STREAMS_BOOST_WAVE_SUPPORT_MS_EXTENSIONS 1
#else
#define STREAMS_BOOST_WAVE_SUPPORT_MS_EXTENSIONS 0
#endif
#endif

///////////////////////////////////////////////////////////////////////////////
//  Allow the message body of the #error and #warning directives to be 
//  preprocessed before the diagnostic is issued.
//
//  To disable preprocessing of the body of #error and #warning directives, 
//  define the following constant as zero before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_PREPROCESS_ERROR_MESSAGE_BODY)
#define STREAMS_BOOST_WAVE_PREPROCESS_ERROR_MESSAGE_BODY 1
#endif

///////////////////////////////////////////////////////////////////////////////
//  Allow the #pragma directives to be returned to the caller (optionally after 
//  preprocessing the body) 
//
//  To disable the library to emit unknown #pragma directives, define the 
//  following constant as zero before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_EMIT_PRAGMA_DIRECTIVES)
#define STREAMS_BOOST_WAVE_EMIT_PRAGMA_DIRECTIVES 1
#endif

///////////////////////////////////////////////////////////////////////////////
//  Allow the body of a #pragma directive to be preprocessed before the 
//  directive is returned to the caller.
//
//  To disable the preprocessing of the body of #pragma directives, define the 
//  following constant as zero before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_PREPROCESS_PRAGMA_BODY)
#define STREAMS_BOOST_WAVE_PREPROCESS_PRAGMA_BODY 1
#endif

///////////////////////////////////////////////////////////////////////////////
//  Allow to define macros with the command line syntax (-DMACRO(x)=definition)
//
//  To disable the possibility to define macros based on the command line 
//  syntax, define the following constant as zero before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_ENABLE_COMMANDLINE_MACROS)
#define STREAMS_BOOST_WAVE_ENABLE_COMMANDLINE_MACROS 1
#endif

///////////////////////////////////////////////////////////////////////////////
//  Define the pragma keyword to be used by the library to recognize its own
//  pragma's. If nothing else is defined, then 'wave' will be used as the 
//  default keyword, i.e. the library recognizes all 
//
//      #pragma wave option [(argument)]
//
//  and dispatches the handling to the interpret_pragma() preprocessing hook 
//  function (see file: preprocessing_hooks.hpp). The arguments part of the
//  pragma is optional.
//  The STREAMS_BOOST_WAVE_PRAGMA_KEYWORD constant needs to be defined to
//  resolve as a string literal value.
#if !defined(STREAMS_BOOST_WAVE_PRAGMA_KEYWORD)
#define STREAMS_BOOST_WAVE_PRAGMA_KEYWORD "wave"
#endif 

///////////////////////////////////////////////////////////////////////////////
//  Configure Wave thread support, Boost.Spirit and Boost.Pool are configured 
//  based on these settings automatically
//
//  If STREAMS_BOOST_WAVE_SUPPORT_THREADING is not defined, Wave will use the global 
//  Boost build settings (STREAMS_BOOST_HAS_THREADS), if it is defined its value
//  defines, whether threading will be enabled or not (should be set to '0' 
//  or '1').
#if !defined(STREAMS_BOOST_WAVE_SUPPORT_THREADING)
#if defined(STREAMS_BOOST_HAS_THREADS)
#define STREAMS_BOOST_WAVE_SUPPORT_THREADING 1
#else
#define STREAMS_BOOST_WAVE_SUPPORT_THREADING 0
#endif
#endif

#if STREAMS_BOOST_WAVE_SUPPORT_THREADING != 0 
#define STREAMS_BOOST_SPIRIT_THREADSAFE 1
#define PHOENIX_THREADSAFE 1
#else
// disable thread support in Boost.Pool
#define STREAMS_BOOST_NO_MT 1
#endif

///////////////////////////////////////////////////////////////////////////////
//  Define the string type to be used to store the token values and the file 
//  names inside a file_position template class
//
#if !defined(STREAMS_BOOST_WAVE_STRINGTYPE)

// VC7 isn't able to compile the flex_string class, fall back to std::string 
// CW up to 8.3 chokes as well *sigh*
// Tru64/CXX has linker problems when using flex_string
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) || \
    STREAMS_BOOST_WORKAROUND(__MWERKS__, < 0x3200) || \
    (defined(__DECCXX) && defined(__alpha)) || \
    defined(STREAMS_BOOST_WAVE_STRINGTYPE_USE_STDSTRING) 

#define STREAMS_BOOST_WAVE_STRINGTYPE std::string

#if !defined(STREAMS_BOOST_WAVE_STRINGTYPE_USE_STDSTRING)
#define STREAMS_BOOST_WAVE_STRINGTYPE_USE_STDSTRING 1
#endif

#else

// use the following, if you have a fast std::allocator<char>
#define STREAMS_BOOST_WAVE_STRINGTYPE streams_boost::wave::util::flex_string<                 \
        char, std::char_traits<char>, std::allocator<char>,                   \
        streams_boost::wave::util::CowString<                                         \
            streams_boost::wave::util::AllocatorStringStorage<char>                   \
        >                                                                     \
    >                                                                         \
    /**/
    
//  This include is needed for the flex_string class used in the 
//  STREAMS_BOOST_WAVE_STRINGTYPE above.
#include <streams_boost/wave/util/flex_string.hpp>

#endif // STREAMS_BOOST_WORKAROUND(_MSC_VER, <= 1300) et.al.
#endif // !defined(STREAMS_BOOST_WAVE_STRINGTYPE)

///////////////////////////////////////////////////////////////////////////////
//  The following definition forces the Spirit tree code to use list's instead
//  of vectors, which may be more efficient on some platforms
// #define STREAMS_BOOST_SPIRIT_USE_LIST_FOR_TREES

///////////////////////////////////////////////////////////////////////////////
//  The following definition forces the Spirit tree code to use streams_boost pool 
//  allocators instead of the std::allocator for the vector/list's.
// #define STREAMS_BOOST_SPIRIT_USE_STREAMS_BOOST_ALLOCATOR_FOR_TREES

///////////////////////////////////////////////////////////////////////////////
//  Uncomment the following, if you need debug output, the 
//  STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_CPP constants below help to fine control the 
//  amount of the generated debug output.
//#define STREAMS_BOOST_SPIRIT_DEBUG

///////////////////////////////////////////////////////////////////////////////
//  Debug flags for the Wave library, possible flags specified below.
//
//  Note: These flags take effect only if the STREAMS_BOOST_SPIRIT_DEBUG constant
//        above is defined as well.
#define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_CPP_GRAMMAR            0x0001
#define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_TIME_CONVERSION        0x0002
#define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_CPP_EXPR_GRAMMAR       0x0004
#define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_INTLIT_GRAMMAR         0x0008
#define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_CHLIT_GRAMMAR          0x0010
#define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_DEFINED_GRAMMAR        0x0020
#define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_PREDEF_MACROS_GRAMMAR  0x0040

#if !defined(STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_CPP)
#define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_CPP    0    // default is no debugging
#endif 

///////////////////////////////////////////////////////////////////////////////
//
//  For all recognized preprocessor statements the output parse trees 
//  formatted as xml are printed. The formatted parse trees are streamed to the 
//  std::ostream defined by the WAVE_DUMP_PARSE_TREE_OUT constant.
//
//  To enable the output of these parse trees, define the following constant 
//  as zero something not equal to zero before including this file. 
//
#if !defined(STREAMS_BOOST_WAVE_DUMP_PARSE_TREE)
#define STREAMS_BOOST_WAVE_DUMP_PARSE_TREE 0
#endif
#if STREAMS_BOOST_WAVE_DUMP_PARSE_TREE != 0 && !defined(STREAMS_BOOST_WAVE_DUMP_PARSE_TREE_OUT)
#define STREAMS_BOOST_WAVE_DUMP_PARSE_TREE_OUT std::cerr
#endif

///////////////////////////////////////////////////////////////////////////////
//
//  For all #if and #elif directives the preprocessed expressions are printed.
//  These expressions are streamed to the std::ostream defined by the 
//  STREAMS_BOOST_WAVE_DUMP_CONDITIONAL_EXPRESSIONS_OUT constant.
//
//  To enable the output of the preprocessed expressions, define the following 
//  constant as something not equal to zero before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_DUMP_CONDITIONAL_EXPRESSIONS)
#define STREAMS_BOOST_WAVE_DUMP_CONDITIONAL_EXPRESSIONS 0
#endif
#if STREAMS_BOOST_WAVE_DUMP_CONDITIONAL_EXPRESSIONS != 0 && \
   !defined(STREAMS_BOOST_WAVE_DUMP_CONDITIONAL_EXPRESSIONS_OUT)
#define STREAMS_BOOST_WAVE_DUMP_CONDITIONAL_EXPRESSIONS_OUT std::cerr
#endif

///////////////////////////////////////////////////////////////////////////////
//  Decide, whether to use the separate compilation model for the instantiation 
//  of the C++ lexer objects.
//
//  If this is defined, you should explicitly instantiate the C++ lexer
//  template with the correct parameters in a separate compilation unit of
//  your program (see the file instantiate_re2c_lexer.cpp). 
//
//  To use the lexer inclusion model, define the following constant as 
//  something not equal to zero before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_SEPARATE_LEXER_INSTANTIATION)
#define STREAMS_BOOST_WAVE_SEPARATE_LEXER_INSTANTIATION 1
#endif

///////////////////////////////////////////////////////////////////////////////
//  Decide, whether to use the separate compilation model for the instantiation 
//  of the grammar objects.
//
//  If this is defined, you should explicitly instantiate the grammar
//  templates with the correct parameters in a separate compilation unit of
//  your program (see the files instantiate_cpp_grammar.cpp et.al.). 
//
//  To use the grammar inclusion model, define the following constant as 
//  something not equal to zero before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_SEPARATE_GRAMMAR_INSTANTIATION)
#define STREAMS_BOOST_WAVE_SEPARATE_GRAMMAR_INSTANTIATION 1
#endif

///////////////////////////////////////////////////////////////////////////////
//  Decide whether to use a strict C++ lexer.
//  
//  If this is defined to something != 0, then the C++ lexers recognize the 
//  strict C99/C++ basic source character set. If it is not defined or defined 
//  to zero, the C++ lexers recognize the '$' character as part of identifiers.
//
//  The default is to recognize the '$' character as part of identifiers.
//
#if !defined(STREAMS_BOOST_WAVE_USE_STRICT_LEXER)
#define STREAMS_BOOST_WAVE_USE_STRICT_LEXER 0
#endif

///////////////////////////////////////////////////////////////////////////////
//  Decide, whether the serialization of the wave::context class should be 
//  supported
//
//  If this is defined to something not equal to zero the generated code will
//  expose routines allowing to store and reload the internal state of the 
//  wave::context object.
//
//  To enable the availability of the serialization functionality, define the 
//  following constant as something not equal to zero before including this file.
//
#if !defined(STREAMS_BOOST_WAVE_SERIALIZATION)
#define STREAMS_BOOST_WAVE_SERIALIZATION 0
#endif

///////////////////////////////////////////////////////////////////////////////
//  Decide, whether the import keyword is recognized as such
//
//  If this is defined to something not equal to zero the Wave will recognize
//  import as a keyword (T_IMPORT token id)
//
#if !defined(STREAMS_BOOST_WAVE_SUPPORT_IMPORT_KEYWORD)
#define STREAMS_BOOST_WAVE_SUPPORT_IMPORT_KEYWORD 0
#endif

///////////////////////////////////////////////////////////////////////////////
//  Decide, whether to support long long integers in the preprocessor.
//
//  The C++ standard requires the preprocessor to use one of the following 
//  types for integer literals: long or unsigned long depending on an optional 
//  suffix ('u', 'l', 'ul', or 'lu')
//
//  Sometimes it's required to preprocess integer literals bigger than that
//  (i.e. long long or unsigned long long). In this case you need to define the 
//  STREAMS_BOOST_WAVE_SUPPORT_LONGLONG_INTEGER_LITERALS to something not equal to zero.
//
//  This pp constant is effective only, if your target platform supports 
//  long long integers (STREAMS_BOOST_HAS_LONG_LONG is defined).
//
//  Please note, that this setting doesn't relate to the Wave support option
//  support_option_long_long, which enables the recognition of 'll' suffixes 
//  only.
//
//  Defining this pp constant enables the recognition of long long integers
//  even if these do not have the 'll' suffix.
//
#if !defined(STREAMS_BOOST_WAVE_SUPPORT_LONGLONG_INTEGER_LITERALS)
#define STREAMS_BOOST_WAVE_SUPPORT_LONGLONG_INTEGER_LITERALS 0
#endif

namespace streams_boost { namespace wave 
{
#if defined(STREAMS_BOOST_HAS_LONG_LONG) && \
    STREAMS_BOOST_WAVE_SUPPORT_LONGLONG_INTEGER_LITERALS != 0
    typedef streams_boost::long_long_type int_literal_type;
    typedef streams_boost::ulong_long_type uint_literal_type;
#else
    typedef long int_literal_type;
    typedef unsigned long uint_literal_type;
#endif
}}

///////////////////////////////////////////////////////////////////////////////
//  Wave needs at least 4 parameters for phoenix actors
#if !defined(PHOENIX_LIMIT)
#define PHOENIX_LIMIT 6
#endif
#if PHOENIX_LIMIT < 6
// streams_boost/home/classic/spirit/classic_attribute.hpp sets PHOENIX_LIMIT to 3! 
#error "Boost.Wave: the constant PHOENIX_LIMIT must be at least defined to 6" \
" to compile the library."
#endif

///////////////////////////////////////////////////////////////////////////////
//  Set up dll import/export options
#if defined(STREAMS_BOOST_HAS_DECLSPEC) && \
    (defined(STREAMS_BOOST_WAVE_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)) && \
    !defined(STREAMS_BOOST_WAVE_STATIC_LINK)
    
#if defined(STREAMS_BOOST_WAVE_SOURCE)
#define STREAMS_BOOST_WAVE_DECL __declspec(dllexport)
#define STREAMS_BOOST_WAVE_BUILD_DLL
#else
#define STREAMS_BOOST_WAVE_DECL __declspec(dllimport)
#endif

#endif // building a shared library

#ifndef STREAMS_BOOST_WAVE_DECL
#define STREAMS_BOOST_WAVE_DECL
#endif

///////////////////////////////////////////////////////////////////////////////
//  Auto library naming
#if STREAMS_BOOST_VERSION >= 103100   
// auto link features work beginning from Boost V1.31.0
#if !defined(STREAMS_BOOST_WAVE_SOURCE) && !defined(STREAMS_BOOST_ALL_NO_LIB) && \
    !defined(STREAMS_BOOST_WAVE_NO_LIB)

#define STREAMS_BOOST_LIB_NAME streams_boost_wave

// tell the auto-link code to select a dll when required:
#if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_WAVE_DYN_LINK)
#define STREAMS_BOOST_DYN_LINK
#endif

#include <streams_boost/config/auto_link.hpp>

#endif  // auto-linking disabled
#endif  // STREAMS_BOOST_VERSION

///////////////////////////////////////////////////////////////////////////////
//  Compatibility macros 
//  (ensure interface compatibility to older Wave versions)
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//  The preprocessing hook signatures changed after the Boost V1.34.0 release
//
//  To use the preprocessing hook signatures as released with Boost V1.34.0 
//  you need to define the STREAMS_BOOST_WAVE_USE_DEPRECIATED_PREPROCESSING_HOOKS 
//  constant to something not equal zero.
//
//  To force using the new interface define this constant to zero.
//
#if !defined(STREAMS_BOOST_WAVE_USE_DEPRECIATED_PREPROCESSING_HOOKS)
#if STREAMS_BOOST_VERSION < 103500  // before Boost V1.35.0
#define STREAMS_BOOST_WAVE_USE_DEPRECIATED_PREPROCESSING_HOOKS 1
#else
#define STREAMS_BOOST_WAVE_USE_DEPRECIATED_PREPROCESSING_HOOKS 0
#endif
#endif

#endif // !defined(WAVE_CONFIG_HPP_F143F90A_A63F_4B27_AC41_9CA4F14F538D_INCLUDED)