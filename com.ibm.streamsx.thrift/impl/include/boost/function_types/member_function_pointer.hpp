
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef STREAMS_BOOST_FT_MEMBER_FUNCTION_POINTER_HPP_INCLUDED
#define STREAMS_BOOST_FT_MEMBER_FUNCTION_POINTER_HPP_INCLUDED

#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/type_traits/detail/template_arity_spec.hpp>

#include <streams_boost/function_types/detail/synthesize.hpp>
#include <streams_boost/function_types/detail/to_sequence.hpp>

namespace streams_boost 
{ 
  namespace function_types 
  {
    template<typename Types, typename Tag = null_tag> 
    struct member_function_pointer
      : detail::synthesize_mfp< typename detail::to_sequence<Types>::type, Tag >
    { 
      STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2,member_function_pointer,(Types,Tag))
    };
  } 
  STREAMS_BOOST_TT_AUX_TEMPLATE_ARITY_SPEC(2,function_types::member_function_pointer)
} 

#endif

