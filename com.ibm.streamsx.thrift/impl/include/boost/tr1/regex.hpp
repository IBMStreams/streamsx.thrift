//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TR1_REGEX_HPP_INCLUDED
#  define STREAMS_BOOST_TR1_REGEX_HPP_INCLUDED
#  include <streams_boost/tr1/detail/config.hpp>

#ifdef STREAMS_BOOST_HAS_TR1_REGEX

#  ifdef STREAMS_BOOST_HAS_INCLUDE_NEXT
#     include_next STREAMS_BOOST_TR1_HEADER(regex)
#  else
#     include <streams_boost/tr1/detail/config_all.hpp>
#     include STREAMS_BOOST_TR1_STD_HEADER(STREAMS_BOOST_TR1_PATH(regex))
#  endif

#else

#include <streams_boost/regex.hpp>

namespace std{ namespace tr1{

// [7.5] Regex constants
namespace regex_constants {

using ::streams_boost::regex_constants::syntax_option_type;
using ::streams_boost::regex_constants::icase;
using ::streams_boost::regex_constants::nosubs;
using ::streams_boost::regex_constants::optimize;
using ::streams_boost::regex_constants::collate;
using ::streams_boost::regex_constants::ECMAScript;
using ::streams_boost::regex_constants::basic;
using ::streams_boost::regex_constants::extended;
using ::streams_boost::regex_constants::awk;
using ::streams_boost::regex_constants::grep;
using ::streams_boost::regex_constants::egrep;

using ::streams_boost::regex_constants::match_flag_type;
using ::streams_boost::regex_constants::match_default;
using ::streams_boost::regex_constants::match_not_bol;
using ::streams_boost::regex_constants::match_not_eol;
using ::streams_boost::regex_constants::match_not_bow;
using ::streams_boost::regex_constants::match_not_eow;
using ::streams_boost::regex_constants::match_any;
using ::streams_boost::regex_constants::match_not_null;
using ::streams_boost::regex_constants::match_continuous;
using ::streams_boost::regex_constants::match_prev_avail;
using ::streams_boost::regex_constants::format_default;
using ::streams_boost::regex_constants::format_sed;
using ::streams_boost::regex_constants::format_no_copy;
using ::streams_boost::regex_constants::format_first_only;

using ::streams_boost::regex_constants::error_type;
using ::streams_boost::regex_constants::error_collate;
using ::streams_boost::regex_constants::error_ctype;
using ::streams_boost::regex_constants::error_escape;
using ::streams_boost::regex_constants::error_backref;
using ::streams_boost::regex_constants::error_brack;
using ::streams_boost::regex_constants::error_paren;
using ::streams_boost::regex_constants::error_brace;
using ::streams_boost::regex_constants::error_badbrace;
using ::streams_boost::regex_constants::error_range;
using ::streams_boost::regex_constants::error_space;
using ::streams_boost::regex_constants::error_badrepeat;
using ::streams_boost::regex_constants::error_complexity;
using ::streams_boost::regex_constants::error_stack;

} // namespace regex_constants

// [7.6] Class regex_error
using ::streams_boost::regex_error;

// [7.7] Class template regex_traits
using ::streams_boost::regex_traits;

// [7.8] Class template basic_regex
using ::streams_boost::basic_regex;
using ::streams_boost::regex;
#ifndef STREAMS_BOOST_NO_WREGEX
using ::streams_boost::wregex;
#endif

#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x0582)
// [7.8.6] basic_regex swap
using ::streams_boost::swap;
#endif

// [7.9] Class template sub_match
using ::streams_boost::sub_match;

using ::streams_boost::csub_match;
#ifndef STREAMS_BOOST_NO_WREGEX
using ::streams_boost::wcsub_match;
#endif
using ::streams_boost::ssub_match;
#ifndef STREAMS_BOOST_NO_WREGEX
using ::streams_boost::wssub_match;
#endif

// [7.10] Class template match_results
using ::streams_boost::match_results;
using ::streams_boost::cmatch;
#ifndef STREAMS_BOOST_NO_WREGEX
using ::streams_boost::wcmatch;
#endif
using ::streams_boost::smatch;
#ifndef STREAMS_BOOST_NO_WREGEX
using ::streams_boost::wsmatch;
#endif

using ::streams_boost::regex_match;

// [7.11.3] Function template regex_search
using ::streams_boost::regex_search;

// [7.11.4] Function template regex_replace
using ::streams_boost::regex_replace;

// [7.12.1] Class template regex_iterator
using ::streams_boost::regex_iterator;
using ::streams_boost::cregex_iterator;
#ifndef STREAMS_BOOST_NO_WREGEX
using ::streams_boost::wcregex_iterator;
#endif
using ::streams_boost::sregex_iterator;
#ifndef STREAMS_BOOST_NO_WREGEX
using ::streams_boost::wsregex_iterator;
#endif

// [7.12.2] Class template regex_token_iterator
using ::streams_boost::regex_token_iterator;
using ::streams_boost::cregex_token_iterator;
#ifndef STREAMS_BOOST_NO_WREGEX
using ::streams_boost::wcregex_token_iterator;
#endif
using ::streams_boost::sregex_token_iterator;
#ifndef STREAMS_BOOST_NO_WREGEX
using ::streams_boost::wsregex_token_iterator;
#endif

} } // namespaces

#endif

#endif
