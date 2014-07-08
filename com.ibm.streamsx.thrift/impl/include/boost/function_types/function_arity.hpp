
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef STREAMS_BOOST_FT_FUNCTION_ARITY_HPP_INCLUDED
#define STREAMS_BOOST_FT_FUNCTION_ARITY_HPP_INCLUDED

#include <streams_boost/blank.hpp>
#include <streams_boost/mpl/if.hpp>

#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/type_traits/detail/template_arity_spec.hpp>

#include <streams_boost/function_types/is_callable_builtin.hpp>
#include <streams_boost/function_types/components.hpp>

namespace streams_boost 
{ 
  namespace function_types 
  {
    template<typename T> struct function_arity
      : mpl::if_
        < function_types::is_callable_builtin<T>
        , typename components<T>::function_arity, streams_boost::blank
        >::type
    {
      STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,function_arity,(T)) 
    };
  }
  STREAMS_BOOST_TT_AUX_TEMPLATE_ARITY_SPEC(1,function_types::function_arity)
}

#endif

