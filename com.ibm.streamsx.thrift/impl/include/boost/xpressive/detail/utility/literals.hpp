///////////////////////////////////////////////////////////////////////////////
// literals.hpp
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_XPRESSIVE_DETAIL_UTILITY_LITERALS_HPP_EAN_10_04_2005
#define STREAMS_BOOST_XPRESSIVE_DETAIL_UTILITY_LITERALS_HPP_EAN_10_04_2005

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/config.hpp> // for STREAMS_BOOST_STATIC_CONSTANT
#include <streams_boost/cstdint.hpp> // for STREAMS_BOOST_STATIC_CONSTANT
#include <streams_boost/detail/workaround.hpp>

namespace streams_boost { namespace xpressive { namespace detail
{

///////////////////////////////////////////////////////////////////////////////
// char_literal
//
template<typename Char, streams_boost::intmax_t Ch, streams_boost::intmax_t Wch>
struct char_literal;

template<typename Char, streams_boost::intmax_t Ch>
struct char_literal<Char, Ch, Ch>
{
    STREAMS_BOOST_STATIC_CONSTANT(streams_boost::intmax_t, value = Ch);
};

#ifndef STREAMS_BOOST_NO_INCLASS_MEMBER_INITIALIZATION
template<typename Char, streams_boost::intmax_t Ch>
streams_boost::intmax_t const char_literal<Char, Ch, Ch>::value;
#endif

template<typename Ch>
struct string_literal;

template<>
struct string_literal<char>
{
    static char const *pick(char const *cstr, wchar_t const *)
    {
        return cstr;
    }

    static char pick(char ch, wchar_t)
    {
        return ch;
    }
};

template<>
struct string_literal<wchar_t>
{
    static wchar_t const *pick(char const *, wchar_t const *cstr)
    {
        return cstr;
    }

    static wchar_t pick(char, wchar_t ch)
    {
        return ch;
    }
};

#if STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3206))

# define STREAMS_BOOST_XPR_CHAR_(Char, ch) ch
# define STREAMS_BOOST_XPR_CSTR_(Char, st) streams_boost::xpressive::detail::string_literal<Char>::pick(st, L##st)

#else

# define STREAMS_BOOST_XPR_CHAR_(Char, ch) streams_boost::xpressive::detail::char_literal<Char, ch, L##ch>::value
# define STREAMS_BOOST_XPR_CSTR_(Char, st) streams_boost::xpressive::detail::string_literal<Char>::pick(st, L##st)

#endif

}}} // namespace streams_boost::xpressive::detail

#endif
