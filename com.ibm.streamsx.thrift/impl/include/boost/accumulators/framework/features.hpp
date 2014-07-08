///////////////////////////////////////////////////////////////////////////////
// features.hpp
//
//  Copyright 2005 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_ACCUMULATORS_STATISTICS_STATS_HPP_EAN_08_12_2005
#define STREAMS_BOOST_ACCUMULATORS_STATISTICS_STATS_HPP_EAN_08_12_2005

#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/accumulators/accumulators_fwd.hpp>

namespace streams_boost { namespace accumulators
{

///////////////////////////////////////////////////////////////////////////////
// features
//
template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_ACCUMULATORS_MAX_FEATURES, typename Feature)>
struct features
  : mpl::vector<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_ACCUMULATORS_MAX_FEATURES, Feature)>
{
};

}} // namespace streams_boost::accumulators

#endif
