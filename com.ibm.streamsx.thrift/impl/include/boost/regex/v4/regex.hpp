/*
 *
 * Copyright (c) 1998-2002
 * John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 */

 /*
  *   LOCATION:    see http://www.streams_boost.org for most recent version.
  *   FILE         regex.cpp
  *   VERSION      see <streams_boost/version.hpp>
  *   DESCRIPTION: Declares streams_boost::basic_regex<> and associated
  *                functions and classes. This header is the main
  *                entry point for the template regex code.
  */

#ifndef STREAMS_BOOST_RE_REGEX_HPP_INCLUDED
#define STREAMS_BOOST_RE_REGEX_HPP_INCLUDED

#ifdef __cplusplus

// what follows is all C++ don't include in C builds!!

#ifndef STREAMS_BOOST_REGEX_CONFIG_HPP
#include <streams_boost/regex/config.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_WORKAROUND_HPP
#include <streams_boost/regex/v4/regex_workaround.hpp>
#endif

#ifndef STREAMS_BOOST_REGEX_FWD_HPP
#include <streams_boost/regex_fwd.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_TRAITS_HPP
#include <streams_boost/regex/regex_traits.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_RAW_BUFFER_HPP
#include <streams_boost/regex/v4/error_type.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_MATCH_FLAGS
#include <streams_boost/regex/v4/match_flags.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_RAW_BUFFER_HPP
#include <streams_boost/regex/v4/regex_raw_buffer.hpp>
#endif
#ifndef STREAMS_BOOST_RE_PAT_EXCEPT_HPP
#include <streams_boost/regex/pattern_except.hpp>
#endif

#ifndef STREAMS_BOOST_REGEX_V4_CHAR_REGEX_TRAITS_HPP
#include <streams_boost/regex/v4/char_regex_traits.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_STATES_HPP
#include <streams_boost/regex/v4/states.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_REGBASE_HPP
#include <streams_boost/regex/v4/regbase.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_ITERATOR_TRAITS_HPP
#include <streams_boost/regex/v4/iterator_traits.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_BASIC_REGEX_HPP
#include <streams_boost/regex/v4/basic_regex.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_BASIC_REGEX_CREATOR_HPP
#include <streams_boost/regex/v4/basic_regex_creator.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_BASIC_REGEX_PARSER_HPP
#include <streams_boost/regex/v4/basic_regex_parser.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_SUB_MATCH_HPP
#include <streams_boost/regex/v4/sub_match.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_FORMAT_HPP
#include <streams_boost/regex/v4/regex_format.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_MATCH_RESULTS_HPP
#include <streams_boost/regex/v4/match_results.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_PROTECTED_CALL_HPP
#include <streams_boost/regex/v4/protected_call.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_MATCHER_HPP
#include <streams_boost/regex/v4/perl_matcher.hpp>
#endif
//
// template instances:
//
#define STREAMS_BOOST_REGEX_CHAR_T char
#ifdef STREAMS_BOOST_REGEX_NARROW_INSTANTIATE
#  define STREAMS_BOOST_REGEX_INSTANTIATE
#endif
#include <streams_boost/regex/v4/instances.hpp>
#undef STREAMS_BOOST_REGEX_CHAR_T
#ifdef STREAMS_BOOST_REGEX_INSTANTIATE
#  undef STREAMS_BOOST_REGEX_INSTANTIATE
#endif

#ifndef STREAMS_BOOST_NO_WREGEX
#define STREAMS_BOOST_REGEX_CHAR_T wchar_t
#ifdef STREAMS_BOOST_REGEX_WIDE_INSTANTIATE
#  define STREAMS_BOOST_REGEX_INSTANTIATE
#endif
#include <streams_boost/regex/v4/instances.hpp>
#undef STREAMS_BOOST_REGEX_CHAR_T
#ifdef STREAMS_BOOST_REGEX_INSTANTIATE
#  undef STREAMS_BOOST_REGEX_INSTANTIATE
#endif
#endif

#if !defined(STREAMS_BOOST_NO_WREGEX) && defined(STREAMS_BOOST_REGEX_HAS_OTHER_WCHAR_T)
#define STREAMS_BOOST_REGEX_CHAR_T unsigned short
#ifdef STREAMS_BOOST_REGEX_US_INSTANTIATE
#  define STREAMS_BOOST_REGEX_INSTANTIATE
#endif
#include <streams_boost/regex/v4/instances.hpp>
#undef STREAMS_BOOST_REGEX_CHAR_T
#ifdef STREAMS_BOOST_REGEX_INSTANTIATE
#  undef STREAMS_BOOST_REGEX_INSTANTIATE
#endif
#endif


namespace streams_boost{
#ifdef STREAMS_BOOST_REGEX_NO_FWD
typedef basic_regex<char, regex_traits<char> > regex;
#ifndef STREAMS_BOOST_NO_WREGEX
typedef basic_regex<wchar_t, regex_traits<wchar_t> > wregex;
#endif
#endif

typedef match_results<const char*> cmatch;
typedef match_results<std::string::const_iterator> smatch;
#ifndef STREAMS_BOOST_NO_WREGEX
typedef match_results<const wchar_t*> wcmatch;
typedef match_results<std::wstring::const_iterator> wsmatch;
#endif

} // namespace streams_boost
#ifndef STREAMS_BOOST_REGEX_MATCH_HPP
#include <streams_boost/regex/v4/regex_match.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_REGEX_SEARCH_HPP
#include <streams_boost/regex/v4/regex_search.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_ITERATOR_HPP
#include <streams_boost/regex/v4/regex_iterator.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_TOKEN_ITERATOR_HPP
#include <streams_boost/regex/v4/regex_token_iterator.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_REGEX_GREP_HPP
#include <streams_boost/regex/v4/regex_grep.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_REGEX_REPLACE_HPP
#include <streams_boost/regex/v4/regex_replace.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_V4_REGEX_MERGE_HPP
#include <streams_boost/regex/v4/regex_merge.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_SPLIT_HPP
#include <streams_boost/regex/v4/regex_split.hpp>
#endif

#endif  // __cplusplus

#endif  // include































