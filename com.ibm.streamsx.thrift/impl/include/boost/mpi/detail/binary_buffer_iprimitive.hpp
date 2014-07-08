// (C) Copyright 2005-2007 Matthias Troyer

// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Matthias Troyer

#ifndef STREAMS_BOOST_MPI_BINARY_BUFFER_IPRIMITIVE_HPP
#define STREAMS_BOOST_MPI_BINARY_BUFFER_IPRIMITIVE_HPP

#include <mpi.h>
#include <iostream>
#include <cstddef> // size_t
#include <streams_boost/config.hpp>
#include <streams_boost/mpi/exception.hpp>
#include <streams_boost/assert.hpp>
#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/serialization/array.hpp>
#include <streams_boost/serialization/is_bitwise_serializable.hpp>
#include <vector>
#include <streams_boost/mpi/allocator.hpp>
#include <cstring> // for memcpy

namespace streams_boost { namespace mpi {

/// deserialization using MPI_Unpack

class STREAMS_BOOST_MPI_DECL binary_buffer_iprimitive
{
public:
    /// the type of the buffer from which the data is unpacked upon deserialization
    typedef std::vector<char, allocator<char> > buffer_type;

    binary_buffer_iprimitive(buffer_type & b, MPI_Comm const &, int position = 0)
     : buffer_(b),
       position(position)
    {
    }

    void* address ()
    {
      return &buffer_.front();
    }

    void const* address () const
    {
      return &buffer_.front();
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
      load_impl(address,count);
    }

    // fast saving of arrays of fundamental types
    template<class T>
    void load_array(serialization::array<T> const& x, unsigned int /* file_version */)
    {
      STREAMS_BOOST_MPL_ASSERT((serialization::is_bitwise_serializable<STREAMS_BOOST_DEDUCED_TYPENAME remove_const<T>::type>));
      if (x.count())
        load_impl(x.address(), sizeof(T)*x.count());
    }

    typedef serialization::is_bitwise_serializable<mpl::_1> use_array_optimization;

    template<class T>
    void load(serialization::array<T> const& x)
    {
      load_array(x,0u);
    }

    // default saving of primitives.
    template<class T>
    void load( T & t)
    {
      STREAMS_BOOST_MPL_ASSERT((serialization::is_bitwise_serializable<STREAMS_BOOST_DEDUCED_TYPENAME remove_const<T>::type>));
      load_impl(&t, sizeof(T));
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
      load_impl(const_cast<char *>(s.data()),l);
    }

private:

    void load_impl(void * p, int l)
    {
      assert(position+l<=static_cast<int>(buffer_.size()));
      std::memcpy(p,&buffer_[position],l);
      position += l;
    }

    buffer_type & buffer_;
    mutable std::size_t size_;
    int position;
};

} } // end namespace streams_boost::mpi

#endif // STREAMS_BOOST_MPI_PACKED_IPRIMITIVE_HPP
