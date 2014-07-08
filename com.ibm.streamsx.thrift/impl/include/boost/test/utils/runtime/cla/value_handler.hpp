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
//  Description : specific value handlers
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_CLA_VALUE_HANDLER_HPP_062604GER
#define STREAMS_BOOST_RT_CLA_VALUE_HANDLER_HPP_062604GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>

#include <streams_boost/test/utils/runtime/cla/fwd.hpp>

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

namespace cla {

namespace rt_cla_detail {

// ************************************************************************** //
// **************            runtime::cla::assigner            ************** //
// ************************************************************************** //

template<typename T>
class assigner {
public:
    // Constructor
    explicit    assigner( T& loc ) : m_target( loc )    {}

    // value handler implementation
    void        operator()( parameter const&, T& t )  { m_target = t; }

private:
    // Data members
    T&          m_target;
};

} // namespace rt_cla_detail

} // namespace cla

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#endif // STREAMS_BOOST_RT_CLA_VALUE_HANDLER_HPP_062604GER
