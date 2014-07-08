/*=============================================================================
    Boost.Wave: A Standard compliant C++ preprocessor library

    Global application configuration
    
    http://www.streams_boost.org/

    Copyright (c) 2001-2010 Hartmut Kaiser. Distributed under the Boost
    Software License, Version 1.0. (See accompanying file
    LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/

#if !defined(STREAMS_BOOST_SPIRIT_PATTERN_PARSER_HPP)
#define STREAMS_BOOST_SPIRIT_PATTERN_PARSER_HPP

#include <streams_boost/spirit/include/classic_primitives.hpp>
#include <streams_boost/wave/wave_config.hpp>

// this must occur after all of the includes and before any code appears
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#include STREAMS_BOOST_ABI_PREFIX
#endif

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost {
namespace wave {
namespace util {

    ///////////////////////////////////////////////////////////////////////////
    //
    //  pattern_and class
    //
    ///////////////////////////////////////////////////////////////////////////
    template <typename CharT = char>
    struct pattern_and 
      : public streams_boost::spirit::classic::char_parser<pattern_and<CharT> >
    {
        pattern_and(CharT pattern_, unsigned long pattern_mask_ = 0UL)
        :   pattern(pattern_), 
            pattern_mask((0UL != pattern_mask_) ? pattern_mask_ : pattern_)
        {}

        template <typename T>
        bool test(T pattern_) const
        { return ((unsigned long)pattern_ & pattern_mask) == (unsigned long)pattern; }

        CharT         pattern;
        unsigned long pattern_mask;
    };

    template <typename CharT>
    inline pattern_and<CharT>
    pattern_p(CharT pattern, unsigned long pattern_mask = 0UL)
    { return pattern_and<CharT>(pattern, pattern_mask); }

///////////////////////////////////////////////////////////////////////////////
}   // namespace util
}   // namespace wave
}   // namespace streams_boost

// the suffix header occurs after all of the code
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#include STREAMS_BOOST_ABI_SUFFIX
#endif

#endif // defined(STREAMS_BOOST_SPIRIT_PATTERN_PARSER_HPP)
