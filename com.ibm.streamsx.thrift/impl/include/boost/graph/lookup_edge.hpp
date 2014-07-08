//=======================================================================
// Copyright 2009 Trustees of Indiana University
// Author: Jeremiah Willcock
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//=======================================================================

#ifndef STREAMS_BOOST_GRAPH_LOOKUP_EDGE_HPP
#define STREAMS_BOOST_GRAPH_LOOKUP_EDGE_HPP

#include <utility>
#include <streams_boost/config.hpp>
#include <streams_boost/utility/enable_if.hpp>
#include <streams_boost/graph/graph_traits.hpp>

// lookup_edge: a function that acts like edge() but falls back to out_edges()
// and a search when edge() is not provided.

namespace streams_boost {

  template <typename Graph>
  std::pair<typename streams_boost::graph_traits<Graph>::edge_descriptor, bool>
  lookup_edge(typename streams_boost::graph_traits<Graph>::vertex_descriptor src,
              typename streams_boost::graph_traits<Graph>::vertex_descriptor tgt,
              const Graph& g,
              typename streams_boost::enable_if<is_adjacency_matrix<Graph>, int>::type = 0) {
    return edge(src, tgt, g);
  }

  template <typename Graph>
  std::pair<typename streams_boost::graph_traits<Graph>::edge_descriptor, bool>
  lookup_edge(typename streams_boost::graph_traits<Graph>::vertex_descriptor src,
              typename streams_boost::graph_traits<Graph>::vertex_descriptor tgt,
              const Graph& g,
              typename streams_boost::disable_if<is_adjacency_matrix<Graph>, int>::type = 0) {
    typedef typename streams_boost::graph_traits<Graph>::out_edge_iterator it;
    typedef typename streams_boost::graph_traits<Graph>::edge_descriptor edesc;
    std::pair<it, it> oe = out_edges(src, g);
    for (; oe.first != oe.second; ++oe.first) {
      edesc e = *oe.first;
      if (target(e, g) == tgt) return std::make_pair(e, true);
    }
    return std::make_pair(edesc(), false);
  }

}

#endif // STREAMS_BOOST_GRAPH_LOOKUP_EDGE_HPP
