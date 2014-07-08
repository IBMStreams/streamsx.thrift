// (C) Copyright 2005 Matthias Troyer

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Matthias Troyer

#ifndef STREAMS_BOOST_MPI_DETAIL_MPI_DATATYPE_OARCHIVE_HPP
#define STREAMS_BOOST_MPI_DETAIL_MPI_DATATYPE_OARCHIVE_HPP

#include <streams_boost/type_traits/is_enum.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/archive/detail/oserializer.hpp>
#include <streams_boost/archive/detail/auto_link_archive.hpp>
#include <streams_boost/archive/basic_archive.hpp>
#include <streams_boost/mpi/detail/ignore_skeleton_oarchive.hpp>
#include <streams_boost/mpi/detail/mpi_datatype_primitive.hpp>
#include <streams_boost/mpi/datatype_fwd.hpp>
#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/integer.hpp>
#include <streams_boost/archive/detail/register_archive.hpp>

namespace streams_boost { namespace mpi { namespace detail {


// an archive wrapper that stores only the data members but not the
// special types defined by the serialization library
// to define the data skeletons (classes, pointers, container sizes, ...)

class mpi_datatype_oarchive
  : public mpi_datatype_primitive,
    public ignore_skeleton_oarchive<mpi_datatype_oarchive>
{
public:
    template <class T>
    mpi_datatype_oarchive(const T& x)
         :  mpi_datatype_primitive(&x) // register address
        {
          STREAMS_BOOST_MPL_ASSERT((is_mpi_datatype<T>));
          *this << x;                   // serialize the object
        }
        
    // intermediate level to support override of operators
    // for templates in the absence of partial function 
    // template ordering
    template<class T>
    void save_override(T const& t, STREAMS_BOOST_PFTO int)
    {
      save_enum(t,streams_boost::is_enum<T>());
    }

    template<class T>
    void save_enum(T const& t, mpl::false_)
    {
      ignore_skeleton_oarchive<mpi_datatype_oarchive>::save_override(t, 0);
    }

    template<class T>
    void save_enum(T const& t, mpl::true_)
    {
      // select the right sized integer for the enum
      typedef typename streams_boost::uint_t<8*sizeof(T)>::least int_type;
      STREAMS_BOOST_STATIC_ASSERT((sizeof(T)==sizeof(int_type)));
      this->save(*reinterpret_cast<int_type const*>(&t));
    }

};

} } } // end namespace streams_boost::mpi::detail

// required by export
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(streams_boost::mpi::detail::mpi_datatype_oarchive)
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(streams_boost::mpi::detail::ignore_skeleton_oarchive<streams_boost::mpi::detail::mpi_datatype_oarchive>)
STREAMS_BOOST_SERIALIZATION_USE_ARRAY_OPTIMIZATION(streams_boost::mpi::detail::mpi_datatype_oarchive)

#endif // STREAMS_BOOST_MPI_DETAIL_MPI_DATATYPE_OARCHIVE_HPP
