/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_SKIPPER_FWD_HPP)
#define STREAMS_BOOST_SPIRIT_SKIPPER_FWD_HPP

#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/core/scanner/scanner_fwd.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    template <typename BaseT = iteration_policy>
    struct skipper_iteration_policy;

    template <typename BaseT = iteration_policy>
    struct no_skipper_iteration_policy; 

    template <typename ParserT, typename BaseT = iteration_policy>
    class skip_parser_iteration_policy;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

#endif

