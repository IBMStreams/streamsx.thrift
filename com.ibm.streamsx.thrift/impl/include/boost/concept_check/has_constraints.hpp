// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_CONCEPT_CHECK_HAS_CONSTRAINTS_DWA2006429_STREAMS_HPP
# define STREAMS_BOOST_CONCEPT_CHECK_HAS_CONSTRAINTS_DWA2006429_STREAMS_HPP

namespace streams_boost { namespace concept_checking { 

// Here we implement the "metafunction" that detects whether a
// constraints metafunction exists
typedef char yes;
typedef char (&no)[2];

template <class Model, void (Model::*)()>
struct wrap_constraints {};
    
template <class Model>
inline yes has_constraints_(Model*, wrap_constraints<Model,&Model::constraints>* = 0);
inline no has_constraints_(...);

template <class Model>
struct has_constraints
{
    STREAMS_BOOST_STATIC_CONSTANT(
        bool
      , value = sizeof( concept_checking::has_constraints_((Model*)0) ) == 1 );
};

}} // namespace streams_boost::concept_checking

#endif // STREAMS_BOOST_CONCEPT_CHECK_HAS_CONSTRAINTS_DWA2006429_STREAMS_HPP
