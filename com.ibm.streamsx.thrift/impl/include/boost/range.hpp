// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_HPP_27_07_04
#define STREAMS_BOOST_RANGE_HPP_27_07_04

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#if _MSC_VER == 1300 // experiment

#include <streams_boost/range/detail/collection_traits.hpp>
#include <streams_boost/range/iterator_range.hpp>
#include <streams_boost/range/sub_range.hpp>

#else

#include <streams_boost/range/functions.hpp>
#include <streams_boost/range/metafunctions.hpp>
#include <streams_boost/range/iterator_range.hpp>
#include <streams_boost/range/sub_range.hpp>

#endif // _MSC_VER == 1300 // experiment

#endif
