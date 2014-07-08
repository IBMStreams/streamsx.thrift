/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_TAG_OF_24122005_1722)
#define STREAMS_BOOST_FUSION_TAG_OF_24122005_1722

#include <streams_boost/fusion/support/tag_of_fwd.hpp>

#include <streams_boost/config/no_tr1/utility.hpp>

namespace streams_boost { namespace fusion {

    struct std_pair_tag;
    struct fusion_sequence_tag;

    namespace traits
    {
        template<typename T1, typename T2>
        struct tag_of<std::pair<T1, T2> >
        {
            typedef std_pair_tag type;
        };
    }
}}

namespace streams_boost { namespace mpl
{
    template<typename>
    struct sequence_tag;

    template<typename T1, typename T2>
    struct sequence_tag<std::pair<T1, T2> >
    {
        typedef fusion::fusion_sequence_tag type;
    };

    template<typename T1, typename T2>
    struct sequence_tag<std::pair<T1, T2> const>
    {
        typedef fusion::fusion_sequence_tag type;
    };
}}

#endif
