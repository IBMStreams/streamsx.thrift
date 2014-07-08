/*=============================================================================
    Boost.Wave: A Standard compliant C++ preprocessor library
    Persistent application configuration
    
    http://www.streams_boost.org/

    Copyright (c) 2001-2010 Hartmut Kaiser. Distributed under the Boost
    Software License, Version 1.0. (See accompanying file
    LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/

#if !defined(STREAMS_BOOST_WAVE_CONFIG_CONSTANT_HPP)
#define STREAMS_BOOST_WAVE_CONFIG_CONSTANT_HPP

#include <streams_boost/preprocessor/stringize.hpp>
#include <streams_boost/wave/wave_config.hpp>

///////////////////////////////////////////////////////////////////////////////
#if STREAMS_BOOST_WAVE_SUPPORT_VARIADICS_PLACEMARKERS != 0
#define STREAMS_BOOST_WAVE_SUPPORT_VARIADICS_PLACEMARKERS_CONFIG 0x00000001
#else
#define STREAMS_BOOST_WAVE_SUPPORT_VARIADICS_PLACEMARKERS_CONFIG 0x00000000
#endif

///////////////////////////////////////////////////////////////////////////////
#if STREAMS_BOOST_WAVE_SUPPORT_PRAGMA_ONCE != 0
#define STREAMS_BOOST_WAVE_SUPPORT_PRAGMA_ONCE_CONFIG 0x00000002
#else
#define STREAMS_BOOST_WAVE_SUPPORT_PRAGMA_ONCE_CONFIG 0x00000000
#endif

///////////////////////////////////////////////////////////////////////////////
#if STREAMS_BOOST_WAVE_SUPPORT_MS_EXTENSIONS != 0
#define STREAMS_BOOST_WAVE_SUPPORT_MS_EXTENSIONS_CONFIG 0x00000004
#else
#define STREAMS_BOOST_WAVE_SUPPORT_MS_EXTENSIONS_CONFIG 0x00000000
#endif

///////////////////////////////////////////////////////////////////////////////
#if STREAMS_BOOST_WAVE_PREPROCESS_PRAGMA_BODY != 0
#define STREAMS_BOOST_WAVE_PREPROCESS_PRAGMA_BODY_CONFIG 0x00000008
#else
#define STREAMS_BOOST_WAVE_PREPROCESS_PRAGMA_BODY_CONFIG 0x00000000
#endif

///////////////////////////////////////////////////////////////////////////////
#if STREAMS_BOOST_WAVE_USE_STRICT_LEXER != 0
#define STREAMS_BOOST_WAVE_USE_STRICT_LEXER_CONFIG 0x00000010
#else
#define STREAMS_BOOST_WAVE_USE_STRICT_LEXER_CONFIG 0x00000000
#endif

///////////////////////////////////////////////////////////////////////////////
#if STREAMS_BOOST_WAVE_SUPPORT_IMPORT_KEYWORD != 0
#define STREAMS_BOOST_WAVE_SUPPORT_IMPORT_KEYWORD_CONFIG 0x00000020
#else
#define STREAMS_BOOST_WAVE_SUPPORT_IMPORT_KEYWORD_CONFIG 0x00000000
#endif

///////////////////////////////////////////////////////////////////////////////
#define STREAMS_BOOST_WAVE_CONFIG (                                                   \
        STREAMS_BOOST_WAVE_SUPPORT_VARIADICS_PLACEMARKERS_CONFIG |                    \
        STREAMS_BOOST_WAVE_SUPPORT_PRAGMA_ONCE_CONFIG |                               \
        STREAMS_BOOST_WAVE_SUPPORT_MS_EXTENSIONS_CONFIG |                             \
        STREAMS_BOOST_WAVE_PREPROCESS_PRAGMA_BODY_CONFIG |                            \
        STREAMS_BOOST_WAVE_USE_STRICT_LEXER_CONFIG |                                  \
        STREAMS_BOOST_WAVE_SUPPORT_IMPORT_KEYWORD_CONFIG                              \
    )                                                                         \
    /**/

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost { namespace wave {

    ///////////////////////////////////////////////////////////////////////////
    //  Call this function to test the configuration of the calling application
    //  against the configuration of the linked library.
    STREAMS_BOOST_WAVE_DECL bool test_configuration(unsigned int config, 
        char const* pragma_keyword, char const* string_type);
        
///////////////////////////////////////////////////////////////////////////////
}}  // namespace streams_boost::wave

#define STREAMS_BOOST_WAVE_TEST_CONFIGURATION()                                       \
        streams_boost::wave::test_configuration(                                      \
            STREAMS_BOOST_WAVE_CONFIG,                                                \
            STREAMS_BOOST_WAVE_PRAGMA_KEYWORD,                                        \
            STREAMS_BOOST_PP_STRINGIZE((STREAMS_BOOST_WAVE_STRINGTYPE))                       \
        )                                                                     \
    /**/
    
#endif // !STREAMS_BOOST_WAVE_CONFIG_CONSTANT_HPP
