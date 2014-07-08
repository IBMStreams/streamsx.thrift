/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_SUBRULE_FWD_HPP)
#define STREAMS_BOOST_SPIRIT_SUBRULE_FWD_HPP

#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/core/non_terminal/parser_context.hpp>

namespace streams_boost { namespace spirit  {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    template <int ID, typename ContextT = parser_context<> >
    struct subrule; 

    template <int ID, typename DefT, typename ContextT = parser_context<> >
    struct subrule_parser;

    template <typename ScannerT, typename ListT>
    struct subrules_scanner;

    template <typename FirstT, typename RestT>
    struct subrule_list; 

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

#endif

