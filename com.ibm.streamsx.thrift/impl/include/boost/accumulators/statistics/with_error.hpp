///////////////////////////////////////////////////////////////////////////////
// with_error.hpp
//
//  Copyright 2005 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_ACCUMULATORS_STATISTICS_WITH_ERROR_HPP_EAN_01_11_2005
#define STREAMS_BOOST_ACCUMULATORS_STATISTICS_WITH_ERROR_HPP_EAN_01_11_2005

#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/mpl/transform_view.hpp>
#include <streams_boost/mpl/placeholders.hpp>
#include <streams_boost/accumulators/statistics_fwd.hpp>
#include <streams_boost/accumulators/statistics/error_of.hpp>

namespace streams_boost { namespace accumulators
{

namespace detail
{
    template<typename Feature>
    struct error_of_tag
    {
        typedef tag::error_of<Feature> type;
    };
}

///////////////////////////////////////////////////////////////////////////////
// with_error
//
template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_ACCUMULATORS_MAX_FEATURES, typename Feature)>
struct with_error
  : mpl::transform_view<
        mpl::vector<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_ACCUMULATORS_MAX_FEATURES, Feature)>
      , detail::error_of_tag<mpl::_1>
    >
{
};

}} // namespace streams_boost::accumulators

#endif
