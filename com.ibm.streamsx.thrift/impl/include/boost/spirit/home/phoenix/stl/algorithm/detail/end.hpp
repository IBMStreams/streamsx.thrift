// Copyright 2005 Daniel Wallin. 
// Copyright 2005 Joel de Guzman.
//
// Use, modification and distribution is subject to the Boost Software 
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// Modeled after range_ex, Copyright 2004 Eric Niebler

#ifndef PHOENIX_ALGORITHM_DETAIL_END_HPP
#define PHOENIX_ALGORITHM_DETAIL_END_HPP

#include <streams_boost/range/result_iterator.hpp>
#include <streams_boost/range/end.hpp>

namespace streams_boost { namespace phoenix {
namespace detail
{ 
  template<class R>
  typename range_result_iterator<R>::type
  end_(R& r)
  {
      return streams_boost::end(r);
  }
}
}}

#endif
