//  Boost string_algo library find_format_all.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/ for updates, documentation, and revision history.

#ifndef STREAMS_BOOST_STRING_FIND_FORMAT_ALL_DETAIL_HPP
#define STREAMS_BOOST_STRING_FIND_FORMAT_ALL_DETAIL_HPP

#include <streams_boost/algorithm/string/config.hpp>
#include <streams_boost/range/iterator_range.hpp>
#include <streams_boost/range/const_iterator.hpp>
#include <streams_boost/range/value_type.hpp>
#include <streams_boost/algorithm/string/detail/find_format_store.hpp>
#include <streams_boost/algorithm/string/detail/replace_storage.hpp>

namespace streams_boost {
    namespace algorithm {
        namespace detail {

// find_format_all_copy (iterator variant) implementation ---------------------------//

           template< 
                typename OutputIteratorT,
                typename InputT,
                typename FinderT,
                typename FormatterT,
                typename FindResultT,
                typename FormatResultT >
            inline OutputIteratorT find_format_all_copy_impl2(
                OutputIteratorT Output,
                const InputT& Input,
                FinderT Finder,
                FormatterT Formatter,
                const FindResultT& FindResult,
                const FormatResultT& FormatResult )
            {       
                typedef STREAMS_BOOST_STRING_TYPENAME 
                    range_const_iterator<InputT>::type input_iterator_type; 

                typedef find_format_store<
                        input_iterator_type, 
                        FormatterT,
                        FormatResultT > store_type;

                // Create store for the find result
                store_type M( FindResult, FormatResult, Formatter );

                // Initialize last match
                input_iterator_type LastMatch=::streams_boost::begin(Input);

                // Iterate through all matches
                while( M )
                {
                    // Copy the beginning of the sequence
                    std::copy( LastMatch, M.begin(), Output );
                    // Copy formated result
                    std::copy( ::streams_boost::begin(M.format_result()), ::streams_boost::end(M.format_result()), Output );

                    // Proceed to the next match
                    LastMatch=M.end();
                    M=Finder( LastMatch, ::streams_boost::end(Input) );
                }

                // Copy the rest of the sequence
                std::copy( LastMatch, ::streams_boost::end(Input), Output );

                return Output;
            }

            template< 
                typename OutputIteratorT,
                typename InputT,
                typename FinderT,
                typename FormatterT,
                typename FindResultT >
            inline OutputIteratorT find_format_all_copy_impl(
                OutputIteratorT Output,
                const InputT& Input,
                FinderT Finder,
                FormatterT Formatter,
                const FindResultT& FindResult )
            {       
                return ::streams_boost::algorithm::detail::find_format_all_copy_impl2( 
                    Output,
                    Input,
                    Finder,
                    Formatter,
                    FindResult,
                    Formatter(FindResult) );
            }

 // find_format_all_copy implementation ----------------------------------------------//

           template< 
                typename InputT, 
                typename FinderT,
                typename FormatterT,
                typename FindResultT,
                typename FormatResultT >
            inline InputT find_format_all_copy_impl2(
                const InputT& Input,
                FinderT Finder,
                FormatterT Formatter,
                const FindResultT& FindResult,
                const FormatResultT& FormatResult)
            {
                typedef STREAMS_BOOST_STRING_TYPENAME 
                    range_const_iterator<InputT>::type input_iterator_type; 

                typedef find_format_store<
                        input_iterator_type, 
                        FormatterT,
                        FormatResultT > store_type;

                // Create store for the find result
                store_type M( FindResult, FormatResult, Formatter );

                // Initialize last match
                input_iterator_type LastMatch=::streams_boost::begin(Input);

                // Output temporary
                InputT Output;

                // Iterate through all matches
                while( M )
                {
                    // Copy the beginning of the sequence
                    insert( Output, ::streams_boost::end(Output), LastMatch, M.begin() );
                    // Copy formated result
                    insert( Output, ::streams_boost::end(Output), M.format_result() );

                    // Proceed to the next match
                    LastMatch=M.end();
                    M=Finder( LastMatch, ::streams_boost::end(Input) );
                }

                // Copy the rest of the sequence
                ::streams_boost::algorithm::detail::insert( Output, ::streams_boost::end(Output), LastMatch, ::streams_boost::end(Input) );

                return Output;
            }

            template< 
                typename InputT, 
                typename FinderT,
                typename FormatterT,
                typename FindResultT >
            inline InputT find_format_all_copy_impl(
                const InputT& Input,
                FinderT Finder,
                FormatterT Formatter,
                const FindResultT& FindResult)
            {
                return ::streams_boost::algorithm::detail::find_format_all_copy_impl2(
                    Input,
                    Finder,
                    Formatter,
                    FindResult,
                    Formatter(FindResult) );
            }

 // find_format_all implementation ------------------------------------------------//
        
            template<
                typename InputT,
                typename FinderT,
                typename FormatterT,
                typename FindResultT,
                typename FormatResultT >
            inline void find_format_all_impl2( 
                InputT& Input,
                FinderT Finder,
                FormatterT Formatter,
                FindResultT FindResult,
                FormatResultT FormatResult)
            {
                typedef STREAMS_BOOST_STRING_TYPENAME 
                    range_iterator<InputT>::type input_iterator_type; 
                typedef find_format_store<
                        input_iterator_type, 
                        FormatterT,
                        FormatResultT > store_type;

                // Create store for the find result
                store_type M( FindResult, FormatResult, Formatter );
          
                // Instantiate replacement storage
                std::deque<
                    STREAMS_BOOST_STRING_TYPENAME range_value<InputT>::type> Storage;

                // Initialize replacement iterators
                input_iterator_type InsertIt=::streams_boost::begin(Input);
                input_iterator_type SearchIt=::streams_boost::begin(Input);
                
                while( M )
                {
                    // process the segment
                    InsertIt=process_segment( 
                        Storage,
                        Input,
                        InsertIt,
                        SearchIt,
                        M.begin() );
                    
                    // Adjust search iterator
                    SearchIt=M.end();

                    // Copy formated replace to the storage
                    ::streams_boost::algorithm::detail::copy_to_storage( Storage, M.format_result() );

                    // Find range for a next match
                    M=Finder( SearchIt, ::streams_boost::end(Input) );
                }

                // process the last segment
                InsertIt=::streams_boost::algorithm::detail::process_segment( 
                    Storage,
                    Input,
                    InsertIt,
                    SearchIt,
                    ::streams_boost::end(Input) );
                
                if ( Storage.empty() )
                {
                    // Truncate input
                    ::streams_boost::algorithm::detail::erase( Input, InsertIt, ::streams_boost::end(Input) );
                }
                else
                {
                    // Copy remaining data to the end of input
                    ::streams_boost::algorithm::detail::insert( Input, ::streams_boost::end(Input), Storage.begin(), Storage.end() );
                }
            }

            template<
                typename InputT,
                typename FinderT,
                typename FormatterT,
                typename FindResultT >
            inline void find_format_all_impl( 
                InputT& Input,
                FinderT Finder,
                FormatterT Formatter,
                FindResultT FindResult)
            {
                ::streams_boost::algorithm::detail::find_format_all_impl2(
                    Input,
                    Finder,
                    Formatter,
                    FindResult,
                    Formatter(FindResult) );
            }

        } // namespace detail
    } // namespace algorithm
} // namespace streams_boost

#endif  // STREAMS_BOOST_STRING_FIND_FORMAT_ALL_DETAIL_HPP
