//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////
#ifndef STREAMS_BOOST_INTERPROCESS_NULL_INDEX_HPP
#define STREAMS_BOOST_INTERPROCESS_NULL_INDEX_HPP

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>

#include <streams_boost/interprocess/offset_ptr.hpp>

//!\file
//!Describes a null index adaptor, so that if we don't want to construct 
//!named objects, we can use this null index type to save resources.

namespace streams_boost {
namespace interprocess {

//!Null index type
//!used to save compilation time when
//!named indexes are not needed.
template <class MapConfig>
class null_index
{
   /// @cond
   typedef typename MapConfig::
      segment_manager_base    segment_manager_base;
   /// @endcond

   public:
   typedef void * iterator;
   typedef const void * const_iterator;

   //!begin() is equal
   //!to end()
   const_iterator begin() const
   {  return const_iterator(0);  }

   //!begin() is equal
   //!to end()
   iterator begin()
   {  return iterator(0);  }

   //!begin() is equal
   //!to end()
   const_iterator end() const
   {  return const_iterator(0);  }

   //!begin() is equal
   //!to end()
   iterator end()
   {  return iterator(0);  }

   //!Empty constructor
   null_index(segment_manager_base *){}
};

}}   //namespace streams_boost { namespace interprocess {

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif   //#ifndef STREAMS_BOOST_INTERPROCESS_NULL_INDEX_HPP
