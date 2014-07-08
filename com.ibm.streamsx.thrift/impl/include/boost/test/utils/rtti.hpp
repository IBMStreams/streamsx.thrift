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
//  Description : simple facilities for accessing type information at runtime
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_RTTI_HPP_062604GER
#define STREAMS_BOOST_TEST_RTTI_HPP_062604GER

#include <cstddef>

namespace streams_boost {

namespace rtti {

// ************************************************************************** //
// **************                   rtti::type_id              ************** //
// ************************************************************************** //

typedef std::ptrdiff_t id_t;

namespace rtti_detail {

template<typename T>
struct rttid_holder {
    static id_t id() { return reinterpret_cast<id_t>( &inst() ); }

private:
    struct rttid {};

    static rttid const& inst() { static rttid s_inst;  return s_inst; }
};

} // namespace rtti_detail

//____________________________________________________________________________//

template<typename T>   
inline id_t
type_id()
{
    return rtti_detail::rttid_holder<T>::id();
}

//____________________________________________________________________________//

#define STREAMS_BOOST_RTTI_SWITCH( type_id_ ) if( ::streams_boost::rtti::id_t switch_by_id = type_id_ )
#define STREAMS_BOOST_RTTI_CASE( type )       if( switch_by_id == ::streams_boost::rtti::type_id<type>() )

//____________________________________________________________________________//

} // namespace rtti

} // namespace streams_boost

#endif // STREAMS_BOOST_RT_RTTI_HPP_062604GER
