// Copyright (C) 2004-2006 The Trustees of Indiana University.

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Douglas Gregor
//           Andrew Lumsdaine

//
// Distributed graph concepts and helpers
//

#ifndef STREAMS_BOOST_GRAPH_DISTRIBUTED_CONCEPTS_HPP
#define STREAMS_BOOST_GRAPH_DISTRIBUTED_CONCEPTS_HPP

#ifndef STREAMS_BOOST_GRAPH_USE_MPI
#error "Parallel BGL files should not be included unless <streams_boost/graph/use_mpi.hpp> has been included"
#endif

#include <streams_boost/version.hpp>
#include <streams_boost/graph/graph_traits.hpp>
#include <streams_boost/graph/graph_concepts.hpp>

#if STREAMS_BOOST_VERSION >= 103500
#  include <streams_boost/concept/detail/concept_def.hpp>
#endif

namespace streams_boost { 

class distributed_graph_tag { };
class distributed_vertex_list_graph_tag { };
class distributed_edge_list_graph_tag { };

#if STREAMS_BOOST_VERSION >= 103500
  namespace concepts {
#endif

#if STREAMS_BOOST_VERSION < 103500

template <class G>
struct DistributedVertexListGraphConcept
{
  typedef typename graph_traits<G>::vertex_iterator vertex_iterator;
  typedef typename graph_traits<G>::vertices_size_type vertices_size_type;
  typedef typename graph_traits<G>::traversal_category
    traversal_category;
  void constraints() {
    function_requires< GraphConcept<G> >();
    function_requires< MultiPassInputIteratorConcept<vertex_iterator> >();
    function_requires< ConvertibleConcept<traversal_category,
      distributed_vertex_list_graph_tag> >();

#ifdef STREAMS_BOOST_VECTOR_AS_GRAPH_GRAPH_ADL_HACK
    // dwa 2003/7/11 -- This clearly shouldn't be necessary, but if
    // you want to use vector_as_graph, it is!  I'm sure the graph
    // library leaves these out all over the place.  Probably a
    // redesign involving specializing a template with a static
    // member function is in order :(
    using streams_boost::vertices;
#endif      
    p = vertices(g);
    v = *p.first;
    const_constraints(g);
  }
  void const_constraints(const G& cg) {
#ifdef STREAMS_BOOST_VECTOR_AS_GRAPH_GRAPH_ADL_HACK
    // dwa 2003/7/11 -- This clearly shouldn't be necessary, but if
    // you want to use vector_as_graph, it is!  I'm sure the graph
    // library leaves these out all over the place.  Probably a
    // redesign involving specializing a template with a static
    // member function is in order :(
    using streams_boost::vertices;
#endif 
    
    p = vertices(cg);
    v = *p.first;
    V = num_vertices(cg);
  }
  std::pair<vertex_iterator,vertex_iterator> p;
  typename graph_traits<G>::vertex_descriptor v;
  G g;
  vertices_size_type V;
};

template <class G>
struct DistributedEdgeListGraphConcept
{
  typedef typename graph_traits<G>::edge_descriptor edge_descriptor;
  typedef typename graph_traits<G>::edge_iterator edge_iterator;
  typedef typename graph_traits<G>::edges_size_type edges_size_type;
  typedef typename graph_traits<G>::traversal_category
    traversal_category;
  void constraints() {
    function_requires< GraphConcept<G> >();
    function_requires< MultiPassInputIteratorConcept<edge_iterator> >();
    function_requires< DefaultConstructibleConcept<edge_descriptor> >();
    function_requires< EqualityComparableConcept<edge_descriptor> >();
    function_requires< AssignableConcept<edge_descriptor> >();
    function_requires< ConvertibleConcept<traversal_category,
      distributed_edge_list_graph_tag> >();

    p = edges(g);
    e = *p.first;
    u = source(e, g);
    v = target(e, g);
    const_constraints(g);
  }
  void const_constraints(const G& cg) {
    p = edges(cg);
    E = num_edges(cg);
    e = *p.first;
    u = source(e, cg);
    v = target(e, cg);
  }
  std::pair<edge_iterator,edge_iterator> p;
  typename graph_traits<G>::vertex_descriptor u, v;
  typename graph_traits<G>::edge_descriptor e;
  edges_size_type E;
  G g;
};
#else
  STREAMS_BOOST_concept(DistributedVertexListGraph,(G))
    : Graph<G>
  {
    typedef typename graph_traits<G>::vertex_iterator vertex_iterator;
    typedef typename graph_traits<G>::vertices_size_type vertices_size_type;
    typedef typename graph_traits<G>::traversal_category
      traversal_category;
    ~DistributedVertexListGraph() {
      STREAMS_BOOST_CONCEPT_ASSERT((MultiPassInputIterator<vertex_iterator>));
      STREAMS_BOOST_CONCEPT_ASSERT((Convertible<traversal_category,
        distributed_vertex_list_graph_tag>));

#ifdef STREAMS_BOOST_VECTOR_AS_GRAPH_GRAPH_ADL_HACK
      // dwa 2003/7/11 -- This clearly shouldn't be necessary, but if
      // you want to use vector_as_graph, it is!  I'm sure the graph
      // library leaves these out all over the place.  Probably a
      // redesign involving specializing a template with a static
      // member function is in order :(
      using streams_boost::vertices;
#endif      
      p = vertices(g);
      v = *p.first;
      const_constraints(g);
    }
    void const_constraints(const G& cg) {
#ifdef STREAMS_BOOST_VECTOR_AS_GRAPH_GRAPH_ADL_HACK
      // dwa 2003/7/11 -- This clearly shouldn't be necessary, but if
      // you want to use vector_as_graph, it is!  I'm sure the graph
      // library leaves these out all over the place.  Probably a
      // redesign involving specializing a template with a static
      // member function is in order :(
      using streams_boost::vertices;
#endif 
      
      p = vertices(cg);
      v = *p.first;
      V = num_vertices(cg);
    }
    std::pair<vertex_iterator,vertex_iterator> p;
    typename graph_traits<G>::vertex_descriptor v;
    G g;
    vertices_size_type V;
  };

