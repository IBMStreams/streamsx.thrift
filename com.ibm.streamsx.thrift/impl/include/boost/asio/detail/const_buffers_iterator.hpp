//
// const_buffers_iterator.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_CONST_BUFFERS_ITERATOR_HPP
#define STREAMS_BOOST_ASIO_DETAIL_CONST_BUFFERS_ITERATOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <cstddef>
#include <streams_boost/config.hpp>
#include <streams_boost/iterator/iterator_facade.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/buffer.hpp>

namespace streams_boost {
namespace asio {
namespace detail {

// A proxy iterator for a sub-range in a list of buffers.
template <typename ConstBufferSequence>
class const_buffers_iterator
  : public streams_boost::iterator_facade<const_buffers_iterator<ConstBufferSequence>,
        const char, streams_boost::bidirectional_traversal_tag>
{
public:
  // Default constructor creates an iterator in an undefined state.
  const_buffers_iterator()
  {
  }

  // Create an iterator for the specified position.
  const_buffers_iterator(const ConstBufferSequence& buffers,
      std::size_t position)
    : begin_(buffers.begin()),
      current_(buffers.begin()),
      end_(buffers.end()),
      position_(0)
  {
    while (current_ != end_)
    {
      current_buffer_ = *current_;
      std::size_t buffer_size = streams_boost::asio::buffer_size(current_buffer_);
      if (position - position_ < buffer_size)
      {
        current_buffer_position_ = position - position_;
        position_ = position;
        return;
      }
      position_ += buffer_size;
      ++current_;
    }
    current_buffer_ = streams_boost::asio::const_buffer();
    current_buffer_position_ = 0;
  }

  std::size_t position() const
  {
    return position_;
  }

private:
  friend class streams_boost::iterator_core_access;

  void increment()
  {
    if (current_ == end_)
      return;

    ++position_;

    ++current_buffer_position_;
    if (current_buffer_position_ != streams_boost::asio::buffer_size(current_buffer_))
      return;

    ++current_;
    current_buffer_position_ = 0;
    while (current_ != end_)
    {
      current_buffer_ = *current_;
      if (streams_boost::asio::buffer_size(current_buffer_) > 0)
        return;
      ++current_;
    }
  }

  void decrement()
  {
    if (position_ == 0)
      return;

    --position_;

    if (current_buffer_position_ != 0)
    {
      --current_buffer_position_;
      return;
    }

    typename ConstBufferSequence::const_iterator iter = current_;
    while (iter != begin_)
    {
      --iter;
      streams_boost::asio::const_buffer buffer = *iter;
      std::size_t buffer_size = streams_boost::asio::buffer_size(buffer);
      if (buffer_size > 0)
      {
        current_ = iter;
        current_buffer_ = buffer;
        current_buffer_position_ = buffer_size - 1;
        return;
      }
    }
  }

  bool equal(const const_buffers_iterator& other) const
  {
    return position_ == other.position_;
  }

  const char& dereference() const
  {
    return streams_boost::asio::buffer_cast<const char*>(
        current_buffer_)[current_buffer_position_];
  }

  streams_boost::asio::const_buffer current_buffer_;
  std::size_t current_buffer_position_;
  typename ConstBufferSequence::const_iterator begin_;
  typename ConstBufferSequence::const_iterator current_;
  typename ConstBufferSequence::const_iterator end_;
  std::size_t position_;
};

} // namespace detail
} // namespace asio
} // namespace streams_boost

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_CONST_BUFFERS_ITERATOR_HPP
