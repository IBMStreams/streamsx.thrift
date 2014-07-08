// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_END_HPP
#define STREAMS_BOOST_RANGE_END_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <streams_boost/range/config.hpp>

#ifdef STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING
#include <streams_boost/range/detail/end.hpp>
#else

#include <streams_boost/range/detail/implementation_help.hpp>
#include <streams_boost/range/iterator.hpp>
#include <streams_boost/range/const_iterator.hpp>

namespace streams_boost
{

#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564)) && \
    !STREAMS_BOOST_WORKAROUND(__GNUC__, < 3) \
    /**/
namespace range_detail
{
#endif

        //////////////////////////////////////////////////////////////////////
        // primary template
        //////////////////////////////////////////////////////////////////////
        template< typename C >
        inline STREAMS_BOOST_DEDUCED_TYPENAME range_iterator<C>::type
        range_end( C& c )
        {
            //
            // If you get a compile-error here, it is most likely because
            // you have not implemented range_begin() properly in
            // the namespace of C
            //
            return c.end();
        }

        //////////////////////////////////////////////////////////////////////
        // pair
        //////////////////////////////////////////////////////////////////////

        template< typename Iterator >
        inline Iterator range_end( const std::pair<Iterator,Iterator>& p )
        {
            return p.second;
        }

        template< typename Iterator >
        inline Iterator range_end( std::pair<Iterator,Iterator>& p )
        {
            return p.second;
        }

        //////////////////////////////////////////////////////////////////////
        // array
        //////////////////////////////////////////////////////////////////////

        template< typename T, std::size_t sz >
        inline const T* range_end( const T (&a)[sz] )
        {
            return range_detail::array_end<T,sz>( a );
        }

        template< typename T, std::size_t sz >
        inline T* range_end( T (&a)[sz] )
        {
            return range_detail::array_end<T,sz>( a );
        }

#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564)) && \
    !STREAMS_BOOST_WORKAROUND(__GNUC__, < 3) \
    /**/
} // namespace 'range_detail'
#endif

template< class T >
inline STREAMS_BOOST_DEDUCED_TYPENAME range_iterator<T>::type end( T& r )
{
#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564)) && \
    !STREAMS_BOOST_WORKAROUND(__GNUC__, < 3) \
    /**/
    using namespace range_detail;
#endif
    return range_end( r );
}

template< class T >
inline STREAMS_BOOST_DEDUCED_TYPENAME range_iterator<const T>::type end( const T& r )
{
#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564)) && \
    !STREAMS_BOOST_WORKAROUND(__GNUC__, < 3) \
    /**/
    using namespace range_detail;
#endif
    return range_end( r );
}

} // namespace 'streams_boost'



#endif // STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING


namespace streams_boost
{
    template< class T >
    inline STREAMS_BOOST_DEDUCED_TYPENAME range_iterator<const T>::type
    const_end( const T& r )
    {
        return streams_boost::end( r );
    }
}

#endif

