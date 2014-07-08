#ifndef STREAMS_BOOST_SMART_PTR_DETAIL_SP_CONVERTIBLE_HPP_INCLUDED
#define STREAMS_BOOST_SMART_PTR_DETAIL_SP_CONVERTIBLE_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//  detail/sp_convertible.hpp
//
//  Copyright 2008 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt

#include <streams_boost/config.hpp>

#if !defined( STREAMS_BOOST_SP_NO_SP_CONVERTIBLE ) && defined( STREAMS_BOOST_NO_SFINAE )
# define STREAMS_BOOST_SP_NO_SP_CONVERTIBLE
#endif

#if !defined( STREAMS_BOOST_SP_NO_SP_CONVERTIBLE ) && defined( __GNUC__ ) && ( __GNUC__ * 100 + __GNUC_MINOR__ < 303 )
# define STREAMS_BOOST_SP_NO_SP_CONVERTIBLE
#endif

#if !defined( STREAMS_BOOST_SP_NO_SP_CONVERTIBLE ) && defined( __BORLANDC__ ) && ( __BORLANDC__ <= 0x620 )
# define STREAMS_BOOST_SP_NO_SP_CONVERTIBLE
#endif

#if !defined( STREAMS_BOOST_SP_NO_SP_CONVERTIBLE )

namespace streams_boost
{

namespace detail
{

template< class Y, class T > struct sp_convertible
{
    typedef char (&yes) [1];
    typedef char (&no)  [2];

    static yes f( T* );
    static no  f( ... );

    enum _vt { value = sizeof( f( static_cast<Y*>(0) ) ) == sizeof(yes) };
};

struct sp_empty
{
};

template< bool > struct sp_enable_if_convertible_impl;

template<> struct sp_enable_if_convertible_impl<true>
{
    typedef sp_empty type;
};

template<> struct sp_enable_if_convertible_impl<false>
{
};

template< class Y, class T > struct sp_enable_if_convertible: public sp_enable_if_convertible_impl< sp_convertible< Y, T >::value >
{
};

} // namespace detail

} // namespace streams_boost

#endif // !defined( STREAMS_BOOST_SP_NO_SP_CONVERTIBLE )

#endif  // #ifndef STREAMS_BOOST_SMART_PTR_DETAIL_SP_CONVERTIBLE_HPP_INCLUDED
