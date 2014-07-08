// (C) Copyright 2005 Matthias Troyer 

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Matthias Troyer

#ifndef STREAMS_BOOST_MPI_DETAIL_IGNORE_SKELETON_OARCHIVE_HPP
#define STREAMS_BOOST_MPI_DETAIL_IGNORE_SKELETON_OARCHIVE_HPP

#include <streams_boost/serialization/pfto.hpp>

#include <streams_boost/archive/detail/auto_link_archive.hpp>
#include <streams_boost/archive/detail/common_oarchive.hpp>
#include <streams_boost/archive/basic_archive.hpp>
#include <streams_boost/archive/detail/oserializer.hpp>
#include <streams_boost/serialization/collection_size_type.hpp>
#include <streams_boost/serialization/array.hpp>

namespace streams_boost { namespace mpi { namespace detail {

template<class Archive>
class ignore_skeleton_oarchive 
  : public archive::detail::common_oarchive<Archive>
{
public:
    ignore_skeleton_oarchive()
      : archive::detail::common_oarchive<Archive>(archive::no_header)
    {
    }

#ifdef STREAMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
public:
#else
    friend class archive::detail::interface_oarchive<Archive>;
    friend class archive::save_access;
protected:
#endif

    // intermediate level to support override of operators
    // for templates in the absence of partial function 
    // template ordering
    template<class T>
    void save_override(T const& t, STREAMS_BOOST_PFTO int)
    {
        archive::save(* this->This(), t);
    }

#define STREAMS_BOOST_ARCHIVE_IGNORE_IMPLEMENTATION(T) \
    void save_override(T const & , int)        \
    {}

STREAMS_BOOST_ARCHIVE_IGNORE_IMPLEMENTATION(archive::class_id_optional_type)
STREAMS_BOOST_ARCHIVE_IGNORE_IMPLEMENTATION(archive::version_type)
STREAMS_BOOST_ARCHIVE_IGNORE_IMPLEMENTATION(archive::class_id_type)
STREAMS_BOOST_ARCHIVE_IGNORE_IMPLEMENTATION(archive::class_id_reference_type)
STREAMS_BOOST_ARCHIVE_IGNORE_IMPLEMENTATION(archive::object_id_type)
STREAMS_BOOST_ARCHIVE_IGNORE_IMPLEMENTATION(archive::object_reference_type)
STREAMS_BOOST_ARCHIVE_IGNORE_IMPLEMENTATION(archive::tracking_type)
STREAMS_BOOST_ARCHIVE_IGNORE_IMPLEMENTATION(archive::class_name_type)
STREAMS_BOOST_ARCHIVE_IGNORE_IMPLEMENTATION(serialization::collection_size_type)

    void save_override(std::string const & s, int)       
    {
      if (s.size())
        save_override(serialization::make_array(s.data(),s.size()),0);
    }

#undef STREAMS_BOOST_ARCHIVE_IGNORE_IMPLEMENTATION
};


} } } // end namespace streams_boost::mpi::detail

#endif // STREAMS_BOOST_MPI_DETAIL_IGNORE_SKELETON_OARCHIVE_HPP
