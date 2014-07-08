// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_STREAM_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_STREAM_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/iostreams/constants.hpp>
#include <streams_boost/iostreams/detail/char_traits.hpp>
#include <streams_boost/iostreams/detail/config/overload_resolution.hpp>
#include <streams_boost/iostreams/detail/forward.hpp>
#include <streams_boost/iostreams/detail/iostream.hpp>  // standard streams.
#include <streams_boost/iostreams/detail/select.hpp>
#include <streams_boost/iostreams/stream_buffer.hpp>
#include <streams_boost/mpl/and.hpp>
#include <streams_boost/type_traits/is_convertible.hpp>
#include <streams_boost/utility/base_from_member.hpp>

namespace streams_boost { namespace iostreams { namespace detail {

template<typename Device, typename Tr>
struct stream_traits {
    typedef typename char_type_of<Device>::type                char_type;
    typedef Tr                                                 traits_type;
    typedef typename category_of<Device>::type                 mode;
    typedef typename
            iostreams::select< // Dismbiguation required for Tru64.
                mpl::and_<
                    is_convertible<mode, input>,
                    is_convertible<mode, output>
                >,
                STREAMS_BOOST_IOSTREAMS_BASIC_IOSTREAM(char_type, traits_type),
                is_convertible<mode, input>,
                STREAMS_BOOST_IOSTREAMS_BASIC_ISTREAM(char_type, traits_type),
                else_,
                STREAMS_BOOST_IOSTREAMS_BASIC_OSTREAM(char_type, traits_type)
            >::type stream_type;
    typedef typename
            iostreams::select< // Dismbiguation required for Tru64.
                mpl::and_<
                    is_convertible<mode, input>,
                    is_convertible<mode, output>
                >,
                iostream_tag,
                is_convertible<mode, input>,
                istream_tag,
                else_,
                ostream_tag
            >::type stream_tag;
};

// By encapsulating initialization in a base, we can define the macro
// STREAMS_BOOST_IOSTREAMS_DEFINE_FORWARDING_FUNCTIONS to generate constuctors
// without base member initializer lists.
template< typename Device,
          typename Tr =
              STREAMS_BOOST_IOSTREAMS_CHAR_TRAITS(
                  STREAMS_BOOST_DEDUCED_TYPENAME char_type_of<Device>::type
              ),
          typename Alloc =
              std::allocator<
                  STREAMS_BOOST_DEDUCED_TYPENAME char_type_of<Device>::type
              >,
          typename Base = // VC6 Workaround.
              STREAMS_BOOST_DEDUCED_TYPENAME
              detail::stream_traits<Device, Tr>::stream_type >
class stream_base
    : protected base_from_member< stream_buffer<Device, Tr, Alloc> >,
      public Base
{
private:
    typedef base_from_member< stream_buffer<Device, Tr, Alloc> >  pbase_type;
    typedef typename stream_traits<Device, Tr>::stream_type       stream_type;
protected:
    using pbase_type::member; // Avoid warning about 'this' in initializer list.
public:
    stream_base() : pbase_type(), stream_type(&member) { }
};

} } } // End namespaces detail, iostreams, streams_boost.

#ifdef STREAMS_BOOST_IOSTREAMS_BROKEN_OVERLOAD_RESOLUTION
# include <streams_boost/iostreams/detail/broken_overload_resolution/stream.hpp>
#else

namespace streams_boost { namespace iostreams {

//
// Template name: stream.
// Description: A iostream which reads from and writes to an instance of a
//      designated device type.
// Template paramters:
//      Device - A device type.
//      Alloc - The allocator type.
//
template< typename Device,
          typename Tr =
              STREAMS_BOOST_IOSTREAMS_CHAR_TRAITS(
                  STREAMS_BOOST_DEDUCED_TYPENAME char_type_of<Device>::type
              ),
          typename Alloc =
              std::allocator<
                  STREAMS_BOOST_DEDUCED_TYPENAME char_type_of<Device>::type
              > >
struct stream : detail::stream_base<Device, Tr, Alloc> {
public:
    typedef typename char_type_of<Device>::type  char_type;
    struct category 
        : mode_of<Device>::type,
          closable_tag,
          detail::stream_traits<Device, Tr>::stream_tag
        { };
    STREAMS_BOOST_IOSTREAMS_STREAMBUF_TYPEDEFS(Tr)
private:
    typedef typename
            detail::stream_traits<
                Device, Tr
            >::stream_type                       stream_type;
public:
    stream() { }
    STREAMS_BOOST_IOSTREAMS_FORWARD( stream, open_impl, Device,
                             STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS,
                             STREAMS_BOOST_IOSTREAMS_PUSH_ARGS )
    bool is_open() const { return this->member.is_open(); }
    void close() { this->member.close(); }
    bool auto_close() const { return this->member.auto_close(); }
    void set_auto_close(bool close) { this->member.set_auto_close(close); }
    bool strict_sync() { return this->member.strict_sync(); }
    Device& operator*() { return *this->member; }
    Device* operator->() { return &*this->member; }
    Device* component() { return this->member.component(); }
private:
    void open_impl(const Device& dev STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS()) // For forwarding.
    { 
        this->clear(); 
        this->member.open(dev STREAMS_BOOST_IOSTREAMS_PUSH_ARGS()); 
    }
};

} } // End namespaces iostreams, streams_boost.

#endif // #ifdef STREAMS_BOOST_IOSTREAMS_BROKEN_OVERLOAD_RESOLUTION

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_stream_HPP_INCLUDED
