// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_PUSH_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_PUSH_HPP_INCLUDED 

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif                    
 
#include <streams_boost/config.hpp> // STREAMS_BOOST_MSVC.
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/iostreams/categories.hpp>
#include <streams_boost/iostreams/categories.hpp>
#include <streams_boost/iostreams/detail/adapter/range_adapter.hpp>
#include <streams_boost/iostreams/detail/config/wide_streams.hpp>
#include <streams_boost/iostreams/detail/enable_if_stream.hpp>   
#include <streams_boost/iostreams/pipeline.hpp>   
#include <streams_boost/iostreams/detail/push_params.hpp>   
#include <streams_boost/iostreams/detail/resolve.hpp>
#include <streams_boost/mpl/bool.hpp>   
#include <streams_boost/preprocessor/cat.hpp> 
#include <streams_boost/preprocessor/control/iif.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/type_traits/is_convertible.hpp>

//
// Macro: STREAMS_BOOST_IOSTREAMS_DEFINE_PUSH_CONSTRUCTOR(name, mode, ch, helper).
// Description: Defines overloads with name 'name' which forward to a function
//      'helper' which takes a filter or devide by const reference.
//
#define STREAMS_BOOST_IOSTREAMS_DEFINE_PUSH_CONSTRUCTOR(name, mode, ch, helper) \
    STREAMS_BOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, 0, ?) \
    /**/

//
// Macro: STREAMS_BOOST_IOSTREAMS_DEFINE_PUSH(name, mode, ch, helper).
// Description: Defines constructors which forward to a function
//      'helper' which takes a filter or device by const reference.
//
#define STREAMS_BOOST_IOSTREAMS_DEFINE_PUSH(name, mode, ch, helper) \
    STREAMS_BOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, 1, void) \
    /**/

//--------------------Definition of STREAMS_BOOST_IOSTREAMS_DEFINE_PUSH_IMPL----------//
          
#define STREAMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, arg, helper, has_return) \
    this->helper( ::streams_boost::iostreams::detail::resolve<mode, ch>(arg) \
                  STREAMS_BOOST_IOSTREAMS_PUSH_ARGS() ); \
    /**/

#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) && \
    !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600) \
    /**/
# ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
#  define STREAMS_BOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, has_return, result) \
    template<typename CharType, typename TraitsType> \
    STREAMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(::std::basic_streambuf<CharType, TraitsType>& sb STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { STREAMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, sb, helper, has_return); } \
    template<typename CharType, typename TraitsType> \
    STREAMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(::std::basic_istream<CharType, TraitsType>& is STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { STREAMS_BOOST_STATIC_ASSERT((!is_convertible<mode, output>::value)); \
      STREAMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, is, helper, has_return); } \
    template<typename CharType, typename TraitsType> \
    STREAMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(::std::basic_ostream<CharType, TraitsType>& os STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { STREAMS_BOOST_STATIC_ASSERT((!is_convertible<mode, input>::value)); \
      STREAMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, os, helper, has_return); } \
    template<typename CharType, typename TraitsType> \
    STREAMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(::std::basic_iostream<CharType, TraitsType>& io STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { STREAMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, io, helper, has_return); } \
    template<typename Iter> \
    STREAMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(const iterator_range<Iter>& rng STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { STREAMS_BOOST_PP_EXPR_IF(has_return, return) \
    this->helper( ::streams_boost::iostreams::detail::range_adapter< \
                      mode, iterator_range<Iter> \
                  >(rng) \
                  STREAMS_BOOST_IOSTREAMS_PUSH_ARGS() ); } \
    template<typename Pipeline, typename Concept> \
    STREAMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(const ::streams_boost::iostreams::pipeline<Pipeline, Concept>& p) \
    { p.push(*this); } \
    template<typename T> \
    STREAMS_BOOST_PP_IIF(has_return, result, explicit) \
    name(const T& t STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS() STREAMS_BOOST_IOSTREAMS_DISABLE_IF_STREAM(T)) \
    { this->helper( ::streams_boost::iostreams::detail::resolve<mode, ch>(t) \
                    STREAMS_BOOST_IOSTREAMS_PUSH_ARGS() ); } \
    /**/
# else // # ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
#  define STREAMS_BOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, has_return, result) \
    STREAMS_BOOST_PP_IF(has_return, result, explicit) \
    name(::std::streambuf& sb STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { STREAMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, sb, helper, has_return); } \
    STREAMS_BOOST_PP_IF(has_return, result, explicit) \
    name(::std::istream& is STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { STREAMS_BOOST_STATIC_ASSERT((!is_convertible<mode, output>::value)); \
      STREAMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, is, helper, has_return); } \
    STREAMS_BOOST_PP_IF(has_return, result, explicit) \
    name(::std::ostream& os STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { STREAMS_BOOST_STATIC_ASSERT((!is_convertible<mode, input>::value)); \
      STREAMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, os, helper, has_return); } \
    STREAMS_BOOST_PP_IF(has_return, result, explicit) \
    name(::std::iostream& io STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { STREAMS_BOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, io, helper, has_return); } \
    template<typename Iter> \
    STREAMS_BOOST_PP_IF(has_return, result, explicit) \
    name(const iterator_range<Iter>& rng STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { STREAMS_BOOST_PP_EXPR_IF(has_return, return) \
    this->helper( ::streams_boost::iostreams::detail::range_adapter< \
                      mode, iterator_range<Iter> \
                  >(rng) \
                  STREAMS_BOOST_IOSTREAMS_PUSH_ARGS() ); } \
    template<typename Pipeline, typename Concept> \
    STREAMS_BOOST_PP_IF(has_return, result, explicit) \
    name(const ::streams_boost::iostreams::pipeline<Pipeline, Concept>& p) \
    { p.push(*this); } \
    template<typename T> \
    STREAMS_BOOST_PP_EXPR_IF(has_return, result) \
    name(const T& t STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS() STREAMS_BOOST_IOSTREAMS_DISABLE_IF_STREAM(T)) \
    { this->helper( ::streams_boost::iostreams::detail::resolve<mode, ch>(t) \
                    STREAMS_BOOST_IOSTREAMS_PUSH_ARGS() ); } \
    /**/
# endif // # ifndef STREAMS_BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
#else // #if VC6, VC7.0, Borland 5.x
# define STREAMS_BOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, has_return, result) \
    template<typename T> \
    void STREAMS_BOOST_PP_CAT(name, _msvc_impl) \
    ( ::streams_boost::mpl::true_, const T& t STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS() ) \
    { t.push(*this); } \
    template<typename T> \
    void STREAMS_BOOST_PP_CAT(name, _msvc_impl) \
    ( ::streams_boost::mpl::false_, const T& t STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS() ) \
    { this->helper( ::streams_boost::iostreams::detail::resolve<mode, ch>(t) \
                    STREAMS_BOOST_IOSTREAMS_PUSH_ARGS() ); } \
    template<typename T> \
    STREAMS_BOOST_PP_IF(has_return, result, explicit) \
    name(const T& t STREAMS_BOOST_IOSTREAMS_PUSH_PARAMS()) \
    { \
        this->STREAMS_BOOST_PP_CAT(name, _msvc_impl) \
              ( ::streams_boost::iostreams::detail::is_pipeline<T>(), \
                t STREAMS_BOOST_IOSTREAMS_PUSH_ARGS() ); \
    } \
    /**/
#endif // #if VC6, VC7.0, Borland 5.x

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_PUSH_HPP_INCLUDED
