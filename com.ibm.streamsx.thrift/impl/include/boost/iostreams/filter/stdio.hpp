// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2005-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

// Based on the work of Christopher Diggins.

#ifndef STREAMS_BOOST_IOSTREAMS_STDIO_FILTER_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_STDIO_FILTER_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <iostream>
#include <memory>    // allocator.
#include <vector>
#include <streams_boost/iostreams/detail/config/wide_streams.hpp>
#include <streams_boost/iostreams/detail/char_traits.hpp>
#include <streams_boost/iostreams/detail/ios.hpp>
#include <streams_boost/iostreams/device/array.hpp>
#include <streams_boost/iostreams/device/back_inserter.hpp>
#include <streams_boost/iostreams/filter/aggregate.hpp>
#include <streams_boost/iostreams/pipeline.hpp>
#include <streams_boost/iostreams/stream_buffer.hpp>

namespace streams_boost { namespace iostreams {

namespace detail {

} // End namespace detail.

template<typename Ch, typename Alloc = std::allocator<Ch> >
class basic_stdio_filter : public aggregate_filter<Ch, Alloc> {
private:
    typedef aggregate_filter<Ch, Alloc>       base_type;
public:
    typedef typename base_type::char_type    char_type;
    typedef typename base_type::category     category;
    typedef typename base_type::vector_type  vector_type;
private:
    static std::istream& standard_input(char*) { return std::cin; }
    static std::ostream& standard_output(char*) { return std::cout; }
#ifndef STREAMS_BOOST_IOSTREAMS_NO_WIDE_STREAMS
    static std::wistream& standard_input(wchar_t*) { return std::wcin; }
    static std::wostream& standard_output(wchar_t*) { return std::wcout; }
#endif // STREAMS_BOOST_IOSTREAMS_NO_WIDE_STREAMS

    struct scoped_redirector { // Thanks to Maxim Egorushkin.
        typedef STREAMS_BOOST_IOSTREAMS_CHAR_TRAITS(Ch)                  traits_type;
        typedef STREAMS_BOOST_IOSTREAMS_BASIC_IOS(Ch, traits_type)       ios_type;
        typedef STREAMS_BOOST_IOSTREAMS_BASIC_STREAMBUF(Ch, traits_type) streambuf_type;
        scoped_redirector( ios_type& ios,
                           streambuf_type* newbuf )
            : ios_(ios), old_(ios.rdbuf(newbuf))
            { }
        ~scoped_redirector() { ios_.rdbuf(old_); }
        scoped_redirector& operator=(const scoped_redirector&);
        ios_type&        ios_;
        streambuf_type*  old_;
    };

    virtual void do_filter() = 0;
    virtual void do_filter(const vector_type& src, vector_type& dest)
    {
        stream_buffer< basic_array_source<Ch> >
                          srcbuf(&src[0], &src[0] + src.size());
        stream_buffer< back_insert_device<vector_type> >
                          destbuf(iostreams::back_inserter(dest));
        scoped_redirector redirect_input(standard_input((Ch*)0), &srcbuf);
        scoped_redirector redirect_output(standard_output((Ch*)0), &destbuf);
        do_filter();
    }
};
STREAMS_BOOST_IOSTREAMS_PIPABLE(basic_stdio_filter, 2)

typedef basic_stdio_filter<char>     stdio_filter;
typedef basic_stdio_filter<wchar_t>  wstdio_wfilter;

} } // End namespaces iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_STDIO_FILTER_HPP_INCLUDED
