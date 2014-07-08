//  Boost version.hpp configuration header file  ------------------------------//

//  (C) Copyright John maddock 1999. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/config for documentation

#ifndef STREAMS_BOOST_VERSION_HPP
#define STREAMS_BOOST_VERSION_HPP

//
//  Caution, this is the only streams_boost header that is guarenteed
//  to change with every streams_boost release, including this header
//  will cause a recompile every time a new streams_boost version is
//  released.
//
//  STREAMS_BOOST_VERSION % 100 is the patch level
//  STREAMS_BOOST_VERSION / 100 % 1000 is the minor version
//  STREAMS_BOOST_VERSION / 100000 is the major version

#define STREAMS_BOOST_VERSION 104200

//
//  STREAMS_BOOST_LIB_VERSION must be defined to be the same as STREAMS_BOOST_VERSION
//  but as a *string* in the form "x_y[_z]" where x is the major version
//  number, y is the minor version number, and z is the patch level if not 0.
//  This is used by <config/auto_link.hpp> to select which library version to link to.

#define STREAMS_BOOST_LIB_VERSION "1_42"

#endif



