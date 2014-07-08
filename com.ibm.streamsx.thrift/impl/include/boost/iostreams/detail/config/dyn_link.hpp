// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

// Adapted from http://www.streams_boost.org/more/separate_compilation.html, by
// John Maddock.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_DYN_LINK_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_DYN_LINK_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

//------------------Enable dynamic linking on windows-------------------------// 

#ifdef STREAMS_BOOST_HAS_DECLSPEC 
# if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_IOSTREAMS_DYN_LINK)
#  ifdef STREAMS_BOOST_IOSTREAMS_SOURCE
#   define STREAMS_BOOST_IOSTREAMS_DECL __declspec(dllexport)
#  else
#   define STREAMS_BOOST_IOSTREAMS_DECL __declspec(dllimport)
#  endif  
# endif  
#endif 

#ifndef STREAMS_BOOST_IOSTREAMS_DECL
# define STREAMS_BOOST_IOSTREAMS_DECL
#endif

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_CONFIG_DYN_LINK_HPP_INCLUDED
