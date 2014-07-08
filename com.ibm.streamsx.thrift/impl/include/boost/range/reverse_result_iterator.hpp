// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_REVERSE_RESULT_ITERATOR_HPP
#define STREAMS_BOOST_RANGE_REVERSE_RESULT_ITERATOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/range/reverse_iterator.hpp>

namespace streams_boost
{
    //
    // This interface is deprecated, use range_reverse_iterator<T>
    //
   
    template< typename C >
    struct range_reverse_result_iterator : range_reverse_iterator<C>
    { };
    
} // namespace streams_boost

#endif
