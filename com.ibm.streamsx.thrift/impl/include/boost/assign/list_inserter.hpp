// Boost.Assign library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/assign/
//

#ifndef STREAMS_BOOST_ASSIGN_LIST_INSERTER_HPP
#define STREAMS_BOOST_ASSIGN_LIST_INSERTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/detail/workaround.hpp>

#include <streams_boost/mpl/if.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/range/begin.hpp>
#include <streams_boost/range/end.hpp>
#include <streams_boost/config.hpp>
#include <cstddef>

#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/iteration/local.hpp>
#include <streams_boost/preprocessor/arithmetic/inc.hpp>

namespace streams_boost
{
namespace assign_detail
{
    template< class T >
    struct repeater
    {
        std::size_t  sz;
        T            val;

        repeater( std::size_t sz_, T r ) : sz( sz_ ), val( r )
        { }
    };
    
    template< class Fun >
    struct fun_repeater
    {
        std::size_t  sz;
        Fun          val;
        
        fun_repeater( std::size_t sz_, Fun r ) : sz( sz_ ), val( r )
        { }
    };
    
    template< class C >
    class call_push_back
    {
        C& c_;
    public:
        call_push_back( C& c ) : c_( c )
        { }
        
        template< class T >
        void operator()( T r ) 
        {
            c_.push_back( r );
        }
    };
    
    template< class C >
    class call_push_front
    {
        C& c_;
    public:
        call_push_front( C& c ) : c_( c )
        { }
        
        template< class T >
        void operator()( T r ) 
        {
            c_.push_front( r );
        }
    };
    
    template< class C >
    class call_push
    {
        C& c_;
    public:
        call_push( C& c ) : c_( c )
        { }
    
        template< class T >
        void operator()( T r ) 
        {
            c_.push( r );
        }
    };
    
    template< class C >
    class call_insert
    {
        C& c_;
    public:
        call_insert( C& c ) : c_( c )
        { }
    
        template< class T >
        void operator()( T r ) 
        {
            c_.insert( r );
        }
    };

    template< class C >
    class call_add_edge
    {
        C& c_;
    public:
        call_add_edge( C& c ) : c_(c)
        { }

        template< class T >
        void operator()( T l, T r )
        {
            add_edge( l, r, c_ );
        }

        template< class T, class EP >
        void operator()( T l, T r, const EP& ep )
        {
            add_edge( l, r, ep, c_ );
        }

    };
    
    struct forward_n_arguments {};
    
} // namespace 'assign_detail'

namespace assign
{

    template< class T >
    inline assign_detail::repeater<T>
    repeat( std::size_t sz, T r )
    {
        return assign_detail::repeater<T>( sz, r );
    }
    
    template< class Function >
    inline assign_detail::fun_repeater<Function>
    repeat_fun( std::size_t sz, Function r )
    {
        return assign_detail::fun_repeater<Function>( sz, r );
    }
    

    template< class Function, class Argument = assign_detail::forward_n_arguments > 
    class list_inserter
    {
        struct single_arg_type {};
        struct n_arg_type      {};

        typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::if_c< is_same<Argument,assign_detail::forward_n_arguments>::value,
                                                  n_arg_type,
                                                  single_arg_type >::type arg_type;  
            
    public:
        
        list_inserter( Function fun ) : insert_( fun )
        {}
        
        template< class Function2, class Arg >
        list_inserter( const list_inserter<Function2,Arg>& r ) 
        : insert_( r.fun_private() ) 
        {}

        list_inserter( const list_inserter& r ) : insert_( r.insert_ )
        {}

        list_inserter& operator()()
        {
            insert_( Argument() );
            return *this;
        }
        
        template< class T >
        list_inserter& operator=( const T& r )
        {
            insert_( r );
            return *this;
        }
        
        template< class T >
        list_inserter& operator=( assign_detail::repeater<T> r )
        {
            return operator,( r );
        }
        
        template< class Nullary_function >
        list_inserter& operator=( const assign_detail::fun_repeater<Nullary_function>& r )
        {
            return operator,( r );
        }
        
        template< class T >
        list_inserter& operator,( const T& r )
        {
            insert_( r  );
            return *this;
        }

#if STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3205))
        template< class T >
        list_inserter& operator,( const assign_detail::repeater<T> & r )
        {
            return repeat( r.sz, r.val ); 
        }
#else
        template< class T >
        list_inserter& operator,( assign_detail::repeater<T> r )
        {
            return repeat( r.sz, r.val ); 
        }
#endif
        
        template< class Nullary_function >
        list_inserter& operator,( const assign_detail::fun_repeater<Nullary_function>& r )
        {
            return repeat_fun( r.sz, r.val ); 
        }

        template< class T >
        list_inserter& repeat( std::size_t sz, T r )
        {
            std::size_t i = 0;
            while( i++ != sz )
                insert_( r );
            return *this;
        }
        
        template< class Nullary_function >
        list_inserter& repeat_fun( std::size_t sz, Nullary_function fun )
        {
            std::size_t i = 0;
            while( i++ != sz )
                insert_( fun() );
            return *this;
        }

