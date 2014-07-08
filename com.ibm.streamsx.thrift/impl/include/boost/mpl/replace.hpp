
#ifndef STREAMS_BOOST_MPL_REPLACE_HPP_INCLUDED
#define STREAMS_BOOST_MPL_REPLACE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
// Copyright John R. Bandela 2000-2002
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: replace.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/replace_if.hpp>
#include <streams_boost/mpl/same_as.hpp>
#include <streams_boost/mpl/aux_/inserter_algorithm.hpp>

namespace streams_boost { namespace mpl {

namespace aux {

template<
      typename Sequence
    , typename OldType
    , typename NewType
    , typename Inserter 
    >
struct replace_impl
    : replace_if_impl< Sequence, same_as<OldType>, NewType, Inserter >
{
};

template<
      typename Sequence
    , typename OldType
    , typename NewType
    , typename Inserter 
    >
struct reverse_replace_impl
    : reverse_replace_if_impl< Sequence, same_as<OldType>, NewType, Inserter >
{
};

} // namespace aux

STREAMS_BOOST_MPL_AUX_INSERTER_ALGORITHM_DEF(4, replace)

}}

#endif // STREAMS_BOOST_MPL_REPLACE_HPP_INCLUDED
