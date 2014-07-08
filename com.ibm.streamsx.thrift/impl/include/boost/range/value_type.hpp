// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_VALUE_TYPE_HPP
#define STREAMS_BOOST_RANGE_VALUE_TYPE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <streams_boost/range/config.hpp>
#include <streams_boost/range/iterator.hpp>

//#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
//#include <streams_boost/range/detail/value_type.hpp>
//#else

#include <streams_boost/iterator/iterator_traits.hpp>

namespace streams_boost
{
    template< class T >
    struct range_value : iterator_value< typename range_iterator<T>::type >
    { };
}

#endif