
#ifndef STREAMS_BOOST_MPL_RATIONAL_C_HPP_INCLUDED
#define STREAMS_BOOST_MPL_RATIONAL_C_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: rational_c.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/static_constant.hpp>

namespace streams_boost { namespace mpl {

template<
      typename IntegerType
    , IntegerType N
    , IntegerType D = 1
    >
struct rational_c
{
    STREAMS_BOOST_STATIC_CONSTANT(IntegerType, numerator = N);
    STREAMS_BOOST_STATIC_CONSTANT(IntegerType, denominator = D);
    
    typedef rational_c<IntegerType,N,D> type;
    rational_c() {}
};

}}

#endif // STREAMS_BOOST_MPL_RATIONAL_C_HPP_INCLUDED
