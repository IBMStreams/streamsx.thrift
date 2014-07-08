
#ifndef STREAMS_BOOST_MPL_AUX_PREPROCESSOR_RANGE_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_PREPROCESSOR_RANGE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: range.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/preprocessor/seq/subseq.hpp>

#define STREAMS_BOOST_MPL_PP_RANGE(first, length) \
    STREAMS_BOOST_PP_SEQ_SUBSEQ((0)(1)(2)(3)(4)(5)(6)(7)(8)(9), first, length) \
/**/

#endif // STREAMS_BOOST_MPL_AUX_PREPROCESSOR_RANGE_HPP_INCLUDED
