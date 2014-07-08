///////////////////////////////////////////////////////////////////////////////
// ignore_unused.hpp
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_XPRESSIVE_DETAIL_UTILITY_IGNORE_UNUSED_HPP_EAN_10_04_2005
#define STREAMS_BOOST_XPRESSIVE_DETAIL_UTILITY_IGNORE_UNUSED_HPP_EAN_10_04_2005

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

namespace streams_boost { namespace xpressive { namespace detail
{

    template<typename T>
    void ignore_unused(T const &)
    {
    }

}}}

#endif

