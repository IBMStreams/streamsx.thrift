//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TR1_MEMORY_HPP_INCLUDED
#  define STREAMS_BOOST_TR1_MEMORY_HPP_INCLUDED
#  include <streams_boost/tr1/detail/config.hpp>
#  include <streams_boost/detail/workaround.hpp>
#  include <memory>

#ifndef STREAMS_BOOST_HAS_TR1_SHARED_PTR

//
// This header can get included by streams_boost/shared_ptr.hpp which leads
// to cyclic dependencies, the workaround is to forward declare all 
// the streams_boost components, and then include the actual headers afterwards.
// This is fragile, but seems to work, and doesn't require modification
// of streams_boost/shared_ptr.hpp.
//
namespace streams_boost{

class bad_weak_ptr;
template<class T> class weak_ptr;
template<class T> class shared_ptr;
template<class T> void swap(weak_ptr<T> & a, weak_ptr<T> & b);
template<class T> void swap(shared_ptr<T> & a, shared_ptr<T> & b);
template<class T, class U> shared_ptr<T> static_pointer_cast(shared_ptr<U> const & r);
template<class T, class U> shared_ptr<T> dynamic_pointer_cast(shared_ptr<U> const & r);
template<class T, class U> shared_ptr<T> const_pointer_cast(shared_ptr<U> const & r);
template<class D, class T> D * get_deleter(shared_ptr<T> const & p);
template<class T> class enable_shared_from_this;

namespace detail{
class shared_count;
class weak_count;
}

}

namespace std{ namespace tr1{

   using ::streams_boost::bad_weak_ptr;
   using ::streams_boost::shared_ptr;
#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x0582)
   using ::streams_boost::swap;
#endif
   using ::streams_boost::static_pointer_cast;
   using ::streams_boost::dynamic_pointer_cast;
   using ::streams_boost::const_pointer_cast;
   using ::streams_boost::get_deleter;
   using ::streams_boost::weak_ptr;
   using ::streams_boost::enable_shared_from_this;

} }
#include <streams_boost/shared_ptr.hpp>
#include <streams_boost/weak_ptr.hpp>
#include <streams_boost/enable_shared_from_this.hpp>

#else

#  ifdef STREAMS_BOOST_HAS_INCLUDE_NEXT
#     include_next STREAMS_BOOST_TR1_HEADER(memory)
#  else
#     include <streams_boost/tr1/detail/config_all.hpp>
#     include STREAMS_BOOST_TR1_STD_HEADER(STREAMS_BOOST_TR1_PATH(memory))
#  endif

#endif

#endif

