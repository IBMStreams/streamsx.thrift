// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_BROKEN_OVERLOAD_RESOLUTION_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_BROKEN_OVERLOAD_RESOLUTION_HPP_INCLUDED

#include <streams_boost/config.hpp>                     // STREAMS_BOOST_STATIC_CONSANT.
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/type_traits/is_same.hpp>

namespace streams_boost { namespace iostreams { namespace detail {

template<typename Device, typename U>
struct forward_impl {
    STREAMS_BOOST_STATIC_CONSTANT(bool, value =
        ( !is_same< U, Device >::value &&
          !is_same< U, reference_wrapper<Device> >::value ));
};

template<typename Device, typename U>
struct forward
    : mpl::bool_<forward_impl<Device, U>::value>
    { };

} } } // End namespaces detail, iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_BROKEN_OVERLOAD_RESOLUTION_HPP_INCLUDED
