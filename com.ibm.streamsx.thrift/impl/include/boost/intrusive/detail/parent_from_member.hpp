/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga  2007-2009
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////
#ifndef STREAMS_BOOST_INTRUSIVE_PARENT_FROM_MEMBER_HPP
#define STREAMS_BOOST_INTRUSIVE_PARENT_FROM_MEMBER_HPP

#include <streams_boost/intrusive/detail/config_begin.hpp>
#include <cstddef>

#if defined(STREAMS_BOOST_MSVC) || ((defined(_WIN32) || defined(__WIN32__) || defined(WIN32)) && defined(STREAMS_BOOST_INTEL))

#define STREAMS_BOOST_INTRUSIVE_MSVC_COMPLIANT_PTR_TO_MEMBER
#include <streams_boost/cstdint.hpp>
#endif

namespace streams_boost {
namespace intrusive {
namespace detail {

template<class Parent, class Member>
inline std::ptrdiff_t offset_from_pointer_to_member(const Member Parent::* ptr_to_member)
{
   //The implementation of a pointer to member is compiler dependent.
   #if defined(STREAMS_BOOST_INTRUSIVE_MSVC_COMPLIANT_PTR_TO_MEMBER)
   //msvc compliant compilers use their the first 32 bits as offset (even in 64 bit mode)
   return *(const streams_boost::int32_t*)(void*)&ptr_to_member;
   //This works with gcc, msvc, ac++, ibmcpp
   #elif defined(__GNUC__)   || defined(__HP_aCC) || defined(STREAMS_BOOST_INTEL) || \
         defined(__IBMCPP__) || defined(__DECCXX)
   const Parent * const parent = 0;
   const char *const member = reinterpret_cast<const char*>(&(parent->*ptr_to_member));
   return std::ptrdiff_t(member - reinterpret_cast<const char*>(parent));
   #else
   //This is the traditional C-front approach: __MWERKS__, __DMC__, __SUNPRO_CC
   return (*(const std::ptrdiff_t*)(void*)&ptr_to_member) - 1;
   #endif
}

template<class Parent, class Member>
inline Parent *parent_from_member(Member *member, const Member Parent::* ptr_to_member)
{
   return (Parent*)((char*)member - 
      offset_from_pointer_to_member(ptr_to_member));
}

template<class Parent, class Member>
inline const Parent *parent_from_member(const Member *member, const Member Parent::* ptr_to_member)
{
   return (const Parent*)((const char*)member - 
      offset_from_pointer_to_member(ptr_to_member));
}

}  //namespace detail {
}  //namespace intrusive {
}  //namespace streams_boost {

#ifdef STREAMS_BOOST_INTRUSIVE_MSVC_COMPLIANT_PTR_TO_MEMBER
#undef STREAMS_BOOST_INTRUSIVE_MSVC_COMPLIANT_PTR_TO_MEMBER
#endif

#include <streams_boost/intrusive/detail/config_end.hpp>

#endif   //#ifndef STREAMS_BOOST_INTRUSIVE_PARENT_FROM_MEMBER_HPP
