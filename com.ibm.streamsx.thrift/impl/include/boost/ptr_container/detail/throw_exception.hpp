//
// Boost.Pointer Container
//
//  Copyright Thorsten Ottosen 2006. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/ptr_container/
//

#ifndef STREAMS_BOOST_PTR_CONTAINER_DETAIL_THROW_EXCEPTION
#define STREAMS_BOOST_PTR_CONTAINER_DETAIL_THROW_EXCEPTION

#include <streams_boost/assert.hpp>
#include <streams_boost/config.hpp>

#ifdef STREAMS_BOOST_NO_EXCEPTIONS
#define STREAMS_BOOST_PTR_CONTAINER_NO_EXCEPTIONS
#endif

#ifdef STREAMS_BOOST_PTR_CONTAINER_NO_EXCEPTIONS

#define STREAMS_BOOST_PTR_CONTAINER_THROW_EXCEPTION( If, Ex, Msg ) STREAMS_BOOST_ASSERT( !(If) && Msg ) 

#else

#define STREAMS_BOOST_PTR_CONTAINER_THROW_EXCEPTION( If, Ex, Msg ) if( (If) ) throw Ex ( Msg )

#endif // STREAMS_BOOST_PTR_CONTAINER_NO_EXCEPTIONS


#endif
