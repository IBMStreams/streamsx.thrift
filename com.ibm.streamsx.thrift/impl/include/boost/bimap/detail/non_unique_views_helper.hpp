// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file detail/non_unique_views_helper.hpp
/// \brief Details for non unique views

#ifndef STREAMS_BOOST_BIMAP_DETAIL_NON_UNIQUE_VIEWS_HELPER_HPP
#define STREAMS_BOOST_BIMAP_DETAIL_NON_UNIQUE_VIEWS_HELPER_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

/*===========================================================================*/
#define STREAMS_BOOST_BIMAP_NON_UNIQUE_VIEW_INSERT_FUNCTIONS                         \
                                                                             \
template <class InputIterator>                                               \
void insert(InputIterator iterBegin, InputIterator iterEnd)                  \
{                                                                            \
    for( ; iterBegin != iterEnd ; ++iterBegin )                              \
    {                                                                        \
        this->base().insert(                                                 \
            this->template functor<                                          \
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_to_base>()(              \
                    STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type(*iterBegin)) ); \
    }                                                                        \
}                                                                            \
                                                                             \
std::pair<STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator, bool> insert(              \
    STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::call_traits<                             \
        STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type >::param_type x)            \
{                                                                            \
    typedef STREAMS_BOOST_DEDUCED_TYPENAME base_::base_type::iterator base_iterator; \
                                                                             \
    std::pair< base_iterator, bool > r(                                      \
        this->base().insert(                                                 \
            this->template functor<                                          \
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_to_base>()(x) )          \
    );                                                                       \
                                                                             \
    return std::pair<typename base_::iterator, bool>(                        \
        this->template functor<                                              \
            STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_from_base>()(r.first),    \
            r.second                                                         \
    );                                                                       \
}                                                                            \
                                                                             \
STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator insert(                               \
    STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator pos,                              \
        STREAMS_BOOST_DEDUCED_TYPENAME ::streams_boost::call_traits<                         \
            STREAMS_BOOST_DEDUCED_TYPENAME base_::value_type >::param_type x)        \
{                                                                            \
    return this->template functor<                                           \
        STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_from_base>()(                 \
            this->base().insert(                                             \
                this->template functor<                                      \
                    STREAMS_BOOST_DEDUCED_TYPENAME base_::iterator_to_base>()(pos),  \
            this->template functor<                                          \
                STREAMS_BOOST_DEDUCED_TYPENAME base_::value_to_base>()(x))           \
    );                                                                       \
}
/*===========================================================================*/

#endif // STREAMS_BOOST_BIMAP_DETAIL_NON_UNIQUE_VIEWS_HELPER_HPP
