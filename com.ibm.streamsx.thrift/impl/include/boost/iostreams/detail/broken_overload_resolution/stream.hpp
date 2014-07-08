// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_BROKEN_OVERLOAD_RESOLUTION_STREAM_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_BROKEN_OVERLOAD_RESOLUTION_STREAM_HPP_INCLUDED

#include <streams_boost/iostreams/detail/broken_overload_resolution/forward.hpp>

namespace streams_boost { namespace iostreams {

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
    template<typename U0>
    stream(const U0& u0)
    {
        open_impl(detail::forward<Device, U0>(), u0);
    }
    template<typename U0, typename U1>
    stream(const U0& u0, const U1& u1)
    {
        open_impl(detail::forward<Device, U0>(), u0, u1);
    }
    template<typename U0, typename U1, typename U2>
    stream(const U0& u0, const U1& u1, const U2& u2)
    {
        open_impl(detail::forward<Device, U0>(), u0, u1, u2);
    }
#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //---------------------------------//
    template<typename U0>
    stream(U0& u0)
    {
        open_impl(detail::forward<Device, U0>(), u0);
    }
    template<typename U0, typename U1>
    stream(U0& u0, const U1& u1)
    {
        open_impl(detail::forward<Device, U0>(), u0, u1);
    }
    template<typename U0, typename U1, typename U2>
    stream(U0& u0, const U1& u1, const U2& u2)
    {
        open_impl(detail::forward<Device, U0>(), u0, u1, u2);
    }
#endif // !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //---------------------------//
    template<typename U0>
    void open(const U0& u0)
    {
        open_impl(detail::forward<Device, U0>(), u0);
    }
    template<typename U0, typename U1>
    void open(const U0& u0, const U1& u1)
    {
        open_impl(detail::forward<Device, U0>(), u0, u1);
    }
    template<typename U0, typename U1, typename U2>
    void open(const U0& u0, const U1& u1, const U2& u2)
    {
        open_impl(detail::forward<Device, U0>(), u0, u1, u2);
    }
#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //---------------------------------//
    template<typename U0>
    void open(U0& u0)
    {
        open_impl(detail::forward<Device, U0>(), u0);
    }
    template<typename U0, typename U1>
    void open(U0& u0, const U1& u1)
    {
        open_impl(detail::forward<Device, U0>(), u0, u1);
    }
    template<typename U0, typename U1, typename U2>
    void open(U0& u0, const U1& u1, const U2& u2)
    {
        open_impl(detail::forward<Device, U0>(), u0, u1, u2);
    }
#endif // !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //---------------------------//
    bool is_open() const { return this->member.is_open(); }
    void close() { this->member.close(); }
    bool auto_close() const { return this->member.auto_close(); }
    void set_auto_close(bool close) { this->member.set_auto_close(close); }
    bool strict_sync() { return this->member.strict_sync(); }
    Device& operator*() { return *this->member; }
    Device* operator->() { return &*this->member; }
private:
    template<typename U0>
    void open_impl(mpl::false_, const U0& u0)
    {
        this->clear(); 
        this->member.open(u0);
    }
#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //---------------------------------//
    template<typename U0>
    void open_impl(mpl::false_, U0& u0)
    {
        this->clear(); 
        this->member.open(detail::wrap(u0));
    }
#endif // !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //---------------------------//
    template<typename U0>
    void open_impl(mpl::true_, const U0& u0)
    {
        this->clear(); 
        this->member.open(Device(const_cast<U0&>(u0)));
    }
#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //---------------------------------//
    template<typename U0>
    void open_impl(mpl::true_, U0& u0)
    {
        this->clear(); 
        this->member.open(Device(u0));
    }
#endif // !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //---------------------------//
    template<typename U0, typename U1>
    void open_impl(mpl::false_, const U0& u0, const U1& u1)
    {
        this->clear(); 
        this->member.open(u0, u1);
    }
    template<typename U0, typename U1>
    void open_impl(mpl::true_, const U0& u0, const U1& u1)
    {
        this->clear(); 
        this->member.open(Device(const_cast<U0&>(u0), u1));
    }
#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //---------------------------------//
    template<typename U0, typename U1>
    void open_impl(mpl::true_, U0& u0, const U1& u1)
    {
        this->clear(); 
        this->member.open(Device(u0, u1));
    }
#endif // !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //---------------------------//
    template<typename U0, typename U1, typename U2>
    void open_impl(mpl::false_, const U0& u0, const U1& u1, const U2& u2)
    {
        this->clear(); 
        this->member.open(u0, u1, u2);
    }
    template<typename U0, typename U1, typename U2>
    void open_impl(mpl::true_, const U0& u0, const U1& u1, const U2& u2)
    {
        this->clear(); 
        this->member.open(Device(const_cast<U0&>(u0), u1, u2));
    }
#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //---------------------------------//
    template<typename U0, typename U1, typename U2>
    void open_impl(mpl::true_, U0& u0, const U1& u1, const U2& u2)
    {
        this->clear(); 
        this->member.open(Device(u0, u1, u2));
    }
#endif
};

} } // End namespaces iostreams, streams_boost.

#endif STREAMS_BOOST_IOSTREAMS_DETAIL_BROKEN_OVERLOAD_RESOLUTION_STREAM_HPP_INCLUDED
