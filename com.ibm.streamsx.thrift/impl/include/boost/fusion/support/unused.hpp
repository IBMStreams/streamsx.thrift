/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_SUPPORT_UNUSED_20070305_1038)
#define STREAMS_BOOST_FUSION_SUPPORT_UNUSED_20070305_1038

#include <streams_boost/config.hpp>
#if defined(STREAMS_BOOST_MSVC)
# pragma warning(push)
# pragma warning(disable: 4522) // multiple assignment operators specified warning
#endif

#define STREAMS_BOOST_FUSION_UNUSED_HAS_IO

namespace streams_boost { namespace fusion
{
    struct unused_type
    {
        unused_type()
        {
        }

        template <typename T>
        unused_type(T const&)
        {
        }

        template <typename T>
        unused_type const&
        operator=(T const&) const
        {
            return *this;
        }

        template <typename T>
        unused_type&
        operator=(T const&)
        {
            return *this;
        }

        unused_type const&
        operator=(unused_type const&) const
        {
            return *this;
        }

        unused_type&
        operator=(unused_type const&)
        {
            return *this;
        }
    };

    unused_type const unused = unused_type();

    namespace detail
    {
        struct unused_only
        {
            unused_only(unused_type const&) {}
        };
    }

    template <typename Out>
    inline Out& operator<<(Out& out, detail::unused_only const&)
    {
        return out;
    }

    template <typename In>
    inline In& operator>>(In& in, unused_type&)
    {
        return in;
    }
}}

#if defined(STREAMS_BOOST_MSVC)
# pragma warning(pop)
#endif

#endif
