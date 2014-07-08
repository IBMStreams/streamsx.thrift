/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)
 * 
 * See http://www.streams_boost.org/libs/iostreams for documentation.

 * File:        streams_boost/iostreams/detail/execute.hpp
 * Date:        Thu Dec 06 13:21:54 MST 2007
 * Copyright:   2007-2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the function streams_boost::iostreams::detail::absolute_path, used for 
 * debug output for mapped files.
 */

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_ABSOLUTE_PATH_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_ABSOLUTE_PATH_HPP_INCLUDED

#include <string>
#include <streams_boost/iostreams/detail/config/windows_posix.hpp>
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
# include <cctype>
#endif
#include <streams_boost/iostreams/detail/current_directory.hpp>

namespace streams_boost { namespace iostreams { namespace detail {

// Resolves the given path relative to the current working directory
inline std::string absolute_path(const std::string& path)
{
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
    return path.size() && (path[0] == '/' || path[0] == '\\') ||
           path.size() > 1 && std::isalpha(path[0]) && path[1] == ':' ?
               path :
               current_directory() + '\\' + path;
#else // #ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
    return path.size() && (path[0] == '/') ?
        path :
        current_directory() + '/' + path;
#endif // #ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
}

} } } // End namespaces detail, iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_ABSOLUTE_PATH_HPP_INCLUDED
