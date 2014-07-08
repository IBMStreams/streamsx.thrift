/*=============================================================================
    Boost.Wave: A Standard compliant C++ preprocessor library

    http://www.streams_boost.org/

    Copyright (c) 2001-2010 Hartmut Kaiser. Distributed under the Boost
    Software License, Version 1.0. (See accompanying file
    LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/

#if !defined(CPP_EXPRESSION_GRAMMAR_GEN_HPP_42399258_6CDC_4101_863D_5C7D95B5A6CA_INCLUDED)
#define CPP_EXPRESSION_GRAMMAR_GEN_HPP_42399258_6CDC_4101_863D_5C7D95B5A6CA_INCLUDED

#include <streams_boost/wave/wave_config.hpp>
#include <streams_boost/wave/cpp_iteration_context.hpp>
#include <streams_boost/wave/grammars/cpp_value_error.hpp>

#include <list>
#include <streams_boost/pool/pool_alloc.hpp>

// this must occur after all of the includes and before any code appears
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#include STREAMS_BOOST_ABI_PREFIX
#endif

// suppress warnings about dependent classes not being exported from the dll
#ifdef STREAMS_BOOST_MSVC
#pragma warning(push)
#pragma warning(disable : 4251 4231 4660)
#endif

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost {
namespace wave {
namespace grammars {

///////////////////////////////////////////////////////////////////////////////
//  
//  expression_grammar_gen template class
//
//      This template helps separating the compilation of the 
//      expression_grammar class from the compilation of the main 
//      pp_iterator. This is done to safe compilation time.
//
///////////////////////////////////////////////////////////////////////////////

template <typename TokenT>
struct STREAMS_BOOST_WAVE_DECL expression_grammar_gen {

    typedef TokenT token_type;
    typedef std::list<token_type, streams_boost::fast_pool_allocator<token_type> >
        token_sequence_type;

    static bool evaluate(
        typename token_sequence_type::const_iterator const &first, 
        typename token_sequence_type::const_iterator const &last, 
        typename token_type::position_type const &tok,
        bool if_block_status, value_error &status);
};

///////////////////////////////////////////////////////////////////////////////
}   //  namespace grammars
}   //  namespace wave 
}   //  namespace streams_boost

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

// the suffix header occurs after all of the code
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#include STREAMS_BOOST_ABI_SUFFIX
#endif

#endif // !defined(CPP_EXPRESSION_GRAMMAR_GEN_HPP_42399258_6CDC_4101_863D_5C7D95B5A6CA_INCLUDED)
