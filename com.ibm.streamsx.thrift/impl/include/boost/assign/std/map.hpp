// Boost.Assign library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/assign/
//


#ifndef STREAMS_BOOST_ASSIGN_STD_MAP_HPP
#define STREAMS_BOOST_ASSIGN_STD_MAP_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/assign/list_inserter.hpp>
#include <streams_boost/config.hpp>
#include <map>

namespace streams_boost
{
namespace assign
{

    template< class K, class V, class C, class A, class P >
    inline list_inserter< assign_detail::call_insert< std::map<K,V,C,A> >, P >
    operator+=( std::map<K,V,C,A>& m, const P& p )
    {
        return insert( m )( p );
    }
    
    template< class K, class V, class C, class A, class P >
    inline list_inserter< assign_detail::call_insert< std::multimap<K,V,C,A> >, P >
    operator+=( std::multimap<K,V,C,A>& m, const P& p )
    {
        return insert( m )( p );
    }

}
}

#endif
