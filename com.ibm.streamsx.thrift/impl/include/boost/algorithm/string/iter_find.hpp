//  Boost string_algo library iter_find.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/ for updates, documentation, and revision history.

#ifndef STREAMS_BOOST_STRING_ITER_FIND_HPP
#define STREAMS_BOOST_STRING_ITER_FIND_HPP

#include <streams_boost/algorithm/string/config.hpp>
#include <algorithm>
#include <iterator>
#include <streams_boost/iterator/transform_iterator.hpp>

#include <streams_boost/range/iterator_range.hpp>
#include <streams_boost/range/begin.hpp>
#include <streams_boost/range/end.hpp>
#include <streams_boost/range/iterator.hpp>
#include <streams_boost/range/value_type.hpp>
#include <streams_boost/range/as_literal.hpp>

#include <streams_boost/algorithm/string/concept.hpp>
#include <streams_boost/algorithm/string/find_iterator.hpp>
#include <streams_boost/algorithm/string/detail/util.hpp>

/*! \file
    Defines generic split algorithms. Split algorithms can be 
    used to divide a sequence into several part according 
    to a given criteria. Result is given as a 'container 
    of containers' where elements are copies or references 
    to extracted parts.

    There are two algorithms provided. One iterates over matching
    substrings, the other one over the gaps between these matches.
*/

namespace streams_boost {
    namespace algorithm {

//  iterate find ---------------------------------------------------//

        //! Iter find algorithm
        /*!
            This algorithm executes a given finder in iteration on the input,
            until the end of input is reached, or no match is found.
            Iteration is done using built-in find_iterator, so the real 
            searching is performed only when needed.
            In each iteration new match is found and added to the result.

            \param Result A 'container container' to contain the result of search.
                Both outer and inner container must have constructor taking a pair
                of iterators as an argument.
                Typical type of the result is 
                    \c std::vector<streams_boost::iterator_range<iterator>>
                (each element of such a vector will container a range delimiting 
                a match).
            \param Input A container which will be searched.
            \param Finder A Finder object used for searching
            \return A reference the result

            \note Prior content of the result will be overwritten.
        */
        template< 
            typename SequenceSequenceT,
            typename RangeT,
            typename FinderT >
        inline SequenceSequenceT&
        iter_find(
            SequenceSequenceT& Result,
            RangeT& Input,
            FinderT Finder )
        {
            STREAMS_BOOST_CONCEPT_ASSERT((
                FinderConcept<
                    FinderT,
                    STREAMS_BOOST_STRING_TYPENAME range_iterator<RangeT>::type>
                ));

            iterator_range<STREAMS_BOOST_STRING_TYPENAME range_iterator<RangeT>::type> lit_input(::streams_boost::as_literal(Input));

            typedef STREAMS_BOOST_STRING_TYPENAME 
                range_iterator<RangeT>::type input_iterator_type;
            typedef find_iterator<input_iterator_type> find_iterator_type;
            typedef detail::copy_iterator_rangeF<
                STREAMS_BOOST_STRING_TYPENAME 
                    range_value<SequenceSequenceT>::type,
                input_iterator_type> copy_range_type;
            
            input_iterator_type InputEnd=::streams_boost::end(lit_input);

            typedef transform_iterator<copy_range_type, find_iterator_type>
                transform_iter_type;
    
            transform_iter_type itBegin=
                ::streams_boost::make_transform_iterator( 
                    find_iterator_type( ::streams_boost::begin(lit_input), InputEnd, Finder ),
                    copy_range_type());
            
            transform_iter_type itEnd=
                ::streams_boost::make_transform_iterator( 
                    find_iterator_type(),
                    copy_range_type());

            SequenceSequenceT Tmp(itBegin, itEnd);
                        
            Result.swap(Tmp);
            return Result;
        }

//  iterate split ---------------------------------------------------//

        //! Split find algorithm
        /*!
            This algorithm executes a given finder in iteration on the input,
            until the end of input is reached, or no match is found.
            Iteration is done using built-in find_iterator, so the real 
            searching is performed only when needed.
            Each match is used as a separator of segments. These segments are then
            returned in the result.

            \param Result A 'container container' to container the result of search.
                Both outer and inner container must have constructor taking a pair
                of iterators as an argument.
                Typical type of the result is 
                    \c std::vector<streams_boost::iterator_range<iterator>>
                (each element of such a vector will container a range delimiting 
                a match).
            \param Input A container which will be searched.
            \param Finder A finder object used for searching
            \return A reference the result

            \note Prior content of the result will be overwritten.
        */
        template< 
            typename SequenceSequenceT,
            typename RangeT,
            typename FinderT >
        inline SequenceSequenceT&
        iter_split(
            SequenceSequenceT& Result,
            RangeT& Input,
            FinderT Finder )
        {
            STREAMS_BOOST_CONCEPT_ASSERT((
                FinderConcept<FinderT,
                STREAMS_BOOST_STRING_TYPENAME range_iterator<RangeT>::type>
                ));

            iterator_range<STREAMS_BOOST_STRING_TYPENAME range_iterator<RangeT>::type> lit_input(::streams_boost::as_literal(Input));

            typedef STREAMS_BOOST_STRING_TYPENAME 
                range_iterator<RangeT>::type input_iterator_type;
            typedef split_iterator<input_iterator_type> find_iterator_type;
            typedef detail::copy_iterator_rangeF<
                STREAMS_BOOST_STRING_TYPENAME 
                    range_value<SequenceSequenceT>::type,
                input_iterator_type> copy_range_type;
            
            input_iterator_type InputEnd=::streams_boost::end(lit_input);

            typedef transform_iterator<copy_range_type, find_iterator_type>
                transform_iter_type;
    
            transform_iter_type itBegin=
                ::streams_boost::make_transform_iterator( 
                    find_iterator_type( ::streams_boost::begin(lit_input), InputEnd, Finder ),
                    copy_range_type() );

            transform_iter_type itEnd=
                ::streams_boost::make_transform_iterator( 
                    find_iterator_type(),
                    copy_range_type() );
            
            SequenceSequenceT Tmp(itBegin, itEnd);

            Result.swap(Tmp);
            return Result;
        }

    } // namespace algorithm

    // pull names to the streams_boost namespace
    using algorithm::iter_find;
    using algorithm::iter_split;

} // namespace streams_boost


#endif  // STREAMS_BOOST_STRING_ITER_FIND_HPP
