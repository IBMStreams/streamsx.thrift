// Copyright 2004 The Trustees of Indiana University.

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Douglas Gregor
//           Andrew Lumsdaine
#ifndef STREAMS_BOOST_GRAPH_RANDOM_LAYOUT_HPP
#define STREAMS_BOOST_GRAPH_RANDOM_LAYOUT_HPP

#include <streams_boost/graph/graph_traits.hpp>
#include <streams_boost/random/uniform_int.hpp>
#include <streams_boost/random/uniform_01.hpp>
#include <streams_boost/random/uniform_real.hpp>
#include <streams_boost/type_traits/is_integral.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/graph/iteration_macros.hpp>

namespace streams_boost {

template<typename Topology,
         typename Graph, typename PositionMap>
void
random_graph_layout
 (const Graph& g, PositionMap position_map,
  const Topology& topology)
{
  BGL_FORALL_VERTICES_T(v, g, Graph) {
    put(position_map, v, topology.random_point());
  }
}

} // end namespace streams_boost

#endif // STREAMS_BOOST_GRAPH_RANDOM_LAYOUT_HPP
