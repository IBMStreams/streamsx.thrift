// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_BACK_INSERTER_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_BACK_INSERTER_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/iostreams/detail/ios.hpp> // streamsize.
#include <streams_boost/iostreams/categories.hpp>

namespace streams_boost { namespace iostreams {

template<typename Container>
class back_insert_device {
public:
    typedef typename Container::value_type  char_type;
    typedef sink_tag                        category;
    back_insert_device(Container& cnt) : container(&cnt) { }
    std::streamsize write(const char_type* s, std::streamsize n)
    { 
        container->insert(container->end(), s, s + n); 
        return n;
    }
protected:
    Container* container;
};

template<typename Container>
back_insert_device<Container> back_inserter(Container& cnt)
{ return back_insert_device<Container>(cnt); }

} } // End namespaces iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_BACK_INSERTER_HPP_INCLUDED
