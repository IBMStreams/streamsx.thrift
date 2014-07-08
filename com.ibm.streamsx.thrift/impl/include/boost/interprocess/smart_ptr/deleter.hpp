//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2007-2009.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_DELETER_HPP
#define STREAMS_BOOST_INTERPROCESS_DELETER_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/interprocess_fwd.hpp>
#include <streams_boost/interprocess/detail/utilities.hpp>
#include <streams_boost/pointer_to_other.hpp>

//!\file
//!Describes the functor to delete objects from the segment.

namespace streams_boost {
namespace interprocess { 

//!A deleter that uses the segment manager's destroy_ptr 
//!function to destroy the passed pointer resource.
//!
//!This deleter is used
template<class T, class SegmentManager>
class deleter
{
   public:
   typedef typename streams_boost::pointer_to_other
      <typename SegmentManager::void_pointer, T>::type   pointer;

   private:
   typedef typename streams_boost::pointer_to_other
      <pointer, SegmentManager>::type   segment_manager_pointer;

   segment_manager_pointer mp_mngr;

   public:
   deleter(segment_manager_pointer pmngr)
      :  mp_mngr(pmngr)
   {}

   void operator()(const pointer &p)
   {  mp_mngr->destroy_ptr(detail::get_pointer(p));   }
};

}  //namespace interprocess { 
}  //namespace streams_boost {

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif   //#ifndef STREAMS_BOOST_INTERPROCESS_DELETER_HPP
