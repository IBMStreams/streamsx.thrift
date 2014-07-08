// Boost.Range library concept checks
//
//  Copyright Daniel Walker 2006. Use, modification and distribution
//  are subject to the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_CONCEPTS_HPP
#define STREAMS_BOOST_RANGE_CONCEPTS_HPP

#include <streams_boost/concept_check.hpp>
#include <streams_boost/iterator/iterator_concepts.hpp>
#include <streams_boost/range/begin.hpp>
#include <streams_boost/range/end.hpp>

/*!
 * \file
 * \brief Concept checks for the Boost Range library.
 *
 * The structures in this file may be used in conjunction with the
 * Boost Concept Check library to insure that the type of a function
 * parameter is compatible with a range concept. If not, a meaningful
 * compile time error is generated. Checks are provided for the range
 * concepts related to iterator traversal categories. For example, the
 * following line checks that the type T models the ForwardRange
 * concept.
 *
 * \code
 * function_requires<ForwardRangeConcept<T> >();
 * \endcode
 *
 * An additional concept check is required for the value access
 * property of the range. For example to check for a
 * ForwardReadableRange, the following code is required.
 *
 * \code
 * function_requires<ForwardRangeConcept<T> >();
 * function_requires<
 *     ReadableIteratorConcept<
 *         typename range_iterator<T>::type
 *     >
 * >();
 * \endcode
 *
 * \see http://www.streams_boost.org/libs/range/doc/range.html for details
 * about range concepts.
 * \see http://www.streams_boost.org/libs/iterator/doc/iterator_concepts.html
 * for details about iterator concepts.
 * \see http://www.streams_boost.org/libs/concept_check/concept_check.htm for
 * details about concept checks.
 */

namespace streams_boost {

    //! Check if a type T models the SinglePassRange range concept.
    template<typename T>
    struct SinglePassRangeConcept 
    {
        typedef typename range_iterator<T const>::type  range_const_iterator;
        typedef typename range_iterator<T>::type        range_iterator;

        void constraints()
        {
            function_requires<
                streams_boost_concepts::SinglePassIteratorConcept<
                    range_iterator
                >
            >();
            i = streams_boost::begin(a);
            i = streams_boost::end(a);
            const_constraints(a);
        }
        
        void const_constraints(const T& a)
        {
            ci = streams_boost::begin(a);
            ci = streams_boost::end(a);
        }
        T a;
        range_iterator i;
        range_const_iterator ci;
    };

    //! Check if a type T models the ForwardRange range concept.
    template<typename T>
    struct ForwardRangeConcept 
    {
        void constraints()
        {
            function_requires<
                SinglePassRangeConcept<T>
            >();        
            function_requires<
                streams_boost_concepts::ForwardTraversalConcept<
                    typename range_iterator<T>::type
                >
            >();
        }
    };

    //! Check if a type T models the BidirectionalRange range concept.
    template<typename T>
    struct BidirectionalRangeConcept 
    {
        void constraints()
        {
            function_requires<
                    ForwardRangeConcept<T>
            >();        
            function_requires<
                streams_boost_concepts::BidirectionalTraversalConcept<
                    typename range_iterator<T>::type
                >
            >();
        }
    };

    //! Check if a type T models the RandomAccessRange range concept.
    template<typename T>
    struct RandomAccessRangeConcept 
    {
        void constraints()
        {
            function_requires<
                BidirectionalRangeConcept<T>
            >();        
            function_requires<
                streams_boost_concepts::RandomAccessTraversalConcept<
                    typename range_iterator<T>::type
                >
            >();
         }
    };

} // namespace streams_boost

#endif // STREAMS_BOOST_RANGE_CONCEPTS_HPP
