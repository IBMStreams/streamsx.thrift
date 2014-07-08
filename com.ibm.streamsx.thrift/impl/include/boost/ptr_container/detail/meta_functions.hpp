//
// Boost.Pointer Container
//
//  Copyright Thorsten Ottosen 2008. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/ptr_container/
//

#ifndef STREAMS_BOOST_PTR_CONTAINER_DETAIL_META_FUNCTIONS
#define STREAMS_BOOST_PTR_CONTAINER_DETAIL_META_FUNCTIONS

#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/eval_if.hpp>

namespace streams_boost
{
namespace ptr_container_detail
{
    template< class T >
    struct select_value_compare
    {
        typedef typename T::value_compare type;
    };

    template< class T >
    struct select_key_compare
    {
        typedef typename T::key_compare type;
    };

    template< class T >
    struct select_hasher
    {
        typedef typename T::hasher type;
    };

    template< class T >
    struct select_key_equal
    {
        typedef typename T::key_equal type;
    };

    template< class T >
    struct select_iterator
    {
        typedef typename T::iterator type;
    };
    
    template< class T >
    struct select_local_iterator
    {
        typedef typename T::local_iterator type;
    };

    template< class T >
    struct select_const_local_iterator
    {
        typedef typename T::const_local_iterator type;
    };
}
}

#endif
