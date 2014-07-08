//Copyright (c) 2006-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_UUID_E7255CE26C1211DE85800C9155D89593
#define STREAMS_UUID_E7255CE26C1211DE85800C9155D89593

namespace
streams_boost
    {
    template <class Tag,class T> class error_info;

    //Use with parsing errors exceptions, for example in a XML file parser.
    typedef error_info<struct errinfo_at_line_,int> errinfo_at_line;
    }

#endif
