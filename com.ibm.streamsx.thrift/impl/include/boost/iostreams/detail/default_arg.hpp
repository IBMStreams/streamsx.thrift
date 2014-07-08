// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2005-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_DEFAULT_ARG_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_DEFAULT_ARG_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif            

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
# include <streams_boost/mpl/identity.hpp>
# define STREAMS_BOOST_IOSTREAMS_DEFAULT_ARG(arg) mpl::identity< arg >::type
#else
# define STREAMS_BOOST_IOSTREAMS_DEFAULT_ARG(arg) arg
#endif

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_DEFAULT_ARG_HPP_INCLUDED
