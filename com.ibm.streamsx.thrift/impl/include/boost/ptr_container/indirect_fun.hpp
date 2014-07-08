//
// Boost.Pointer Container
//
//  Copyright Thorsten Ottosen 2003-2007. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/ptr_container/
//

#ifndef STREAMS_BOOST_PTR_CONTAINER_INDIRECT_FUN_HPP
#define STREAMS_BOOST_PTR_CONTAINER_INDIRECT_FUN_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
    #pragma once
#endif

#include <streams_boost/config.hpp>

#ifdef STREAMS_BOOST_NO_SFINAE
#else
#include <streams_boost/utility/result_of.hpp>
#include <streams_boost/pointee.hpp>
#endif // STREAMS_BOOST_NO_SFINAE

#include <streams_boost/assert.hpp>
#include <functional>


namespace streams_boost
{


    template
    < 
              class Fun
#ifdef STREAMS_BOOST_NO_SFINAE
            , class Result = bool
#endif        
    >
    class indirect_fun
    {
        Fun fun;
    public:
        indirect_fun() : fun(Fun())
        { }
        
        indirect_fun( Fun f ) : fun(f)
        { }
    
        template< class T >
#ifdef STREAMS_BOOST_NO_SFINAE
        Result    
#else            
        STREAMS_BOOST_DEDUCED_TYPENAME result_of< Fun( STREAMS_BOOST_DEDUCED_TYPENAME pointee<T>::type& ) >::type 
#endif            
        operator()( const T& r ) const
        { 
            return fun( *r );
        }
    
        template< class T, class U >
#ifdef STREAMS_BOOST_NO_SFINAE
        Result    
#else                        
        STREAMS_BOOST_DEDUCED_TYPENAME result_of< Fun( STREAMS_BOOST_DEDUCED_TYPENAME pointee<T>::type&, 
                                               STREAMS_BOOST_DEDUCED_TYPENAME pointee<U>::type& ) >::type
#endif            
        operator()( const T& r, const U& r2 ) const
        { 
            return fun( *r, *r2 ); 
        }
    };

    template< class Fun >
    inline indirect_fun<Fun> make_indirect_fun( Fun f )
    {
        return indirect_fun<Fun>( f );
    }


    template
    < 
        class Fun, 
        class Arg1, 
        class Arg2 = Arg1 
#ifdef STREAMS_BOOST_NO_SFINAE
      , class Result = bool   
#endif           
    >
    class void_ptr_indirect_fun
    {
        Fun fun;
    public:
        
        void_ptr_indirect_fun() : fun(Fun())
        { }

        void_ptr_indirect_fun( Fun f ) : fun(f)
        { }
#ifdef STREAMS_BOOST_NO_SFINAE
        Result    
#else            
        STREAMS_BOOST_DEDUCED_TYPENAME result_of< Fun( Arg1& ) >::type 
#endif            
        operator()( const void* r ) const
        { 
            STREAMS_BOOST_ASSERT( r != 0 );
            return fun( * static_cast<const Arg1*>( r ) );
        }

#ifdef STREAMS_BOOST_NO_SFINAE
        Result    
#else                    
        STREAMS_BOOST_DEDUCED_TYPENAME result_of< Fun( Arg1&, Arg2& ) >::type 
#endif            
        operator()( const void* l, const void* r ) const
        { 
            STREAMS_BOOST_ASSERT( l != 0 && r != 0 );
            return fun( * static_cast<const Arg1*>( l ), * static_cast<const Arg2*>( r ) );
        }
    };

    template< class Arg, class Fun >
    inline void_ptr_indirect_fun<Fun,Arg> make_void_ptr_indirect_fun( Fun f )
    {
        return void_ptr_indirect_fun<Fun,Arg>( f );
    }
     
} // namespace 'streams_boost'

#endif
