// Copyright (C) 2005, 2006 Douglas Gregor.

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// Message Passing Interface 1.1 -- Section 4.5. Gather
#ifndef STREAMS_BOOST_MPI_GATHER_HPP
#define STREAMS_BOOST_MPI_GATHER_HPP

#include <streams_boost/mpi/exception.hpp>
#include <streams_boost/mpi/datatype.hpp>
#include <vector>
#include <streams_boost/mpi/packed_oarchive.hpp>
#include <streams_boost/mpi/packed_iarchive.hpp>
#include <streams_boost/mpi/detail/point_to_point.hpp>
#include <streams_boost/mpi/communicator.hpp>
#include <streams_boost/mpi/environment.hpp>
#include <streams_boost/assert.hpp>

namespace streams_boost { namespace mpi {

namespace detail {
  // We're gathering at the root for a type that has an associated MPI
  // datatype, so we'll use MPI_Gather to do all of the work.
  template<typename T>
  void
  gather_impl(const communicator& comm, const T* in_values, int n, 
              T* out_values, int root, mpl::true_)
  {
    MPI_Datatype type = get_mpi_datatype<T>(*in_values);
    STREAMS_BOOST_MPI_CHECK_RESULT(MPI_Gather,
                           (const_cast<T*>(in_values), n, type,
                            out_values, n, type, root, comm));
  }

  // We're gathering from a non-root for a type that has an associated MPI
  // datatype, so we'll use MPI_Gather to do all of the work.
  template<typename T>
  void
  gather_impl(const communicator& comm, const T* in_values, int n, int root, 
              mpl::true_)
  {
    MPI_Datatype type = get_mpi_datatype<T>(*in_values);
    STREAMS_BOOST_MPI_CHECK_RESULT(MPI_Gather,
                           (const_cast<T*>(in_values), n, type,
                            0, n, type, root, comm));
  }

  // We're gathering at the root for a type that does not have an
  // associated MPI datatype, so we'll need to serialize
  // it. Unfortunately, this means that we cannot use MPI_Gather, so
  // we'll just have all of the non-root nodes send individual
  // messages to the root.
  template<typename T>
  void
  gather_impl(const communicator& comm, const T* in_values, int n, 
              T* out_values, int root, mpl::false_)
  {
    int tag = environment::collectives_tag();
    int size = comm.size();

    for (int src = 0; src < size; ++src) {
      if (src == root)
        std::copy(in_values, in_values + n, out_values + n * src);
      else
        comm.recv(src, tag, out_values + n * src, n);
    }
  }

  // We're gathering at a non-root for a type that does not have an
  // associated MPI datatype, so we'll need to serialize
  // it. Unfortunately, this means that we cannot use MPI_Gather, so
  // we'll just have all of the non-root nodes send individual
  // messages to the root.
  template<typename T>
  void
  gather_impl(const communicator& comm, const T* in_values, int n, int root, 
              mpl::false_)
  {
    int tag = environment::collectives_tag();
    comm.send(root, tag, in_values, n);
  }
} // end namespace detail

template<typename T>
void
gather(const communicator& comm, const T& in_value, T* out_values, int root)
{
  if (comm.rank() == root)
    detail::gather_impl(comm, &in_value, 1, out_values, root, 
                        is_mpi_datatype<T>());
  else
    detail::gather_impl(comm, &in_value, 1, root, is_mpi_datatype<T>());
}

template<typename T>
void gather(const communicator& comm, const T& in_value, int root)
{
  STREAMS_BOOST_ASSERT(comm.rank() != root);
  detail::gather_impl(comm, &in_value, 1, root, is_mpi_datatype<T>());
}

template<typename T>
void
gather(const communicator& comm, const T& in_value, std::vector<T>& out_values,
       int root)
{
  if (comm.rank() == root) {
    out_values.resize(comm.size());
    ::streams_boost::mpi::gather(comm, in_value, &out_values[0], root);
  } else {
    ::streams_boost::mpi::gather(comm, in_value, root);
  }
}

template<typename T>
void
gather(const communicator& comm, const T* in_values, int n, T* out_values, 
       int root)
{
  if (comm.rank() == root)
    detail::gather_impl(comm, in_values, n, out_values, root, 
                        is_mpi_datatype<T>());
  else
    detail::gather_impl(comm, in_values, n, root, is_mpi_datatype<T>());
}

template<typename T>
void
gather(const communicator& comm, const T* in_values, int n, 
       std::vector<T>& out_values, int root)
{
  ::streams_boost::mpi::gather(comm, in_values, n, &out_values[0], root);
}

template<typename T>
void gather(const communicator& comm, const T* in_values, int n, int root)
{
  STREAMS_BOOST_ASSERT(comm.rank() != root);
  detail::gather_impl(comm, in_values, n, root, is_mpi_datatype<T>());
}


} } // end namespace streams_boost::mpi

#endif // STREAMS_BOOST_MPI_GATHER_HPP
