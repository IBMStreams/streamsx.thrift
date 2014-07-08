//  Boost string_algo library formatter.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/ for updates, documentation, and revision history.

#ifndef STREAMS_BOOST_STRING_FORMATTER_HPP
#define STREAMS_BOOST_STRING_FORMATTER_HPP

#include <streams_boost/detail/iterator.hpp>
#include <streams_boost/range/value_type.hpp>
#include <streams_boost/range/iterator_range.hpp>
#include <streams_boost/range/as_literal.hpp>

#include <streams_boost/algorithm/string/detail/formatter.hpp>

/*! \file
    Defines Formatter generators. Formatter is a functor which formats
    a string according to given parameters. A Formatter works
    in conjunction with a Finder. A Finder can provide additional information
    for a specific Formatter. An example of such a cooperation is regex_finder
    and regex_formatter.

    Formatters are used as pluggable components for replace facilities. 
    This header contains generator functions for the Formatters provided in this library.
*/

namespace streams_boost {
    namespace algorithm {

// generic formatters  ---------------------------------------------------------------//

        //! Constant formatter
        /*!
            Construct the \c const_formatter. Const formatter always returns
            the same value, regardless of the parameter.

            \param Format A predefined value used as a result for formating
            \return An instance of the \c const_formatter object.
        */
        template<typename RangeT>
        inline detail::const_formatF<
            iterator_range<
                STREAMS_BOOST_STRING_TYPENAME range_const_iterator<RangeT>::type> >
        const_formatter(const RangeT& Format)
        {
            return detail::const_formatF<
                iterator_range<
                    STREAMS_BOOST_STRING_TYPENAME range_const_iterator<RangeT>::type> >(::streams_boost::as_literal(Format));
        }

        //! Identity formatter
        /*!
            Construct the \c identity_formatter. Identity formatter always returns
            the parameter.

            \return An instance of the \c identity_formatter object.
        */
        template<typename RangeT>
        inline detail::identity_formatF<
            iterator_range<
                STREAMS_BOOST_STRING_TYPENAME range_const_iterator<RangeT>::type> >
        identity_formatter()
        {
            return detail::identity_formatF<
                iterator_range<
                    STREAMS_BOOST_STRING_TYPENAME range_const_iterator<RangeT>::type> >();
        }

        //! Empty formatter
        /*!
            Construct the \c empty_formatter. Empty formatter always returns an empty
            sequence. 

            \param Input container used to select a correct value_type for the
                         resulting empty_container<>.
            \return An instance of the \c empty_formatter object.
        */
        template<typename RangeT>
        inline detail::empty_formatF< 
            STREAMS_BOOST_STRING_TYPENAME range_value<RangeT>::type>
        empty_formatter(const RangeT&)
        {
            return detail::empty_formatF<
                STREAMS_BOOST_STRING_TYPENAME range_value<RangeT>::type>();
        }


    } // namespace algorithm

    // pull the names to the streams_boost namespace
    using algorithm::const_formatter;
    using algorithm::identity_formatter;
    using algorithm::empty_formatter;

} // namespace streams_boost


#endif  // STREAMS_BOOST_FORMATTER_HPP
