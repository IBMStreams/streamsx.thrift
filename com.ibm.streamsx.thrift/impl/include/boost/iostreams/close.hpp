// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_CLOSE_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_CLOSE_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/config.hpp>  // DEDUCED_TYPENAME, MSVC.
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/iostreams/categories.hpp>
#include <streams_boost/iostreams/flush.hpp>
#include <streams_boost/iostreams/detail/adapter/non_blocking_adapter.hpp>
#include <streams_boost/iostreams/detail/ios.hpp> // STREAMS_BOOST_IOS
#include <streams_boost/iostreams/detail/select.hpp>
#include <streams_boost/iostreams/detail/wrap_unwrap.hpp>
#include <streams_boost/iostreams/operations_fwd.hpp>
#include <streams_boost/iostreams/traits.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/type_traits/is_convertible.hpp>
#include <streams_boost/type_traits/is_integral.hpp>
#include <streams_boost/type_traits/remove_cv.hpp>
#include <streams_boost/type_traits/remove_reference.hpp>

// Must come last.
#include <streams_boost/iostreams/detail/config/disable_warnings.hpp>

namespace streams_boost { namespace iostreams {

template<typename T>
void close(T& t);

template<typename T>
void close(T& t, STREAMS_BOOST_IOS::openmode which);

template<typename T, typename Sink>
void close(T& t, Sink& snk, STREAMS_BOOST_IOS::openmode which);
    
namespace detail {

template<typename T>
void close_all(T& t)
{ 
    try {
        streams_boost::iostreams::close(t, STREAMS_BOOST_IOS::in);
    } catch (...) {
        try {
            streams_boost::iostreams::close(t, STREAMS_BOOST_IOS::out);
        } catch (...) { }
        throw;
    }
    streams_boost::iostreams::close(t, STREAMS_BOOST_IOS::out);
}

template<typename T, typename Sink>
void close_all(T& t, Sink& snk)
{ 
    try {
        streams_boost::iostreams::close(t, snk, STREAMS_BOOST_IOS::in);
    } catch (...) {
        try {
            streams_boost::iostreams::close(t, snk, STREAMS_BOOST_IOS::out);
        } catch (...) { }
        throw;
    }
    streams_boost::iostreams::close(t, snk, STREAMS_BOOST_IOS::out);
}

} // End namespaces detail. 

} } // End namespaces iostreams, streams_boost.

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300) //-----------------------------------//
# include <streams_boost/iostreams/detail/vc6/close.hpp>
#else // #if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300) //--------------------------//

