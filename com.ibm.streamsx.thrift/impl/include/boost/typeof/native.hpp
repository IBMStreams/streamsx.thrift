// Copyright (C) 2006 Arkadiy Vertleyb
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_NATIVE_HPP_INCLUDED
#define STREAMS_BOOST_TYPEOF_NATIVE_HPP_INCLUDED

#ifndef MSVC_TYPEOF_HACK

#ifdef STREAMS_BOOST_NO_SFINAE

namespace streams_boost { namespace type_of {

    template<class T> 
        T& ensure_obj(const T&);

}}

#else

#include <streams_boost/type_traits/is_function.hpp> 
#include <streams_boost/utility/enable_if.hpp>

namespace streams_boost { namespace type_of {
# ifdef STREAMS_BOOST_NO_SFINAE
    template<class T> 
    T& ensure_obj(const T&);
# else
    template<typename T>
        typename enable_if<is_function<T>, T&>::type
        ensure_obj(T&);

    template<typename T>
        typename disable_if<is_function<T>, T&>::type
        ensure_obj(const T&);
# endif
}}

#endif//STREAMS_BOOST_NO_SFINAE

#define STREAMS_BOOST_TYPEOF(expr) STREAMS_BOOST_TYPEOF_KEYWORD(streams_boost::type_of::ensure_obj(expr))
#define STREAMS_BOOST_TYPEOF_TPL STREAMS_BOOST_TYPEOF

#define STREAMS_BOOST_TYPEOF_NESTED_TYPEDEF_TPL(name,expr) \
    struct name {\
        typedef STREAMS_BOOST_TYPEOF_TPL(expr) type;\
    };

#define STREAMS_BOOST_TYPEOF_NESTED_TYPEDEF(name,expr) \
    struct name {\
        typedef STREAMS_BOOST_TYPEOF(expr) type;\
    };

#endif//MSVC_TYPEOF_HACK

#define STREAMS_BOOST_TYPEOF_REGISTER_TYPE(x)
#define STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(x, params)

#endif//STREAMS_BOOST_TYPEOF_NATIVE_HPP_INCLUDED

