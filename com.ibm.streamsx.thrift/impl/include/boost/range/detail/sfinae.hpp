// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_DETAIL_SFINAE_HPP
#define STREAMS_BOOST_RANGE_DETAIL_SFINAE_HPP

#include <streams_boost/range/config.hpp>
#include <streams_boost/type_traits/is_array.hpp>
#include <streams_boost/type_traits/detail/yes_no_type.hpp>
#include <utility>


namespace streams_boost 
{
    namespace range_detail
    {          
        using type_traits::yes_type;
        using type_traits::no_type;

        //////////////////////////////////////////////////////////////////////
        // string
        //////////////////////////////////////////////////////////////////////
        
        yes_type is_string_impl( const char* const );
        yes_type is_string_impl( const wchar_t* const );
        no_type  is_string_impl( ... );
        
        template< std::size_t sz >
        yes_type is_char_array_impl( char STREAMS_BOOST_RANGE_ARRAY_REF()[sz] );
        template< std::size_t sz >
        yes_type is_char_array_impl( const char STREAMS_BOOST_RANGE_ARRAY_REF()[sz] );
        no_type  is_char_array_impl( ... );
        
        template< std::size_t sz >
        yes_type is_wchar_t_array_impl( wchar_t STREAMS_BOOST_RANGE_ARRAY_REF()[sz] );
        template< std::size_t sz >
        yes_type is_wchar_t_array_impl( const wchar_t STREAMS_BOOST_RANGE_ARRAY_REF()[sz] );
        no_type  is_wchar_t_array_impl( ... );
                                     
        yes_type is_char_ptr_impl( char* const );
        no_type  is_char_ptr_impl( ... );
        
        yes_type is_const_char_ptr_impl( const char* const );
        no_type  is_const_char_ptr_impl( ... );

        yes_type is_wchar_t_ptr_impl( wchar_t* const );
        no_type  is_wchar_t_ptr_impl( ... );
        
        yes_type is_const_wchar_t_ptr_impl( const wchar_t* const );
        no_type  is_const_wchar_t_ptr_impl( ... );
        
        //////////////////////////////////////////////////////////////////////
        // pair
        //////////////////////////////////////////////////////////////////////

        template< typename Iterator >
        yes_type is_pair_impl( const std::pair<Iterator,Iterator>* );
        no_type  is_pair_impl( ... );

        //////////////////////////////////////////////////////////////////////
        // tags
        //////////////////////////////////////////////////////////////////////

        struct char_or_wchar_t_array_tag {};
        
    } // namespace 'range_detail'
    
} // namespace 'streams_boost'

#endif
