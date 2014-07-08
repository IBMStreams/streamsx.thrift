// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_PARAM_TYPE_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_PARAM_TYPE_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <streams_boost/iostreams/traits.hpp>
#include <streams_boost/mpl/if.hpp>

namespace streams_boost { namespace iostreams { namespace detail {

template<typename T>
struct param_type {
    typedef typename mpl::if_<is_std_io<T>, T&, const T&>::type type;
};

} } } // End namespaces detail, iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_PARAM_TYPE_HPP_INCLUDED //-----------//