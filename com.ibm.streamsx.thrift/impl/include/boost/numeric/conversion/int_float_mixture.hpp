//  (c) Copyright Fernando Luis Cacciola Carballal 2000-2004
//  Use, modification, and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.streams_boost.org/libs/numeric/conversion
//
// Contact the author at: fernando_cacciola@hotmail.com
// 
#ifndef STREAMS_BOOST_NUMERIC_CONVERSION_INT_FLOAT_MIXTURE_FLC_12NOV2002_HPP
#define STREAMS_BOOST_NUMERIC_CONVERSION_INT_FLOAT_MIXTURE_FLC_12NOV2002_HPP

#include "streams_boost/numeric/conversion/detail/int_float_mixture.hpp"

namespace streams_boost { namespace numeric
{

template<class T, class S>
struct int_float_mixture
  : convdetail::get_int_float_mixture<  STREAMS_BOOST_DEDUCED_TYPENAME remove_cv<T>::type
                                       ,STREAMS_BOOST_DEDUCED_TYPENAME remove_cv<S>::type
                                     >::type {} ;

} } // namespace streams_boost::numeric

#endif
//
///////////////////////////////////////////////////////////////////////////////////////////////


