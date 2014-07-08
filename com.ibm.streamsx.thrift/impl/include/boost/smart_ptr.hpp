//
//  smart_ptr.hpp
//
//  For convenience, this header includes the rest of the smart
//  pointer library headers.
//
//  Copyright (c) 2003 Peter Dimov  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  http://www.streams_boost.org/libs/smart_ptr/smart_ptr.htm
//

#include <streams_boost/config.hpp>

#include <streams_boost/scoped_ptr.hpp>
#include <streams_boost/scoped_array.hpp>
#include <streams_boost/shared_ptr.hpp>
#include <streams_boost/shared_array.hpp>

#if !defined(STREAMS_BOOST_NO_MEMBER_TEMPLATES) || defined(STREAMS_BOOST_MSVC6_MEMBER_TEMPLATES)
# include <streams_boost/weak_ptr.hpp>
# include <streams_boost/intrusive_ptr.hpp>
# include <streams_boost/enable_shared_from_this.hpp>
#endif
