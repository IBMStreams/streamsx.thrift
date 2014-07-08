///////////////////////////////////////////////////////////////////////////////
// rolling_sum.hpp
//
// Copyright 2008 Eric Niebler. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_ACCUMULATORS_STATISTICS_ROLLING_SUM_HPP_EAN_26_12_2008
#define STREAMS_BOOST_ACCUMULATORS_STATISTICS_ROLLING_SUM_HPP_EAN_26_12_2008

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
    // rolling_sum_impl
    //    returns the sum of the samples in the rolling window
    template<typename Sample>
    struct rolling_sum_impl
      : accumulator_base
    {
        typedef Sample result_type;

        template<typename Args>
        rolling_sum_impl(Args const &args)
          : sum_(args[sample | Sample()])
        {}

        template<typename Args>
        void operator ()(Args const &args)
        {
            if(is_rolling_window_plus1_full(args))
            {
                this->sum_ -= rolling_window_plus1(args).front();
            }
            this->sum_ += args[sample];
        }

        template<typename Args>
        result_type result(Args const &args) const
        {
            return this->sum_;
        }

    private:
        Sample sum_;
    };
} // namespace impl

///////////////////////////////////////////////////////////////////////////////
// tag::rolling_sum
//
namespace tag
{
    struct rolling_sum
      : depends_on< rolling_window_plus1 >
    {
        /// INTERNAL ONLY
        ///
        typedef accumulators::impl::rolling_sum_impl< mpl::_1 > impl;

        #ifdef STREAMS_BOOST_ACCUMULATORS_DOXYGEN_INVOKED
        /// tag::rolling_window::window_size named parameter
        static streams_boost::parameter::keyword<tag::rolling_window_size> const window_size;
        #endif
    };
} // namespace tag

///////////////////////////////////////////////////////////////////////////////
// extract::rolling_sum
//
namespace extract
{
    extractor<tag::rolling_sum> const rolling_sum = {};

    STREAMS_BOOST_ACCUMULATORS_IGNORE_GLOBAL(rolling_sum)
}

using extract::rolling_sum;

}} // namespace streams_boost::accumulators

#endif
