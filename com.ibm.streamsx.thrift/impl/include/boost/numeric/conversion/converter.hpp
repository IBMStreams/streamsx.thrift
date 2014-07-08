//  (c) Copyright Fernando Luis Cacciola Carballal 2000-2004
//  Use, modification, and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.streams_boost.org/libs/numeric/conversion
//
// Contact the author at: fernando_cacciola@hotmail.com
// 
#ifndef STREAMS_BOOST_NUMERIC_CONVERSION_CONVERTER_FLC_12NOV2002_HPP
#define STREAMS_BOOST_NUMERIC_CONVERSION_CONVERTER_FLC_12NOV2002_HPP

#include "streams_boost/numeric/conversion/conversion_traits.hpp"
#include "streams_boost/numeric/conversion/converter_policies.hpp"

#include "streams_boost/numeric/conversion/detail/converter.hpp"

namespace streams_boost { namespace numeric 
{

template<class T,
         class S,
         class Traits           = conversion_traits<T,S>,
         class OverflowHandler  = def_overflow_handler,
         class Float2IntRounder = Trunc< STREAMS_BOOST_DEDUCED_TYPENAME Traits::source_type>  ,
         class RawConverter     = raw_converter<Traits>,
         class UserRangeChecker = UseInternalRangeChecker
        >
struct converter : convdetail::get_converter_impl<Traits,
                                                  OverflowHandler,
                                                  Float2IntRounder,
                                                  RawConverter,
                                                  UserRangeChecker
                                                 >::type
{
  typedef Traits traits ;

  typedef typename Traits::argument_type argument_type ;
  typedef typename Traits::result_type   result_type   ;

  result_type operator() ( argument_type s ) const { return this->convert(s) ; }
} ;



template<class S,
         class OverflowHandler  = def_overflow_handler,
         class Float2IntRounder = Trunc<S>  ,
         class UserRangeChecker = UseInternalRangeChecker
        >
struct make_converter_from
{
  template<class T,
           class Traits       = conversion_traits<T,S>,
           class RawConverter = raw_converter<Traits>
          > 
  struct to
  {
    typedef converter<T,S,Traits,OverflowHandler,Float2IntRounder,RawConverter,UserRangeChecker> type ;
  } ;

} ;

} } // namespace streams_boost::numeric

#endif


