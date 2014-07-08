/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)
 * 
 * See http://www.streams_boost.org/libs/iostreams for documentation.
 *
 * File:        streams_boost/iostreams/detail/restrict.hpp
 * Date:        Sun Jan 06 12:57:30 MST 2008
 * Copyright:   2008 CodeRage, LLC
                2004-2007 Jonathan Turkanis
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the class template streams_boost::iostreams::restriction and the 
 * overloaded function template streams_boost::iostreams::restrict
 */

#ifndef STREAMS_BOOST_IOSTREAMS_RESTRICT_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_RESTRICT_HPP_INCLUDED

#include <streams_boost/iostreams/detail/restrict_impl.hpp>
#define STREAMS_BOOST_IOSTREAMS_RESTRICT restrict
#include <streams_boost/iostreams/detail/restrict_impl.hpp>
#undef STREAMS_BOOST_IOSTREAMS_RESTRICT

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_RESTRICT_HPP_INCLUDED
