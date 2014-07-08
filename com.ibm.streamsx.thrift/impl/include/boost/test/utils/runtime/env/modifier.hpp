//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Use, modification, and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 49312 $
//
//  Description : defines variable modifiers
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_ENV_MODIFIER_HPP_062604GER
#define STREAMS_BOOST_RT_ENV_MODIFIER_HPP_062604GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>

// Boost.Test
#include <streams_boost/test/utils/named_params.hpp>

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

namespace environment {

// ************************************************************************** //
// **************         environment variable modifiers       ************** //
// ************************************************************************** //

namespace {

nfp::typed_keyword<cstring,struct global_id_t>   global_id;
nfp::keyword<struct default_value_t>             default_value;
nfp::keyword<struct interpreter_t>               interpreter;

} // local namespace
} // namespace environment

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#endif // STREAMS_BOOST_RT_ENV_MODIFIER_HPP_062604GER
