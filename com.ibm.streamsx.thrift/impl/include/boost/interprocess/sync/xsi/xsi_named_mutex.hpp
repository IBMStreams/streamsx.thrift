//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_XSI_XSI_NAMED_MUTEX_HPP
#define STREAMS_BOOST_INTERPROCESS_XSI_XSI_NAMED_MUTEX_HPP

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>

#if defined(STREAMS_BOOST_INTERPROCESS_WINDOWS)
#error "This header can't be used in Windows operating systems"
#endif

#include <streams_boost/interprocess/detail/move.hpp>
#include <streams_boost/interprocess/creation_tags.hpp>
#include <streams_boost/interprocess/exceptions.hpp>
#include <streams_boost/interprocess/detail/utilities.hpp>
#include <streams_boost/interprocess/detail/os_file_functions.hpp>
#include <streams_boost/interprocess/interprocess_fwd.hpp>
#include <streams_boost/interprocess/exceptions.hpp>
#include <streams_boost/interprocess/sync/xsi/basic_xsi_semaphore.hpp>
#include <cstddef>
#include <cassert>
#include <streams_boost/cstdint.hpp>
#include <string>

//!\file
//!Describes a class representing a xsi-based named_mutex.

namespace streams_boost {
namespace interprocess {

//!A class that wraps a XSI (System V)-based named semaphore
//!that undoes the operation if the process crashes.
class xsi_named_mutex
{
   /// @cond
   //Non-copyable and non-assignable
   xsi_named_mutex(xsi_named_mutex &);
   xsi_named_mutex &operator=(xsi_named_mutex &);
   /// @endcond

   public:
   STREAMS_BOOST_INTERPROCESS_MOVABLE_BUT_NOT_COPYABLE(xsi_named_mutex)

   //!Default constructor.
   //!Represents an empty xsi_named_mutex.
   xsi_named_mutex();

   //!Tries to create a new XSI-based named mutex with a key obtained from a call to ftok (with path
   //!"path" and id "id"), and permissions "perm".
   //!If the named mutex previously exists, it tries to open it.
   //!Otherwise throws an error.
   xsi_named_mutex(open_or_create_t, const char *path, streams_boost::uint8_t id, int perm = 0666)
   {  this->priv_open_or_create(detail::DoOpenOrCreate, path, id, perm);  }

   //!Moves the ownership of "moved"'s named mutex to *this. 
   //!After the call, "moved" does not represent any named mutex 
   //!Does not throw
   xsi_named_mutex(STREAMS_BOOST_INTERPROCESS_RV_REF(xsi_named_mutex) moved)
   {  this->swap(moved);   }

   //!Moves the ownership of "moved"'s named mutex to *this.
   //!After the call, "moved" does not represent any named mutex. 
   //!Does not throw
   xsi_named_mutex &operator=(STREAMS_BOOST_INTERPROCESS_RV_REF(xsi_named_mutex) moved)
   {  
      xsi_named_mutex tmp(streams_boost::interprocess::move(moved));
      this->swap(tmp);
      return *this;  
   }

   //!Swaps two xsi_named_mutex. Does not throw
   void swap(xsi_named_mutex &other);

   //!Destroys *this. The named mutex is still valid after
   //!destruction. use remove() to destroy the named mutex.
   ~xsi_named_mutex();

   //!Returns the path used to construct the
   //!named mutex.
   const char *get_path() const;

   //!Returns access
   //!permissions
   int get_permissions() const;

   //!Returns the mapping handle.
   //!Never throws
   mapping_handle_t get_mapping_handle() const;

   //!Erases a XSI-based named mutex from the system.
   //!Returns false on error. Never throws
   bool remove();

   void lock();

   void unlock();

   /// @cond
   private:

   //!Closes a previously opened file mapping. Never throws.
   void priv_close();

   //!Closes a previously opened file mapping. Never throws.
   bool priv_open_or_create( detail::create_enum_t type
                           , const char *path
                           , streams_boost::uint8_t id
                           , int perm);
   int            m_semid;
   key_t          m_key;
   streams_boost::uint8_t m_id;
   int            m_perm;
   std::string    m_path;
   /// @endcond
};

/// @cond

inline xsi_named_mutex::xsi_named_mutex() 
   :  m_semid(-1), m_key(-1), m_id(0), m_perm(0), m_path()
{}

inline xsi_named_mutex::~xsi_named_mutex() 
{  this->priv_close(); }

inline const char *xsi_named_mutex::get_path() const
{  return m_path.c_str(); }

inline void xsi_named_mutex::swap(xsi_named_mutex &other)
{
   std::swap(m_key,   other.m_key);
   std::swap(m_id,    other.m_id);
   std::swap(m_semid, other.m_semid);
   std::swap(m_perm,  other.m_perm);
   m_path.swap(other.m_path);   
}

inline mapping_handle_t xsi_named_mutex::get_mapping_handle() const
{  mapping_handle_t mhnd = { m_semid, true};   return mhnd;   }

inline int xsi_named_mutex::get_permissions() const
{  return m_perm; }

inline bool xsi_named_mutex::priv_open_or_create
   (detail::create_enum_t type, const char *path, streams_boost::uint8_t id, int perm)
{
   key_t key;
   if(path){
      key  = ::ftok(path, id);
      if(((key_t)-1) == key){
         error_info err = system_error_code();
         throw interprocess_exception(err);
      }
   }
   else{
      key = IPC_PRIVATE;
   }

   perm &= 0x01FF;

   int semid;
   if(!xsi::simple_sem_open_or_create(key, 1, semid, perm)){
      error_info err = system_error_code();
      throw interprocess_exception(err);
   }

   m_perm = perm;
   m_semid = semid;
   m_path = path ? path : "";
   m_id   = id;
   m_key  = key;

   return true;
}

inline void xsi_named_mutex::priv_close()
{
}

inline void xsi_named_mutex::lock()
{
	if(!xsi::simple_sem_op(m_semid, -1)){
      error_info err = system_error_code();
      throw interprocess_exception(err);
   }
}

inline void xsi_named_mutex::unlock()
{
   bool success = xsi::simple_sem_op(m_semid, 1);
   (void)success;
   assert(success);
}

inline bool xsi_named_mutex::remove()
{
   if(m_semid != -1){
      int ret = ::semctl(m_semid, IPC_RMID, 0);
      if(-1 == ret)
         return false;
      //Now put it in default-constructed state
      m_semid  = -1;
      m_key    = -1;
      m_id     = 0;
      m_perm   = 0;
      m_path.clear();
   }
   return false;
}

///@endcond

}  //namespace interprocess {
}  //namespace streams_boost {

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif   //STREAMS_BOOST_INTERPROCESS_XSI_XSI_NAMED_MUTEX_HPP
