// Copyright (C) 2003, Fernando Luis Cacciola Carballal.
//
// Use, modification, and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/optional for documentation.
//
// You are welcome to contact the author at:
//  fernando_cacciola@hotmail.com
//
#ifndef STREAMS_BOOST_NONE_T_17SEP2003_HPP
#define STREAMS_BOOST_NONE_T_17SEP2003_HPP

namespace streams_boost {

namespace detail { struct none_helper{}; }

typedef int detail::none_helper::*none_t ;

} // namespace streams_boost

#endif

