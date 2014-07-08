/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined (STREAMS_BOOST_FUSION_PAIR_TIE_20060812_2058)
#define STREAMS_BOOST_FUSION_PAIR_TIE_20060812_2058

#include <streams_boost/type_traits/is_const.hpp>
#include <streams_boost/utility/enable_if.hpp>

namespace streams_boost { namespace fusion {

    template<typename Key, typename T>
    struct pair;

    namespace result_of
    {
        template<typename Key, typename T>
        struct pair_tie
        {
            typedef fusion::pair<Key, T&> type;
        };
    }

    template<typename Key, typename T>
    typename disable_if<is_const<T>, typename result_of::pair_tie<Key, T>::type>::type
    pair_tie(T& t)
    {
        return typename result_of::pair_tie<Key, T>::type(t);
    }

    template<typename Key, typename T>
    typename result_of::pair_tie<Key, T const>::type
    pair_tie(T const& t)
    {
        return typename result_of::pair_tie<Key, T const>::type(t);
    }
}}

#endif
