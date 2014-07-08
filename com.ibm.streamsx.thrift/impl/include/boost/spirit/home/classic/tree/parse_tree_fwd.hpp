/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_TREE_PARSE_TREE_FWD_HPP)
#define STREAMS_BOOST_SPIRIT_TREE_PARSE_TREE_FWD_HPP

#include <streams_boost/spirit/home/classic/namespace.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    template <
        typename MatchPolicyT, 
        typename NodeFactoryT,
        typename T = nil_t
    >
    struct pt_tree_policy;

    template <
        typename IteratorT,
        typename NodeFactoryT = node_val_data_factory<nil_t>,
        typename T = nil_t
    >
    struct pt_match_policy;

    template <typename T>
    struct gen_pt_node_parser;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

#endif

