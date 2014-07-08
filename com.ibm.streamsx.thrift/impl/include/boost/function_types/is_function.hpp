
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).
//------------------------------------------------------------------------------

#ifndef STREAMS_BOOST_FT_IS_FUNCTION_HPP_INCLUDED
#define STREAMS_BOOST_FT_IS_FUNCTION_HPP_INCLUDED

#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/type_traits/detail/template_arity_spec.hpp>

#include <streams_boost/function_types/components.hpp>

namespace streams_boost 
{ 
  namespace function_types 
  {
    template< typename T, typename Tag = null_tag > 
    struct is_function
      : function_types::represents
        < function_types::components<T>
        , function_types::tag<Tag ,detail::function_tag> 
        >
    { 
      STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2,is_function,(T,Tag))
    };
  }
  STREAMS_BOOST_TT_AUX_TEMPLATE_ARITY_SPEC(2,function_types::is_function)
} 

#endif

