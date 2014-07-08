///////////////////////////////////////////////////////////////////////////////
/// \file stats.hpp
/// Contains the stats<> template.
///
//  Copyright 2005 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_ACCUMULATORS_STATISTICS_STATS_HPP_EAN_28_10_2005
#define STREAMS_BOOST_ACCUMULATORS_STATISTICS_STATS_HPP_EAN_28_10_2005

#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/accumulators/statistics_fwd.hpp>

namespace streams_boost { namespace accumulators
{

///////////////////////////////////////////////////////////////////////////////
/// An MPL sequence of statistics.
template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_ACCUMULATORS_MAX_FEATURES, typename Stat)>
struct stats
  : mpl::vector<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_ACCUMULATORS_MAX_FEATURES, Stat)>
{
};

}} // namespace streams_boost::accumulators

#endif
