// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_IS_ITERATOR_RANGE_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_IS_ITERATOR_RANGE_HPP_INCLUDED       
 
#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/iostreams/detail/bool_trait_def.hpp>

// Must come last.
#include <streams_boost/iostreams/detail/config/disable_warnings.hpp>

namespace streams_boost { 

# if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //---------------------------------//

// We avoid dependence on Boost.Range by using a forward declaration.
template<typename Iterator>
class iterator_range;
    
namespace iostreams {

STREAMS_BOOST_IOSTREAMS_BOOL_TRAIT_DEF(is_iterator_range, streams_boost::iterator_range, 1)

} // End namespace iostreams.

# else // # if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) //-----------------------//

namespace iostreams {    

    template<typename T>
    struct is_iterator_range {
        STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
    };

} // End namespace iostreams.

# endif // # if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300) //----------------------//

} // End namespace streams_boost.

#include <streams_boost/iostreams/detail/config/enable_warnings.hpp>

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_IS_ITERATOR_RANGE_HPP_INCLUDED
