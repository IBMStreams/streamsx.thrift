// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_CONCEPTS_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_CONCEPTS_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/config.hpp>  // STREAMS_BOOST_MSVC
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/iostreams/categories.hpp>
#include <streams_boost/iostreams/detail/default_arg.hpp>
#include <streams_boost/iostreams/detail/ios.hpp>  // openmode.
#include <streams_boost/iostreams/positioning.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/type_traits/is_convertible.hpp>

namespace streams_boost { namespace iostreams {

//--------------Definitions of helper templates for device concepts-----------//

template<typename Mode, typename Ch = STREAMS_BOOST_IOSTREAMS_DEFAULT_ARG(char)>
struct device {
    typedef Ch char_type;
    struct category
        : Mode,
          device_tag,
          closable_tag,
          localizable_tag
        { };

    void close()
    {
        using namespace detail;
        STREAMS_BOOST_STATIC_ASSERT((!is_convertible<Mode, two_sequence>::value));
    }

    void close(STREAMS_BOOST_IOS::openmode)
    {
        using namespace detail;
        STREAMS_BOOST_STATIC_ASSERT((is_convertible<Mode, two_sequence>::value));
    }

    template<typename Locale>
    void imbue(const Locale&) { }
};

template<typename Mode, typename Ch = STREAMS_BOOST_IOSTREAMS_DEFAULT_ARG(wchar_t)>
struct wdevice : device<Mode, Ch> { };

typedef device<input>    source;
typedef wdevice<input>   wsource;
typedef device<output>   sink;
typedef wdevice<output>  wsink;

//--------------Definitions of helper templates for simple filter concepts----//

template<typename Mode, typename Ch = STREAMS_BOOST_IOSTREAMS_DEFAULT_ARG(char)>
struct filter {
    typedef Ch char_type;
    struct category
        : Mode,
          filter_tag,
          closable_tag,
          localizable_tag
        { };

    template<typename Device>
    void close(Device&)
    {
        using namespace detail;
        STREAMS_BOOST_STATIC_ASSERT((!is_convertible<Mode, two_sequence>::value));
        STREAMS_BOOST_STATIC_ASSERT((!is_convertible<Mode, dual_use>::value));
    }

    template<typename Device>
    void close(Device&, STREAMS_BOOST_IOS::openmode)
    {
        using namespace detail;
        STREAMS_BOOST_STATIC_ASSERT(
            (is_convertible<Mode, two_sequence>::value) ||
            (is_convertible<Mode, dual_use>::value)
        );
    }

    template<typename Locale>
    void imbue(const Locale&) { }
};

template<typename Mode, typename Ch = STREAMS_BOOST_IOSTREAMS_DEFAULT_ARG(wchar_t)>
struct wfilter : filter<Mode, Ch> { };

typedef filter<input>      input_filter;
typedef wfilter<input>     input_wfilter;
typedef filter<output>     output_filter;
typedef wfilter<output>    output_wfilter;
typedef filter<seekable>   seekable_filter;
typedef wfilter<seekable>  seekable_wfilter;
typedef filter<dual_use>   dual_use_filter;
typedef wfilter<dual_use>  dual_use_wfilter;
        
//------Definitions of helper templates for multi-character filter cncepts----//

template<typename Mode, typename Ch = char>
struct multichar_filter : filter<Mode, Ch> {
    struct category : filter<Mode, Ch>::category, multichar_tag { };
};

template<typename Mode, typename Ch = wchar_t>
struct multichar_wfilter : multichar_filter<Mode, Ch> { };

typedef multichar_filter<input>      multichar_input_filter;
typedef multichar_wfilter<input>     multichar_input_wfilter;
typedef multichar_filter<output>     multichar_output_filter;
typedef multichar_wfilter<output>    multichar_output_wfilter;
typedef multichar_filter<dual_use>   multichar_dual_use_filter;
typedef multichar_wfilter<dual_use>  multichar_dual_use_wfilter;

//----------------------------------------------------------------------------//

} } // End namespaces iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_CONCEPTS_HPP_INCLUDED
