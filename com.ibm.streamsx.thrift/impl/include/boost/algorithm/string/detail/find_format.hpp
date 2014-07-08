//  Boost string_algo library find_format.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
// 
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/ for updates, documentation, and revision history.

#ifndef STREAMS_BOOST_STRING_FIND_FORMAT_DETAIL_HPP
#define STREAMS_BOOST_STRING_FIND_FORMAT_DETAIL_HPP

#include <streams_boost/algorithm/string/config.hpp>
#include <streams_boost/range/iterator_range.hpp>
#include <streams_boost/range/const_iterator.hpp>
#include <streams_boost/range/iterator.hpp>
#include <streams_boost/algorithm/string/detail/find_format_store.hpp>
#include <streams_boost/algorithm/string/detail/replace_storage.hpp>

namespace streams_boost {
    namespace algorithm {
        namespace detail {

// find_format_copy (iterator variant) implementation -------------------------------//

           template< 
                typename OutputIteratorT,
                typename InputT,
                typename FormatterT,
                typename FindResultT,
                typename FormatResultT >
            inline OutputIteratorT find_format_copy_impl2(
                OutputIteratorT Output,
                const InputT& Input,
                FormatterT Formatter,
                const FindResultT& FindResult,
                const FormatResultT& FormatResult )
            {       
                typedef find_format_store<
                    STREAMS_BOOST_STRING_TYPENAME 
                        range_const_iterator<InputT>::type, 
                        FormatterT,
                        FormatResultT > store_type;

                // Create store for the find result
                store_type M( FindResult, FormatResult, Formatter );

                if ( !M )
                {
                    // Match not found - return original sequence
                    std::copy( ::streams_boost::begin(Input), ::streams_boost::end(Input), Output );
                    return Output;
                }

                // Copy the beginning of the sequence
                std::copy( ::streams_boost::begin(Input), ::streams_boost::begin(M), Output );
                // Format find result
                // Copy formated result
                std::copy( ::streams_boost::begin(M.format_result()), ::streams_boost::end(M.format_result()), Output );
                // Copy the rest of the sequence
                std::copy( M.end(), ::streams_boost::end(Input), Output );

                return Output;
            }

            template< 
                typename OutputIteratorT,
                typename InputT,
                typename FormatterT,
                typename FindResultT >
            inline OutputIteratorT find_format_copy_impl(
                OutputIteratorT Output,
                const InputT& Input,
                FormatterT Formatter,
                const FindResultT& FindResult )
            {       
                return ::streams_boost::algorithm::detail::find_format_copy_impl2( 
                    Output,
                    Input,
                    Formatter,
                    FindResult,
                    Formatter(FindResult) );
            }

 
// find_format_copy implementation --------------------------------------------------//

           template< 
                typename InputT, 
                typename FormatterT,
                typename FindResultT,
                typename FormatResultT >
            inline InputT find_format_copy_impl2(
                const InputT& Input,
                FormatterT Formatter,
                const FindResultT& FindResult,
                const FormatResultT& FormatResult)
            {
                typedef find_format_store<
                    STREAMS_BOOST_STRING_TYPENAME 
                        range_const_iterator<InputT>::type, 
                        FormatterT,
                        FormatResultT > store_type;

                // Create store for the find result
                store_type M( FindResult, FormatResult, Formatter );

                if ( !M )
                {
                    // Match not found - return original sequence
                    return InputT( Input );
                }

                InputT Output;
                // Copy the beginning of the sequence
                insert( Output, ::streams_boost::end(Output), ::streams_boost::begin(Input), M.begin() );
                // Copy formated result
                insert( Output, ::streams_boost::end(Output), M.format_result() );
                // Copy the rest of the sequence
                insert( Output, ::streams_boost::end(Output), M.end(), ::streams_boost::end(Input) );

                return Output;
            }

            template< 
                typename InputT, 
                typename FormatterT,
                typename FindResultT >
            inline InputT find_format_copy_impl(
                const InputT& Input,
                FormatterT Formatter,
                const FindResultT& FindResult)
            {
                return ::streams_boost::algorithm::detail::find_format_copy_impl2(
                    Input,
                    Formatter,
                    FindResult,
                    Formatter(FindResult) );
            }

 // replace implementation ----------------------------------------------------//
        
            template<
                typename InputT,
                typename FormatterT,
                typename FindResultT,
                typename FormatResultT >
            inline void find_format_impl2( 
                InputT& Input,
                FormatterT Formatter,
                const FindResultT& FindResult,
                const FormatResultT& FormatResult)
            {
                typedef find_format_store<
                    STREAMS_BOOST_STRING_TYPENAME 
                        range_iterator<InputT>::type, 
                        FormatterT,
                        FormatResultT > store_type;

                // Create store for the find result
                store_type M( FindResult, FormatResult, Formatter );

                if ( !M )
                {
                    // Search not found - return original sequence
                    return;
                }

                // Replace match
                ::streams_boost::algorithm::detail::replace( Input, M.begin(), M.end(), M.format_result() );
            }

            template<
                typename InputT,
                typename FormatterT,
                typename FindResultT >
            inline void find_format_impl( 
                InputT& Input,
                FormatterT Formatter,
                const FindResultT& FindResult)
            {
                ::streams_boost::algorithm::detail::find_format_impl2(
                    Input,
                    Formatter,
                    FindResult,
                    Formatter(FindResult) );
            }

        } // namespace detail
    } // namespace algorithm
} // namespace streams_boost

#endif  // STREAMS_BOOST_STRING_FIND_FORMAT_DETAIL_HPP
