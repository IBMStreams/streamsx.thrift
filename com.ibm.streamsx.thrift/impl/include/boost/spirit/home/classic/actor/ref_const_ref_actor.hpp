/*=============================================================================
    Copyright (c) 2003 Jonathan de Halleux (dehalleux@pelikhan.com)
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef STREAMS_BOOST_SPIRIT_ACTOR_REF_CONST_REF_ACTOR_HPP
#define STREAMS_BOOST_SPIRIT_ACTOR_REF_CONST_REF_ACTOR_HPP

#include <streams_boost/spirit/home/classic/namespace.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    ///////////////////////////////////////////////////////////////////////////
    //  Summary:
    //  A semantic action policy holder. This holder stores a reference to ref
    //  and a const reference to value_ref.
    //  act methods are feed with ref and value_ref. The parse result is
    //  not used by this holder.
    //
    //  (This doc uses convention available in actors.hpp)
    //
    //  Constructor:
    //      ...(T& ref_, ValueT const& value_ref_);
    //      where ref_ and value_ref_ are stored in the holder.
    //
    //  Action calls:
    //      act(ref, value_ref);
    //
    //  () operators: both
    //
    ///////////////////////////////////////////////////////////////////////////
    template<
        typename T,
        typename ValueT,
        typename ActionT
    >
    class ref_const_ref_actor : public ActionT
    {
    private:
        T& ref;
        ValueT const& value_ref;
    public:
        ref_const_ref_actor(
            T& ref_,
            ValueT const& value_ref_
            )
        :
            ref(ref_),
            value_ref(value_ref_)
        {}


        template<typename T2>
        void operator()(T2 const& /*val*/) const
        {
            this->act(ref,value_ref); // defined in ActionT
        }


        template<typename IteratorT>
            void operator()(
            IteratorT const& /*first*/,
            IteratorT const& /*last*/
            ) const
        {
            this->act(ref,value_ref); // defined in ActionT
        }
    };

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}}

#endif