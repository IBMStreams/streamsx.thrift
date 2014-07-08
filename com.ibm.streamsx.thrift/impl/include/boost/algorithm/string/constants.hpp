//  Boost string_algo library constants.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/ for updates, documentation, and revision history.

#ifndef STREAMS_BOOST_STRING_CONSTANTS_HPP
#define STREAMS_BOOST_STRING_CONSTANTS_HPP

namespace streams_boost {
    namespace algorithm {

    //! Token compression mode 
    /*!
        Specifies token compression mode for the token_finder.
    */
    enum token_compress_mode_type
    {
        token_compress_on,    //!< Compress adjacent tokens
        token_compress_off  //!< Do not compress adjacent tokens
    };
    
    } // namespace algorithm

    // pull the names to the streams_boost namespace
    using algorithm::token_compress_on;
    using algorithm::token_compress_off;

} // namespace streams_boost

#endif  // STREAMS_BOOST_STRING_CONSTANTS_HPP

