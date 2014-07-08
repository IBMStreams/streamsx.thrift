/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_RANGE_MAY_16_2006_0720_PM)
#define STREAMS_BOOST_SPIRIT_RANGE_MAY_16_2006_0720_PM

#if defined(_MSC_VER)
#pragma once
#endif

namespace streams_boost { namespace spirit { namespace support { namespace detail
{
    ///////////////////////////////////////////////////////////////////////////
    //  A closed range (first, last)
    ///////////////////////////////////////////////////////////////////////////
    template <typename T>
    struct range
    {
        typedef T value_type;

        range() : first(), last() {}
        range(T first, T last) : first(first), last(last) {}

        T first;
        T last;
    };
}}}}

#endif
