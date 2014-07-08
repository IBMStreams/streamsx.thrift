// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_STREAM_BUFFER_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_STREAM_BUFFER_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <memory>            // allocator.
#include <streams_boost/config.hpp>  // STREAMS_BOOST_DEDUCED_TYPENAME.
#include <streams_boost/iostreams/detail/char_traits.hpp>
#include <streams_boost/iostreams/detail/config/overload_resolution.hpp>
#include <streams_boost/iostreams/detail/forward.hpp>
#include <streams_boost/iostreams/detail/ios.hpp>  // failure, streamsize.
#include <streams_boost/iostreams/detail/streambuf/direct_streambuf.hpp>
#include <streams_boost/iostreams/detail/streambuf/indirect_streambuf.hpp>
#include <streams_boost/iostreams/traits.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/throw_exception.hpp>
#include <streams_boost/type_traits/is_convertible.hpp>

// Must come last.
#include <streams_boost/iostreams/detail/config/disable_warnings.hpp>  // MSVC.

namespace streams_boost { namespace iostreams { namespace detail {

template<typename T, typename Tr, typename Alloc, typename Mode>
struct stream_buffer_traits {
    typedef typename
            mpl::if_<
                is_convertible<
                    STREAMS_BOOST_DEDUCED_TYPENAME category_of<T>::type,
                    direct_tag
                >,
                direct_streambuf<T, Tr>,
                indirect_streambuf<T, Tr, Alloc, Mode>
            >::type type;
};

} } } // End namespaces detail, iostreams, streams_boost

#ifdef STREAMS_BOOST_IOSTREAMS_BROKEN_OVERLOAD_RESOLUTION
# include <streams_boost/iostreams/detail/broken_overload_resolution/stream_buffer.hpp>
#else

namespace streams_boost { namespace iostreams {

template< typename T,
          typename Tr =
              STREAMS_BOOST_IOSTREAMS_CHAR_TRAITS(
                  STREAMS_BOOST_DEDUCED_TYPENAME char_type_of<T>::type
              ),
          typename Alloc =
              std::allocator<
                  STREAMS_BOOST_DEDUCED_TYPENAME char_type_of<T>::type
              >,
          typename Mode = STREAMS_BOOST_DEDUCED_TYPENAME mode_of<T>::type >
class stream_buffer
    : public detail::stream_buffer_traits<T, Tr, Alloc, Mode>::type
{
private:
    STREAMS_BOOST_STATIC_ASSERT((
        is_convertible<
            STREAMS_BOOST_DEDUCED_TYPENAME iostreams::category_of<T>::type, Mode
        >::value
    ));
    typedef typename
            detail::stream_buffer_traits<
                T, Tr, Alloc, Mode
            >::type                           base_type;
public:
    typedef typename char_type_of<T>::type    char_type;
    struct category 
        : Mode,
          closable_tag,
          streambuf_tag
        { };
    STREAMS_BOOST_IOSTREAMS_STREAMBUF_TYPEDEFS(Tr)
public:
    stream_buffer() { }
    ~stream_buffer()
    { 
        try { 
            if (this->is_open() && this->auto_close()) 
                this->close(); 
        } catch (...) { } 
    }
    STREAMS_BOOST_IOSTREAMS_FORWARD( stream_buffer, open_impl, T,
                             STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS,
                             STREAMS_BOOST_IOSTREAMS_PUSH_ARGS )
    T& operator*() { return *this->component(); }
    T* operator->() { return this->component(); }
private:
    void open_impl(const T& t STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS())
        {   // Used for forwarding.
            if (this->is_open())
                streams_boost::throw_exception(
                    STREAMS_BOOST_IOSTREAMS_FAILURE("already open")
                );
            base_type::open(t STREAMS_BOOST_IOSTREAMS_PUSH_ARGS());
        }
};

} } // End namespaces iostreams, streams_boost.

#endif // #ifdef STREAMS_BOOST_IOSTREAMS_BROKEN_OVERLOAD_RESOLUTION

#include <streams_boost/iostreams/detail/config/enable_warnings.hpp>  // MSVC.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_STREAM_BUFFER_HPP_INCLUDED
