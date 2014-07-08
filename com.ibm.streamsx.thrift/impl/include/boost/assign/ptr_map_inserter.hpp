// Boost.Assign library
//
//  Copyright Thorsten Ottosen 2006. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/assign/
//

#ifndef STREAMS_BOOST_ASSIGN_PTR_CONTAINER_PTR_MAP_INSERTER_HPP
#define STREAMS_BOOST_ASSIGN_PTR_CONTAINER_PTR_MAP_INSERTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/assign/list_inserter.hpp>
#include <streams_boost/type_traits/remove_reference.hpp>
#include <streams_boost/type_traits/remove_pointer.hpp>

namespace streams_boost
{

namespace assign
{
    template< class PtrMap, class Obj > 
    class ptr_map_inserter
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME
                remove_pointer< STREAMS_BOOST_DEDUCED_TYPENAME 
                       remove_reference<Obj>::type >::type
           obj_type;
        typedef STREAMS_BOOST_DEDUCED_TYPENAME PtrMap::key_type
           key_type;
        
    public:
        
        ptr_map_inserter( PtrMap& m ) : m_( m )
        {}
        
        template< class Key >
        ptr_map_inserter& operator()( const Key& t )
        {
            key_type k(t);
            m_.insert( k, new obj_type );
            return *this;
        }

#ifndef STREAMS_BOOST_ASSIGN_MAX_PARAMS // use user's value
#define STREAMS_BOOST_ASSIGN_MAX_PARAMS 6        
#endif
#define STREAMS_BOOST_ASSIGN_MAX_PARAMETERS (STREAMS_BOOST_ASSIGN_MAX_PARAMS - 1)
#define STREAMS_BOOST_ASSIGN_PARAMS1(n) STREAMS_BOOST_PP_ENUM_PARAMS(n, class T)
#define STREAMS_BOOST_ASSIGN_PARAMS2(n) STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(n, T, const& t)
#define STREAMS_BOOST_ASSIGN_PARAMS3(n) STREAMS_BOOST_PP_ENUM_PARAMS(n, t)
        
#define STREAMS_BOOST_PP_LOCAL_LIMITS (1, STREAMS_BOOST_ASSIGN_MAX_PARAMETERS)
#define STREAMS_BOOST_PP_LOCAL_MACRO(n) \
    template< class T, STREAMS_BOOST_ASSIGN_PARAMS1(n) > \
    ptr_map_inserter& operator()( const T& t, STREAMS_BOOST_ASSIGN_PARAMS2(n) ) \
    { \
        key_type k(t); \
        m_.insert( k, new obj_type( STREAMS_BOOST_ASSIGN_PARAMS3(n) ) ); \
        return *this; \
    } \
    /**/
        
#include STREAMS_BOOST_PP_LOCAL_ITERATE()

    private:

        ptr_map_inserter& operator=( const ptr_map_inserter& );
        PtrMap& m_;
    };
    
    template< class PtrMap >
    inline ptr_map_inserter< PtrMap, typename PtrMap::mapped_reference >
    ptr_map_insert( PtrMap& m )
    {
        return ptr_map_inserter< PtrMap, typename PtrMap::mapped_reference >( m );
    }

#ifndef STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING

    template< class T, class PtrMap >
    inline ptr_map_inserter< PtrMap, T >
    ptr_map_insert( PtrMap& m )
    {
        return ptr_map_inserter< PtrMap, T >( m );
    }

#endif
     
} // namespace 'assign'
} // namespace 'streams_boost'

#undef STREAMS_BOOST_ASSIGN_PARAMS1
#undef STREAMS_BOOST_ASSIGN_PARAMS2
#undef STREAMS_BOOST_ASSIGN_PARAMS3
#undef STREAMS_BOOST_ASSIGN_MAX_PARAMETERS

#endif
