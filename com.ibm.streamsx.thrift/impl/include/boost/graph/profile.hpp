//
//=======================================================================
// Copyright 2002 Marc Wintermantel (wintermantel@even-ag.ch)
// ETH Zurich, Center of Structure Technologies (www.imes.ethz.ch/st)
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//=======================================================================

#ifndef STREAMS_BOOST_GRAPH_PROFILE_HPP
#define STREAMS_BOOST_GRAPH_PROFILE_HPP

#include <streams_boost/graph/graph_traits.hpp>
#include <streams_boost/detail/numeric_traits.hpp>
#include <streams_boost/graph/bandwidth.hpp>

namespace streams_boost {

  template <typename Graph, typename VertexIndexMap>
  typename graph_traits<Graph>::vertices_size_type
  profile(const Graph& g, VertexIndexMap index)
  {
    typename graph_traits<Graph>::vertices_size_type b = 0;
    typename graph_traits<Graph>::vertex_iterator i, end;
    for (tie(i, end) = vertices(g); i != end; ++i){
      b += ith_bandwidth(*i, g, index) + 1;
    }
    
    return b;
  }

  template <typename Graph>
  typename graph_traits<Graph>::vertices_size_type
  profile(const Graph& g)
  {
    return profile(g, get(vertex_index, g));
  }
 
  
} // namespace streams_boost

#endif // STREAMS_BOOST_GRAPH_PROFILE_HPP
