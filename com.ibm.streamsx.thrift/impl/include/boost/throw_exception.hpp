#ifndef STREAMS_BOOST_THROW_EXCEPTION_HPP_INCLUDED
#define STREAMS_BOOST_THROW_EXCEPTION_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  streams_boost/throw_exception.hpp
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//  Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  http://www.streams_boost.org/libs/utility/throw_exception.html
//

#include <streams_boost/exception/detail/attribute_noreturn.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/config.hpp>
#include <exception>

#if !defined( STREAMS_BOOST_EXCEPTION_DISABLE ) && defined( __BORLANDC__ ) && STREAMS_BOOST_WORKAROUND( __BORLANDC__, STREAMS_BOOST_TESTED_AT(0x593) )
# define STREAMS_BOOST_EXCEPTION_DISABLE
#endif

#if !defined( STREAMS_BOOST_EXCEPTION_DISABLE ) && defined( STREAMS_BOOST_MSVC ) && STREAMS_BOOST_WORKAROUND( STREAMS_BOOST_MSVC, < 1310 )
# define STREAMS_BOOST_EXCEPTION_DISABLE
#endif

#if !defined( STREAMS_BOOST_EXCEPTION_DISABLE )
# include <streams_boost/exception/exception.hpp>
# include <streams_boost/current_function.hpp>
# define STREAMS_BOOST_THROW_EXCEPTION(x) ::streams_boost::throw_exception(::streams_boost::enable_error_info(x) <<\
    ::streams_boost::throw_function(STREAMS_BOOST_CURRENT_FUNCTION) <<\
    ::streams_boost::throw_file(__FILE__) <<\
    ::streams_boost::throw_line(__LINE__))
#else
# define STREAMS_BOOST_THROW_EXCEPTION(x) ::streams_boost::throw_exception(x)
#endif

namespace streams_boost
{

#ifdef STREAMS_BOOST_NO_EXCEPTIONS

void throw_exception( std::exception const & e ); // user defined

#else

inline void throw_exception_assert_compatibility( std::exception const & ) { }

template<class E> STREAMS_BOOST_ATTRIBUTE_NORETURN inline void throw_exception( E const & e )
{
    //All streams_boost exceptions are required to derive from std::exception,
    //to ensure compatibility with STREAMS_BOOST_NO_EXCEPTIONS.
    throw_exception_assert_compatibility(e);

#ifndef STREAMS_BOOST_EXCEPTION_DISABLE
    throw enable_current_exception(enable_error_info(e));
#else
    throw e;
#endif
}

#endif

} // namespace streams_boost

#endif // #ifndef STREAMS_BOOST_THROW_EXCEPTION_HPP_INCLUDED
