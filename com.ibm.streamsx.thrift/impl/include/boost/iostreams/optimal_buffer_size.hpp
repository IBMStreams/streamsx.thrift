// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_OPTIMAL_BUFFER_SIZE_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_OPTIMAL_BUFFER_SIZE_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/config.hpp>  // DEDUCED_TYPENAME, MSVC.
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/iostreams/constants.hpp>  // constants.
#include <streams_boost/iostreams/detail/dispatch.hpp>
#include <streams_boost/iostreams/detail/wrap_unwrap.hpp>
#include <streams_boost/iostreams/operations_fwd.hpp>
#include <streams_boost/mpl/if.hpp>

// Must come last.
#include <streams_boost/iostreams/detail/config/disable_warnings.hpp>

namespace streams_boost { namespace iostreams {

namespace detail {

template<typename T>
struct optimal_buffer_size_impl;

} // End namespace detail.

template<typename T>
std::streamsize optimal_buffer_size(const T& t)
{
    typedef detail::optimal_buffer_size_impl<T> impl;
    return impl::optimal_buffer_size(detail::unwrap(t));
}

namespace detail {

//------------------Definition of optimal_buffer_size_impl--------------------//

template<typename T>
struct optimal_buffer_size_impl
    : mpl::if_<
          is_custom<T>,
          operations<T>,
          optimal_buffer_size_impl<
              STREAMS_BOOST_DEDUCED_TYPENAME
              dispatch<
                  T, optimally_buffered_tag, device_tag, filter_tag
              >::type
          >
      >::type
    { };

template<>
struct optimal_buffer_size_impl<optimally_buffered_tag> {
    template<typename T>
    static std::streamsize optimal_buffer_size(const T& t)
    { return t.optimal_buffer_size(); }
};

template<>
struct optimal_buffer_size_impl<device_tag> {
    template<typename T>
    static std::streamsize optimal_buffer_size(const T&)
    { return default_device_buffer_size; }
};

template<>
struct optimal_buffer_size_impl<filter_tag> {
    template<typename T>
    static std::streamsize optimal_buffer_size(const T&)
    { return default_filter_buffer_size; }
};

} // End namespace detail.

} } // End namespaces iostreams, streams_boost.

#include <streams_boost/iostreams/detail/config/enable_warnings.hpp>

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_OPTIMAL_BUFFER_SIZE_HPP_INCLUDED
