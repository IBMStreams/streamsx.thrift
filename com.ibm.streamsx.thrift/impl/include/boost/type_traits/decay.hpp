//  (C) Copyright John Maddock & Thorsten Ottosen 2005.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_DECAY_HPP_INCLUDED
#define STREAMS_BOOST_TT_DECAY_HPP_INCLUDED

#include <streams_boost/type_traits/config.hpp>
#include <streams_boost/type_traits/is_array.hpp>
#include <streams_boost/type_traits/is_function.hpp>
#include <streams_boost/type_traits/remove_bounds.hpp>
#include <streams_boost/type_traits/add_pointer.hpp>
#include <streams_boost/type_traits/remove_reference.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/identity.hpp>

namespace streams_boost 
{

    template< class T >
    struct decay
    {
    private:
        typedef STREAMS_BOOST_DEDUCED_TYPENAME remove_reference<T>::type Ty;
    public:
        typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if< 
            is_array<Ty>,
            mpl::identity<STREAMS_BOOST_DEDUCED_TYPENAME remove_bounds<Ty>::type*>,
            STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if< 
                is_function<Ty>,
                add_pointer<Ty>,
                mpl::identity<Ty>
            >
        >::type type;
    };
    
} // namespace streams_boost


#endif // STREAMS_BOOST_TT_DECAY_HPP_INCLUDED