namespace streams_boost { namespace iostreams {

namespace detail {

template<typename T>
struct close_impl;

} // End namespace detail.

template<typename T>
void close(T& t) { detail::close_all(t); }

template<typename T>
void close(T& t, STREAMS_BOOST_IOS::openmode which)
{ 
#ifdef STREAMS_BOOST_IOSTREAMS_STRICT
    assert(which == STREAMS_BOOST_IOS::in || which == STREAMS_BOOST_IOS::out);
#else
    if (which == (STREAMS_BOOST_IOS::in | STREAMS_BOOST_IOS::out)) {
        detail::close_all(t);
        return;
    }
#endif
    detail::close_impl<T>::close(detail::unwrap(t), which); 
}

template<typename T, typename Sink>
void close(T& t, Sink& snk, STREAMS_BOOST_IOS::openmode which)
{ 
#ifdef STREAMS_BOOST_IOSTREAMS_STRICT
    assert(which == STREAMS_BOOST_IOS::in || which == STREAMS_BOOST_IOS::out);
#else
    if (which == (STREAMS_BOOST_IOS::in | STREAMS_BOOST_IOS::out)) {
        detail::close_all(t, snk);
        return;
    }
#endif
    detail::close_impl<T>::close(detail::unwrap(t), snk, which); 
}

namespace detail {

//------------------Definition of close_impl----------------------------------//

struct close_streams_boost_stream { };
struct close_filtering_stream { };

template<typename T>
struct close_tag {
    typedef typename category_of<T>::type             category;
    typedef typename detail::unwrapped_type<T>::type  unwrapped;
    typedef typename
            iostreams::select<
                mpl::not_< is_convertible<category, closable_tag> >,
                any_tag,
                mpl::or_<
                    is_streams_boost_stream<unwrapped>,
                    is_streams_boost_stream_buffer<unwrapped>
                >,
                close_streams_boost_stream,
                mpl::or_<
                    is_filtering_stream<unwrapped>,
                    is_filtering_streambuf<unwrapped>
                >,
                close_filtering_stream,
                mpl::or_<
                    is_convertible<category, two_sequence>,
                    is_convertible<category, dual_use>
                >,
                two_sequence,
                else_,
                closable_tag
            >::type type;
};

template<typename T>
struct close_impl
    : mpl::if_<
          is_custom<T>,
          operations<T>,
          close_impl<STREAMS_BOOST_DEDUCED_TYPENAME close_tag<T>::type>
      >::type
    { };

template<>
struct close_impl<any_tag> {
    template<typename T>
    static void close(T& t, STREAMS_BOOST_IOS::openmode which)
    {
        if (which == STREAMS_BOOST_IOS::out)
            iostreams::flush(t);
    }

    template<typename T, typename Sink>
    static void close(T& t, Sink& snk, STREAMS_BOOST_IOS::openmode which)
    {
        if (which == STREAMS_BOOST_IOS::out) {
            non_blocking_adapter<Sink> nb(snk);
            iostreams::flush(t, nb);
        }
    }
};

template<>
struct close_impl<close_streams_boost_stream> {
    template<typename T>
    static void close(T& t)
    {
        t.close();
    }
    template<typename T>
    static void close(T& t, STREAMS_BOOST_IOS::openmode which)
    {
        if (which == STREAMS_BOOST_IOS::out)
            t.close();
    }
};

template<>
struct close_impl<close_filtering_stream> {
    template<typename T>
    static void close(T& t, STREAMS_BOOST_IOS::openmode which)
    {
        typedef typename category_of<T>::type category;
        const bool in =  is_convertible<category, input>::value &&
                        !is_convertible<category, output>::value;
        if (in == (which == STREAMS_BOOST_IOS::in) && t.is_complete())
            t.pop();
    }
};

template<>
struct close_impl<closable_tag> {
    template<typename T>
    static void close(T& t, STREAMS_BOOST_IOS::openmode which)
    {
        typedef typename category_of<T>::type category;
        const bool in =  is_convertible<category, input>::value &&
                        !is_convertible<category, output>::value;
        if (in == (which == STREAMS_BOOST_IOS::in))
            t.close();
    }
    template<typename T, typename Sink>
    static void close(T& t, Sink& snk, STREAMS_BOOST_IOS::openmode which)
    {
        typedef typename category_of<T>::type category;
        const bool in =  is_convertible<category, input>::value &&
                        !is_convertible<category, output>::value;
        if (in == (which == STREAMS_BOOST_IOS::in)) {
            non_blocking_adapter<Sink> nb(snk);
            t.close(nb);
        }
    }
};

template<>
struct close_impl<two_sequence> {
    template<typename T>
    static void close(T& t, STREAMS_BOOST_IOS::openmode which) { t.close(which); }
    template<typename T, typename Sink>
    static void close(T& t, Sink& snk, STREAMS_BOOST_IOS::openmode which)
    {
        non_blocking_adapter<Sink> nb(snk);
        t.close(nb, which);
    }
};

} // End namespace detail.

} } // End namespaces iostreams, streams_boost.

#endif // #if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300) //-------------------------//

#include <streams_boost/iostreams/detail/config/enable_warnings.hpp>

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_CLOSE_HPP_INCLUDED
