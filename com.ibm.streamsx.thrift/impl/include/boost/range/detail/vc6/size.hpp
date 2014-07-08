// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//


#ifndef STREAMS_BOOST_RANGE_DETAIL_VC6_SIZE_HPP
#define STREAMS_BOOST_RANGE_DETAIL_VC6_SIZE_HPP

#include <streams_boost/range/detail/implementation_help.hpp>
#include <streams_boost/range/detail/size_type.hpp>
#include <streams_boost/range/detail/common.hpp>
#include <streams_boost/range/detail/remove_extent.hpp>
#include <iterator>

namespace streams_boost 
{
    namespace range_detail
    {
        template< typename T >
        struct range_size_;

        //////////////////////////////////////////////////////////////////////
        // default
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct range_size_<std_container_>
        {
            template< typename C >
            struct inner {
                static STREAMS_BOOST_RANGE_DEDUCED_TYPENAME C::size_type fun( const C& c )
                {
                    return c.size();
                };
            };
        };
                    
        //////////////////////////////////////////////////////////////////////
        // pair
        //////////////////////////////////////////////////////////////////////
        
        template<>
        struct range_size_<std_pair_>
        {
            template< typename P >
            struct inner {
                static STREAMS_BOOST_RANGE_DEDUCED_TYPENAME range_size<P>::type 
                fun( const P& p )
                {
                    return std::distance( p.first, p.second );
                }
            };
        };
 
        //////////////////////////////////////////////////////////////////////
        // array
        //////////////////////////////////////////////////////////////////////

        template<>
        struct range_size_<array_>
        {
            template<typename T>
            struct inner {
                static std::size_t fun(T& t)
                {
                    return remove_extent<T>::size;
                }
            };
        };
        
        template<>
        struct range_size_<char_array_>
        {
            template<typename T>
            struct inner {
                static std::size_t fun(T& t)
                {
                    return sizeof(T) / sizeof(T[0]);
                }
            };
        };
        
        template<>
        struct range_size_<wchar_t_array_>
        {
            template<typename T>
            struct inner {
                static std::size_t fun(T& t)
                {
                    return sizeof(T) / sizeof(T[0]);
                }
            };
        };

        //////////////////////////////////////////////////////////////////////
        // string
        //////////////////////////////////////////////////////////////////////

        template<>
        struct range_size_<char_ptr_>
        {
            template<typename T>
            struct inner {
                static std::size_t fun( const char* s )
                {
                    return streams_boost::range_detail::str_size( s );
                }
            };
        };

        template<>
        struct range_size_<const_char_ptr_>
        {
            template<typename T>
            struct inner {
                static std::size_t fun( const char* s )
                {
                    return streams_boost::range_detail::str_size( s );
                }
            };
        };
        
        template<>
        struct range_size_<wchar_t_ptr_>
        {
            template<typename T>
            struct inner {
                static std::size_t fun( const wchar_t* s )
                {
                    return streams_boost::range_detail::str_size( s );
                }
            };
        };

        template<>
        struct range_size_<const_wchar_t_ptr_>
        {
            template<typename T>
            struct inner {
                static std::size_t fun( const wchar_t* s )
                {
                    return streams_boost::range_detail::str_size( s );
                }
            };
        };
  
    } // namespace 'range_detail'
    

    template< typename C >
    STREAMS_BOOST_RANGE_DEDUCED_TYPENAME range_size<C>::type 
    size( const C& c )
    {
        return range_detail::range_size_<range_detail::range<C>::type>::inner<C>::fun( c );
    }
    
} // namespace 'streams_boost'


#endif
