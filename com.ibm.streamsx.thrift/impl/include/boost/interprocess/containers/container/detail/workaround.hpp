//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_CONTAINERS_DETAIL_WORKAROUND_HPP
#define STREAMS_BOOST_CONTAINERS_DETAIL_WORKAROUND_HPP

#include <streams_boost/interprocess/containers/container/detail/config_begin.hpp>

#if     defined(STREAMS_BOOST_HAS_RVALUE_REFS) && defined(STREAMS_BOOST_HAS_VARIADIC_TMPL)\
    && !defined(STREAMS_BOOST_INTERPROCESS_DISABLE_VARIADIC_TMPL)
#define STREAMS_BOOST_CONTAINERS_PERFECT_FORWARDING

#endif

#include <streams_boost/interprocess/containers/container/detail/config_end.hpp>

#endif   //#ifndef STREAMS_BOOST_CONTAINERS_DETAIL_WORKAROUND_HPP
