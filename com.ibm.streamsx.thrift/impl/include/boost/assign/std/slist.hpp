// Boost.Assign library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/assign/
//

#ifndef STREAMS_BOOST_ASSIGN_STD_SLIST_HPP
#define STREAMS_BOOST_ASSIGN_STD_SLIST_HPP

#include <streams_boost/config.hpp>
#ifdef STREAMS_BOOST_HAS_SLIST

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/assign/list_inserter.hpp>
#ifdef STREAMS_BOOST_SLIST_HEADER
# include STREAMS_BOOST_SLIST_HEADER
#else
# include <slist>
#endif

namespace streams_boost
{
namespace assign
{

    template< class V, class A, class V2 >
    inline list_inserter< assign_detail::call_push_back< STREAMS_BOOST_STD_EXTENSION_NAMESPACE::slist<V,A> >, V >
    operator+=( STREAMS_BOOST_STD_EXTENSION_NAMESPACE::slist<V,A>& c, V2 v )
    {
        return push_back( c )( v );
    }
    
}
}

#endif // STREAMS_BOOST_HAS_SLIST

#endif 
