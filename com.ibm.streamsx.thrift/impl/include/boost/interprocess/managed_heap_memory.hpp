//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_MANAGED_HEAP_MEMORY_HPP
#define STREAMS_BOOST_INTERPROCESS_MANAGED_HEAP_MEMORY_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>
#include <streams_boost/interprocess/creation_tags.hpp>
#include <streams_boost/interprocess/detail/move.hpp>
#include <vector>
#include <streams_boost/interprocess/detail/managed_memory_impl.hpp>
#include <streams_boost/detail/no_exceptions_support.hpp>

//!\file
//!Describes a named heap memory allocation user class. 

namespace streams_boost {
namespace interprocess {

//!A basic heap memory named object creation class. Initializes the 
//!heap memory segment. Inherits all basic functionality from 
//!basic_managed_memory_impl<CharType, AllocationAlgorithm, IndexType>*/
template
      <
         class CharType, 
         class AllocationAlgorithm, 
         template<class IndexConfig> class IndexType
      >
class basic_managed_heap_memory 
   : public detail::basic_managed_memory_impl <CharType, AllocationAlgorithm, IndexType>
{
   /// @cond
   private:

   typedef detail::basic_managed_memory_impl 
      <CharType, AllocationAlgorithm, IndexType>             base_t;
   STREAMS_BOOST_INTERPROCESS_MOVABLE_BUT_NOT_COPYABLE(basic_managed_heap_memory)
   /// @endcond

   public: //functions

   //!Default constructor. Does nothing.
   //!Useful in combination with move semantics
   basic_managed_heap_memory(){}

   //!Destructor. Liberates the heap memory holding the managed data.
   //!Never throws.
   ~basic_managed_heap_memory()
   {  this->priv_close();  }

   //!Creates heap memory and initializes the segment manager.
   //!This can throw.
   basic_managed_heap_memory(std::size_t size)
      :  m_heapmem(size, char(0))
   {
      if(!base_t::create_impl(&m_heapmem[0], size)){
         this->priv_close();
         throw interprocess_exception();
      }
   }

   //!Moves the ownership of "moved"'s managed memory to *this. Does not throw
   basic_managed_heap_memory(STREAMS_BOOST_INTERPROCESS_RV_REF(basic_managed_heap_memory) moved)
   {  this->swap(moved);   }

   //!Moves the ownership of "moved"'s managed memory to *this. Does not throw
   basic_managed_heap_memory &operator=(STREAMS_BOOST_INTERPROCESS_RV_REF(basic_managed_heap_memory) moved)
   {
      basic_managed_heap_memory tmp(streams_boost::interprocess::move(moved));
      this->swap(tmp);
      return *this;
   }

   //!Tries to resize internal heap memory so that
   //!we have room for more objects. 
   //!WARNING: If memory is reallocated, all the objects will 
   //!be binary-copied to the new buffer. To be able to use
   //!this function, all pointers constructed in this buffer
   //!must be offset pointers. Otherwise, the result is undefined.
   //!Returns true if the growth has been successful, so you will
   //!have some extra bytes to allocate new objects. If returns 
   //!false, the heap allocation has failed.
   bool grow(std::size_t extra_bytes)
   {  
      //If memory is reallocated, data will
      //be automatically copied
      STREAMS_BOOST_TRY{
         m_heapmem.resize(m_heapmem.size()+extra_bytes);
      }
      STREAMS_BOOST_CATCH(...){
         return false;
      }
      STREAMS_BOOST_CATCH_END

      //Grow always works
      base_t::close_impl();
      base_t::open_impl(&m_heapmem[0], m_heapmem.size());
      base_t::grow(extra_bytes);
      return true;
   }

   //!Swaps the ownership of the managed heap memories managed by *this and other.
   //!Never throws.
   void swap(basic_managed_heap_memory &other)
   {
      base_t::swap(other);
      m_heapmem.swap(other.m_heapmem);
   }

   /// @cond
   private:
   //!Frees resources. Never throws.
   void priv_close()
   {  
      base_t::destroy_impl();
      std::vector<char>().swap(m_heapmem);
   }

   std::vector<char>  m_heapmem;
   /// @endcond
};


}  //namespace interprocess {
}  //namespace streams_boost {

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif   //STREAMS_BOOST_INTERPROCESS_MANAGED_HEAP_MEMORY_HPP
