// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_CHAR_TRAITS_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_CHAR_TRAITS_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif 

#include <streams_boost/config.hpp>
#include <cstddef>
#include <cstdio>  // EOF.
#include <string>  // std::char_traits.
#include <streams_boost/iostreams/detail/char_traits.hpp>
#include <streams_boost/iostreams/detail/config/wide_streams.hpp>
#ifndef STREAMS_BOOST_IOSTREAMS_NO_WIDE_STREAMS
# include <cwchar>
#endif

#ifdef STREAMS_BOOST_NO_STDC_NAMESPACE
namespace std { using ::wint_t; }
#endif

namespace streams_boost { namespace iostreams {

// Dinkumware that comes with QNX Momentics 6.3.0, 4.0.2, incorrectly defines
// the EOF and WEOF macros to not std:: qualify the wint_t type (and so does
// Sun C++ 5.8 + STLport 4). Fix by placing the def in this scope.
// NOTE: Use STREAMS_BOOST_WORKAROUND?
#if (defined(__QNX__) && defined(STREAMS_BOOST_DINKUMWARE_STDLIB))  \
    || defined(__SUNPRO_CC)
using ::std::wint_t;
#endif

const int WOULD_BLOCK = (int) (EOF - 1);

#ifndef STREAMS_BOOST_IOSTREAMS_NO_WIDE_STREAMS
const std::wint_t WWOULD_BLOCK = (std::wint_t) (WEOF - 1);
#endif

template<typename Ch>
struct char_traits;

template<>
struct char_traits<char> : STREAMS_BOOST_IOSTREAMS_CHAR_TRAITS(char) {
    static char newline() { return '\n'; }
    static int good() { return '\n'; }
    static int would_block() { return WOULD_BLOCK; }
    static bool is_good(int c) { return c != EOF && c != WOULD_BLOCK; }
    static bool is_eof(int c) { return c == EOF; }
    static bool would_block(int c) { return c == WOULD_BLOCK; }
};

#ifndef STREAMS_BOOST_IOSTREAMS_NO_WIDE_STREAMS
template<>
struct char_traits<wchar_t> : std::char_traits<wchar_t> {
    static wchar_t newline() { return L'\n'; }
    static std::wint_t good() { return L'\n'; }
    static std::wint_t would_block() { return WWOULD_BLOCK; }
    static bool is_good(std::wint_t c) { return c != WEOF && c != WWOULD_BLOCK; }
    static bool is_eof(std::wint_t c) { return c == WEOF; }
    static bool would_block(std::wint_t c) { return c == WWOULD_BLOCK; }
};
#endif

} } // End namespaces iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_CHAR_TRAITS_HPP_INCLUDED
