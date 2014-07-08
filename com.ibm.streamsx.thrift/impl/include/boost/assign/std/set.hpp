// Boost.Assign library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/assign/
//


#ifndef STREAMS_BOOST_ASSIGN_STD_SET_HPP
#define STREAMS_BOOST_ASSIGN_STD_SET_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/assign/list_inserter.hpp>
#include <streams_boost/config.hpp>
#include <set>

namespace streams_boost
{
namespace assign
{
    template< class K, class C, class A, class K2 >
    inline list_inserter< assign_detail::call_insert< std::set<K,C,A> >, K > 
    operator+=( std::set<K,C,A>& c, K2 k )
    {
        return insert( c )( k );
    }
    
    template< class K, class C, class A, class K2 >
    inline list_inserter< assign_detail::call_insert< std::multiset<K,C,A> >, K > 
    operator+=( std::multiset<K,C,A>& c, K2 k )
    {
        return insert( c )( k );
    }
    
}
}

#endif