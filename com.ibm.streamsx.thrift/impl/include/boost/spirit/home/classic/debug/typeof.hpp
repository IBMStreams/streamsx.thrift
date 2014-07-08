/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_DEBUG_TYPEOF_HPP)
#define STREAMS_BOOST_SPIRIT_DEBUG_TYPEOF_HPP

#include <streams_boost/typeof/typeof.hpp>

#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/core/typeof.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    // debug_node.hpp
    template<typename ContextT> struct parser_context_linker;
    template<typename ScannerT> struct scanner_context_linker;
    template<typename ContextT> struct closure_context_linker;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

// debug_node.hpp
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::parser_context_linker,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::scanner_context_linker,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::closure_context_linker,1)

#endif

