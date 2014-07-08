/*=============================================================================
    Copyright (c) 2007 Tobias Schwinger

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_SEQUENCE_EMPTY_IMPL_HPP_INCLUDED)
#define STREAMS_BOOST_FUSION_SEQUENCE_EMPTY_IMPL_HPP_INCLUDED

#include <streams_boost/type_traits/is_convertible.hpp>

namespace streams_boost { namespace fusion
{
    struct cons_tag;

    struct nil;

    template <typename Car, typename Cdr>
    struct cons;

    namespace extension
    {
        template <typename Tag>
        struct empty_impl;

        template <>
        struct empty_impl<cons_tag>
        {
            template <typename Sequence>
            struct apply
                : streams_boost::is_convertible<Sequence, nil>
            {};
        };
    }
}}

#endif
