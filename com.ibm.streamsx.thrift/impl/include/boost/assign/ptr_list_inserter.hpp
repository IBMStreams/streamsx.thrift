// Boost.Assign library
//
//  Copyright Thorsten Ottosen 2003-2005. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/assign/
//

#ifndef STREAMS_BOOST_ASSIGN_PTR_LIST_INSERTER_HPP
#define STREAMS_BOOST_ASSIGN_PTR_LIST_INSERTER_HPP

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
    template< class Function, class Obj > 
    class ptr_list_inserter
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME
                remove_pointer< STREAMS_BOOST_DEDUCED_TYPENAME 
                       remove_reference<Obj>::type >::type
           obj_type;
    public:
        
        ptr_list_inserter( Function fun ) : insert_( fun )
        {}
        
        template< class Function2, class Obj2 >
        ptr_list_inserter( const ptr_list_inserter<Function2,Obj2>& r ) 
        : insert_( r.fun_private() ) 
        {}

        ptr_list_inserter( const ptr_list_inserter& r ) : insert_( r.insert_ )
        {}

        ptr_list_inserter& operator()()
        {
            insert_( new obj_type() );
            return *this;
        }
        
        template< class T >
        ptr_list_inserter& operator()( const T& t )
        {
            insert_( new obj_type(t) );
            return *this;
        }

#ifndef STREAMS_BOOST_ASSIGN_MAX_PARAMS // use user's value
#define STREAMS_BOOST_ASSIGN_MAX_PARAMS 5        
#endif
#define STREAMS_BOOST_ASSIGN_MAX_PARAMETERS (STREAMS_BOOST_ASSIGN_MAX_PARAMS - 1)
#define STREAMS_BOOST_ASSIGN_PARAMS1(n) STREAMS_BOOST_PP_ENUM_PARAMS(n, class T)
#define STREAMS_BOOST_ASSIGN_PARAMS2(n) STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(n, T, const& t)
#define STREAMS_BOOST_ASSIGN_PARAMS3(n) STREAMS_BOOST_PP_ENUM_PARAMS(n, t)
        
#define STREAMS_BOOST_PP_LOCAL_LIMITS (1, STREAMS_BOOST_ASSIGN_MAX_PARAMETERS)
#define STREAMS_BOOST_PP_LOCAL_MACRO(n) \
    template< class T, STREAMS_BOOST_ASSIGN_PARAMS1(n) > \
    ptr_list_inserter& operator()( const T& t, STREAMS_BOOST_ASSIGN_PARAMS2(n) ) \
    { \
        insert_( new obj_type(t, STREAMS_BOOST_ASSIGN_PARAMS3(n) )); \
        return *this; \
    } \
    /**/
        
#include STREAMS_BOOST_PP_LOCAL_ITERATE()

    private:
        
        ptr_list_inserter& operator=( const ptr_list_inserter& );
        Function insert_;
    };
    
    template< class Obj, class Function >
    inline ptr_list_inserter< Function, Obj >
    make_ptr_list_inserter( Function fun )
    {
        return ptr_list_inserter< Function, Obj >( fun );
    }
    
    template< class C >
    inline ptr_list_inserter< assign_detail::call_push_back<C>, 
                              STREAMS_BOOST_DEDUCED_TYPENAME C::reference >
    ptr_push_back( C& c )
    {
        return make_ptr_list_inserter<STREAMS_BOOST_DEDUCED_TYPENAME C::reference>
                   ( assign_detail::call_push_back<C>( c ) ); 
    }

#ifndef STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING

    template< class T, class C >
    inline ptr_list_inserter< assign_detail::call_push_back<C>, T >
    ptr_push_back( C& c )
    {
        return make_ptr_list_inserter<T>( 
                    assign_detail::call_push_back<C>( c ) );
    }

#endif
    
    template< class C >
    inline ptr_list_inserter< assign_detail::call_push_front<C>,
                              STREAMS_BOOST_DEDUCED_TYPENAME C::reference >
    ptr_push_front( C& c )
    {
        return make_ptr_list_inserter<STREAMS_BOOST_DEDUCED_TYPENAME C::reference>
                 ( assign_detail::call_push_front<C>( c ) );
    }

#ifndef STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING

    template< class T, class C >
    inline ptr_list_inserter< assign_detail::call_push_front<C>, T >
    ptr_push_front( C& c )
    {
        return make_ptr_list_inserter<T>( 
                    assign_detail::call_push_front<C>( c ) );
    }

#endif
    
    template< class C >
    inline ptr_list_inserter< assign_detail::call_insert<C>, 
                          STREAMS_BOOST_DEDUCED_TYPENAME C::reference>
    ptr_insert( C& c )
    {
        return make_ptr_list_inserter<STREAMS_BOOST_DEDUCED_TYPENAME C::reference>
                    ( assign_detail::call_insert<C>( c ) );
    }

#ifndef STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING

    template< class T, class C >
    inline ptr_list_inserter< assign_detail::call_insert<C>, T >
    ptr_insert( C& c )
    {
        return make_ptr_list_inserter<T>( assign_detail::call_insert<C>( c ) );
    }

#endif
    
    
} // namespace 'assign'
} // namespace 'streams_boost'

#undef STREAMS_BOOST_ASSIGN_PARAMS1
#undef STREAMS_BOOST_ASSIGN_PARAMS2
#undef STREAMS_BOOST_ASSIGN_PARAMS3
#undef STREAMS_BOOST_ASSIGN_MAX_PARAMETERS

#endif
