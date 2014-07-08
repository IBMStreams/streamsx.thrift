// Copyright 2004 The Trustees of Indiana University.

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Douglas Gregor
//           Andrew Lumsdaine

//
// This file contains helps that enable concept-based overloading
// within the Boost Graph Library.
//
#ifndef STREAMS_BOOST_GRAPH_OVERLOADING_HPP
#define STREAMS_BOOST_GRAPH_OVERLOADING_HPP

#include <streams_boost/type_traits/is_base_and_derived.hpp>
#include <streams_boost/utility/enable_if.hpp>

namespace streams_boost {  namespace graph { namespace detail {

struct no_parameter {};

} } } // end namespace streams_boost::graph::detail

#ifndef STREAMS_BOOST_NO_SFINAE

#define STREAMS_BOOST_GRAPH_ENABLE_IF_MODELS(Graph, Tag, Type)               \
  typename enable_if_c<(is_base_and_derived<                         \
                          Tag,                                       \
                          typename graph_traits<Graph>::traversal_category>::value), \
                       Type>::type

#define STREAMS_BOOST_GRAPH_ENABLE_IF_MODELS_PARM(Graph, Tag)                   \
  , STREAMS_BOOST_GRAPH_ENABLE_IF_MODELS(Graph, Tag,                            \
                                 ::streams_boost::graph::detail::no_parameter)  \
    = ::streams_boost::graph::detail::no_parameter()

#else

#define STREAMS_BOOST_GRAPH_ENABLE_IF_MODELS(Graph, Tag, Type) Type
#define STREAMS_BOOST_GRAPH_ENABLE_IF_MODELS_PARM(Graph, Tag)

#endif // no SFINAE support

#endif // STREAMS_BOOST_GRAPH_OVERLOADING_HPP
