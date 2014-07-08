/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_EXCEPTIONS_FWD_HPP)
#define STREAMS_BOOST_SPIRIT_EXCEPTIONS_FWD_HPP

#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/core/nil.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    template <typename ErrorDescrT, typename IteratorT = char const*>
    struct parser_error;

    template <typename ErrorDescrT, typename ParserT>
    struct assertive_parser;

    template <typename ErrorDescrT>
    struct assertion;

    template <typename T = nil_t>
    struct error_status;

    template <typename ErrorDescrT, typename ParserT, typename HandlerT>
    struct fallback_parser;

    template <typename ErrorDescrT>
    struct guard;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

#endif

