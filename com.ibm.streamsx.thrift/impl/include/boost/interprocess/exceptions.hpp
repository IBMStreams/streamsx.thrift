//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTERPROCESS_EXCEPTIONS_HPP
#define STREAMS_BOOST_INTERPROCESS_EXCEPTIONS_HPP

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#include <streams_boost/interprocess/detail/config_begin.hpp>
#include <streams_boost/interprocess/detail/workaround.hpp>
#include <streams_boost/interprocess/errors.hpp>
#include <stdexcept>
#include <new>

//!\file
//!Describes exceptions thrown by interprocess classes

namespace streams_boost {

namespace interprocess {

//!This class is the base class of all exceptions
//!thrown by streams_boost::interprocess
class interprocess_exception : public std::exception
{
   public:
   interprocess_exception(error_code_t ec = other_error )
      :  m_err(ec)
   {
      try   {  m_str = "streams_boost::interprocess_exception::library_error"; }
      catch (...) {}
   }

   interprocess_exception(native_error_t sys_err_code)
      :  m_err(sys_err_code)
   {
      try   {  fill_system_message(m_err.get_native_error(), m_str); }
      catch (...) {}
   }

   interprocess_exception(const error_info &err_info)
      :  m_err(err_info)
   {
      try{
         if(m_err.get_native_error() != 0){
            fill_system_message(m_err.get_native_error(), m_str);
         }/*
         else{
            m_str = "streams_boost::interprocess_exception::library_error";
         }*/
      }
      catch(...){}
   }

   virtual ~interprocess_exception() throw(){}

   virtual const char * what() const throw()
   {  return m_str.c_str();  }

   native_error_t get_native_error()const { return m_err.get_native_error(); }

   // Note: a value of other_error implies a library (rather than system) error
   error_code_t   get_error_code()  const { return m_err.get_error_code(); }

   /// @cond
   private:
   error_info        m_err;
   std::string       m_str;
   /// @endcond
};

//!This is the exception thrown by shared interprocess_mutex family when a deadlock situation
//!is detected or when using a interprocess_condition the interprocess_mutex is not locked
class lock_exception : public interprocess_exception
{
   public:
   lock_exception()
      :  interprocess_exception(lock_error)
   {}

   virtual const char* what() const throw()
   {  return "streams_boost::interprocess::lock_exception";  }
};

//!This is the exception thrown by named interprocess_semaphore when a deadlock situation
//!is detected or when an error is detected in the post/wait operation
/*
class sem_exception : public interprocess_exception
{
   public:
   sem_exception()
      :  interprocess_exception(lock_error)
   {}

   virtual const char* what() const throw()
   {  return "streams_boost::interprocess::sem_exception";  }
};
*/
//!This is the exception thrown by synchronization objects when there is
//!an error in a wait() function
/*
class wait_exception : public interprocess_exception
{
   public:
   virtual const char* what() const throw()
   {  return "streams_boost::interprocess::wait_exception";  }
};
*/

//!This exception is thrown when a named object is created
//!in "open_only" mode and the resource was not already created
/*
class not_previously_created : public interprocess_exception
{
 public:
    virtual const char* what() const throw()
      {  return "streams_boost::interprocess::not_previously_created";  }
};
*/

//!This exception is thrown when a memory request can't be
//!fulfilled.
class bad_alloc : public interprocess_exception
{
 public:
    virtual const char* what() const throw()
      {  return "streams_boost::interprocess::bad_alloc";  }
};

}  // namespace interprocess {

}  // namespace streams_boost

#include <streams_boost/interprocess/detail/config_end.hpp>

#endif // STREAMS_BOOST_INTERPROCESS_EXCEPTIONS_HPP
