///////////////////////////////////////////////////////////////////////////////
// any_matcher.hpp
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_XPRESSIVE_DETAIL_CORE_MATCHER_ANY_MATCHER_HPP_EAN_10_04_2005
#define STREAMS_BOOST_XPRESSIVE_DETAIL_CORE_MATCHER_ANY_MATCHER_HPP_EAN_10_04_2005

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/xpressive/detail/detail_fwd.hpp>
#include <streams_boost/xpressive/detail/core/quant_style.hpp>
#include <streams_boost/xpressive/detail/core/state.hpp>

namespace streams_boost { namespace xpressive { namespace detail
{

    ///////////////////////////////////////////////////////////////////////////////
    // any_matcher
    //
    struct any_matcher
    {
        STREAMS_BOOST_XPR_QUANT_STYLE(quant_fixed_width, 1, true)

        template<typename BidiIter, typename Next>
        static bool match(match_state<BidiIter> &state, Next const &next)
        {
            if(state.eos())
            {
                return false;
            }

            ++state.cur_;
            if(next.match(state))
            {
                return true;
            }

            --state.cur_;
            return false;
        }
    };

}}}

#endif
