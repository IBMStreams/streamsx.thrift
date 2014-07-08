//  Boost string_algo library trim.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/ for updates, documentation, and revision history.

#ifndef STREAMS_BOOST_STRING_TRIM_DETAIL_HPP
#define STREAMS_BOOST_STRING_TRIM_DETAIL_HPP

#include <streams_boost/algorithm/string/config.hpp>
#include <streams_boost/detail/iterator.hpp>

namespace streams_boost {
    namespace algorithm {
        namespace detail {

//  trim iterator helper -----------------------------------------------//

            template< typename ForwardIteratorT, typename PredicateT >
            inline ForwardIteratorT trim_end_iter_select( 
                ForwardIteratorT InBegin, 
                ForwardIteratorT InEnd, 
                PredicateT IsSpace,
                std::forward_iterator_tag )
            {
                ForwardIteratorT TrimIt=InBegin;

                for( ForwardIteratorT It=InBegin; It!=InEnd; ++It )
                {
                    if ( !IsSpace(*It) ) 
                    {
                        TrimIt=It;
                        ++TrimIt;
                    }
                }

                return TrimIt;
            }

            template< typename ForwardIteratorT, typename PredicateT >
            inline ForwardIteratorT trim_end_iter_select( 
                ForwardIteratorT InBegin, 
                ForwardIteratorT InEnd, 
                PredicateT IsSpace,
                std::bidirectional_iterator_tag )
            {
                for( ForwardIteratorT It=InEnd; It!=InBegin;  )
                {
                    if ( !IsSpace(*(--It)) )
                        return ++It;
                }

                return InBegin;
            }
   // Search for first non matching character from the beginning of the sequence
            template< typename ForwardIteratorT, typename PredicateT >
            inline ForwardIteratorT trim_begin( 
                ForwardIteratorT InBegin, 
                ForwardIteratorT InEnd, 
                PredicateT IsSpace )
            {
                ForwardIteratorT It=InBegin;
                for(; It!=InEnd; ++It )
                {
                    if (!IsSpace(*It))
                        return It;
                }

                return It;
            }

            // Search for first non matching character from the end of the sequence
            template< typename ForwardIteratorT, typename PredicateT >
            inline ForwardIteratorT trim_end( 
                ForwardIteratorT InBegin, 
                ForwardIteratorT InEnd, 
                PredicateT IsSpace )
            {
                typedef STREAMS_BOOST_STRING_TYPENAME streams_boost::detail::
                    iterator_traits<ForwardIteratorT>::iterator_category category;

                return ::streams_boost::algorithm::detail::trim_end_iter_select( InBegin, InEnd, IsSpace, category() );
            }


        } // namespace detail
    } // namespace algorithm
} // namespace streams_boost


#endif  // STREAMS_BOOST_STRING_TRIM_DETAIL_HPP
