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

#ifndef STREAMS_BOOST_RT_CONFIGURATION_HPP_062604GER
#define STREAMS_BOOST_RT_CONFIGURATION_HPP_062604GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>
#include <streams_boost/test/utils/runtime/parameter.hpp>
#include <streams_boost/test/utils/runtime/argument.hpp>

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

// ************************************************************************** //
// **************            runtime::configuration            ************** //
// ************************************************************************** //

class config_source {
    virtual parameter const& config_param_begin() const = 0;
    virtual parameter const& config_param_end() const   = 0;

protected:
    config_source()     {}
    ~config_source()    {}
};

// ************************************************************************** //
// **************            runtime::configuration            ************** //
// ************************************************************************** //

template<typename StoragePolicy,typename IdentificationPlicy,typename ConflictResolutionPolicy>
class configuration : public StoragePolicy, public IdentificationPlicy, public ConflictResolutionPolicy {
public:
    // Constructor
    configuration();

    void    use( config_source const& )
    {

    }
private:
};

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#endif // STREAMS_BOOST_RT_CONFIGURATION_HPP_062604GER
