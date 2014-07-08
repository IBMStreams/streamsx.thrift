//Copyright (c) 2006-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_UUID_0E11109E6C1311DEB7EA649255D89593
#define STREAMS_UUID_0E11109E6C1311DEB7EA649255D89593

#include <string>

namespace
streams_boost
    {
    template <class Tag,class T> class error_info;

    //Usage hint:
    //STREAMS_BOOST_THROW_EXCEPTION(
    //    bad_type() <<
    //    errinfo_type_info_name(typeid(x).name()) );
    typedef error_info<struct errinfo_type_info_name_,std::string> errinfo_type_info_name;
    }

#endif
