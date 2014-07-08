//
//=======================================================================
// Copyright 1997, 1998, 1999, 2000 University of Notre Dame.
// Authors: Andrew Lumsdaine, Lie-Quan Lee, Jeremy G. Siek
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//=======================================================================
//
#ifndef STREAMS_BOOST_GRAPH_TRANSPOSE_HPP
#define STREAMS_BOOST_GRAPH_TRANSPOSE_HPP

#include <streams_boost/config.hpp>
#include <streams_boost/graph/graph_traits.hpp>
#include <streams_boost/graph/reverse_graph.hpp>
#include <streams_boost/graph/copy.hpp>


namespace streams_boost {

  template <class VertexListGraph, class MutableGraph> 
  void transpose_graph(const VertexListGraph& G, MutableGraph& G_T)
  {
    reverse_graph<VertexListGraph> R(G);
    copy_graph(R, G_T);
  }
  
  template <class VertexListGraph, class MutableGraph, 
    class P, class T, class R> 
  void transpose_graph(const VertexListGraph& G, MutableGraph& G_T,
                       const bgl_named_params<P, T, R>& params)
  {
    reverse_graph<VertexListGraph> Rev(G);
    copy_graph(Rev, G_T, params);
  }

} // namespace streams_boost

#endif // STREAMS_BOOST_GRAPH_TRANSPOSE_HPP
