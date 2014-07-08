/*=============================================================================
    Copyright (c) 2001-2003 Joel de Guzman
    Copyright (c) 2002-2003 Hartmut Kaiser
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_DEBUG_MAIN_HPP)
#define STREAMS_BOOST_SPIRIT_DEBUG_MAIN_HPP

///////////////////////////////////////////////////////////////////////////
#if defined(STREAMS_BOOST_SPIRIT_DEBUG)

#include <streams_boost/spirit/home/classic/version.hpp>

///////////////////////////////////////////////////////////////////////////////
//
//  Spirit.Debug includes and defines
//
///////////////////////////////////////////////////////////////////////////////

    #include <iostream>

    ///////////////////////////////////////////////////////////////////////////
    //
    //  The STREAMS_BOOST_SPIRIT_DEBUG_OUT defines the stream object, which should be used
    //  for debug diagnostics. This defaults to std::cout.
    //
    ///////////////////////////////////////////////////////////////////////////
    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_OUT)
    #define STREAMS_BOOST_SPIRIT_DEBUG_OUT std::cout
    #endif

    ///////////////////////////////////////////////////////////////////////////
    //
    //  The STREAMS_BOOST_SPIRIT_DEBUG_PRINT_SOME constant defines the number of characters
    //  from the stream to be printed for diagnosis. This defaults to the first
    //  20 characters.
    //
    ///////////////////////////////////////////////////////////////////////////
    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_PRINT_SOME)
    #define STREAMS_BOOST_SPIRIT_DEBUG_PRINT_SOME 20
    #endif

    ///////////////////////////////////////////////////////////////////////////
    //
    //  Additional STREAMS_BOOST_SPIRIT_DEBUG_FLAGS control the level of diagnostics printed
    //  Basic constants are defined in debug/minimal.hpp.
    //
    ///////////////////////////////////////////////////////////////////////////
    #define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_NODES        0x0001  // node diagnostics
    #define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_ESCAPE_CHAR  0x0002  // escape_char_parse diagnostics
    #define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_TREES        0x0004  // parse tree/ast diagnostics
    #define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_CLOSURES     0x0008  // closure diagnostics
    #define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_SLEX         0x8000  // slex diagnostics

    #define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_MAX          0xFFFF  // print maximal diagnostics

    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_FLAGS)
    #define STREAMS_BOOST_SPIRIT_DEBUG_FLAGS STREAMS_BOOST_SPIRIT_DEBUG_FLAGS_MAX
    #endif

    ///////////////////////////////////////////////////////////////////////////
    //
    //  By default all nodes are traced (even those, not registered with
    //  STREAMS_BOOST_SPIRIT_DEBUG_RULE et.al. - see below). The following constant may be
    //  used to redefine this default.
    //
    ///////////////////////////////////////////////////////////////////////////
    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACENODE)
    #define STREAMS_BOOST_SPIRIT_DEBUG_TRACENODE          (true)
    #endif // !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACENODE)

    ///////////////////////////////////////////////////////////////////////////
    //
    //  Helper macros for giving rules and subrules a name accessible through
    //  parser_name() functions (see parser_names.hpp).
    //
    //  Additionally, the macros STREAMS_BOOST_SPIRIT_DEBUG_RULE, SPIRIT_DEBUG_NODE and
    //  STREAMS_BOOST_SPIRIT_DEBUG_GRAMMAR enable/disable the tracing of the 
    //  correspondingnode accordingly to the PP constant 
    //  STREAMS_BOOST_SPIRIT_DEBUG_TRACENODE.
    //
    //  The macros STREAMS_BOOST_SPIRIT_DEBUG_TRACE_RULE, STREAMS_BOOST_SPIRIT_DEBUG_TRACE_NODE 
    //  and STREAMS_BOOST_SPIRIT_DEBUG_TRACE_GRAMMAR allow to specify a flag to define, 
    //  whether the corresponding node is to be traced or not.
    //
    ///////////////////////////////////////////////////////////////////////////
    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_RULE)
    #define STREAMS_BOOST_SPIRIT_DEBUG_RULE(r)    \
        ::STREAMS_BOOST_SPIRIT_CLASSIC_NS::impl::get_node_registry(). \
            register_node(&r, #r, STREAMS_BOOST_SPIRIT_DEBUG_TRACENODE)
    #endif // !defined(STREAMS_BOOST_SPIRIT_DEBUG_RULE)

    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_NODE)
    #define STREAMS_BOOST_SPIRIT_DEBUG_NODE(r)    \
        ::STREAMS_BOOST_SPIRIT_CLASSIC_NS::impl::get_node_registry(). \
            register_node(&r, #r, STREAMS_BOOST_SPIRIT_DEBUG_TRACENODE)
    #endif // !defined(STREAMS_BOOST_SPIRIT_DEBUG_NODE)

    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_GRAMMAR)
    #define STREAMS_BOOST_SPIRIT_DEBUG_GRAMMAR(r)    \
        ::STREAMS_BOOST_SPIRIT_CLASSIC_NS::impl::get_node_registry(). \
            register_node(&r, #r, STREAMS_BOOST_SPIRIT_DEBUG_TRACENODE)
    #endif // !defined(STREAMS_BOOST_SPIRIT_DEBUG_GRAMMAR)

    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACE_RULE)
    #define STREAMS_BOOST_SPIRIT_DEBUG_TRACE_RULE(r, t)    \
        ::STREAMS_BOOST_SPIRIT_CLASSIC_NS::impl::get_node_registry(). \
            register_node(&r, #r, (t))
    #endif // !defined(STREAMS_BOOST_SPIRIT_TRACE_RULE)

    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACE_NODE)
    #define STREAMS_BOOST_SPIRIT_DEBUG_TRACE_NODE(r, t)    \
        ::STREAMS_BOOST_SPIRIT_CLASSIC_NS::impl::get_node_registry(). \
            register_node(&r, #r, (t))
    #endif // !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACE_NODE)

    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACE_GRAMMAR)
    #define STREAMS_BOOST_SPIRIT_DEBUG_TRACE_GRAMMAR(r, t)    \
        ::STREAMS_BOOST_SPIRIT_CLASSIC_NS::impl::get_node_registry(). \
            register_node(&r, #r, (t))
    #endif // !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACE_GRAMMAR)

    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACE_RULE_NAME)
    #define STREAMS_BOOST_SPIRIT_DEBUG_TRACE_RULE_NAME(r, n, t)    \
        ::STREAMS_BOOST_SPIRIT_CLASSIC_NS::impl::get_node_registry(). \
            register_node(&r, (n), (t))
    #endif // !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACE_RULE_NAME)

    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACE_NODE_NAME)
    #define STREAMS_BOOST_SPIRIT_DEBUG_TRACE_NODE_NAME(r, n, t)    \
        ::STREAMS_BOOST_SPIRIT_CLASSIC_NS::impl::get_node_registry(). \
            register_node(&r, (n), (t))
    #endif // !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACE_NODE_NAME)

    #if !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACE_GRAMMAR_NAME)
    #define STREAMS_BOOST_SPIRIT_DEBUG_TRACE_GRAMMAR_NAME(r, n, t)    \
        ::STREAMS_BOOST_SPIRIT_CLASSIC_NS::impl::get_node_registry(). \
            register_node(&r, (n), (t))
    #endif // !defined(STREAMS_BOOST_SPIRIT_DEBUG_TRACE_GRAMMAR_NAME)

    //////////////////////////////////
    #include <streams_boost/spirit/home/classic/debug/debug_node.hpp>

#else
    //////////////////////////////////
    #include <streams_boost/spirit/home/classic/debug/minimal.hpp>

#endif // STREAMS_BOOST_SPIRIT_DEBUG

#endif

