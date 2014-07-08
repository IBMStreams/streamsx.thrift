// Copyright 2004, 2005 The Trustees of Indiana University.

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Douglas Gregor
//           Andrew Lumsdaine
#ifndef STREAMS_BOOST_GRAPH_POINT_TRAITS_HPP
#define STREAMS_BOOST_GRAPH_POINT_TRAITS_HPP

namespace streams_boost { namespace graph {

template<typename Point>
struct point_traits
{
  // The type of each component of the point
  typedef typename Point::component_type component_type;

  // The number of dimensions in the point
  static std::size_t dimensions(const Point& point);
};

} } // end namespace streams_boost::graph

#endif // STREAMS_BOOST_GRAPH_POINT_TRAITS_HPP
