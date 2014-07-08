/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2001-2010 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_LOCALS_APRIL_03_2007_0506PM)
#define STREAMS_BOOST_SPIRIT_LOCALS_APRIL_03_2007_0506PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/mpl/bool.hpp>

#if !defined(STREAMS_BOOST_SPIRIT_MAX_LOCALS_SIZE)
# define STREAMS_BOOST_SPIRIT_MAX_LOCALS_SIZE 10
#else
# if STREAMS_BOOST_SPIRIT_MAX_LOCALS_SIZE < 3
#   undef STREAMS_BOOST_SPIRIT_MAX_LOCALS_SIZE
#   define STREAMS_BOOST_SPIRIT_MAX_LOCALS_SIZE 10
# endif
#endif

namespace streams_boost { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    template <
        STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
            STREAMS_BOOST_SPIRIT_MAX_LOCALS_SIZE, typename T, mpl::na)
    >
    struct locals
      : mpl::vector<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_SPIRIT_MAX_LOCALS_SIZE, T)> {};

    ///////////////////////////////////////////////////////////////////////////
    namespace detail
    {
        template <typename T>
        struct is_locals
          : mpl::false_
        {};

        template <STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_SPIRIT_MAX_LOCALS_SIZE, typename T)>
        struct is_locals<locals<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_SPIRIT_MAX_LOCALS_SIZE, T)> >
          : mpl::true_
        {};
    }
}}

#endif
