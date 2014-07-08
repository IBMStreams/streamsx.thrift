// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_DETAIL_DIFFERENCE_TYPE_HPP
#define STREAMS_BOOST_RANGE_DETAIL_DIFFERENCE_TYPE_HPP

#include <streams_boost/range/detail/common.hpp>
#include <streams_boost/iterator/iterator_traits.hpp>

//////////////////////////////////////////////////////////////////////////////
// missing partial specialization  workaround.
//////////////////////////////////////////////////////////////////////////////

namespace streams_boost 
{
    namespace range_detail 
    {        
        template< typename T >
        struct range_difference_type_;

        template<>
        struct range_difference_type_<std_container_>
        {
            template< typename C >
            struct pts
            {
                typedef STREAMS_BOOST_DEDUCED_TYPENAME C::difference_type type;
            };
        };

        template<>
        struct range_difference_type_<std_pair_>
        {
            template< typename P >
            struct pts
            {
                typedef STREAMS_BOOST_RANGE_DEDUCED_TYPENAME streams_boost::iterator_difference< STREAMS_BOOST_DEDUCED_TYPENAME P::first_type>::type type;                
            };
        };

        template<>
        struct range_difference_type_<array_>
        {
            template< typename A >
            struct pts
            {
                typedef std::ptrdiff_t type;
            };
        };

        template<>
        struct range_difference_type_<char_array_>
        { 
            template< typename A >
            struct pts
            {
                typedef std::ptrdiff_t type;
            };
        };

        template<>
        struct range_difference_type_<char_ptr_>
        {
            template< typename S >
            struct pts
            {
                typedef std::ptrdiff_t type;
            };         
        };
        
        template<>
        struct range_difference_type_<const_char_ptr_>
        {
            template< typename S >
            struct pts
            {
                typedef std::ptrdiff_t type;
            };         
        };
        
        template<>
        struct range_difference_type_<wchar_t_ptr_>
        {
            template< typename S >
            struct pts
            {
                typedef std::ptrdiff_t type;
            };         
        };
        
        template<>
        struct range_difference_type_<const_wchar_t_ptr_>
        {
            template< typename S >
            struct pts
            {
                typedef std::ptrdiff_t type;
            };         
        };
        
    } 
    
    template< typename C >
    class range_difference
    {
        typedef STREAMS_BOOST_RANGE_DEDUCED_TYPENAME range_detail::range<C>::type c_type;
    public:
        typedef STREAMS_BOOST_RANGE_DEDUCED_TYPENAME range_detail::range_difference_type_<c_type>::STREAMS_BOOST_NESTED_TEMPLATE pts<C>::type type; 
    };

}

#endif

