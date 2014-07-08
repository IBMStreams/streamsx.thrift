//
//  streams_boost/assert.hpp - STREAMS_BOOST_ASSERT(expr)
//
//  Copyright (c) 2001, 2002 Peter Dimov and Multi Media Ltd.
//  Copyright (c) 2007 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  Note: There are no include guards. This is intentional.
//
//  See http://www.streams_boost.org/libs/utility/assert.html for documentation.
//

#undef STREAMS_BOOST_ASSERT

#if defined(STREAMS_BOOST_DISABLE_ASSERTS)

# define STREAMS_BOOST_ASSERT(expr) ((void)0)

#elif defined(STREAMS_BOOST_ENABLE_ASSERT_HANDLER)

#include <streams_boost/current_function.hpp>

namespace streams_boost
{

void assertion_failed(char const * expr, char const * function, char const * file, long line); // user defined

} // namespace streams_boost

#define STREAMS_BOOST_ASSERT(expr) ((expr)? ((void)0): ::streams_boost::assertion_failed(#expr, STREAMS_BOOST_CURRENT_FUNCTION, __FILE__, __LINE__))

#else
# include <assert.h> // .h to support old libraries w/o <cassert> - effect is the same
# define STREAMS_BOOST_ASSERT(expr) assert(expr)
#endif

#undef STREAMS_BOOST_VERIFY

#if defined(STREAMS_BOOST_DISABLE_ASSERTS) || ( !defined(STREAMS_BOOST_ENABLE_ASSERT_HANDLER) && defined(NDEBUG) )

# define STREAMS_BOOST_VERIFY(expr) ((void)(expr))

#else

# define STREAMS_BOOST_VERIFY(expr) STREAMS_BOOST_ASSERT(expr)

#endif
