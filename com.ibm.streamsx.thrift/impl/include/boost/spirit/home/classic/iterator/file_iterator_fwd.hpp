/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/

#if !defined(STREAMS_BOOST_SPIRIT_FILE_ITERATOR_FWD_HPP)
#define STREAMS_BOOST_SPIRIT_FILE_ITERATOR_FWD_HPP

#include <streams_boost/spirit/home/classic/namespace.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    namespace fileiter_impl 
    {
        template <typename CharT = char>
        class std_file_iterator;

        // may never be defined -- so what...
        template <typename CharT = char>
        class mmap_file_iterator;
    } 

    // no defaults here -- too much dependencies
    template <
        typename CharT,
        typename BaseIterator
    > class file_iterator;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

#endif

