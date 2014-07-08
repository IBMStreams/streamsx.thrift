//  (C) Copyright Gennadiy Rozental 2004-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 49312 $
//
//  Description : basic_cstring class wrap C string and provide std_string like 
//                interface
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_BASIC_CSTRING_FWD_HPP_071894GER
#define STREAMS_BOOST_TEST_BASIC_CSTRING_FWD_HPP_071894GER

#include <streams_boost/detail/workaround.hpp>

namespace streams_boost {

namespace unit_test {

template<typename CharT> class      basic_cstring;
typedef basic_cstring<char const>   const_string;
#if STREAMS_BOOST_WORKAROUND(__DECCXX_VER, STREAMS_BOOST_TESTED_AT(60590041))
typedef const_string                literal_string;
#else
typedef const_string const          literal_string;
#endif

typedef char const* const           c_literal_string;

} // namespace unit_test

} // namespace streams_boost

#endif // STREAMS_BOOST_TEST_BASIC_CSTRING_FWD_HPP_071894GER

