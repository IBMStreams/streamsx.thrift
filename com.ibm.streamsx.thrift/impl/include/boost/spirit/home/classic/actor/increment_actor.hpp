/*=============================================================================
    Copyright (c) 2003 Jonathan de Halleux (dehalleux@pelikhan.com)
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef STREAMS_BOOST_SPIRIT_ACTOR_INCREMENT_ACTOR_HPP
#define STREAMS_BOOST_SPIRIT_ACTOR_INCREMENT_ACTOR_HPP

#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/actor/ref_actor.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    ///////////////////////////////////////////////////////////////////////////
    //  Summary:
    //  A semantic action policy that calls the ++ operator on a reference.
    //  (This doc uses convention available in actors.hpp)
    //
    //  Actions:
    //      ++ref;
    //
    //  Policy name:
    //      increment_action
    //
    //  Policy holder, corresponding helper method:
    //      ref_actor, increment_a( ref );
    //
    //  () operators: both.
    //
    //  See also ref_actor for more details.
    ///////////////////////////////////////////////////////////////////////////
    struct increment_action
    {
        template<
            typename T
        >
        void act(T& ref_) const
        {
            ++ref_;
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    // helper method that creates a increment_actor.
    ///////////////////////////////////////////////////////////////////////////
    template<typename T>
    inline ref_actor<T,increment_action> increment_a(T& ref_)
    {
        return ref_actor<T,increment_action>(ref_);
    }

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}}

#endif
