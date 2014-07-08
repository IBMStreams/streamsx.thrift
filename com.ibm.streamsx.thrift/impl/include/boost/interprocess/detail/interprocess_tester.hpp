//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2007-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_DETAIL_INTERPROCESS_TESTER_HPP
#define STREAMS_BOOST_INTERPROCESS_DETAIL_INTERPROCESS_TESTER_HPP

namespace streams_boost{
namespace interprocess{
namespace detail{

class interprocess_tester
{
   public:
   template<class T>
   static void dont_close_on_destruction(T &t)
   {  t.dont_close_on_destruction(); }
};

}  //namespace detail{
}  //namespace interprocess{
}  //namespace streams_boost{

#endif   //#ifndef STREAMS_BOOST_INTERPROCESS_DETAIL_INTERPROCESS_TESTER_HPP

