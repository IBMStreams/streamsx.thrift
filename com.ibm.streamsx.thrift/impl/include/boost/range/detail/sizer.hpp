// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_DETAIL_SIZER_HPP
#define STREAMS_BOOST_RANGE_DETAIL_SIZER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/range/config.hpp>
#include <cstddef>

namespace streams_boost 
{
    //////////////////////////////////////////////////////////////////////
    // constant array size
    //////////////////////////////////////////////////////////////////////
    
    template< typename T, std::size_t sz >
    char (& sizer( const T STREAMS_BOOST_RANGE_ARRAY_REF()[sz] ) )[sz];
    
    template< typename T, std::size_t sz >
    char (& sizer( T STREAMS_BOOST_RANGE_ARRAY_REF()[sz] ) )[sz];

} // namespace 'streams_boost'

#endif
