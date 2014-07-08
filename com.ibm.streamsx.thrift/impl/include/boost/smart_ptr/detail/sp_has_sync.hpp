#ifndef STREAMS_BOOST_SMART_PTR_DETAIL_SP_HAS_SYNC_HPP_INCLUDED
#define STREAMS_BOOST_SMART_PTR_DETAIL_SP_HAS_SYNC_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  streams_boost/smart_ptr/detail/sp_has_sync.hpp
//
//  Copyright (c) 2008, 2009 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  Defines the STREAMS_BOOST_SP_HAS_SYNC macro if the __sync_* intrinsics
//  are available.
//

#if defined(__GNUC__) && ( __GNUC__ * 100 + __GNUC_MINOR__ >= 401 )

#define STREAMS_BOOST_SP_HAS_SYNC

#if defined( __arm__ )  || defined( __armel__ )
#undef STREAMS_BOOST_SP_HAS_SYNC
#endif

#if defined( __hppa ) || defined( __hppa__ )
#undef STREAMS_BOOST_SP_HAS_SYNC
#endif

#if defined( __m68k__ )
#undef STREAMS_BOOST_SP_HAS_SYNC
#endif

#if defined( __sparc__ )
#undef STREAMS_BOOST_SP_HAS_SYNC
#endif

#if defined( __INTEL_COMPILER ) && !defined( __ia64__ ) && ( __INTEL_COMPILER < 1100 )
#undef STREAMS_BOOST_SP_HAS_SYNC
#endif

#endif // __GNUC__ * 100 + __GNUC_MINOR__ >= 401

#endif // #ifndef STREAMS_BOOST_SMART_PTR_DETAIL_SP_HAS_SYNC_HPP_INCLUDED
