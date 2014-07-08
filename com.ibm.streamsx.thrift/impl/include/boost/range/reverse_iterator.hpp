// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_REVERSE_ITERATOR_HPP
#define STREAMS_BOOST_RANGE_REVERSE_ITERATOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <streams_boost/range/config.hpp>
#include <streams_boost/range/iterator.hpp>
#include <streams_boost/iterator/reverse_iterator.hpp>


namespace streams_boost
{
    //////////////////////////////////////////////////////////////////////////
    // default
    //////////////////////////////////////////////////////////////////////////
    
    template< typename C >
    struct range_reverse_iterator
    {
        typedef reverse_iterator< 
            STREAMS_BOOST_DEDUCED_TYPENAME range_iterator<C>::type > type;
    };
    

} // namespace streams_boost


#endif
