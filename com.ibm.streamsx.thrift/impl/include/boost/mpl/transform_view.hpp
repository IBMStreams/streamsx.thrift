
#ifndef STREAMS_BOOST_MPL_TRANSFORM_VIEW_HPP_INCLUDED
#define STREAMS_BOOST_MPL_TRANSFORM_VIEW_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: transform_view.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/begin_end.hpp>
#include <streams_boost/mpl/lambda.hpp>
#include <streams_boost/mpl/aux_/transform_iter.hpp>
#include <streams_boost/mpl/aux_/na_spec.hpp>

namespace streams_boost { namespace mpl {

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(F)
    >
struct transform_view
{
 private:
    typedef typename lambda<F>::type f_;
    typedef typename begin<Sequence>::type first_;
    typedef typename end<Sequence>::type last_;
 
 public:
    struct tag;
    typedef transform_view type;
    typedef aux::transform_iter< first_,last_,f_ > begin;
    typedef aux::transform_iter< last_,last_,f_ > end;
};

STREAMS_BOOST_MPL_AUX_NA_SPEC(2, transform_view)

}}

#endif // STREAMS_BOOST_MPL_TRANSFORM_VIEW_HPP_INCLUDED
