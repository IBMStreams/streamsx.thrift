// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_OPERATIONS_FWD_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_OPERATIONS_FWD_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/mpl/not.hpp>
#include <streams_boost/type_traits/is_base_and_derived.hpp>

namespace streams_boost { namespace iostreams {

template<typename T>
struct operations;

namespace detail {

struct custom_tag { };

template<typename T>
struct is_custom
    : mpl::not_<
          is_base_and_derived< custom_tag, operations<T> >
      >
    { };

} // End namespace detail.

template<typename T>
struct operations : detail::custom_tag { };

} } // End namespaces iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_OPERATIONS_FWD_HPP_INCLUDED //--------------//
