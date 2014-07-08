//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTRUSIVE_DETAIL_WRKRND_HPP
#define STREAMS_BOOST_INTRUSIVE_DETAIL_WRKRND_HPP

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ > 2)
// C++0x features are only enabled when -std=c++0x or -std=gnu++0x are
// passed on the command line, which in turn defines
// __GXX_EXPERIMENTAL_CXX0X__. Note: __GXX_EXPERIMENTAL_CPP0X__ is
// defined by some very early development versions of GCC 4.3; we will
// remove this part of the check in the near future.
#  if defined(__GXX_EXPERIMENTAL_CPP0X__) || defined(__GXX_EXPERIMENTAL_CXX0X__)
#     define STREAMS_BOOST_INTRUSIVE_RVALUE_REFERENCE
#     define STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
#  endif
#endif

#if defined(STREAMS_BOOST_INTRUSIVE_RVALUE_REFERENCE) && defined(STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES)
#define STREAMS_BOOST_INTRUSIVE_PERFECT_FORWARDING
#endif

#endif   //#ifndef STREAMS_BOOST_INTRUSIVE_DETAIL_WRKRND_HPP
