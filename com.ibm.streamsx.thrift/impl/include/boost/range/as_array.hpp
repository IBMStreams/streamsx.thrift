// Boost.Range library
//
//  Copyright Thorsten Ottosen 2006. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_AS_ARRAY_HPP
#define STREAMS_BOOST_RANGE_AS_ARRAY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <streams_boost/range/iterator_range.hpp>
#include <streams_boost/range/detail/str_types.hpp>

namespace streams_boost
{

    template< class R >
    inline iterator_range< STREAMS_BOOST_DEDUCED_TYPENAME range_iterator<R>::type > 
    as_array( R& r )
    {
        return streams_boost::make_iterator_range( r );
    }

#ifndef STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING

    template< class Range >
    inline streams_boost::iterator_range< STREAMS_BOOST_DEDUCED_TYPENAME range_iterator<const Range>::type > 
    as_array( const Range& r )
    {
        return streams_boost::make_iterator_range( r );
    }
    
#endif
    
}

#endif

