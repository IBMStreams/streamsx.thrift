#ifndef STREAMS_BOOST_DETAIL_INTERLOCKED_HPP_INCLUDED
#define STREAMS_BOOST_DETAIL_INTERLOCKED_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  streams_boost/detail/interlocked.hpp
//
//  Copyright 2005 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//

#include <streams_boost/config.hpp>

#if defined( STREAMS_BOOST_USE_WINDOWS_H )

# include <windows.h>

# define STREAMS_BOOST_INTERLOCKED_INCREMENT InterlockedIncrement
# define STREAMS_BOOST_INTERLOCKED_DECREMENT InterlockedDecrement
# define STREAMS_BOOST_INTERLOCKED_COMPARE_EXCHANGE InterlockedCompareExchange
# define STREAMS_BOOST_INTERLOCKED_EXCHANGE InterlockedExchange
# define STREAMS_BOOST_INTERLOCKED_EXCHANGE_ADD InterlockedExchangeAdd
# define STREAMS_BOOST_INTERLOCKED_COMPARE_EXCHANGE_POINTER InterlockedCompareExchangePointer
# define STREAMS_BOOST_INTERLOCKED_EXCHANGE_POINTER InterlockedExchangePointer

#elif defined(_WIN32_WCE)

// under Windows CE we still have old-style Interlocked* functions

extern "C" long __cdecl InterlockedIncrement( long* );
extern "C" long __cdecl InterlockedDecrement( long* );
extern "C" long __cdecl InterlockedCompareExchange( long*, long, long );
extern "C" long __cdecl InterlockedExchange( long*, long );
extern "C" long __cdecl InterlockedExchangeAdd( long*, long );

# define STREAMS_BOOST_INTERLOCKED_INCREMENT InterlockedIncrement
# define STREAMS_BOOST_INTERLOCKED_DECREMENT InterlockedDecrement
# define STREAMS_BOOST_INTERLOCKED_COMPARE_EXCHANGE InterlockedCompareExchange
# define STREAMS_BOOST_INTERLOCKED_EXCHANGE InterlockedExchange
# define STREAMS_BOOST_INTERLOCKED_EXCHANGE_ADD InterlockedExchangeAdd

# define STREAMS_BOOST_INTERLOCKED_COMPARE_EXCHANGE_POINTER(dest,exchange,compare) \
    ((void*)STREAMS_BOOST_INTERLOCKED_COMPARE_EXCHANGE((long*)(dest),(long)(exchange),(long)(compare)))
# define STREAMS_BOOST_INTERLOCKED_EXCHANGE_POINTER(dest,exchange) \
    ((void*)STREAMS_BOOST_INTERLOCKED_EXCHANGE((long*)(dest),(long)(exchange)))

#elif defined( STREAMS_BOOST_MSVC ) || defined( STREAMS_BOOST_INTEL_WIN )

#if defined( __CLRCALL_PURE_OR_CDECL )

extern "C" long __CLRCALL_PURE_OR_CDECL _InterlockedIncrement( long volatile * );
extern "C" long __CLRCALL_PURE_OR_CDECL _InterlockedDecrement( long volatile * );
extern "C" long __CLRCALL_PURE_OR_CDECL _InterlockedCompareExchange( long volatile *, long, long );
extern "C" long __CLRCALL_PURE_OR_CDECL _InterlockedExchange( long volatile *, long );
extern "C" long __CLRCALL_PURE_OR_CDECL _InterlockedExchangeAdd( long volatile *, long );

#else

extern "C" long __cdecl _InterlockedIncrement( long volatile * );
extern "C" long __cdecl _InterlockedDecrement( long volatile * );
extern "C" long __cdecl _InterlockedCompareExchange( long volatile *, long, long );
extern "C" long __cdecl _InterlockedExchange( long volatile *, long );
extern "C" long __cdecl _InterlockedExchangeAdd( long volatile *, long );

#endif

