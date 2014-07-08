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
  *   FILE         regex_fwd.cpp
  *   VERSION      see <streams_boost/version.hpp>
  *   DESCRIPTION: Forward declares streams_boost::basic_regex<> and
  *                associated typedefs.
  */

#ifndef STREAMS_BOOST_REGEX_FWD_HPP_INCLUDED
#define STREAMS_BOOST_REGEX_FWD_HPP_INCLUDED

#ifndef STREAMS_BOOST_REGEX_CONFIG_HPP
#include <streams_boost/regex/config.hpp>
#endif

//
// define STREAMS_BOOST_REGEX_NO_FWD if this
// header doesn't work!
//
#ifdef STREAMS_BOOST_REGEX_NO_FWD
#  ifndef STREAMS_BOOST_RE_REGEX_HPP
#     include <streams_boost/regex.hpp>
#  endif
#else

namespace streams_boost{

template <class charT>
class cpp_regex_traits;
template <class charT>
struct c_regex_traits;
template <class charT>
class w32_regex_traits;

#ifdef STREAMS_BOOST_REGEX_USE_WIN32_LOCALE
template <class charT, class implementationT = w32_regex_traits<charT> >
struct regex_traits;
#elif defined(STREAMS_BOOST_REGEX_USE_CPP_LOCALE)
template <class charT, class implementationT = cpp_regex_traits<charT> >
struct regex_traits;
#else
template <class charT, class implementationT = c_regex_traits<charT> >
struct regex_traits;
#endif

template <class charT, class traits = regex_traits<charT> >
class basic_regex;

typedef basic_regex<char, regex_traits<char> > regex;
#ifndef STREAMS_BOOST_NO_WREGEX
typedef basic_regex<wchar_t, regex_traits<wchar_t> > wregex;
#endif

} // namespace streams_boost

#endif  // STREAMS_BOOST_REGEX_NO_FWD

#endif




