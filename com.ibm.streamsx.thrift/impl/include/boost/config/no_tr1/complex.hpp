//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// The aim of this header is just to include <complex> but to do
// so in a way that does not result in recursive inclusion of
// the Boost TR1 components if streams_boost/tr1/tr1/complex is in the
// include search path.  We have to do this to avoid circular
// dependencies:
//

#ifndef STREAMS_BOOST_CONFIG_COMPLEX
#  define STREAMS_BOOST_CONFIG_COMPLEX

#  ifndef STREAMS_BOOST_TR1_NO_RECURSION
#     define STREAMS_BOOST_TR1_NO_RECURSION
#     define STREAMS_BOOST_CONFIG_NO_COMPLEX_RECURSION
#  endif

#  include <complex>

#  ifdef STREAMS_BOOST_CONFIG_NO_COMPLEX_RECURSION
#     undef STREAMS_BOOST_TR1_NO_RECURSION
#     undef STREAMS_BOOST_CONFIG_NO_COMPLEX_RECURSION
#  endif

#endif
