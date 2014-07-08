//Copyright (c) 2006-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_UUID_DDFBB4546C1211DEA4659E9055D89593
#define STREAMS_UUID_DDFBB4546C1211DEA4659E9055D89593

#include "streams_boost/exception/error_info.hpp"

namespace
streams_boost
    {
    //Usage hint:
    //if( api_function(....)!=0 )
    //    STREAMS_BOOST_THROW_EXCEPTION(
    //        failure() <<
    //        errinfo_api_function("api_function") );
    typedef error_info<struct errinfo_api_function_,char const *> errinfo_api_function;
    }

#endif
