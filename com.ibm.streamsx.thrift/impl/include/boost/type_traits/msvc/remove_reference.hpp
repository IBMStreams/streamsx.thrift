// Copyright (C) 2004 Peder Holt
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPE_TRAITS_MSVC_REMOVE_REFERENCE_HOLT_2004_0827
#define STREAMS_BOOST_TYPE_TRAITS_MSVC_REMOVE_REFERENCE_HOLT_2004_0827

#include <streams_boost/type_traits/msvc/typeof.hpp>
#include <streams_boost/type_traits/is_reference.hpp>

namespace streams_boost {
    namespace detail {
        template<bool IsReference>
        struct remove_reference_impl_typeof {
            template<typename T,typename ID>
            struct inner {
                typedef T type;
            };
        };
        template<>
        struct remove_reference_impl_typeof<true> {
            template<typename T,typename ID>
            struct inner {
                template<typename U>
                static msvc_register_type<U,ID> test(U&(*)());
                static msvc_register_type<T,ID> test(...);
                STREAMS_BOOST_STATIC_CONSTANT(unsigned,register_test=sizeof(test( (T(*)())(NULL) ) ));
                typedef typename msvc_extract_type<ID>::id2type::type type;
            };
        };
    } //namespace detail
    
    template<typename T>
    struct remove_reference {
        typedef typename detail::remove_reference_impl_typeof<
            streams_boost::is_reference<T>::value
        >::template inner<T,remove_reference<T> >::type type;
        STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,remove_reference,T)
    };
} //namespace streams_boost

#endif //STREAMS_BOOST_TYPE_TRAITS_MSVC_REMOVE_REFERENCE_HOLT_2004_0827
