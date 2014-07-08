// Copyright (C) 2000, 2001 Stephen Cleary
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org for updates, documentation, and revision history.

#ifndef STREAMS_BOOST_POOLFWD_HPP
#define STREAMS_BOOST_POOLFWD_HPP

#include <streams_boost/config.hpp> // for workarounds

// std::size_t
#include <cstddef>

// streams_boost::details::pool::default_mutex
#include <streams_boost/pool/detail/mutex.hpp>

namespace streams_boost {

//
// Location: <streams_boost/pool/simple_segregated_storage.hpp>
//
template <typename SizeType = std::size_t>
class simple_segregated_storage;

//
// Location: <streams_boost/pool/pool.hpp>
//
struct default_user_allocator_new_delete;
struct default_user_allocator_malloc_free;

template <typename UserAllocator = default_user_allocator_new_delete>
class pool;

//
// Location: <streams_boost/pool/object_pool.hpp>
//
template <typename T, typename UserAllocator = default_user_allocator_new_delete>
class object_pool;

//
// Location: <streams_boost/pool/singleton_pool.hpp>
//
template <typename Tag, unsigned RequestedSize,
    typename UserAllocator = default_user_allocator_new_delete,
    typename Mutex = details::pool::default_mutex,
    unsigned NextSize = 32>
struct singleton_pool;

//
// Location: <streams_boost/pool/pool_alloc.hpp>
//
struct pool_allocator_tag;

template <typename T,
    typename UserAllocator = default_user_allocator_new_delete,
    typename Mutex = details::pool::default_mutex,
    unsigned NextSize = 32>
class pool_allocator;

struct fast_pool_allocator_tag;

template <typename T,
    typename UserAllocator = default_user_allocator_new_delete,
    typename Mutex = details::pool::default_mutex,
    unsigned NextSize = 32>
class fast_pool_allocator;

} // namespace streams_boost

#endif
