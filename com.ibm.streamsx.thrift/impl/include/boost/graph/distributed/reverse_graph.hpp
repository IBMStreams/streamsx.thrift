// Copyright (C) 2005-2006 The Trustees of Indiana University.

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Nick Edmonds
//           Andrew Lumsdaine
#ifndef STREAMS_BOOST_GRAPH_DISTRIBUTED_REVERSE_GRAPH_HPP
#define STREAMS_BOOST_GRAPH_DISTRIBUTED_REVERSE_GRAPH_HPP

#ifndef STREAMS_BOOST_GRAPH_USE_MPI
#error "Parallel BGL files should not be included unless <streams_boost/graph/use_mpi.hpp> has been included"
#endif

#include <streams_boost/graph/reverse_graph.hpp>
#include <streams_boost/graph/parallel/container_traits.hpp>

namespace streams_boost {
  namespace graph {
    namespace parallel {
      /// Retrieve the process group from a reverse graph
      template<typename Graph, typename GraphRef>
      struct process_group_type<reverse_graph<Graph, GraphRef> >
        : process_group_type<Graph> { };
    }

  }

  /// Retrieve the process group from a reverse graph
  template<typename Graph, typename GraphRef>
  inline typename graph::parallel::process_group_type<Graph>::type
  process_group(reverse_graph<Graph, GraphRef> const& g) {
    return process_group(g.m_g);
  }
} // namespace streams_boost

#endif
