// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2005-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_COUNTED_ARRAY_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_COUNTED_ARRAY_HPP_INCLUDED

#include <algorithm>                               // min.
#include <streams_boost/iostreams/categories.hpp>
#include <streams_boost/iostreams/detail/char_traits.hpp>
#include <streams_boost/iostreams/detail/ios.hpp>          // streamsize.

namespace streams_boost { namespace iostreams { namespace detail {

template<typename Ch>
class counted_array_source {
public:
    typedef Ch          char_type;
    typedef source_tag  category;
    counted_array_source(const Ch* buf, std::streamsize size) 
        : buf_(buf), ptr_(0), end_(size)
        { }
    std::streamsize read(Ch* s, std::streamsize n)
    {
        std::streamsize result = (std::min)(n, end_ - ptr_);
        STREAMS_BOOST_IOSTREAMS_CHAR_TRAITS(char_type)::copy
            (s, buf_ + ptr_, result);
        ptr_ += result;
        return result;
    }
    std::streamsize count() const { return ptr_; }
private:
    const Ch*        buf_;
    std::streamsize  ptr_, end_;
};

template<typename Ch>
struct counted_array_sink {
public:
    typedef Ch        char_type;
    typedef sink_tag  category;
    counted_array_sink(Ch* buf, std::streamsize size) 
        : buf_(buf), ptr_(0), end_(size)
        { }
        std::streamsize write(const Ch* s, std::streamsize n)
    {
        std::streamsize result = (std::min)(n, end_ - ptr_);
        STREAMS_BOOST_IOSTREAMS_CHAR_TRAITS(char_type)::copy
            (buf_ + ptr_, s, result);
        ptr_ += result;
        return result;
    }
    std::streamsize count() const { return ptr_; }
private:
    Ch*              buf_;
    std::streamsize  ptr_, end_;
};

} } } // End namespaces iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_COUNTED_ARRAY_HPP_INCLUDED
