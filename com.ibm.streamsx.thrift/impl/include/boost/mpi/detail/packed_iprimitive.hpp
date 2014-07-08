// (C) Copyright 2005 Matthias Troyer

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Matthias Troyer

#ifndef STREAMS_BOOST_MPI_PACKED_IPRIMITIVE_HPP
#define STREAMS_BOOST_MPI_PACKED_IPRIMITIVE_HPP

#include <streams_boost/mpi/config.hpp>
#include <iostream>
#include <cstddef> // size_t
#include <streams_boost/config.hpp>
#include <streams_boost/mpi/datatype.hpp>
#include <streams_boost/mpi/exception.hpp>
#include <streams_boost/assert.hpp>
#include <streams_boost/serialization/array.hpp>
#include <streams_boost/serialization/detail/get_data.hpp>
#include <vector>
#include <streams_boost/mpi/allocator.hpp>

namespace streams_boost { namespace mpi {

/// deserialization using MPI_Unpack

class STREAMS_BOOST_MPI_DECL packed_iprimitive
{
public:
    /// the type of the buffer from which the data is unpacked upon deserialization
    typedef std::vector<char, allocator<char> > buffer_type;

    packed_iprimitive(buffer_type & b, MPI_Comm const & comm, int position = 0)
         : buffer_(b),
           comm(comm),
           position(position)
        {
        }

    void* address ()
    {
      return &buffer_[0];
    }

    void const* address () const
    {
      return &buffer_[0];
    }

    const std::size_t& size() const
    {
      return size_ = buffer_.size();
    }

    void resize(std::size_t s)
    {
      buffer_.resize(s);
    }

    void load_binary(void *address, std::size_t count)
        {
          load_impl(address,MPI_BYTE,count);
        }

    // fast saving of arrays of fundamental types
    template<class T>
    void load_array(serialization::array<T> const& x, unsigned int /* file_version */)
    {
      if (x.count())
        load_impl(x.address(), get_mpi_datatype(*x.address()), x.count());
    }

    template<class T>
    void load(serialization::array<T> const& x)
    {
      load_array(x,0u);
    }

    typedef is_mpi_datatype<mpl::_1> use_array_optimization;

    // default saving of primitives.
    template<class T>
    void load( T & t)
    {
        load_impl(&t, get_mpi_datatype(t), 1);
    }

    void load( std::string & s)
    {
       unsigned int l;
        load(l);
        // borland de-allocator fixup
        #if STREAMS_BOOST_WORKAROUND(_RWSTD_VER, STREAMS_BOOST_TESTED_AT(20101))
        if(NULL != s.data())
        #endif
        s.resize(l);
        // note breaking a rule here - could be a problem on some platform
        load_impl(const_cast<char *>(s.data()),MPI_CHAR,l);
    }

private:

    void load_impl(void * p, MPI_Datatype t, int l)
    {
        STREAMS_BOOST_MPI_CHECK_RESULT(MPI_Unpack,
        (const_cast<char*>(streams_boost::serialization::detail::get_data(buffer_)), buffer_.size(), &position, p, l, t, comm));
    }

        buffer_type & buffer_;
        mutable std::size_t size_;
        MPI_Comm comm;
        int position;
};

} } // end namespace streams_boost::mpi

#endif // STREAMS_BOOST_MPI_PACKED_IPRIMITIVE_HPP
