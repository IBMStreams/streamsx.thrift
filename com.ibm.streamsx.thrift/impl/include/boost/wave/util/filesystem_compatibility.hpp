/*=============================================================================
    Boost.Wave: A Standard compliant C++ preprocessor library

    http://www.streams_boost.org/

    Copyright (c) 2001-2010 Hartmut Kaiser. Distributed under the Boost
    Software License, Version 1.0. (See accompanying file
    LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/

#if !defined(STREAMS_BOOST_WAVE_FILESYSTEM_COMPATIBILITY_MAR_09_2009_0142PM)
#define STREAMS_BOOST_WAVE_FILESYSTEM_COMPATIBILITY_MAR_09_2009_0142PM

#include <string>

#include <streams_boost/filesystem/path.hpp>
#include <streams_boost/filesystem/operations.hpp>

namespace streams_boost { namespace wave { namespace util
{
///////////////////////////////////////////////////////////////////////////////
// filesystem wrappers allowing to handle different Boost versions
#if !defined(STREAMS_BOOST_FILESYSTEM_NO_DEPRECATED)
// interface wrappers for older Boost versions
    inline streams_boost::filesystem::path initial_path()
    {
        return streams_boost::filesystem::initial_path(); 
    }

    inline streams_boost::filesystem::path current_path()
    {
        return streams_boost::filesystem::current_path(); 
    }

    template <typename String>
    inline streams_boost::filesystem::path create_path(String const& p)
    {
        return streams_boost::filesystem::path(p, streams_boost::filesystem::native);
    }

    inline std::string leaf(streams_boost::filesystem::path const& p) 
    { 
        return p.leaf(); 
    }

    inline streams_boost::filesystem::path branch_path(streams_boost::filesystem::path const& p) 
    { 
        return p.branch_path(); 
    }

    inline streams_boost::filesystem::path normalize(streams_boost::filesystem::path& p)
    {
        return p.normalize();
    }

    inline std::string native_file_string(streams_boost::filesystem::path const& p) 
    { 
        return p.native_file_string(); 
    }

#else
// interface wrappers if deprecated functions do not exist
    inline streams_boost::filesystem::path initial_path()
    { 
        return streams_boost::filesystem::initial_path<streams_boost::filesystem::path>();
    }

    inline streams_boost::filesystem::path current_path()
    { 
        return streams_boost::filesystem::current_path<streams_boost::filesystem::path>();
    }

    template <typename String>
    inline streams_boost::filesystem::path create_path(String const& p)
    {
        return streams_boost::filesystem::path(p);
    }

    inline std::string leaf(streams_boost::filesystem::path const& p) 
    { 
        return p.filename(); 
    }

    inline streams_boost::filesystem::path branch_path(streams_boost::filesystem::path const& p) 
    { 
        return p.parent_path(); 
    }

    inline streams_boost::filesystem::path normalize(streams_boost::filesystem::path& p)
    {
        return p; // function doesn't exist anymore
    }

    inline std::string native_file_string(streams_boost::filesystem::path const& p) 
    { 
        return p.file_string(); 
    }

#endif

}}}

#endif
