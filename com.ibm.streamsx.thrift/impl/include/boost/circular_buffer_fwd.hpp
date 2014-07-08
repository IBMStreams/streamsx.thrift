// Forward declaration of the circular buffer and its adaptor.

// Copyright (c) 2003-2008 Jan Gaspar

// Use, modification, and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See www.streams_boost.org/libs/circular_buffer for documentation.

#if !defined(STREAMS_BOOST_CIRCULAR_BUFFER_FWD_HPP)
#define STREAMS_BOOST_CIRCULAR_BUFFER_FWD_HPP

#if defined(_MSC_VER) && _MSC_VER >= 1200
    #pragma once
#endif

#include <streams_boost/config.hpp>
#if !defined(STREAMS_BOOST_NO_STD_ALLOCATOR)
    #include <memory>
#else
    #include <vector>
#endif

namespace streams_boost {

#if !defined(STREAMS_BOOST_NO_STD_ALLOCATOR)
    #define STREAMS_BOOST_CB_DEFAULT_ALLOCATOR(T) std::allocator<T>
#else
    #define STREAMS_BOOST_CB_DEFAULT_ALLOCATOR(T) STREAMS_BOOST_DEDUCED_TYPENAME std::vector<T>::allocator_type
#endif

template <class T, class Alloc = STREAMS_BOOST_CB_DEFAULT_ALLOCATOR(T)>
class circular_buffer;

template <class T, class Alloc = STREAMS_BOOST_CB_DEFAULT_ALLOCATOR(T)>
class circular_buffer_space_optimized;

#undef STREAMS_BOOST_CB_DEFAULT_ALLOCATOR

} // namespace streams_boost

#endif // #if !defined(STREAMS_BOOST_CIRCULAR_BUFFER_FWD_HPP)
