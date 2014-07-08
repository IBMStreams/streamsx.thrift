//////////////////////////////////////////////////////////////////////////////
//
// This file is the adaptation for Interprocess of streams_boost/detail/bad_weak_ptr.hpp
//
// (C) Copyright Peter Dimov and Multi Media Ltd. 2001, 2002, 2003
// (C) Copyright Ion Gaztanaga 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////
#ifndef STREAMS_BOOST_INTERPROCESS_BAD_WEAK_PTR_HPP_INCLUDED
#define STREAMS_BOOST_INTERPROCESS_BAD_WEAK_PTR_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>

#ifndef STREAMS_BOOST_NO_EXCEPTIONS
#include <exception>
#endif

namespace streams_boost{
namespace interprocess{

class bad_weak_ptr
   :  public std::exception
{
   public:

   virtual char const * what() const throw()
   {  return "streams_boost::interprocess::bad_weak_ptr"; }
};

} // namespace interprocess 
} // namespace streams_boost

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif  // #ifndef STREAMS_BOOST_INTERPROCESS_BAD_WEAK_PTR_HPP_INCLUDED
