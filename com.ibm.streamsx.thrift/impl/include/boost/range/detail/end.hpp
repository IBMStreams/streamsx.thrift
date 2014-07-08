// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_DETAIL_END_HPP
#define STREAMS_BOOST_RANGE_DETAIL_END_HPP

#include <streams_boost/config.hpp> // STREAMS_BOOST_MSVC
#include <streams_boost/detail/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
# include <streams_boost/range/detail/vc6/end.hpp>
#else
# include <streams_boost/range/detail/implementation_help.hpp>
# include <streams_boost/range/iterator.hpp>
# include <streams_boost/range/detail/common.hpp>
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1310)
#  include <streams_boost/range/detail/remove_extent.hpp>
# endif

namespace streams_boost 
{
    namespace range_detail
    {
        template< typename T >
        struct range_end;

        //////////////////////////////////////////////////////////////////////
        // default
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct range_end<std_container_>
        {
            template< typename C >
            static STREAMS_BOOST_RANGE_DEDUCED_TYPENAME range_iterator<C>::type 
            fun( C& c )
            {
                return c.end();
            };
        };
                    
        //////////////////////////////////////////////////////////////////////
        // pair
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct range_end<std_pair_>
        {
            template< typename P >
            static STREAMS_BOOST_RANGE_DEDUCED_TYPENAME range_iterator<P>::type 
            fun( const P& p )
            {
                return p.second;
            }
        };
 
        //////////////////////////////////////////////////////////////////////
        // array
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct range_end<array_>  
        {
        #if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1310)
            template< typename T, std::size_t sz >
            static T* fun( T STREAMS_BOOST_RANGE_ARRAY_REF()[sz] )
            {
                return streams_boost::range_detail::array_end( streams_boost_range_array );
            }
        #else
            template<typename T>
            static STREAMS_BOOST_RANGE_DEDUCED_TYPENAME remove_extent<T>::type* fun(T& t)
            {
                return t + remove_extent<T>::size;
            }
        #endif
        };
        
    } // namespace 'range_detail'
    
    template< typename C >
    inline STREAMS_BOOST_RANGE_DEDUCED_TYPENAME range_iterator<C>::type 
    end( C& c )
    {
        return range_detail::range_end< STREAMS_BOOST_RANGE_DEDUCED_TYPENAME range_detail::range<C>::type >::fun( c );
    }
    
} // namespace 'streams_boost'

# endif // VC6
#endif
