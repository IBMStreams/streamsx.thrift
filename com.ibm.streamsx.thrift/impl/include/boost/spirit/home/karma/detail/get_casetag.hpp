//  Copyright (c) 2001-2010 Hartmut Kaiser
//  Copyright (c) 2001-2010 Joel de Guzman
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if !defined(STREAMS_BOOST_SPIRIT_KARMA_GET_CASETAG_JANUARY_19_2009_1107AM)
#define STREAMS_BOOST_SPIRIT_KARMA_GET_CASETAG_JANUARY_19_2009_1107AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/mpl/identity.hpp>

namespace streams_boost { namespace spirit { namespace karma { namespace detail
{
    template <typename Modifiers, bool case_modifier = false>
    struct get_casetag : mpl::identity<unused_type> {};

    template <typename Modifiers>
    struct get_casetag<Modifiers, true>
      : mpl::if_<has_modifier<Modifiers, tag::char_code_base<tag::lower> >
          , tag::lower, tag::upper> {};

}}}}

#endif
