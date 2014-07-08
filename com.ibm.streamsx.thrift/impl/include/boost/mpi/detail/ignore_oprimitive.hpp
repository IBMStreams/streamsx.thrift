// (C) Copyright 2005 Matthias Troyer

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Matthias Troyer

#ifndef STREAMS_BOOST_MPI_DETAIL_IGNORE_OPRIMITIVE_HPP
#define STREAMS_BOOST_MPI_DETAIL_IGNORE_OPRIMITIVE_HPP

#include <streams_boost/config.hpp>
#include <streams_boost/mpi/datatype.hpp>
#include <streams_boost/serialization/array.hpp>

namespace streams_boost { namespace mpi { namespace detail {

/// @brief a minimal output archive, which ignores any save
///
/// This class implements a minimal output archive, probably an output archive
/// archetype, doing nothing at any save. It's use, besides acting as an
/// archetype is as a base class to implement special archives that ignore
/// saving of most types

class ignore_oprimitive
{
public:
    /// a trivial default constructor
    ignore_oprimitive()
    {}

        /// don't do anything when saving binary data
    void save_binary(const void *, std::size_t )
    {
    }

        /// don't do anything when saving arrays
    template<class T>
    void save_array(serialization::array<T> const&, unsigned int )
    {
    }

    typedef is_mpi_datatype<mpl::_1> use_array_optimization;


#ifndef STREAMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
    friend class archive::save_access;
protected:
#else
public:
#endif

        /// don't do anything when saving primitive types
    template<class T>
    void save(const T & t)
    {
    }
};

} } } // end namespace streams_boost::mpi::detail

#endif // STREAMS_BOOST_MPI_DETAIL_IGNORE_OPRIMITIVE_HPP
