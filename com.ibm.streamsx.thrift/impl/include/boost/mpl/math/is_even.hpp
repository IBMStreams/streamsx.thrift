
#ifndef STREAMS_BOOST_MPL_MATH_IS_EVEN_HPP_INCLUDED
#define STREAMS_BOOST_MPL_MATH_IS_EVEN_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: is_even.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/mpl/aux_/config/msvc.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

namespace streams_boost { namespace mpl {

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)
namespace aux
{
  template <class N>
  struct is_even_base
  {
      enum { value = (N::value % 2) == 0 };
      typedef bool_<value> type;
  };
}
#endif 

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(N)
    >
struct is_even
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)
  : aux::is_even_base<N>::type
#else
  : bool_<((N::value % 2) == 0)>
#endif 
{
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,is_even,(N))
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(1, is_even)

}}

#endif // STREAMS_BOOST_MPL_MATH_IS_EVEN_HPP_INCLUDED
