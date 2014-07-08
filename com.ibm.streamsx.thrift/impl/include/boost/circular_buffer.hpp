// Circular buffer library header file.

// Copyright (c) 2003-2008 Jan Gaspar

// Use, modification, and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See www.streams_boost.org/libs/circular_buffer for documentation.

#if !defined(STREAMS_BOOST_CIRCULAR_BUFFER_HPP)
#define STREAMS_BOOST_CIRCULAR_BUFFER_HPP

#if defined(_MSC_VER) && _MSC_VER >= 1200
    #pragma once
#endif

#include <streams_boost/circular_buffer_fwd.hpp>
#include <streams_boost/detail/workaround.hpp>

// STREAMS_BOOST_CB_ENABLE_DEBUG: Debug support control.
#if defined(NDEBUG) || defined(STREAMS_BOOST_CB_DISABLE_DEBUG)
    #define STREAMS_BOOST_CB_ENABLE_DEBUG 0
#else
    #define STREAMS_BOOST_CB_ENABLE_DEBUG 1
#endif

// STREAMS_BOOST_CB_ASSERT: Runtime assertion.
#if STREAMS_BOOST_CB_ENABLE_DEBUG
    #include <streams_boost/assert.hpp>
    #define STREAMS_BOOST_CB_ASSERT(Expr) STREAMS_BOOST_ASSERT(Expr)
#else
    #define STREAMS_BOOST_CB_ASSERT(Expr) ((void)0)
#endif

// STREAMS_BOOST_CB_STATIC_ASSERT: Compile time assertion.
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
    #define STREAMS_BOOST_CB_STATIC_ASSERT(Expr) ((void)0)
#else
    #include <streams_boost/static_assert.hpp>
    #define STREAMS_BOOST_CB_STATIC_ASSERT(Expr) STREAMS_BOOST_STATIC_ASSERT(Expr)
#endif

// STREAMS_BOOST_CB_IS_CONVERTIBLE: Check if Iterator::value_type is convertible to Type.
#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, <= 0x0550) || STREAMS_BOOST_WORKAROUND(__MWERKS__, <= 0x2407) || \
    STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
    #define STREAMS_BOOST_CB_IS_CONVERTIBLE(Iterator, Type) ((void)0)
#else
    #include <streams_boost/detail/iterator.hpp>
    #include <streams_boost/type_traits/is_convertible.hpp>
    #define STREAMS_BOOST_CB_IS_CONVERTIBLE(Iterator, Type) \
        STREAMS_BOOST_CB_STATIC_ASSERT((is_convertible<typename detail::iterator_traits<Iterator>::value_type, Type>::value))
#endif

// STREAMS_BOOST_CB_ASSERT_TEMPLATED_ITERATOR_CONSTRUCTORS:
// Check if the STL provides templated iterator constructors for its containers.
#if defined(STREAMS_BOOST_NO_TEMPLATED_ITERATOR_CONSTRUCTORS)
    #define STREAMS_BOOST_CB_ASSERT_TEMPLATED_ITERATOR_CONSTRUCTORS STREAMS_BOOST_CB_STATIC_ASSERT(false);
#else
    #define STREAMS_BOOST_CB_ASSERT_TEMPLATED_ITERATOR_CONSTRUCTORS ((void)0);
#endif

#include <streams_boost/circular_buffer/debug.hpp>
#include <streams_boost/circular_buffer/details.hpp>
#include <streams_boost/circular_buffer/base.hpp>
#include <streams_boost/circular_buffer/space_optimized.hpp>

#undef STREAMS_BOOST_CB_ASSERT_TEMPLATED_ITERATOR_CONSTRUCTORS
#undef STREAMS_BOOST_CB_IS_CONVERTIBLE
#undef STREAMS_BOOST_CB_STATIC_ASSERT
#undef STREAMS_BOOST_CB_ASSERT
#undef STREAMS_BOOST_CB_ENABLE_DEBUG

#endif // #if !defined(STREAMS_BOOST_CIRCULAR_BUFFER_HPP)
