// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

// To do: handle bidirection streams and output-seekable components.

#ifndef STREAMS_BOOST_IOSTREAMS_SKIP_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_SKIP_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/iostreams/char_traits.hpp>
#include <streams_boost/iostreams/detail/ios.hpp>  // failure.
#include <streams_boost/iostreams/operations.hpp>
#include <streams_boost/iostreams/seek.hpp>
#include <streams_boost/iostreams/traits.hpp>
#include <streams_boost/mpl/and.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/or.hpp>
#include <streams_boost/throw_exception.hpp>
#include <streams_boost/type_traits/is_convertible.hpp>

namespace streams_boost { namespace iostreams {

namespace detail {

template<typename Device>
void skip(Device& dev, stream_offset off, mpl::true_)
{ iostreams::seek(dev, off, STREAMS_BOOST_IOS::cur); }

template<typename Device>
void skip(Device& dev, stream_offset off, mpl::false_)
{   // gcc 2.95 needs namespace qualification for char_traits.
    typedef typename char_type_of<Device>::type  char_type;
    typedef iostreams::char_traits<char_type>    traits_type;
    for (stream_offset z = 0; z < off; ) {
        typename traits_type::int_type c;
        if (traits_type::is_eof(c = iostreams::get(dev)))
            streams_boost::throw_exception(STREAMS_BOOST_IOSTREAMS_FAILURE("bad skip offset"));
        if (!traits_type::would_block(c))
            ++z;
    }
}

template<typename Filter, typename Device>
void skip( Filter& flt, Device& dev, stream_offset off,
           STREAMS_BOOST_IOS::openmode which, mpl::true_ )
{ streams_boost::iostreams::seek(flt, dev, off, STREAMS_BOOST_IOS::cur, which); }

template<typename Filter, typename Device>
void skip( Filter& flt, Device& dev, stream_offset off,
           STREAMS_BOOST_IOS::openmode, mpl::false_ )
{ 
    typedef typename char_type_of<Device>::type char_type;
    char_type c;
    for (stream_offset z = 0; z < off; ) {
        std::streamsize amt;
        if ((amt = iostreams::read(flt, dev, &c, 1)) == -1)
            streams_boost::throw_exception(STREAMS_BOOST_IOSTREAMS_FAILURE("bad skip offset"));
        if (amt == 1)
            ++z;
    }
}

} // End namespace detail.

template<typename Device>
void skip(Device& dev, stream_offset off)
{ 
    typedef typename mode_of<Device>::type     mode;
    typedef mpl::or_<
        is_convertible<mode, input_seekable>,
        is_convertible<mode, output_seekable>
    >                                          can_seek;
    STREAMS_BOOST_STATIC_ASSERT(
        (can_seek::value || is_convertible<mode, input>::value)
    );
    detail::skip(dev, off, can_seek());
}

template<typename Filter, typename Device>
void skip( Filter& flt, Device& dev, stream_offset off, 
           STREAMS_BOOST_IOS::openmode which = STREAMS_BOOST_IOS::in | STREAMS_BOOST_IOS::out )
{ 
    typedef typename mode_of<Filter>::type                 filter_mode;
    typedef typename mode_of<Device>::type                 device_mode;
    typedef mpl::or_<
        mpl::and_<
            is_convertible<filter_mode, input_seekable>,
            is_convertible<device_mode, input_seekable>
        >,
        mpl::and_<
            is_convertible<filter_mode, output_seekable>,
            is_convertible<device_mode, output_seekable>
        >
    >                                                      can_seek;
    STREAMS_BOOST_STATIC_ASSERT(
        ( can_seek::value || 
          (is_convertible<filter_mode, input>::value &&
          is_convertible<device_mode, input>::value) )
    );
    detail::skip(flt, dev, off, which, can_seek());
}

} } // End namespaces iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_SKIP_HPP_INCLUDED //------------------------//