# pragma intrinsic( _InterlockedIncrement )
# pragma intrinsic( _InterlockedDecrement )
# pragma intrinsic( _InterlockedCompareExchange )
# pragma intrinsic( _InterlockedExchange )
# pragma intrinsic( _InterlockedExchangeAdd )

# if defined(_M_IA64) || defined(_M_AMD64)

extern "C" void* __cdecl _InterlockedCompareExchangePointer( void* volatile *, void*, void* );
extern "C" void* __cdecl _InterlockedExchangePointer( void* volatile *, void* );

#  pragma intrinsic( _InterlockedCompareExchangePointer )
#  pragma intrinsic( _InterlockedExchangePointer )

#  define STREAMS_BOOST_INTERLOCKED_COMPARE_EXCHANGE_POINTER _InterlockedCompareExchangePointer
#  define STREAMS_BOOST_INTERLOCKED_EXCHANGE_POINTER _InterlockedExchangePointer

# else

#  define STREAMS_BOOST_INTERLOCKED_COMPARE_EXCHANGE_POINTER(dest,exchange,compare) \
    ((void*)STREAMS_BOOST_INTERLOCKED_COMPARE_EXCHANGE((long volatile*)(dest),(long)(exchange),(long)(compare)))
#  define STREAMS_BOOST_INTERLOCKED_EXCHANGE_POINTER(dest,exchange) \
    ((void*)STREAMS_BOOST_INTERLOCKED_EXCHANGE((long volatile*)(dest),(long)(exchange)))

# endif

# define STREAMS_BOOST_INTERLOCKED_INCREMENT _InterlockedIncrement
# define STREAMS_BOOST_INTERLOCKED_DECREMENT _InterlockedDecrement
# define STREAMS_BOOST_INTERLOCKED_COMPARE_EXCHANGE _InterlockedCompareExchange
# define STREAMS_BOOST_INTERLOCKED_EXCHANGE _InterlockedExchange
# define STREAMS_BOOST_INTERLOCKED_EXCHANGE_ADD _InterlockedExchangeAdd

#elif defined( WIN32 ) || defined( _WIN32 ) || defined( __WIN32__ ) || defined( __CYGWIN__ )

namespace streams_boost
{

namespace detail
{

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement( long volatile * );
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement( long volatile * );
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange( long volatile *, long, long );
extern "C" __declspec(dllimport) long __stdcall InterlockedExchange( long volatile *, long );
extern "C" __declspec(dllimport) long __stdcall InterlockedExchangeAdd( long volatile *, long );

} // namespace detail

} // namespace streams_boost

# define STREAMS_BOOST_INTERLOCKED_INCREMENT ::streams_boost::detail::InterlockedIncrement
# define STREAMS_BOOST_INTERLOCKED_DECREMENT ::streams_boost::detail::InterlockedDecrement
# define STREAMS_BOOST_INTERLOCKED_COMPARE_EXCHANGE ::streams_boost::detail::InterlockedCompareExchange
# define STREAMS_BOOST_INTERLOCKED_EXCHANGE ::streams_boost::detail::InterlockedExchange
# define STREAMS_BOOST_INTERLOCKED_EXCHANGE_ADD ::streams_boost::detail::InterlockedExchangeAdd

# define STREAMS_BOOST_INTERLOCKED_COMPARE_EXCHANGE_POINTER(dest,exchange,compare) \
    ((void*)STREAMS_BOOST_INTERLOCKED_COMPARE_EXCHANGE((long volatile*)(dest),(long)(exchange),(long)(compare)))
# define STREAMS_BOOST_INTERLOCKED_EXCHANGE_POINTER(dest,exchange) \
    ((void*)STREAMS_BOOST_INTERLOCKED_EXCHANGE((long volatile*)(dest),(long)(exchange)))

#else

# error "Interlocked intrinsics not available"

#endif

#endif // #ifndef STREAMS_BOOST_DETAIL_INTERLOCKED_HPP_INCLUDED
