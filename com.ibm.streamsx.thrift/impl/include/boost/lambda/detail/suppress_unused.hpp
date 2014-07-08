// Boost Lambda Library  suppress_unused.hpp -----------------------------
//
// Copyright (C) 2009 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see www.streams_boost.org

// ------------------------------------------------------------

#ifndef STREAMS_BOOST_LAMBDA_SUPRESS_UNUSED_HPP
#define STREAMS_BOOST_LAMBDA_SUPRESS_UNUSED_HPP

namespace streams_boost { 
namespace lambda {
namespace detail {

template<class T>
inline void suppress_unused_variable_warnings(const T&) {}

}
}
}

#endif
