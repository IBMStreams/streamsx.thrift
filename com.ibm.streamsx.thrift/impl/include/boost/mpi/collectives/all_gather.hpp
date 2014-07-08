// Copyright (C) 2005-2006 Douglas Gregor <doug.gregor -at- gmail.com>.

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// Message Passing Interface 1.1 -- Section 4.7. Gather-to-all
#ifndef STREAMS_BOOST_MPI_ALL_GATHER_HPP
#define STREAMS_BOOST_MPI_ALL_GATHER_HPP

#include <streams_boost/mpi/exception.hpp>
#include <streams_boost/mpi/datatype.hpp>
#include <vector>
#include <streams_boost/serialization/vector.hpp>

// all_gather falls back to gather+broadcast in some cases
#include <streams_boost/mpi/collectives/broadcast.hpp>
#include <streams_boost/mpi/collectives/gather.hpp>

namespace streams_boost { namespace mpi {

namespace detail {
  // We're all-gathering for a type that has an associated MPI
  // datatype, so we'll use MPI_Gather to do all of the work.
  template<typename T>
  void
  all_gather_impl(const communicator& comm, const T* in_values, int n, 
                  T* out_values, mpl::true_)
  {
    MPI_Datatype type = streams_boost::mpi::get_mpi_datatype<T>(*in_values);
    STREAMS_BOOST_MPI_CHECK_RESULT(MPI_Allgather,
                           (const_cast<T*>(in_values), n, type,
                            out_values, n, type, comm));
  }

  // We're all-gathering for a type that has no associated MPI
  // type. So, we'll do a manual gather followed by a broadcast.
  template<typename T>
  void
  all_gather_impl(const communicator& comm, const T* in_values, int n, 
                  T* out_values, mpl::false_)
  {
    gather(comm, in_values, n, out_values, 0);
    broadcast(comm, out_values, comm.size() * n, 0);
  }
} // end namespace detail

template<typename T>
inline void
all_gather(const communicator& comm, const T& in_value, T* out_values)
{
  detail::all_gather_impl(comm, &in_value, 1, out_values, is_mpi_datatype<T>());
}

template<typename T>
void
all_gather(const communicator& comm, const T& in_value, 
           std::vector<T>& out_values)
{
  out_values.resize(comm.size());
  ::streams_boost::mpi::all_gather(comm, &in_value, 1, &out_values[0]);
}

template<typename T>
inline void
all_gather(const communicator& comm, const T* in_values, int n, T* out_values)
{
  detail::all_gather_impl(comm, in_values, n, out_values, is_mpi_datatype<T>());
}

template<typename T>
void
all_gather(const communicator& comm, const T* in_values, int n,
           std::vector<T>& out_values)
{
  out_values.resize(comm.size() * n);
  ::streams_boost::mpi::all_gather(comm, in_values, n, &out_values[0]);
}

} } // end namespace streams_boost::mpi

#endif // STREAMS_BOOST_MPI_ALL_GATHER_HPP
