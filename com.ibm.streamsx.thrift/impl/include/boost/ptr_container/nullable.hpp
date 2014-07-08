//
// Boost.Pointer Container
//
//  Copyright Thorsten Ottosen 2003-2005. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/ptr_container/
//


#ifndef STREAMS_BOOST_INDIRECT_CONTAINER_NULLABLE_HPP
#define STREAMS_BOOST_INDIRECT_CONTAINER_NULLABLE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <streams_boost/type_traits/detail/yes_no_type.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/config.hpp>

namespace streams_boost
{
    
    template< class T >
    struct nullable
    {
        typedef T type;
    };   

    namespace ptr_container_detail
    {
        template< class T >
        type_traits::yes_type is_nullable( const nullable<T>* );

        type_traits::no_type is_nullable( ... );        
    }

    template< class T >
    struct is_nullable
    {
    private:
            STREAMS_BOOST_STATIC_CONSTANT( T*, var );
    public:

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, >= 1400)  
#pragma warning(push)  
#pragma warning(disable:6334)  
#endif  

            STREAMS_BOOST_STATIC_CONSTANT(bool, value = sizeof( ptr_container_detail::is_nullable( var ) ) 
                                                == sizeof( type_traits::yes_type ) );
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, >= 1400)  
#pragma warning(pop)  
#endif  
            
    };
    
    template< class T >
    struct remove_nullable
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if< is_nullable<T>,
                                                      T,
                                            mpl::identity<T> >::type
            type;
    };

}

#endif
