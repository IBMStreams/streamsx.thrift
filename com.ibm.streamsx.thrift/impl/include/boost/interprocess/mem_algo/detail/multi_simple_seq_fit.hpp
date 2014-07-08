//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_MULTI_SIMPLE_SEQ_FIT_HPP
#define STREAMS_BOOST_INTERPROCESS_MULTI_SIMPLE_SEQ_FIT_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>

#include <streams_boost/interprocess/interprocess_fwd.hpp>
#include <streams_boost/interprocess/mem_algo/detail/simple_seq_fit_impl.hpp>
#include <streams_boost/interprocess/intersegment_ptr.hpp>

/*!\file
   Describes sequential fit algorithm used to allocate objects in shared memory.
*/

namespace streams_boost {

namespace interprocess {

/*!This class implements the simple sequential fit algorithm with a simply
   linked list of free buffers.*/
template<class MutexFamily, class VoidPtr>
class multi_simple_seq_fit 
   : public detail::simple_seq_fit_impl<MutexFamily, VoidPtr>
{
   typedef detail::simple_seq_fit_impl<MutexFamily, VoidPtr> base_t;
 public:
   /*!Constructor. "size" is the total size of the managed memory segment, 
      "extra_hdr_bytes" indicates the extra bytes beginning in the sizeof(multi_simple_seq_fit)
      offset that the allocator should not use at all.*/
   multi_simple_seq_fit           (std::size_t size, std::size_t extra_hdr_bytes)
      : base_t(size, extra_hdr_bytes){}

   /*!Allocates bytes from existing segments. If there is no memory, it uses
      the growing functor associated with the group to allocate a new segment.
      If this fails, returns 0.*/
   void* allocate             (std::size_t nbytes)
      {  return base_t::multi_allocate(nbytes);   }
};

}  //namespace interprocess {

}  //namespace streams_boost {

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif   //#ifndef STREAMS_BOOST_INTERPROCESS_MULTI_SIMPLE_SEQ_FIT_HPP

