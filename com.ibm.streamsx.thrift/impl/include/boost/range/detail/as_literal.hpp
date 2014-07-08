// Boost.Range library
//
//  Copyright Thorsten Ottosen 2006. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_DETAIL_AS_LITERAL_HPP
#define STREAMS_BOOST_RANGE_DETAIL_AS_LITERAL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <streams_boost/range/detail/detail_str.hpp>
#include <streams_boost/range/iterator_range.hpp>

namespace streams_boost
{
    template< class Range >
    inline iterator_range<STREAMS_BOOST_DEDUCED_TYPENAME range_iterator<Range>::type> 
    as_literal( Range& r )
    {
        return ::streams_boost::make_iterator_range( ::streams_boost::range_detail::str_begin(r),
                                             ::streams_boost::range_detail::str_end(r) );
    }

}

#endif
