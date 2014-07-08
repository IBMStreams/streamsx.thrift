/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_CATEGORY_OF_07212005_1025)
#define FUSION_CATEGORY_OF_07212005_1025

namespace streams_boost { namespace fusion { namespace detail
{
    template <typename T>
    struct fusion_category_of
    {
        typedef typename T::category type;
    };
}}}

#endif