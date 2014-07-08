#ifndef STREAMS_BOOST_DETAIL_NO_EXCEPTIONS_SUPPORT_HPP_
#define STREAMS_BOOST_DETAIL_NO_EXCEPTIONS_SUPPORT_HPP_

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

//----------------------------------------------------------------------
// (C) Copyright 2004 Pavel Vozenilek.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt
// or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
//
// This file contains helper macros used when exception support may be
// disabled (as indicated by macro STREAMS_BOOST_NO_EXCEPTIONS).
//
// Before picking up these macros you may consider using RAII techniques
// to deal with exceptions - their syntax can be always the same with 
// or without exception support enabled.
//

/* Example of use:

void foo() {
  STREAMS_BOOST_TRY {
    ...
  } STREAMS_BOOST_CATCH(const std::bad_alloc&) {
      ...
      STREAMS_BOOST_RETHROW
  } STREAMS_BOOST_CATCH(const std::exception& e) {
      ...
  }
  STREAMS_BOOST_CATCH_END
}

With exception support enabled it will expand into:

void foo() {
  { try {
    ...
  } catch (const std::bad_alloc&) {
      ...
      throw;
  } catch (const std::exception& e) {
      ...
  }
  }
}

With exception support disabled it will expand into:

void foo() {
  { if(true) {
    ...
  } else if (false) {
      ...
  } else if (false)  {
      ...
  }
  }
}
*/
//----------------------------------------------------------------------

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

#if !(defined STREAMS_BOOST_NO_EXCEPTIONS)
#    define STREAMS_BOOST_TRY { try
#    define STREAMS_BOOST_CATCH(x) catch(x)
#    define STREAMS_BOOST_RETHROW throw;
#    define STREAMS_BOOST_CATCH_END }
#else
#    if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
#        define STREAMS_BOOST_TRY { if ("")
#        define STREAMS_BOOST_CATCH(x) else if (!"")
#    else
#        define STREAMS_BOOST_TRY { if (true)
#        define STREAMS_BOOST_CATCH(x) else if (false)
#    endif
#    define STREAMS_BOOST_RETHROW
#    define STREAMS_BOOST_CATCH_END }
#endif


#endif 
