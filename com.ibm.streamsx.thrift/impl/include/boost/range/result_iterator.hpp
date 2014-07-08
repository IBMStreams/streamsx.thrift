// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_RESULT_ITERATOR_HPP
#define STREAMS_BOOST_RANGE_RESULT_ITERATOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/range/iterator.hpp>

namespace streams_boost
{
    //
    // This interface is deprecated, use range_iterator<T>
    //
    
    template< typename C >
    struct range_result_iterator : range_iterator<C>
    { };
    
} // namespace streams_boost


#endif
