// (C) Copyright 2005 Matthias Troyer

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Matthias Troyer

#ifndef STREAMS_BOOST_MPI_DETAIL_CONTENT_OARCHIVE_HPP
#define STREAMS_BOOST_MPI_DETAIL_CONTENT_OARCHIVE_HPP

#include <streams_boost/archive/detail/auto_link_archive.hpp>
#include <streams_boost/archive/basic_archive.hpp>
#include <streams_boost/mpi/detail/ignore_skeleton_oarchive.hpp>
#include <streams_boost/mpi/detail/mpi_datatype_primitive.hpp>
#include <streams_boost/mpi/datatype.hpp>
#include <streams_boost/archive/detail/register_archive.hpp>

namespace streams_boost { namespace mpi {

namespace detail {
  // an archive wrapper that stores only the data members but not the
  // special types defined by the serialization library
  // to define the data skeletons (classes, pointers, container sizes, ...)

  class STREAMS_BOOST_MPI_DECL content_oarchive
    : public mpi_datatype_primitive,
      public ignore_skeleton_oarchive<content_oarchive>
  {
  public:
      content_oarchive()
       : committed(false)
          {}

      content get_content()
      {
        if (!committed)
        {
          // create the content holder only once
          c=this->get_mpi_datatype();
          committed=true;
        }
        return c;
      }

  private:
    bool committed;
    content c;
  };
} // end namespace detail

template <class T>
const content get_content(const T& x)
{
  detail::content_oarchive ar;
  ar << x;
  return ar.get_content();
}

} } // end namespace streams_boost::mpi

// required by export
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(streams_boost::mpi::detail::content_oarchive)
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(streams_boost::mpi::detail::ignore_skeleton_oarchive<streams_boost::mpi::detail::content_oarchive>)
STREAMS_BOOST_SERIALIZATION_USE_ARRAY_OPTIMIZATION(streams_boost::mpi::detail::content_oarchive)
#endif // STREAMS_BOOST_MPI_DETAIL_CONTENT_OARCHIVE_HPP
