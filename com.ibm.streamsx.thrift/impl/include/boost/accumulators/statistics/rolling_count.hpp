///////////////////////////////////////////////////////////////////////////////
// rolling_count.hpp
//
// Copyright 2008 Eric Niebler. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_ACCUMULATORS_STATISTICS_ROLLING_COUNT_HPP_EAN_26_12_2008
#define STREAMS_BOOST_ACCUMULATORS_STATISTICS_ROLLING_COUNT_HPP_EAN_26_12_2008

#include <streams_boost/mpl/placeholders.hpp>
#include <streams_boost/accumulators/framework/accumulator_base.hpp>
#include <streams_boost/accumulators/framework/extractor.hpp>
#include <streams_boost/accumulators/numeric/functional.hpp>
#include <streams_boost/accumulators/framework/parameters/sample.hpp>
#include <streams_boost/accumulators/framework/depends_on.hpp>
#include <streams_boost/accumulators/statistics_fwd.hpp>
#include <streams_boost/accumulators/statistics/rolling_window.hpp>

namespace streams_boost { namespace accumulators
{

namespace impl
{

    ///////////////////////////////////////////////////////////////////////////////
    // rolling_count_impl
    //    returns the count of elements in the rolling window
    template<typename Sample>
    struct rolling_count_impl
      : accumulator_base
    {
        typedef std::size_t result_type;

        rolling_count_impl(dont_care)
        {}

        template<typename Args>
        result_type result(Args const &args) const
        {
            return static_cast<std::size_t>(rolling_window_plus1(args).size()) - is_rolling_window_plus1_full(args);
        }
    };

} // namespace impl

///////////////////////////////////////////////////////////////////////////////
// tag::rolling_count
//
namespace tag
{
    struct rolling_count
      : depends_on< rolling_window_plus1 >
    {
        /// INTERNAL ONLY
        ///
        typedef accumulators::impl::rolling_count_impl< mpl::_1 > impl;

        #ifdef STREAMS_BOOST_ACCUMULATORS_DOXYGEN_INVOKED
        /// tag::rolling_window::window_size named parameter
        static streams_boost::parameter::keyword<tag::rolling_window_size> const window_size;
        #endif
    };
} // namespace tag

///////////////////////////////////////////////////////////////////////////////
// extract::rolling_count
//
namespace extract
{
    extractor<tag::rolling_count> const rolling_count = {};

    STREAMS_BOOST_ACCUMULATORS_IGNORE_GLOBAL(rolling_count)
}

using extract::rolling_count;

}} // namespace streams_boost::accumulators

#endif
