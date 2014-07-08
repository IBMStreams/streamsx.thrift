
#ifndef STREAMS_BOOST_MPL_FOR_EACH_HPP_INCLUDED
#define STREAMS_BOOST_MPL_FOR_EACH_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2008
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: for_each.hpp 55648 2009-08-18 05:16:53Z agurtovoy $
// $Date: 2009-08-18 01:16:53 -0400 (Tue, 18 Aug 2009) $
// $Revision: 55648 $

#include <streams_boost/mpl/is_sequence.hpp>
#include <streams_boost/mpl/begin_end.hpp>
#include <streams_boost/mpl/apply.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/next_prior.hpp>
#include <streams_boost/mpl/deref.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/mpl/aux_/unwrap.hpp>

#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/utility/value_init.hpp>

namespace streams_boost { namespace mpl {

namespace aux {

template< bool done = true >
struct for_each_impl
{
    template<
          typename Iterator
        , typename LastIterator
        , typename TransformFunc
        , typename F
        >
    static void execute(
          Iterator*
        , LastIterator*
        , TransformFunc*
        , F
        )
    {
    }
};

template<>
struct for_each_impl<false>
{
    template<
          typename Iterator
        , typename LastIterator
        , typename TransformFunc
        , typename F
        >
    static void execute(
          Iterator*
        , LastIterator*
        , TransformFunc* 
        , F f
        )
    {
        typedef typename deref<Iterator>::type item;
        typedef typename apply1<TransformFunc,item>::type arg;
    
        // dwa 2002/9/10 -- make sure not to invoke undefined behavior
        // when we pass arg.
        value_initialized<arg> x;
        aux::unwrap(f, 0)(streams_boost::get(x));
        
        typedef typename mpl::next<Iterator>::type iter;
        for_each_impl<streams_boost::is_same<iter,LastIterator>::value>
            ::execute( static_cast<iter*>(0), static_cast<LastIterator*>(0), static_cast<TransformFunc*>(0), f);
    }
};

} // namespace aux

// agurt, 17/mar/02: pointer default parameters are necessary to workaround 
// MSVC 6.5 function template signature's mangling bug
template<
      typename Sequence
    , typename TransformOp
    , typename F
    >
inline
void for_each(F f, Sequence* = 0, TransformOp* = 0)
{
    STREAMS_BOOST_MPL_ASSERT(( is_sequence<Sequence> ));

    typedef typename begin<Sequence>::type first;
    typedef typename end<Sequence>::type last;

    aux::for_each_impl< streams_boost::is_same<first,last>::value >
        ::execute(static_cast<first*>(0), static_cast<last*>(0), static_cast<TransformOp*>(0), f);
}

template<
      typename Sequence
    , typename F
    >
inline
void for_each(F f, Sequence* = 0)
{
    for_each<Sequence, identity<> >(f);
}

}}

#endif // STREAMS_BOOST_MPL_FOR_EACH_HPP_INCLUDED
