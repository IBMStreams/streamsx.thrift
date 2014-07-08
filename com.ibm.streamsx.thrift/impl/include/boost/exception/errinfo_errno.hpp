//Copyright (c) 2006-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_UUID_F0EE17BE6C1211DE87FF459155D89593
#define STREAMS_UUID_F0EE17BE6C1211DE87FF459155D89593
#if defined(__GNUC__) && !defined(STREAMS_BOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma GCC system_header
#endif
#if defined(_MSC_VER) && !defined(STREAMS_BOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma warning(push,1)
#endif

#include "streams_boost/exception/info.hpp"
#include <errno.h>
#include <string.h>

namespace
streams_boost
    {
    typedef error_info<struct errinfo_errno_,int> errinfo_errno;

    //Usage hint:
    //if( c_function(....)!=0 )
    //    STREAMS_BOOST_THROW_EXCEPTION(
    //        failure() <<
    //        errinfo_errno(errno) <<
    //        errinfo_api_function("c_function") );
    inline
    std::string
    to_string( errinfo_errno const & e )
        {
        std::ostringstream tmp;
        int v=e.value();
        tmp << v << ", \"" << strerror(v) << "\"";
        return tmp.str();
        }
    }

#if defined(_MSC_VER) && !defined(STREAMS_BOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma warning(pop)
#endif
#endif
