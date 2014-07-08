#ifndef STREAMS_BOOST_STATECHART_DEEP_HISTORY_HPP_INCLUDED
#define STREAMS_BOOST_STATECHART_DEEP_HISTORY_HPP_INCLUDED
//////////////////////////////////////////////////////////////////////////////
// Copyright 2002-2006 Andreas Huber Doenni
// Distributed under the Boost Software License, Version 1.0. (See accompany-
// ing file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//////////////////////////////////////////////////////////////////////////////



#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/static_assert.hpp>



namespace streams_boost
{
namespace statechart
{

  
  
//////////////////////////////////////////////////////////////////////////////
template< class DefaultState >
class deep_history
{
  public:
    //////////////////////////////////////////////////////////////////////////
    // If you receive a 
    // "use of undefined type 'streams_boost::STATIC_ASSERTION_FAILURE<x>'" or similar
    // compiler error here then you forgot to pass either
    // statechart::has_deep_history or statechart::has_full_history as the
    // last parameter of DefaultState's context.
    STREAMS_BOOST_STATIC_ASSERT( DefaultState::context_type::deep_history::value );

    //////////////////////////////////////////////////////////////////////////
    // The following declarations should be private.
    // They are only public because many compilers lack template friends.
    //////////////////////////////////////////////////////////////////////////
    typedef typename DefaultState::outermost_context_base_type
      outermost_context_base_type;
    typedef typename DefaultState::context_type context_type;
    typedef typename DefaultState::context_ptr_type context_ptr_type;
    typedef typename DefaultState::context_type_list context_type_list;
    typedef typename DefaultState::orthogonal_position orthogonal_position;

    static void deep_construct(
      const context_ptr_type & pContext,
      outermost_context_base_type & outermostContextBase )
    {
      outermostContextBase.template construct_with_deep_history<
        DefaultState >( pContext );
    }
};



} // namespace statechart
} // namespace streams_boost



#endif
