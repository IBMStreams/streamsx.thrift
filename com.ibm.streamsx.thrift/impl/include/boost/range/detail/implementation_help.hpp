// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_DETAIL_IMPLEMENTATION_HELP_HPP
#define STREAMS_BOOST_RANGE_DETAIL_IMPLEMENTATION_HELP_HPP

#include <streams_boost/range/config.hpp>
#include <streams_boost/range/detail/common.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <cstddef>
#include <string.h>

#ifndef STREAMS_BOOST_NO_CWCHAR
#include <wchar.h>
#endif

namespace streams_boost 
{
    namespace range_detail
    {
        template <typename T>
        inline void streams_boost_range_silence_warning( const T& ) { }
        
        /////////////////////////////////////////////////////////////////////
        // end() help
        /////////////////////////////////////////////////////////////////////

        inline const char* str_end( const char* s, const char* )
        {
            return s + strlen( s );
        }
        
#ifndef STREAMS_BOOST_NO_CWCHAR
        inline const wchar_t* str_end( const wchar_t* s, const wchar_t* )
        {
            return s + wcslen( s );
        }
#else
        inline const wchar_t* str_end( const wchar_t* s, const wchar_t* )
        {
            if( s == 0 || s[0] == 0 )
                return s;
            while( *++s != 0 )
                ;
            return s;
        }
#endif         

        template< class Char >
        inline Char* str_end( Char* s )
        {
            return const_cast<Char*>( str_end( s, s ) );
        }

        template< class T, std::size_t sz >
        inline T* array_end( T STREAMS_BOOST_RANGE_ARRAY_REF()[sz] )
        {
            return streams_boost_range_array + sz;
        }
        
        template< class T, std::size_t sz >
        inline const T* array_end( const T STREAMS_BOOST_RANGE_ARRAY_REF()[sz] )
        {
            return streams_boost_range_array + sz;
        }

        /////////////////////////////////////////////////////////////////////
        // size() help
        /////////////////////////////////////////////////////////////////////
        
        template< class Char >
        inline std::size_t str_size( const Char* const& s )
        {
            return str_end( s ) - s;
        }

        template< class T, std::size_t sz >
        inline std::size_t array_size( T STREAMS_BOOST_RANGE_ARRAY_REF()[sz] )
        {
            streams_boost_range_silence_warning( streams_boost_range_array );
            return sz;
        }

        template< class T, std::size_t sz >
        inline std::size_t array_size( const T STREAMS_BOOST_RANGE_ARRAY_REF()[sz] )
        {
            streams_boost_range_silence_warning( streams_boost_range_array );
            return sz;
        }

    } // namespace 'range_detail'
    
} // namespace 'streams_boost'


#endif
