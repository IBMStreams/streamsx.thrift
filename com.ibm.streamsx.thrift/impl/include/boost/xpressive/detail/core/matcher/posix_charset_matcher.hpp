///////////////////////////////////////////////////////////////////////////////
// posix_charset_matcher.hpp
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_XPRESSIVE_DETAIL_CORE_MATCHER_POSIX_CHARSET_MATCHER_STREAMS_HPP_EAN_10_04_2005
#define STREAMS_BOOST_XPRESSIVE_DETAIL_CORE_MATCHER_POSIX_CHARSET_MATCHER_STREAMS_HPP_EAN_10_04_2005

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/assert.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/xpressive/detail/detail_fwd.hpp>
#include <streams_boost/xpressive/detail/core/quant_style.hpp>
#include <streams_boost/xpressive/detail/core/state.hpp>
#include <streams_boost/xpressive/detail/utility/traits_utils.hpp>

namespace streams_boost { namespace xpressive { namespace detail
{

    ///////////////////////////////////////////////////////////////////////////////
    // posix_charset_matcher
    //
    template<typename Traits>
    struct posix_charset_matcher
      : quant_style_fixed_width<1>
    {
        typedef Traits traits_type;
        typedef typename Traits::char_class_type char_class_type;

        posix_charset_matcher(char_class_type m, bool no)
          : not_(no)
          , mask_(m)
        {
            STREAMS_BOOST_ASSERT(0 != this->mask_);
        }

        void inverse()
        {
            this->not_ = !this->not_;
        }

        template<typename BidiIter, typename Next>
        bool match(match_state<BidiIter> &state, Next const &next) const
        {
            if(state.eos() || this->not_ == traits_cast<Traits>(state).isctype(
                *state.cur_, this->mask_))
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

        bool not_;
        char_class_type mask_;
    };

}}}

#endif
