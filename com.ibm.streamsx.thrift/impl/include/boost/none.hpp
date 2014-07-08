// Copyright (C) 2003, Fernando Luis Cacciola Carballal.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/optional for documentation.
//
// You are welcome to contact the author at:
//  fernando_cacciola@hotmail.com
//
#ifndef STREAMS_BOOST_NONE_17SEP2003_HPP
#define STREAMS_BOOST_NONE_17SEP2003_HPP

#include "streams_boost/none_t.hpp"

// NOTE: Borland users have to include this header outside any precompiled headers
// (bcc<=5.64 cannot include instance data in a precompiled header)
//  -- * To be verified, now that there's no unnamed namespace

namespace streams_boost {

none_t const none = ((none_t)0) ;

} // namespace streams_boost

#endif

