///////////////////////////////////////////////////////////////////////////////
// accumulator_concept.hpp
//
//  Copyright 2005 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_ACCUMULATORS_FRAMEWORK_ACCUMULATOR_CONCEPT_HPP_EAN_28_10_2005
#define STREAMS_BOOST_ACCUMULATORS_FRAMEWORK_ACCUMULATOR_CONCEPT_HPP_EAN_28_10_2005

#include <streams_boost/concept_check.hpp>

namespace streams_boost { namespace accumulators
{

template<typename Stat>
struct accumulator_concept
{
    void constraints()
    {
        // TODO: define the stat concept
    }

    Stat stat;
};

}} // namespace streams_boost::accumulators

#endif
