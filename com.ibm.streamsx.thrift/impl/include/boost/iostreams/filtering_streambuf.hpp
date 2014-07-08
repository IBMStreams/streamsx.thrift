// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_FILTERING_STREAMBUF_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_FILTERING_STREAMBUF_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <exception>
#include <memory>                               // allocator.
#include <streams_boost/iostreams/chain.hpp>
#include <streams_boost/iostreams/detail/access_control.hpp>
#include <streams_boost/iostreams/detail/char_traits.hpp>
#include <streams_boost/iostreams/detail/push.hpp>
#include <streams_boost/iostreams/detail/streambuf.hpp> // pubsync.
#include <streams_boost/iostreams/detail/streambuf/chainbuf.hpp>
#include <streams_boost/mpl/if.hpp>                    

namespace streams_boost { namespace iostreams {

//
// Macro: STREAMS_BOOST_IOSTREAMS_DEFINE_FILTERBUF(name_, chain_type_, default_char_)
// Description: Defines a template derived from std::basic_streambuf which uses
//      a chain to perform i/o. The template has the following parameters:
//      Ch - The character type.
//      Tr - The character traits type.
//      Alloc - The allocator type.
//      Access - Indicates accessibility of the chain interface; must be either
//          public_ or protected_; defaults to public_.
//
#define STREAMS_BOOST_IOSTREAMS_DEFINE_FILTER_STREAMBUF(name_, chain_type_, default_char_) \
    template< typename Mode, \
              typename Ch = default_char_, \
              typename Tr = STREAMS_BOOST_IOSTREAMS_CHAR_TRAITS(Ch), \
              typename Alloc = std::allocator<Ch>, \
              typename Access = public_ > \
    class name_ : public streams_boost::iostreams::detail::chainbuf< \
                             chain_type_<Mode, Ch, Tr, Alloc>, Mode, Access \
                         > \
    { \
    public: \
        typedef Ch                                             char_type; \
        struct category \
            : Mode, closable_tag, streambuf_tag \
            { }; \
        STREAMS_BOOST_IOSTREAMS_STREAMBUF_TYPEDEFS(Tr) \
        typedef Mode                                           mode; \
        typedef chain_type_<Mode, Ch, Tr, Alloc>               chain_type; \
        name_() { } \
        STREAMS_BOOST_IOSTREAMS_DEFINE_PUSH_CONSTRUCTOR(name_, mode, Ch, push_impl) \
        ~name_() { if (this->is_complete()) this->STREAMS_BOOST_IOSTREAMS_PUBSYNC(); } \
    }; \
    /**/ 
STREAMS_BOOST_IOSTREAMS_DEFINE_FILTER_STREAMBUF(filtering_streambuf, streams_boost::iostreams::chain, char)
STREAMS_BOOST_IOSTREAMS_DEFINE_FILTER_STREAMBUF(filtering_wstreambuf, streams_boost::iostreams::chain, wchar_t)

typedef filtering_streambuf<input>    filtering_istreambuf;
typedef filtering_streambuf<output>   filtering_ostreambuf;
typedef filtering_wstreambuf<input>   filtering_wistreambuf;
typedef filtering_wstreambuf<output>  filtering_wostreambuf;

} } // End namespaces iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_FILTERING_STREAMBUF_HPP_INCLUDED
