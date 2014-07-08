//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 49312 $
//
//  Description : global framework level forward declaration
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_FWD_HPP_062604GER
#define STREAMS_BOOST_RT_FWD_HPP_062604GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>

// Boost
#include <streams_boost/shared_ptr.hpp>

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

class parameter;

class argument;
typedef shared_ptr<argument> argument_ptr;
typedef shared_ptr<argument const> const_argument_ptr;

template<typename T> class value_interpreter;
template<typename T> class typed_argument;

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#endif // STREAMS_BOOST_RT_FWD_HPP_062604GER
