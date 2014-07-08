//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_MULTI_SEGMENT_SERVICES_HPP
#define STREAMS_BOOST_INTERPROCESS_MULTI_SEGMENT_SERVICES_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>


/*!\file
   Describes a named shared memory allocation user class. 
*/

namespace streams_boost {

namespace interprocess {

class multi_segment_services
{
   public:
   virtual std::pair<void *, std::size_t> create_new_segment(std::size_t mem) = 0;
   virtual bool                           update_segments   () = 0;
   virtual ~multi_segment_services() = 0;
};

inline multi_segment_services::~multi_segment_services()
{}


}} //namespace streams_boost {  namespace interprocess {

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif //#ifdef STREAMS_BOOST_INTERPROCESS_MULTI_SEGMENT_SERVICES_HPP
