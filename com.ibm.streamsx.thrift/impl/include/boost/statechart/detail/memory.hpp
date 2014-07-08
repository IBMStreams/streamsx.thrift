#ifndef STREAMS_BOOST_STATECHART_DETAIL_MEMORY_HPP_INCLUDED
#define STREAMS_BOOST_STATECHART_DETAIL_MEMORY_HPP_INCLUDED
//////////////////////////////////////////////////////////////////////////////
// Copyright 2005-2006 Andreas Huber Doenni
// Distributed under the Boost Software License, Version 1.0. (See accompany-
// ing file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//////////////////////////////////////////////////////////////////////////////



#include <streams_boost/statechart/detail/avoid_unused_warning.hpp>

#include <streams_boost/assert.hpp>
#include <streams_boost/detail/allocator_utilities.hpp>

#include <cstddef> // std::size_t



namespace streams_boost
{
namespace statechart
{
namespace detail
{



template< class MostDerived, class Allocator >
void * allocate( std::size_t size )
{
  avoid_unused_warning( size );
  // The assert below fails when memory is allocated for an event<>,
  // simple_state<> or state<> subtype object, *and* the first template
  // parameter passed to one of these templates is not equal to the most-
  // derived object being constructed.
  // The following examples apply to all these subtypes:
  // // Example 1
  // struct A {};
  // struct B : sc::simple_state< A, /* ... */ >
  // // Above, the first template parameter must be equal to the most-
  // // derived type
  // 
  // // Example 2
  // struct A : sc::event< A >
  // struct B : A { /* ... */ };
  // void f() { delete new B(); }
  // // Above the most-derived type being constructed is B, but A was passed
  // // as the most-derived type to event<>.
  STREAMS_BOOST_ASSERT( size == sizeof( MostDerived ) );
  return typename streams_boost::detail::allocator::rebind_to<
    Allocator, MostDerived
  >::type().allocate( 1, static_cast< MostDerived * >( 0 ) );
}

template< class MostDerived, class Allocator >
void deallocate( void * pObject )
{
  return typename streams_boost::detail::allocator::rebind_to<
    Allocator, MostDerived
  >::type().deallocate( static_cast< MostDerived * >( pObject ), 1 );
}



} // namespace detail
} // namespace statechart
} // namespace streams_boost



#endif
