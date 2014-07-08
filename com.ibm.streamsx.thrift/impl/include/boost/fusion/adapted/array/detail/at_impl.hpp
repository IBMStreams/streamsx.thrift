/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_AT_IMPL_27122005_1241)
#define STREAMS_BOOST_FUSION_AT_IMPL_27122005_1241

#include <streams_boost/type_traits/is_const.hpp>

#include <streams_boost/mpl/if.hpp>

namespace streams_boost { namespace fusion {
    
    struct array_tag;

    namespace extension
    {
        template<typename T>
        struct at_impl;

        template<>
        struct at_impl<array_tag>
        {
            template<typename Sequence, typename N>
            struct apply
            {
                typedef typename mpl::if_<
                    is_const<Sequence>, 
                    typename Sequence::const_reference, 
                    typename Sequence::reference>::type type;

                static type
                call(Sequence& seq)
                {
                    return seq[N::value];
                }
            };
        };
    }
}}

#endif
