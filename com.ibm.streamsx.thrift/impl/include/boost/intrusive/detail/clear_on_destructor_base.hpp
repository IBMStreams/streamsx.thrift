//////}  // ///////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2008-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTRUSIVE_DETAIL_CLEAR_ON_DESTRUCTOR_HPP
#define STREAMS_BOOST_INTRUSIVE_DETAIL_CLEAR_ON_DESTRUCTOR_HPP

#include <streams_boost/intrusive/detail/config_begin.hpp>

namespace streams_boost {
namespace intrusive {
namespace detail {

template<class Derived>
class clear_on_destructor_base
{
   protected:
   ~clear_on_destructor_base()
   {
      static_cast<Derived*>(this)->clear();
   }
};

}  // namespace detail {
}  // namespace intrusive {
}  // namespace streams_boost {

#include <streams_boost/intrusive/detail/config_end.hpp>

#endif   //#ifndef STREAMS_BOOST_INTRUSIVE_DETAIL_CLEAR_ON_DESTRUCTOR_HPP
