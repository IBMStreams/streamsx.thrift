/*=============================================================================
    Copyright (c) 2009 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef STREAMS_BOOST_FUSION_CONTAINER_SET_DETAIL_VALUE_OF_DATA_IMPL_HPP
#define STREAMS_BOOST_FUSION_CONTAINER_SET_DETAIL_VALUE_OF_DATA_IMPL_HPP

#include <streams_boost/fusion/container/set/detail/value_of_data_impl.hpp>

namespace streams_boost { namespace fusion { namespace extension
{
    template <typename>
    struct value_of_data_impl;

    template <>
    struct value_of_data_impl<set_iterator_tag>
      : value_of_impl<set_iterator_tag>
    {};
}}}

#endif
