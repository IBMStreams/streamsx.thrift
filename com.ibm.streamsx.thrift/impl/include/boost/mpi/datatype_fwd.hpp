// Copyright (C) 2006 Douglas Gregor <doug.gregor -at- gmail.com>.

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/** @file datatype_fwd.hpp
 *
 *  This header provides forward declarations for the contents of the
 *  header @c datatype.hpp. It is expected to be used primarily by
 *  user-defined C++ classes that need to specialize @c
 *  is_mpi_datatype.
 */
#ifndef STREAMS_BOOST_MPI_DATATYPE_FWD_HPP
#define STREAMS_BOOST_MPI_DATATYPE_FWD_HPP

#include <streams_boost/mpi/config.hpp>

namespace streams_boost { namespace mpi {

template<typename T> struct is_mpi_builtin_datatype;
template<typename T> struct is_mpi_integer_datatype;
template<typename T> struct is_mpi_floating_point_datatype;
template<typename T> struct is_mpi_logical_datatype;
template<typename T> struct is_mpi_complex_datatype;
template<typename T> struct is_mpi_byte_datatype;
template<typename T> struct is_mpi_datatype;
template<typename T> MPI_Datatype get_mpi_datatype(const T& x = T());

/// a dummy data type giving MPI_PACKED as its MPI_Datatype
struct packed {};
} } // end namespace streams_boost::mpi

#endif // STREAMS_BOOST_MPI_MPI_DATATYPE_FWD_HPP
