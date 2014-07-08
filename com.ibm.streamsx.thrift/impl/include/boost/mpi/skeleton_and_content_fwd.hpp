// (C) Copyright 2006 Douglas Gregor <doug.gregor -at gmail.com>

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Douglas Gregor

/** @file skeleton_and_content_fwd.hpp
 *
 *  This header contains all of the forward declarations required to
 *  use transmit skeletons of data structures and the content of data
 *  structures separately. To actually transmit skeletons or content,
 *  include the header @c streams_boost/mpi/skeleton_and_content.hpp.
 */

#ifndef STREAMS_BOOST_MPI_SKELETON_AND_CONTENT_FWD_HPP
#define STREAMS_BOOST_MPI_SKELETON_AND_CONTENT_FWD_HPP

namespace streams_boost { namespace mpi {

template <class T> struct skeleton_proxy;
template <class T> const skeleton_proxy<T> skeleton(T& x);
class content;
template <class T> const content get_content(const T& x);
class packed_skeleton_iarchive;
class packed_skeleton_oarchive;

} } // end namespace streams_boost::mpi

#endif // STREAMS_BOOST_MPI_SKELETON_AND_CONTENT_FWD_HPP
