// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_FORWARD_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_FORWARD_HPP_INCLUDED   

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif                  
 
#include <streams_boost/config.hpp> // STREAMS_BOOST_MSVC, STREAMS_BOOST_NO_SFINAE
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/iostreams/detail/config/limits.hpp>
#include <streams_boost/iostreams/detail/push_params.hpp>
#include <streams_boost/preprocessor/arithmetic/dec.hpp>
#include <streams_boost/preprocessor/arithmetic/inc.hpp>
#include <streams_boost/preprocessor/punctuation/comma_if.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/preprocessor/tuple/elem.hpp>
#include <streams_boost/type_traits/is_same.hpp>

//------Macros for defining forwarding constructors and open overloads--------//
    
//
// Macro: STREAMS_BOOST_IOSTREAMS_FORWARD(class, impl, device, params, args)
// Description: Defines constructors and overloads of 'open' which construct
//      a device using the specified argument list and pass it to the specified
//      helper function
//   class - The class name
//   impl - The helper function
//   device - The device type
//   params - The list of formal parameters trailing the device parameter in
//     the helper function's signature
//   params - The list of arguments passed to the helper function, following the
//     device argument
//
#define STREAMS_BOOST_IOSTREAMS_FORWARD(class, impl, device, params, args) \
    class(const device& t params()) \
    { this->impl(::streams_boost::iostreams::detail::wrap(t) args()); } \
    class(device& t params()) \
    { this->impl(::streams_boost::iostreams::detail::wrap(t) args()); } \
    class(const ::streams_boost::reference_wrapper<device>& ref params()) \
    { this->impl(ref args()); } \
    void open(const device& t params()) \
    { this->impl(::streams_boost::iostreams::detail::wrap(t) args()); } \
    void open(device& t params()) \
    { this->impl(::streams_boost::iostreams::detail::wrap(t) args()); } \
    void open(const ::streams_boost::reference_wrapper<device>& ref params()) \
    { this->impl(ref args()); } \
    STREAMS_BOOST_PP_REPEAT_FROM_TO( \
        1, STREAMS_BOOST_PP_INC(STREAMS_BOOST_IOSTREAMS_MAX_FORWARDING_ARITY), \
        STREAMS_BOOST_IOSTREAMS_FORWARDING_CTOR, (class, impl, device) \
    ) \
    STREAMS_BOOST_PP_REPEAT_FROM_TO( \
        1, STREAMS_BOOST_PP_INC(STREAMS_BOOST_IOSTREAMS_MAX_FORWARDING_ARITY), \
        STREAMS_BOOST_IOSTREAMS_FORWARDING_FN, (class, impl, device) \
    ) \
    /**/
#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
# define STREAMS_BOOST_IOSTREAMS_FORWARDING_CTOR_I(z, n, tuple) \
    template< typename U100 STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_DEC(n)) \
              STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, STREAMS_BOOST_PP_DEC(n), typename U) > \
    STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, tuple) \
    ( U100& u100 STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_DEC(n)) \
      STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(z, STREAMS_BOOST_PP_DEC(n), const U, &u) \
      STREAMS_BOOST_IOSTREAMS_DISABLE_IF_SAME(U100, STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple))) \
    { this->STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, tuple) \
      ( STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple) \
        ( u100 STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_DEC(n)) \
          STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, STREAMS_BOOST_PP_DEC(n), u)) ); } \
    /**/
# define STREAMS_BOOST_IOSTREAMS_FORWARDING_FN_I(z, n, tuple) \
    template< typename U100 STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_DEC(n)) \
              STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, STREAMS_BOOST_PP_DEC(n), typename U) > \
    void open \
    ( U100& u100 STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_DEC(n)) \
      STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(z, STREAMS_BOOST_PP_DEC(n), const U, &u) \
      STREAMS_BOOST_IOSTREAMS_DISABLE_IF_SAME(U100, STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple))) \
    { this->STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, tuple) \
      ( u100 STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_DEC(n)) \
        STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, STREAMS_BOOST_PP_DEC(n), u) ); } \
    /**/
#else
# define STREAMS_BOOST_IOSTREAMS_FORWARDING_CTOR_I(z, n, tuple)
# define STREAMS_BOOST_IOSTREAMS_FORWARDING_FN_I(z, n, tuple)
#endif
#define STREAMS_BOOST_IOSTREAMS_FORWARDING_CTOR(z, n, tuple) \
    template<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, typename U)> \
    STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, tuple) \
    (STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(z, n, const U, &u) \
      STREAMS_BOOST_IOSTREAMS_DISABLE_IF_SAME(U0, STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple))) \
    { this->STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, tuple) \
      ( STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple) \
        (STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, u)) ); } \
    STREAMS_BOOST_IOSTREAMS_FORWARDING_CTOR_I(z, n, tuple) \
    /**/
#define STREAMS_BOOST_IOSTREAMS_FORWARDING_FN(z, n, tuple) \
    template<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, typename U)> \
    void open(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(z, n, const U, &u) \
      STREAMS_BOOST_IOSTREAMS_DISABLE_IF_SAME(U0, STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple))) \
    { this->STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, tuple) \
      ( STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, tuple) \
        (STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, u)) ); } \
    STREAMS_BOOST_IOSTREAMS_FORWARDING_FN_I(z, n, tuple) \
    /**/

// Disable forwarding constructors if first parameter type is the same
// as the device type
#if !defined(STREAMS_BOOST_NO_SFINAE) && \
    !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x592))
# define STREAMS_BOOST_IOSTREAMS_DISABLE_IF_SAME(device, param) \
    , typename streams_boost::disable_if< streams_boost::is_same<device, param> >::type* = 0 \
    /**/
#else 
# define STREAMS_BOOST_IOSTREAMS_DISABLE_IF_SAME(device, param)
#endif

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_FORWARD_HPP_INCLUDED
