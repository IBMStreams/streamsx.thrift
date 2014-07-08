// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_REND_HPP
#define STREAMS_BOOST_RANGE_REND_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <streams_boost/range/begin.hpp>
#include <streams_boost/range/reverse_iterator.hpp>

namespace streams_boost
{

#ifdef STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING

template< class C >
inline STREAMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<C>::type
rend( C& c )
{
    return STREAMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<C>::type( streams_boost::begin( c ) );
}

#else

template< class C >
inline STREAMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<C>::type
rend( C& c )
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<C>::type
               iter_type;
    return iter_type( streams_boost::begin( c ) );
}

template< class C >
inline STREAMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<const C>::type
rend( const C& c )
{
    typedef STREAMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<const C>::type
        iter_type;
    return iter_type( streams_boost::begin( c ) );
}

#endif

template< class T >
inline STREAMS_BOOST_DEDUCED_TYPENAME range_reverse_iterator<const T>::type
const_rend( const T& r )
{
    return streams_boost::rend( r );
}

} // namespace 'streams_boost'

#endif

