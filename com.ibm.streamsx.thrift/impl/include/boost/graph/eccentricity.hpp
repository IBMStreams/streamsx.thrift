// (C) Copyright 2007-2009 Andrew Sutton
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0 (See accompanying file
// LICENSE_1_0.txt or http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_GRAPH_ECCENTRICITY_HPP
#define STREAMS_BOOST_GRAPH_ECCENTRICITY_HPP

#include <streams_boost/utility.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/graph/detail/geodesic.hpp>

namespace streams_boost
{
template <typename Graph,
            typename DistanceMap,
            typename Combinator>
inline typename property_traits<DistanceMap>::value_type
eccentricity(const Graph& g, DistanceMap dist, Combinator combine)
{
    function_requires< GraphConcept<Graph> >();
    typedef typename graph_traits<Graph>::vertex_descriptor Vertex;
    function_requires< ReadablePropertyMapConcept<DistanceMap,Vertex> >();
    typedef typename property_traits<DistanceMap>::value_type Distance;

    return detail::combine_distances(g, dist, combine, Distance(0));
}

template <typename Graph, typename DistanceMap>
inline typename property_traits<DistanceMap>::value_type
eccentricity(const Graph& g, DistanceMap dist)
{
    function_requires< GraphConcept<Graph> >();
    typedef typename graph_traits<Graph>::vertex_descriptor Vertex;
    function_requires< ReadablePropertyMapConcept<DistanceMap,Vertex> >();
    typedef typename property_traits<DistanceMap>::value_type Distance;

    return eccentricity(g, dist, detail::maximize<Distance>());
}

template <typename Graph, typename DistanceMatrix, typename EccentricityMap>
inline std::pair<typename property_traits<EccentricityMap>::value_type,
                    typename property_traits<EccentricityMap>::value_type>
all_eccentricities(const Graph& g, const DistanceMatrix& dist, EccentricityMap ecc)
{
    function_requires< VertexListGraphConcept<Graph> >();
    typedef typename graph_traits<Graph>::vertex_descriptor Vertex;
    typedef typename graph_traits<Graph>::vertex_iterator VertexIterator;
    function_requires< ReadablePropertyMapConcept<DistanceMatrix,Vertex> >();
    typedef typename property_traits<DistanceMatrix>::value_type DistanceMap;
    function_requires< WritablePropertyMapConcept<EccentricityMap,Vertex> >();
    typedef typename property_traits<EccentricityMap>::value_type Eccentricity;
    STREAMS_BOOST_USING_STD_MIN();
    STREAMS_BOOST_USING_STD_MAX();

    Eccentricity
            r = numeric_values<Eccentricity>::infinity(),
            d = numeric_values<Eccentricity>::zero();
    VertexIterator i, end;
    tie(i, end) = vertices(g);
    for(tie(i, end) = vertices(g); i != end; ++i) {
        DistanceMap dm = get(dist, *i);
        Eccentricity e = eccentricity(g, dm);
        put(ecc, *i, e);

        // track the radius and diameter at the same time
        r = min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (r, e);
        d = max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (d, e);
    }
    return make_pair(r, d);
}

template <typename Graph, typename EccentricityMap>
inline std::pair<typename property_traits<EccentricityMap>::value_type,
                    typename property_traits<EccentricityMap>::value_type>
radius_and_diameter(const Graph& g, EccentricityMap ecc)
{
    function_requires< VertexListGraphConcept<Graph> >();
    typedef typename graph_traits<Graph>::vertex_descriptor Vertex;
    typedef typename graph_traits<Graph>::vertex_iterator VertexIterator;
    function_requires< ReadablePropertyMapConcept<EccentricityMap, Vertex> >();
    typedef typename property_traits<EccentricityMap>::value_type Eccentricity;

    VertexIterator i, end;
    tie(i, end) = vertices(g);
    Eccentricity radius = get(ecc, *i);
    Eccentricity diameter = get(ecc, *i);
    for(i = streams_boost::next(i); i != end; ++i) {
        Eccentricity cur = get(ecc, *i);
        radius = min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (radius, cur);
        diameter = max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (diameter, cur);
    }
    return std::make_pair(radius, diameter);
}


template <typename Graph, typename EccentricityMap>
inline typename property_traits<EccentricityMap>::value_type
radius(const Graph& g, EccentricityMap ecc)
{ return radius_and_diameter(g, ecc).first; }


template <typename Graph, typename EccentricityMap>
inline typename property_traits<EccentricityMap>::value_type
diameter(const Graph& g, EccentricityMap ecc)
{ return radius_and_diameter(g, ecc).second; }

} /* namespace streams_boost */

#endif
