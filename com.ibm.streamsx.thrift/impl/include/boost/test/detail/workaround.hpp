//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 54633 $
//
//  Description : contains mics. workarounds 
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_WORKAROUND_HPP_021005GER
#define STREAMS_BOOST_TEST_WORKAROUND_HPP_021005GER

// Boost
#include <streams_boost/config.hpp> // compilers workarounds and std::ptrdiff_t

// STL
#include <iterator>     // for std::distance

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace streams_boost {

namespace unit_test {

namespace ut_detail {

#ifdef STREAMS_BOOST_NO_STD_DISTANCE
template <class T>
std::ptrdiff_t distance( T const& x_, T const& y_ )
{ 
    std::ptrdiff_t res = 0;

    std::distance( x_, y_, res );

    return res;
}

//____________________________________________________________________________//

#else
using std::distance;
#endif

template <class T> inline void ignore_unused_variable_warning(const T&) {}

} // namespace ut_detail

} // namespace unit_test

namespace unit_test_framework = unit_test;

} // namespace streams_boost

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_WORKAROUND_HPP_021005GER
