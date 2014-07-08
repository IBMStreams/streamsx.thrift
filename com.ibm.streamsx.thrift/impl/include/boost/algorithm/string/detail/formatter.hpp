//  Boost string_algo library formatter.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#ifndef STREAMS_BOOST_STRING_FORMATTER_DETAIL_HPP
#define STREAMS_BOOST_STRING_FORMATTER_DETAIL_HPP


#include <streams_boost/range/iterator_range.hpp>
#include <streams_boost/range/begin.hpp>
#include <streams_boost/range/end.hpp>
#include <streams_boost/range/const_iterator.hpp>

#include <streams_boost/algorithm/string/detail/util.hpp>

//  generic replace functors -----------------------------------------------//

namespace streams_boost {
    namespace algorithm {
        namespace detail {

//  const format functor ----------------------------------------------------//

            // constant format functor
            template<typename RangeT>
            struct const_formatF
            {
            private:
                typedef STREAMS_BOOST_STRING_TYPENAME
                    range_const_iterator<RangeT>::type format_iterator;
                typedef iterator_range<format_iterator> result_type;
            
            public:
                // Construction
                const_formatF(const RangeT& Format) :
                    m_Format(::streams_boost::begin(Format), ::streams_boost::end(Format)) {}

                // Operation
#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
                template<typename Range2T>
                result_type& operator()(const Range2T&)
                {
                    return m_Format;
                }
#endif

                template<typename Range2T>
                const result_type& operator()(const Range2T&) const
                {
                    return m_Format;
                }

            private:
                result_type m_Format;
            };

//  identity format functor ----------------------------------------------------//

            // identity format functor
            template<typename RangeT>
            struct identity_formatF
            {
                // Operation
                template< typename Range2T >
                const RangeT& operator()(const Range2T& Replace) const
                {
                    return RangeT(::streams_boost::begin(Replace), ::streams_boost::end(Replace));
                }
            };

//  empty format functor ( used by erase ) ------------------------------------//
        
            // empty format functor
            template< typename CharT >
            struct empty_formatF
            {
                template< typename ReplaceT >
                empty_container<CharT> operator()(const ReplaceT&) const
                {
                    return empty_container<CharT>();
                }
            };

        } // namespace detail
    } // namespace algorithm
} // namespace streams_boost

#endif  // STREAMS_BOOST_STRING_FORMATTER_DETAIL_HPP
