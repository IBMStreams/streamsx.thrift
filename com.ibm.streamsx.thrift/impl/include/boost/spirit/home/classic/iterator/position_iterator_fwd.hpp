/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    Copyright (c) 2002-2006 Hartmut Kaiser
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_POSITION_ITERATOR_FWD_HPP)
#define STREAMS_BOOST_SPIRIT_POSITION_ITERATOR_FWD_HPP

#include <string>
#include <streams_boost/detail/iterator.hpp> // for streams_boost::detail::iterator_traits
#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/core/nil.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    template <typename String = std::string> 
    struct file_position_base;
    
    typedef file_position_base<std::string> file_position;

    template <typename String = std::string> 
    struct file_position_without_column_base;

    typedef file_position_without_column_base<std::string> file_position_without_column;

    template <
        typename ForwardIteratorT,
        typename PositionT = file_position_base<
            std::basic_string<
                typename streams_boost::detail::iterator_traits<ForwardIteratorT>::value_type
            > 
        >,
        typename SelfT = nil_t
    >
    class position_iterator;

    template
    <
        typename ForwardIteratorT,
        typename PositionT = file_position_base<
            std::basic_string<
                typename streams_boost::detail::iterator_traits<ForwardIteratorT>::value_type
            > 
        >
    >
    class position_iterator2;

    template <typename PositionT> class position_policy;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

#endif

