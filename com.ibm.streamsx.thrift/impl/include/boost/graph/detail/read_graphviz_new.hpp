// Copyright 2004-9 Trustees of Indiana University

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//
// read_graphviz_new.hpp - 
//   Initialize a model of the BGL's MutableGraph concept and an associated
//  collection of property maps using a graph expressed in the GraphViz
// DOT Language.  
//
//   Based on the grammar found at:
//   http://www.graphviz.org/cvs/doc/info/lang.html
//
//   Jeremiah rewrite used grammar found at:
//   http://www.graphviz.org/doc/info/lang.html
//   and page 34 or http://www.graphviz.org/pdf/dotguide.pdf
//
//   See documentation for this code at: 
//     http://www.streams_boost.org/libs/graph/doc/read-graphviz.html
//

// Author: Jeremiah Willcock
//         Ronald Garcia
//

#ifndef STREAMS_BOOST_READ_GRAPHVIZ_NEW_HPP
#define STREAMS_BOOST_READ_GRAPHVIZ_NEW_HPP

#include <streams_boost/ref.hpp>
#include <streams_boost/property_map/dynamic_property_map.hpp>
#include <streams_boost/graph/graph_traits.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <iostream>
#include <cstdlib>

namespace streams_boost {

namespace read_graphviz_detail {
  typedef std::string node_name;
  typedef std::string subgraph_name;

  typedef std::map<std::string, std::string> properties;

  struct node_and_port {
    node_name name;
    std::string angle; // Or empty if no angle
    std::vector<std::string> location; // Up to two identifiers

    friend inline bool operator==(const node_and_port& a, const node_and_port& b) {
      return a.name == b.name &&
             a.angle == b.angle &&
             a.location == b.location;
    }

    friend inline bool operator<(const node_and_port& a, const node_and_port& b) {
      if (a.name != b.name) return a.name < b.name;
      if (a.angle != b.angle) return a.angle < b.angle;
      return a.location < b.location;
    }
  };

  struct edge_info {
    node_and_port source;
    node_and_port target;
    properties props;
  };

  struct parser_result {
    bool graph_is_directed;
    bool graph_is_strict;
    std::map<node_name, properties> nodes; // Global set
    std::vector<edge_info> edges;
    std::map<subgraph_name, properties> graph_props; // Root and subgraphs
  };

  // The actual parser, from libs/graph/src/read_graphviz_new.cpp
  void parse_graphviz_from_string(const std::string& str, parser_result& result, bool want_directed);

  // Translate from those results to a graph
  void translate_results_to_graph(const parser_result& r, ::streams_boost::detail::graph::mutate_graph* mg);

} // namespace read_graphviz_detail

// This is also in streams_boost/graph/graphviz.hpp
namespace detail {
  namespace graph {
    STREAMS_BOOST_GRAPH_DECL bool read_graphviz(const std::string& str, streams_boost::detail::graph::mutate_graph* mg);
  } // end namespace graph
} // end namespace detail

template <typename MutableGraph>
bool read_graphviz(const std::string& str,
                   MutableGraph& graph, streams_boost::dynamic_properties& dp,
                   std::string const& node_id = "node_id") {
  streams_boost::detail::graph::mutate_graph_impl<MutableGraph> mg(graph, dp, node_id);
  return detail::graph::read_graphviz(str, &mg);
}

template <typename InputIter, typename MutableGraph>
bool read_graphviz(InputIter begin, InputIter end,
                   MutableGraph& graph, streams_boost::dynamic_properties& dp,
                   std::string const& node_id = "node_id") {
  return read_graphviz(std::string(begin, end), graph, dp, node_id);
}

} // namespace streams_boost

#endif // STREAMS_BOOST_READ_GRAPHVIZ_NEW_HPP
