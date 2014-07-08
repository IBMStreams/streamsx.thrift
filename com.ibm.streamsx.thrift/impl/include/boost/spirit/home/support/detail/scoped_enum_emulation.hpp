//  Copyright (c) 2001-2010 Hartmut Kaiser
//  http://spirit.sourceforge.net/
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_SPIRIT_SCOPED_ENUM_EMULATION_HPP
#define STREAMS_BOOST_SPIRIT_SCOPED_ENUM_EMULATION_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/version.hpp>
#include <streams_boost/config.hpp>

#if STREAMS_BOOST_VERSION >= 104000
# include <streams_boost/detail/scoped_enum_emulation.hpp>
#else
# if !defined(STREAMS_BOOST_NO_SCOPED_ENUMS)
#  define STREAMS_BOOST_NO_SCOPED_ENUMS
# endif 
# define STREAMS_BOOST_SCOPED_ENUM_START(name) struct name { enum enum_type
# define STREAMS_BOOST_SCOPED_ENUM_END };
# define STREAMS_BOOST_SCOPED_ENUM(name) name::enum_type
#endif

#endif
