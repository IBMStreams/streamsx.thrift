//  Copyright David Abrahams 2002. 
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_DETAIL_FALSE_RESULT_HPP_INCLUDED
#define STREAMS_BOOST_TT_DETAIL_FALSE_RESULT_HPP_INCLUDED

#include <streams_boost/config.hpp>

namespace streams_boost {
namespace type_traits {

// Utility class which always "returns" false
struct false_result
{
    template <typename T> struct result_
    {
        STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
    };
};

}} // namespace streams_boost::type_traits

#endif // STREAMS_BOOST_TT_DETAIL_FALSE_RESULT_HPP_INCLUDED
