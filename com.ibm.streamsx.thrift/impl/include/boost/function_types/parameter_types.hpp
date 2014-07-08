
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef STREAMS_BOOST_FT_PARAMETER_TYPES_HPP_INCLUDED
#define STREAMS_BOOST_FT_PARAMETER_TYPES_HPP_INCLUDED

#include <streams_boost/blank.hpp>
#include <streams_boost/mpl/if.hpp>

#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/type_traits/detail/template_arity_spec.hpp>

#include <streams_boost/mpl/pop_front.hpp>

#include <streams_boost/function_types/is_callable_builtin.hpp>
#include <streams_boost/function_types/components.hpp>

namespace streams_boost 
{ 
  namespace function_types 
  {
    using mpl::placeholders::_;
 
    template< typename T, typename ClassTypeTransform = add_reference<_> >
    struct parameter_types;

    namespace detail
    {
      template<typename T, typename ClassTypeTransform> 
      struct parameter_types_impl
        : mpl::pop_front
          < typename function_types::components<T,ClassTypeTransform>::types 
          >::type
      { };
    }

    template<typename T, typename ClassTypeTransform> struct parameter_types
      : mpl::if_
        < function_types::is_callable_builtin<T>
        , detail::parameter_types_impl<T,ClassTypeTransform>, streams_boost::blank
        >::type
    {
      STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2,parameter_types,(T,ClassTypeTransform)) 
    };
  }
  STREAMS_BOOST_TT_AUX_TEMPLATE_ARITY_SPEC(2,function_types::parameter_types)
}

#endif

