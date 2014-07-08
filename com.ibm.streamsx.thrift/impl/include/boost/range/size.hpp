// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_SIZE_HPP
#define STREAMS_BOOST_RANGE_SIZE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <streams_boost/range/begin.hpp>
#include <streams_boost/range/end.hpp>
#include <streams_boost/range/difference_type.hpp>
#include <streams_boost/assert.hpp>

namespace streams_boost 
{

    template< class T >
    inline STREAMS_BOOST_DEDUCED_TYPENAME range_difference<T>::type size( const T& r )
    {
        STREAMS_BOOST_ASSERT( (streams_boost::end( r ) - streams_boost::begin( r )) >= 0 &&
                      "reachability invariant broken!" );
        return streams_boost::end( r ) - streams_boost::begin( r );
    }

} // namespace 'streams_boost'

#endif
