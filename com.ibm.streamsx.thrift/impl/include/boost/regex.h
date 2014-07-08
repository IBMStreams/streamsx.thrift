/*
 *
 * Copyright (c) 1998-2000
 * Dr John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 */
 
 /*
  *   LOCATION:    see http://www.streams_boost.org/libs/regex for documentation.
  *   FILE         regex.h
  *   VERSION      3.12
  *   DESCRIPTION: Declares POSIX API functions
  */

#ifndef STREAMS_BOOST_RE_REGEX_H
#define STREAMS_BOOST_RE_REGEX_H

#include <streams_boost/cregex.hpp>

/*
*  add using declarations to bring POSIX API functions into
* global scope, only if this is C++ (and not C).
*/
#ifdef __cplusplus

using streams_boost::regoff_t;
using streams_boost::regex_tA;
using streams_boost::regmatch_t;
using streams_boost::REG_BASIC;
using streams_boost::REG_EXTENDED;
using streams_boost::REG_ICASE;
using streams_boost::REG_NOSUB;
using streams_boost::REG_NEWLINE;
using streams_boost::REG_NOSPEC;
using streams_boost::REG_PEND;
using streams_boost::REG_DUMP;
using streams_boost::REG_NOCOLLATE;
using streams_boost::REG_ESCAPE_IN_LISTS;
using streams_boost::REG_NEWLINE_ALT;
using streams_boost::REG_PERL;
using streams_boost::REG_AWK;
using streams_boost::REG_GREP;
using streams_boost::REG_EGREP;
using streams_boost::REG_ASSERT;
using streams_boost::REG_INVARG;
using streams_boost::REG_ATOI;
using streams_boost::REG_ITOA;

using streams_boost::REG_NOTBOL;
using streams_boost::REG_NOTEOL;
using streams_boost::REG_STARTEND;

using streams_boost::reg_comp_flags;
using streams_boost::reg_exec_flags;
using streams_boost::regcompA;
using streams_boost::regerrorA;
using streams_boost::regexecA;
using streams_boost::regfreeA;

#ifndef STREAMS_BOOST_NO_WREGEX
using streams_boost::regcompW;
using streams_boost::regerrorW;
using streams_boost::regexecW;
using streams_boost::regfreeW;
using streams_boost::regex_tW;
#endif

using streams_boost::REG_NOERROR;
using streams_boost::REG_NOMATCH;
using streams_boost::REG_BADPAT;
using streams_boost::REG_ECOLLATE;
using streams_boost::REG_ECTYPE;
using streams_boost::REG_EESCAPE;
using streams_boost::REG_ESUBREG;
using streams_boost::REG_EBRACK;
using streams_boost::REG_EPAREN;
using streams_boost::REG_EBRACE;
using streams_boost::REG_BADBR;
using streams_boost::REG_ERANGE;
using streams_boost::REG_ESPACE;
using streams_boost::REG_BADRPT;
using streams_boost::REG_EEND;
using streams_boost::REG_ESIZE;
using streams_boost::REG_ERPAREN;
using streams_boost::REG_EMPTY;
using streams_boost::REG_E_MEMORY;
using streams_boost::REG_E_UNKNOWN;
using streams_boost::reg_errcode_t;

#endif /* __cplusplus */

#endif /* STREAMS_BOOST_RE_REGEX_H */




