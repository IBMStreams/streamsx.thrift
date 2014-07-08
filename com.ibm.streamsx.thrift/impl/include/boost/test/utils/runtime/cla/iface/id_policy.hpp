//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Use, modification, and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 57992 $
//
//  Description : defines interface for identification_policy
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_CLA_IFACE_ID_POLICY_HPP_062604GER
#define STREAMS_BOOST_RT_CLA_IFACE_ID_POLICY_HPP_062604GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>

#include <streams_boost/test/utils/runtime/cla/fwd.hpp>

// Boost.Test
#include <streams_boost/test/utils/class_properties.hpp>
#include <streams_boost/test/utils/rtti.hpp>

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

namespace cla {

// ************************************************************************** //
// **************             identification_policy            ************** //
// ************************************************************************** //

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable:4244)
#endif

class identification_policy {
public:
    // Public properties
    unit_test::readwrite_property<rtti::id_t>    p_type_id;

    // Policy interface
    virtual bool    responds_to( cstring name ) const = 0;
    virtual cstring id_2_report() const = 0;
    virtual void    usage_info( format_stream& fs ) const = 0;
    virtual bool    matching( parameter const& p, argv_traverser& tr, bool primary ) const = 0;

    virtual bool    conflict_with( identification_policy const& ) const = 0;

protected:
    // Constructor
    explicit        identification_policy( rtti::id_t dyn_type )
    : p_type_id( dyn_type )
    {}
    STREAMS_BOOST_TEST_PROTECTED_VIRTUAL ~identification_policy() {}
};

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(pop)
#endif

} // namespace cla

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#endif // STREAMS_BOOST_RT_CLA_IFACE_ID_POLICY_HPP_062604GER
