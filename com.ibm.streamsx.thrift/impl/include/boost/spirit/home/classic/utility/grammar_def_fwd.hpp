/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_GRAMMAR_DEF_FWD_HPP)
#define STREAMS_BOOST_SPIRIT_GRAMMAR_DEF_FWD_HPP

#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/phoenix/tuples.hpp>

#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/facilities/intercept.hpp>

#if !defined(STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT)
#define STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT PHOENIX_LIMIT
#endif

//  Calculate an integer rounded up to the nearest integer dividable by 3
#if STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT > 12
#define STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT_A     15
#elif STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT > 9
#define STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT_A     12
#elif STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT > 6
#define STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT_A     9
#elif STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT > 3
#define STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT_A     6
#else
#define STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT_A     3
#endif

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    template <
        typename T,
        STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(
            STREAMS_BOOST_PP_DEC(STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT_A),
            typename T, = phoenix::nil_t STREAMS_BOOST_PP_INTERCEPT
        )
    >
    class grammar_def;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

#endif