  STREAMS_BOOST_concept(DistributedEdgeListGraph,(G))
    : Graph<G>
  {
    typedef typename graph_traits<G>::edge_descriptor edge_descriptor;
    typedef typename graph_traits<G>::edge_iterator edge_iterator;
    typedef typename graph_traits<G>::edges_size_type edges_size_type;
    typedef typename graph_traits<G>::traversal_category
      traversal_category;
    ~DistributedEdgeListGraph() {
      STREAMS_BOOST_CONCEPT_ASSERT((MultiPassInputIterator<edge_iterator>));
      STREAMS_BOOST_CONCEPT_ASSERT((DefaultConstructible<edge_descriptor>));
      STREAMS_BOOST_CONCEPT_ASSERT((EqualityComparable<edge_descriptor>));
      STREAMS_BOOST_CONCEPT_ASSERT((Assignable<edge_descriptor>));
      STREAMS_BOOST_CONCEPT_ASSERT((Convertible<traversal_category,
        distributed_edge_list_graph_tag>));

      p = edges(g);
      e = *p.first;
      u = source(e, g);
      v = target(e, g);
      const_constraints(g);
    }
    void const_constraints(const G& cg) {
      p = edges(cg);
      E = num_edges(cg);
      e = *p.first;
      u = source(e, cg);
      v = target(e, cg);
    }
    std::pair<edge_iterator,edge_iterator> p;
    typename graph_traits<G>::vertex_descriptor u, v;
    typename graph_traits<G>::edge_descriptor e;
    edges_size_type E;
    G g;
  };
#endif

#if STREAMS_BOOST_VERSION >= 103500
  } // end namespace concepts

  using concepts::DistributedVertexListGraphConcept;
  using concepts::DistributedEdgeListGraphConcept;
#endif
} // end namespace streams_boost

#if STREAMS_BOOST_VERSION >= 103500
#  include <streams_boost/concept/detail/concept_undef.hpp>
#endif

#endif // STREAMS_BOOST_GRAPH_DISTRIBUTED_CONCEPTS_HPP
