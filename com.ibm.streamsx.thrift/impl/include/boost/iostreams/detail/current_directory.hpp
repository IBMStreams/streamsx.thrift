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
 * Defines the function streams_boost::iostreams::detail::current_directory, used by 
 * streams_boost::iostreams::detail::absolute_path.
 */

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CURRENT_DIRECTORY_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_CURRENT_DIRECTORY_HPP_INCLUDED

#include <streams_boost/config.hpp>  // make sure size_t is in std.
#include <cstddef>           // size_t
#include <string>
#include <streams_boost/iostreams/detail/buffer.hpp>
#include <streams_boost/iostreams/detail/config/windows_posix.hpp>
#include <streams_boost/iostreams/detail/system_failure.hpp>
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
# define WIN32_LEAN_AND_MEAN  // Exclude rarely-used stuff from Windows headers
# include <windows.h>
#else
# include <unistd.h>        // sysconf.
#endif

// Must come last.
#include <streams_boost/iostreams/detail/config/disable_warnings.hpp>

namespace streams_boost { namespace iostreams { namespace detail {

// Returns the current working directory
inline std::string current_directory()
{
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
    DWORD               length;
    basic_buffer<char>  buf(MAX_PATH);
    while (true) {
        length = ::GetCurrentDirectoryA(buf.size(), buf.data());
        if (!length)
            throw_system_failure("failed determining current directory");
        if (length < static_cast<DWORD>(buf.size()))
            break;
        buf.resize(buf.size() * 2);
    }
    return std::string(buf.data(), length);
#else // #ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
    basic_buffer<char> buf(pathconf(".", _PC_PATH_MAX));
    if (!getcwd(buf.data(), static_cast<size_t>(buf.size())))
        throw_system_failure("failed determining current directory");
    return std::string(buf.data());
#endif // #ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
}

} } } // End namespaces detail, iostreams, streams_boost.

#include <streams_boost/iostreams/detail/config/enable_warnings.hpp>

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CURRENT_DIRECTORY_HPP_INCLUDED
