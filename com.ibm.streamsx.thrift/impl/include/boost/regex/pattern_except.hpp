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
  *   FILE         pattern_except.hpp
  *   VERSION      see <streams_boost/version.hpp>
  *   DESCRIPTION: Declares pattern-matching exception classes.
  */

#ifndef STREAMS_BOOST_RE_PAT_EXCEPT_HPP
#define STREAMS_BOOST_RE_PAT_EXCEPT_HPP

#ifndef STREAMS_BOOST_REGEX_CONFIG_HPP
#include <streams_boost/regex/config.hpp>
#endif

#include <stdexcept>
#include <cstddef>
#include <streams_boost/regex/v4/error_type.hpp>

namespace streams_boost{

#ifdef STREAMS_BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4103)
#endif
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_PREFIX
#endif
#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

#ifdef STREAMS_BOOST_MSVC
#pragma warning(push)
#pragma warning(disable : 4275)
#endif
class STREAMS_BOOST_REGEX_DECL regex_error : public std::runtime_error
{
public:
   explicit regex_error(const std::string& s, regex_constants::error_type err = regex_constants::error_unknown, std::ptrdiff_t pos = 0);
   explicit regex_error(regex_constants::error_type err);
   ~regex_error() throw();
   regex_constants::error_type code()const
   { return m_error_code; }
   std::ptrdiff_t position()const
   { return m_position; }
   void raise()const;
private:
   regex_constants::error_type m_error_code;
   std::ptrdiff_t m_position;
};

typedef regex_error bad_pattern;
typedef regex_error bad_expression;

namespace re_detail{

STREAMS_BOOST_REGEX_DECL void STREAMS_BOOST_REGEX_CALL raise_runtime_error(const std::runtime_error& ex);

template <class traits>
void raise_error(const traits& t, regex_constants::error_type code)
{
   (void)t;  // warning suppression
   std::runtime_error e(t.error_string(code));
   ::streams_boost::re_detail::raise_runtime_error(e);
}

}

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

#ifdef STREAMS_BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4103)
#endif
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_SUFFIX
#endif
#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

} // namespace streams_boost

#endif