        template< class SinglePassIterator >
        list_inserter& range( SinglePassIterator first, 
                              SinglePassIterator last )
        {
            for( ; first != last; ++first )
                insert_( *first );
            return *this;
        }
        
        template< class SinglePassRange >
        list_inserter& range( const SinglePassRange& r )
        {
            return range( streams_boost::begin(r), streams_boost::end(r) );
        }
        
        template< class T >
        list_inserter& operator()( const T& t )
        {
            insert_( t );
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
    list_inserter& operator()(T t, STREAMS_BOOST_ASSIGN_PARAMS2(n) ) \
        { \
            STREAMS_BOOST_PP_CAT(insert, STREAMS_BOOST_PP_INC(n))(t, STREAMS_BOOST_ASSIGN_PARAMS3(n), arg_type()); \
            return *this; \
        } \
        /**/

#include STREAMS_BOOST_PP_LOCAL_ITERATE()
        

#define STREAMS_BOOST_PP_LOCAL_LIMITS (1, STREAMS_BOOST_ASSIGN_MAX_PARAMETERS)
#define STREAMS_BOOST_PP_LOCAL_MACRO(n) \
    template< class T, STREAMS_BOOST_ASSIGN_PARAMS1(n) > \
    void STREAMS_BOOST_PP_CAT(insert, STREAMS_BOOST_PP_INC(n))(T const& t, STREAMS_BOOST_ASSIGN_PARAMS2(n), single_arg_type) \
    { \
        insert_( Argument(t, STREAMS_BOOST_ASSIGN_PARAMS3(n) )); \
    } \
    /**/
        
#include STREAMS_BOOST_PP_LOCAL_ITERATE()

#define STREAMS_BOOST_PP_LOCAL_LIMITS (1, STREAMS_BOOST_ASSIGN_MAX_PARAMETERS)
#define STREAMS_BOOST_PP_LOCAL_MACRO(n) \
    template< class T, STREAMS_BOOST_ASSIGN_PARAMS1(n) > \
    void STREAMS_BOOST_PP_CAT(insert, STREAMS_BOOST_PP_INC(n))(T const& t, STREAMS_BOOST_ASSIGN_PARAMS2(n), n_arg_type) \
    { \
        insert_(t, STREAMS_BOOST_ASSIGN_PARAMS3(n) ); \
    } \
    /**/
        
#include STREAMS_BOOST_PP_LOCAL_ITERATE()

        
        Function fun_private() const
        {
            return insert_;
        }

    private:
        
        list_inserter& operator=( const list_inserter& );
        Function insert_;
    };
    
    template< class Function >
    inline list_inserter< Function >
    make_list_inserter( Function fun )
    {
        return list_inserter< Function >( fun );
    }
    
    template< class Function, class Argument >
    inline list_inserter<Function,Argument>
    make_list_inserter( Function fun, Argument* )
    {
        return list_inserter<Function,Argument>( fun );
    }

    template< class C >
    inline list_inserter< assign_detail::call_push_back<C>, 
                          STREAMS_BOOST_DEDUCED_TYPENAME C::value_type >
    push_back( C& c )
    {
        static STREAMS_BOOST_DEDUCED_TYPENAME C::value_type* p = 0;
        return make_list_inserter( assign_detail::call_push_back<C>( c ), 
                                   p );
    }
    
    template< class C >
    inline list_inserter< assign_detail::call_push_front<C>,
                          STREAMS_BOOST_DEDUCED_TYPENAME C::value_type >
    push_front( C& c )
    {
        static STREAMS_BOOST_DEDUCED_TYPENAME C::value_type* p = 0;
        return make_list_inserter( assign_detail::call_push_front<C>( c ),
                                   p );
    }

    template< class C >
    inline list_inserter< assign_detail::call_insert<C>, 
                          STREAMS_BOOST_DEDUCED_TYPENAME C::value_type >
    insert( C& c )
    {
        static STREAMS_BOOST_DEDUCED_TYPENAME C::value_type* p = 0;
        return make_list_inserter( assign_detail::call_insert<C>( c ),
                                   p );
    }

    template< class C >
    inline list_inserter< assign_detail::call_push<C>, 
                          STREAMS_BOOST_DEDUCED_TYPENAME C::value_type >
    push( C& c )
    {
        static STREAMS_BOOST_DEDUCED_TYPENAME C::value_type* p = 0;
        return make_list_inserter( assign_detail::call_push<C>( c ),
                                   p );
    }

    template< class C >
    inline list_inserter< assign_detail::call_add_edge<C> >
    add_edge( C& c )   
    {
        return make_list_inserter( assign_detail::call_add_edge<C>( c ) );
    }
    
} // namespace 'assign'
} // namespace 'streams_boost'

#undef STREAMS_BOOST_ASSIGN_PARAMS1
#undef STREAMS_BOOST_ASSIGN_PARAMS2
#undef STREAMS_BOOST_ASSIGN_PARAMS3
#undef STREAMS_BOOST_ASSIGN_MAX_PARAMETERS

#endif
