// Copyright (C) 2004-2006 The Trustees of Indiana University.

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Douglas Gregor
//           Andrew Lumsdaine
#ifndef STREAMS_BOOST_GRAPH_PARALLEL_DIJKSTRA_DETAIL_HPP
#define STREAMS_BOOST_GRAPH_PARALLEL_DIJKSTRA_DETAIL_HPP

#ifndef STREAMS_BOOST_GRAPH_USE_MPI
#error "Parallel BGL files should not be included unless <streams_boost/graph/use_mpi.hpp> has been included"
#endif

#include <streams_boost/property_map/property_map.hpp>

namespace streams_boost { namespace graph { namespace distributed { namespace detail {

/**********************************************************************
 * Dijkstra queue message data                                        *
 **********************************************************************/
template<typename DistanceMap, typename PredecessorMap>
class dijkstra_msg_value
{
  typedef typename property_traits<DistanceMap>::value_type distance_type;
  typedef typename property_traits<PredecessorMap>::value_type
    predecessor_type;

public:
  typedef std::pair<distance_type, predecessor_type> type;

  static type create(distance_type dist, predecessor_type pred)
  { return std::make_pair(dist, pred); }
};

template<typename DistanceMap>
class dijkstra_msg_value<DistanceMap, dummy_property_map>
{
  typedef typename property_traits<DistanceMap>::key_type vertex_descriptor;
public:
  typedef typename property_traits<DistanceMap>::value_type type;

  static type create(type dist, vertex_descriptor) { return dist; }
};
/**********************************************************************/

} } } } // end namespace streams_boost::graph::distributed::detail

#endif // STREAMS_BOOST_GRAPH_PARALLEL_DIJKSTRA_DETAIL_HPP
