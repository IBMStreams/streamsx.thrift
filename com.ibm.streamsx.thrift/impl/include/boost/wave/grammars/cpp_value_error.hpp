/*=============================================================================
    Boost.Wave: A Standard compliant C++ preprocessor library

    http://www.streams_boost.org/

    Copyright (c) 2001-2010 Hartmut Kaiser. Distributed under the Boost
    Software License, Version 1.0. (See accompanying file
    LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/

#if !defined(STREAMS_BOOST_WAVE_CPP_VALUE_ERROR_INCLUDED)
#define STREAMS_BOOST_WAVE_CPP_VALUE_ERROR_INCLUDED

#include <streams_boost/wave/wave_config.hpp>

// this must occur after all of the includes and before any code appears
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#include STREAMS_BOOST_ABI_PREFIX
#endif

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost {
namespace wave {
namespace grammars {

///////////////////////////////////////////////////////////////////////////////
//
//  value_error enum type
//
//    This is used to encode any error occurred during the evaluation of a 
//    conditional preprocessor expression
//
///////////////////////////////////////////////////////////////////////////////
enum value_error {
    error_noerror = 0x0,
    error_division_by_zero = 0x1,
    error_integer_overflow = 0x2,
    error_character_overflow = 0x4
};
    
///////////////////////////////////////////////////////////////////////////////
}   //  namespace grammars
}   //  namespace wave 
}   //  namespace streams_boost

// the suffix header occurs after all of the code
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#include STREAMS_BOOST_ABI_SUFFIX
#endif

#endif // !defined(STREAMS_BOOST_WAVE_CPP_VALUE_ERROR_INCLUDED)
