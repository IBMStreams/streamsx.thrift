// Copyright (C) 2006 Douglas Gregor <doug.gregor -at- gmail.com>.

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// Message Passing Interface

//  See www.streams_boost.org/libs/mpi for documentation.

/** @file mpi.hpp
 *
 *  This file is a top-level convenience header that includes all of
 *  the Boost.MPI library headers. Users concerned about compile time
 *  may wish to include only specific headers from the Boost.MPI
 *  library.
 *
 */
#ifndef STREAMS_BOOST_MPI_HPP
#define STREAMS_BOOST_MPI_HPP

#include <streams_boost/mpi/allocator.hpp>
#include <streams_boost/mpi/collectives.hpp>
#include <streams_boost/mpi/communicator.hpp>
#include <streams_boost/mpi/datatype.hpp>
#include <streams_boost/mpi/environment.hpp>
#include <streams_boost/mpi/graph_communicator.hpp>
#include <streams_boost/mpi/group.hpp>
#include <streams_boost/mpi/intercommunicator.hpp>
#include <streams_boost/mpi/nonblocking.hpp>
#include <streams_boost/mpi/operations.hpp>
#include <streams_boost/mpi/skeleton_and_content.hpp>
#include <streams_boost/mpi/timer.hpp>

#endif // STREAMS_BOOST_MPI_HPP
