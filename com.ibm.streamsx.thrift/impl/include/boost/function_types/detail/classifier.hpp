
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef STREAMS_BOOST_FT_DETAIL_CLASSIFIER_HPP_INCLUDED
#define STREAMS_BOOST_FT_DETAIL_CLASSIFIER_HPP_INCLUDED

#include <streams_boost/type.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/type_traits/config.hpp>
#include <streams_boost/type_traits/is_reference.hpp>
#include <streams_boost/type_traits/add_reference.hpp>

#include <streams_boost/function_types/config/config.hpp>
#include <streams_boost/function_types/property_tags.hpp>

namespace streams_boost { namespace function_types { namespace detail {

template<typename T> struct classifier;

template<std::size_t S> struct char_array { typedef char (&type)[S]; };

template<bits_t Flags, bits_t CCID, std::size_t Arity> struct encode_charr
{
  typedef typename char_array<
    ::streams_boost::function_types::detail::encode_charr_impl<Flags,CCID,Arity>::value 
  >::type type;
};

char STREAMS_BOOST_TT_DECL classifier_impl(...);

#define STREAMS_BOOST_FT_variations STREAMS_BOOST_FT_function|STREAMS_BOOST_FT_pointer|\
                            STREAMS_BOOST_FT_member_pointer

#define STREAMS_BOOST_FT_type_function(cc,name) STREAMS_BOOST_FT_SYNTAX( \
    R STREAMS_BOOST_PP_EMPTY,STREAMS_BOOST_PP_LPAREN,cc,* STREAMS_BOOST_PP_EMPTY,name,STREAMS_BOOST_PP_RPAREN)

#define STREAMS_BOOST_FT_type_function_pointer(cc,name) STREAMS_BOOST_FT_SYNTAX( \
    R STREAMS_BOOST_PP_EMPTY,STREAMS_BOOST_PP_LPAREN,cc,** STREAMS_BOOST_PP_EMPTY,name,STREAMS_BOOST_PP_RPAREN)

#define STREAMS_BOOST_FT_type_member_function_pointer(cc,name) STREAMS_BOOST_FT_SYNTAX( \
    R STREAMS_BOOST_PP_EMPTY,STREAMS_BOOST_PP_LPAREN,cc,T0::** STREAMS_BOOST_PP_EMPTY,name,STREAMS_BOOST_PP_RPAREN)

#define STREAMS_BOOST_FT_al_path streams_boost/function_types/detail/classifier_impl
#include <streams_boost/function_types/detail/pp_loop.hpp>

template<typename T> struct classifier_bits
{
  static typename streams_boost::add_reference<T>::type tester;

  STREAMS_BOOST_STATIC_CONSTANT(bits_t,value = (bits_t)sizeof(
    streams_boost::function_types::detail::classifier_impl(& tester) 
  )-1);
};

template<typename T> struct classifier
{
  typedef detail::constant<
    ::streams_boost::function_types::detail::decode_bits<
      ::streams_boost::function_types::detail::classifier_bits<T>::value
    >::tag_bits > 
  bits;

  typedef detail::full_mask mask;
 
  typedef detail::constant<
    ::streams_boost::function_types::detail::decode_bits<
      ::streams_boost::function_types::detail::classifier_bits<T>::value
    >::arity > 
  function_arity;
};



} } } // namespace ::streams_boost::function_types::detail

#endif

