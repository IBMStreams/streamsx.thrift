// Boost.Assign library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/assign/
//


#ifndef STREAMS_BOOST_ASSIGN_STD_LIST_HPP
#define STREAMS_BOOST_ASSIGN_STD_LIST_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/assign/list_inserter.hpp>
#include <streams_boost/config.hpp>
#include <list>

namespace streams_boost
{
namespace assign
{

    template< class V, class A, class V2 >
    inline list_inserter< assign_detail::call_push_back< std::list<V,A> >, V >
    operator+=( std::list<V,A>& c, V2 v )
    {
        return push_back( c )( v );
    }
    
}
}

#endif
