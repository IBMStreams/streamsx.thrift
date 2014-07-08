#ifndef STREAMS_BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
#define STREAMS_BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  bind/placeholders.hpp - _N definitions
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  See http://www.streams_boost.org/libs/bind/bind.html for documentation.
//

#include <streams_boost/bind/arg.hpp>
#include <streams_boost/config.hpp>

namespace
{

#if defined(__BORLANDC__) || defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ < 400)

static inline streams_boost::arg<1> _1() { return streams_boost::arg<1>(); }
static inline streams_boost::arg<2> _2() { return streams_boost::arg<2>(); }
static inline streams_boost::arg<3> _3() { return streams_boost::arg<3>(); }
static inline streams_boost::arg<4> _4() { return streams_boost::arg<4>(); }
static inline streams_boost::arg<5> _5() { return streams_boost::arg<5>(); }
static inline streams_boost::arg<6> _6() { return streams_boost::arg<6>(); }
static inline streams_boost::arg<7> _7() { return streams_boost::arg<7>(); }
static inline streams_boost::arg<8> _8() { return streams_boost::arg<8>(); }
static inline streams_boost::arg<9> _9() { return streams_boost::arg<9>(); }

#elif defined(STREAMS_BOOST_MSVC) || (defined(__DECCXX_VER) && __DECCXX_VER <= 60590031) || defined(__MWERKS__) || \
    defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ == 400)  

static streams_boost::arg<1> _1;
static streams_boost::arg<2> _2;
static streams_boost::arg<3> _3;
static streams_boost::arg<4> _4;
static streams_boost::arg<5> _5;
static streams_boost::arg<6> _6;
static streams_boost::arg<7> _7;
static streams_boost::arg<8> _8;
static streams_boost::arg<9> _9;

#else

streams_boost::arg<1> _1;
streams_boost::arg<2> _2;
streams_boost::arg<3> _3;
streams_boost::arg<4> _4;
streams_boost::arg<5> _5;
streams_boost::arg<6> _6;
streams_boost::arg<7> _7;
streams_boost::arg<8> _8;
streams_boost::arg<9> _9;

#endif

} // unnamed namespace

#endif // #ifndef STREAMS_BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
