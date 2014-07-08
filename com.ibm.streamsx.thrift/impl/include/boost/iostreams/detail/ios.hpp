// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_IOS_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_IOS_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              
                 
#include <streams_boost/config.hpp> // STREAMS_BOOST_MSVC.
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/iostreams/detail/config/wide_streams.hpp>
#ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
# if !STREAMS_BOOST_WORKAROUND(__MWERKS__, <= 0x3003)
#  include <ios>
# else
#  include <istream>
#  include <ostream>
# endif
#else 
# include <exception>
# include <iosfwd>
#endif 

namespace streams_boost { namespace iostreams { namespace detail {

#ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES //--------------------------------//
# define STREAMS_BOOST_IOSTREAMS_BASIC_IOS(ch, tr)  std::basic_ios< ch, tr >
# if !STREAMS_BOOST_WORKAROUND(__MWERKS__, <= 0x3003) && \
     !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600) && \
     !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300) \
     /**/

#define STREAMS_BOOST_IOS                std::ios
#define STREAMS_BOOST_IOSTREAMS_FAILURE  std::ios::failure

# else

#define STREAMS_BOOST_IOS                std::ios_base
#define STREAMS_BOOST_IOSTREAMS_FAILURE  std::ios_base::failure

# endif
#else // #ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES //-----------------------//

#define STREAMS_BOOST_IOS                          std::ios
#define STREAMS_BOOST_IOSTREAMS_BASIC_IOS(ch, tr)  std::ios
#define STREAMS_BOOST_IOSTREAMS_FAILURE            streams_boost::iostreams::detail::failure

class failure : std::exception {    
public:
    explicit failure(const std::string& what_arg) : what_(what_arg) { }
    const char* what() const { return what_.c_str(); }
private:
    std::string what_;
};

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES //----------------------//

} } } // End namespace failure, iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_IOS_HPP_INCLUDED
