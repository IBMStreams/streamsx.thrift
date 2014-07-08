// Copyright (C) 2004 Peder Holt
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPE_TRAITS_MSVC_REMOVE_VOLATILE_HOLT_2004_0828
#define STREAMS_BOOST_TYPE_TRAITS_MSVC_REMOVE_VOLATILE_HOLT_2004_0828

#include <streams_boost/type_traits/msvc/typeof.hpp>
#include <streams_boost/type_traits/is_volatile.hpp>
#include <streams_boost/type_traits/is_const.hpp>
#include <streams_boost/type_traits/is_pointer.hpp>
#include <streams_boost/type_traits/is_array.hpp>

namespace streams_boost {
    namespace detail {
        template<bool IsPointer,bool IsArray,bool IsConst,bool IsVolatile>
        struct remove_volatile_impl_typeof {
            template<typename T,typename ID>
            struct inner {
                typedef T type;
            };
            template<typename T>
            struct transform_type {
                typedef T type;
            };
        };
        template<> //Volatile
        struct remove_volatile_impl_typeof<false,false,false,true> {
            template<typename T,typename ID>
            struct inner {
                template<typename U>
                static msvc_register_type<U,ID> test(U volatile&(*)());
                static msvc_register_type<T,ID> test(...);
                STREAMS_BOOST_STATIC_CONSTANT(unsigned,register_test=sizeof(test( (T(*)())(NULL) ) ));
                typedef typename msvc_extract_type<ID>::id2type::type type;
            };            
            template<typename T>
            struct transform_type {
                typedef T& type;
            };
        };
        template<> //CV
        struct remove_volatile_impl_typeof<false,false,true,true> {
            template<typename T,typename ID>
            struct inner {
                template<typename U>
                static msvc_register_type<U const,ID> test(U const volatile&(*)());
                static msvc_register_type<T,ID> test(...);
                STREAMS_BOOST_STATIC_CONSTANT(unsigned,register_test=sizeof(test( (T(*)())(NULL) ) ));
                typedef typename msvc_extract_type<ID>::id2type::type type;
            };
            template<typename T>
            struct transform_type {
                typedef T& type;
            };
        };
        template<> //Volatile Pointer
        struct remove_volatile_impl_typeof<true,false,false,true> {
            template<typename T,typename ID>
            struct inner {
                template<typename U>
                static msvc_register_type<U,ID> test(void(*)(U volatile[]));
                static msvc_register_type<T,ID> test(...);
                STREAMS_BOOST_STATIC_CONSTANT(unsigned,register_test=sizeof(test( (void(*)(T))(NULL) ) ));
                typedef typename msvc_extract_type<ID>::id2type::type type;
            };
            template<typename T>
            struct transform_type {
                typedef T type[];
            };
        };
        template<> //CV Pointer
        struct remove_volatile_impl_typeof<true,false,true,true> {
            template<typename T,typename ID>
            struct inner {
                template<typename U>
                static msvc_register_type<U const,ID> test(void(*)(U const volatile[]));
                static msvc_register_type<T,ID> test(...);
                STREAMS_BOOST_STATIC_CONSTANT(unsigned,register_test=sizeof(test( (void(*)(T))(NULL) ) ));
                typedef typename msvc_extract_type<ID>::id2type::type type;
            };
            template<typename T>
            struct transform_type {
                typedef T type[];
            };
        };        
        template<> //Volatile Array
        struct remove_volatile_impl_typeof<false,true,false,true> {
            template<typename T,typename ID>
            struct inner {
                STREAMS_BOOST_STATIC_CONSTANT(unsigned,value=(sizeof(T)/sizeof((*((T*)NULL))[0])));

                template<typename U>
                static msvc_register_type<U[value],ID> test(void(*)(U volatile[]));
                static msvc_register_type<T,ID> test(...);
                STREAMS_BOOST_STATIC_CONSTANT(unsigned,register_test=sizeof(test( (void(*)(T))(NULL) ) ));
                typedef typename msvc_extract_type<ID>::id2type::type type;                
            };
            template<typename T>
            struct transform_type {
                typedef T type;
            };
        };

        template<> //CV Array
        struct remove_volatile_impl_typeof<false,true,true,true> {
            template<typename T,typename ID>
            struct inner {
                STREAMS_BOOST_STATIC_CONSTANT(unsigned,value=(sizeof(T)/sizeof((*((T*)NULL))[0])));

                template<typename U>
                static msvc_register_type<U const[value],ID> test(void(*)(U const volatile[]));
                static msvc_register_type<T,ID> test(...);
                STREAMS_BOOST_STATIC_CONSTANT(unsigned,register_test=sizeof(test( (void(*)(T))(NULL) ) ));
                typedef typename msvc_extract_type<ID>::id2type::type type;
            };
            template<typename T>
            struct transform_type {
                typedef T type;
            };
        };

    } //namespace detail

    template<typename T>
    struct remove_volatile {
        typedef detail::remove_volatile_impl_typeof<
            streams_boost::is_pointer<T>::value,
            streams_boost::is_array<T>::value,
            streams_boost::is_const<T>::value,
            streams_boost::is_volatile<T>::value
        > remove_volatile_type;
        typedef typename 
            remove_volatile_type::template inner<
                typename remove_volatile_type::template transform_type<T>::type,
                remove_volatile<T>
            >::type
        type;
        STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,remove_volatile,T)
    };
}//namespace streams_boost

#endif //STREAMS_BOOST_TYPE_TRAITS_MSVC_REMOVE_VOLATILE_HOLT_2004_0828
