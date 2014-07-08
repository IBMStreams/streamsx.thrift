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
//  Description : abstract interface for the formal parameter
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_PARAMETER_HPP_062604GER
#define STREAMS_BOOST_RT_PARAMETER_HPP_062604GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

// ************************************************************************** //
// **************              runtime::parameter              ************** //
// ************************************************************************** //

class parameter {
public:
    virtual ~parameter() {}
};

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#endif // STREAMS_BOOST_RT_PARAMETER_HPP_062604GER
