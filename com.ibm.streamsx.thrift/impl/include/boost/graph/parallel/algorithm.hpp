// Copyright 2004 The Trustees of Indiana University.

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Douglas Gregor
//           Andrew Lumsdaine
#ifndef STREAMS_BOOST_PARALLEL_ALGORITHM_HPP
#define STREAMS_BOOST_PARALLEL_ALGORITHM_HPP

#ifndef STREAMS_BOOST_GRAPH_USE_MPI
#error "Parallel BGL files should not be included unless <streams_boost/graph/use_mpi.hpp> has been included"
#endif

#include <streams_boost/optional.hpp>
#include <streams_boost/config.hpp> // for STREAMS_BOOST_STATIC_CONSTANT
#include <vector>
#include <functional>

namespace streams_boost { namespace parallel {
  template<typename BinaryOp>
  struct is_commutative
  {
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
  };

  template<typename T>
  struct minimum : std::binary_function<T, T, T>
  {
    const T& operator()(const T& x, const T& y) const { return x < y? x : y; }
  };

  template<typename T>
  struct maximum : std::binary_function<T, T, T>
  {
    const T& operator()(const T& x, const T& y) const { return x < y? y : x; }
  };

  template<typename T>
  struct sum : std::binary_function<T, T, T>
  {
    const T operator()(const T& x, const T& y) const { return x + y; }
  };

  template<typename ProcessGroup, typename InputIterator,
           typename OutputIterator, typename BinaryOperation>
  OutputIterator
  reduce(ProcessGroup pg, typename ProcessGroup::process_id_type root,
         InputIterator first, InputIterator last, OutputIterator out,
         BinaryOperation bin_op);

  template<typename ProcessGroup, typename T, typename BinaryOperation>
  inline T
  all_reduce(ProcessGroup pg, const T& value, BinaryOperation bin_op)
  {
    T result;
    all_reduce(pg,
               const_cast<T*>(&value), const_cast<T*>(&value+1),
               &result, bin_op);
    return result;
  }

  template<typename ProcessGroup, typename T, typename BinaryOperation>
  inline T
  scan(ProcessGroup pg, const T& value, BinaryOperation bin_op)
  {
    T result;
    scan(pg,
         const_cast<T*>(&value), const_cast<T*>(&value+1),
         &result, bin_op);
    return result;
  }


  template<typename ProcessGroup, typename InputIterator, typename T>
  void
  all_gather(ProcessGroup pg, InputIterator first, InputIterator last,
             std::vector<T>& out);
} } // end namespace streams_boost::parallel

#include <streams_boost/graph/parallel/detail/inplace_all_to_all.hpp>

#endif // STREAMS_BOOST_PARALLEL_ALGORITHM_HPP
