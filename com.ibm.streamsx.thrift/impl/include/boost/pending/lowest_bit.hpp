// -----------------------------------------------------------
// lowest_bit.hpp
//
//           Position of the lowest bit 'on'
//
//         Copyright (c) 2003-2004, 2008 Gennaro Prota
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)
//
// -----------------------------------------------------------

#ifndef STREAMS_BOOST_LOWEST_BIT_HPP_GP_20030301
#define STREAMS_BOOST_LOWEST_BIT_HPP_GP_20030301

#include <assert.h>
#include "streams_boost/pending/integer_log2.hpp"


namespace streams_boost {

    template <typename T>
    int lowest_bit(T x) {

        assert(x >= 1); // PRE

        // clear all bits on except the rightmost one,
        // then calculate the logarithm base 2
        //
        return streams_boost::integer_log2<T>( x - ( x & (x-1) ) );

    }


}


#endif // include guard
