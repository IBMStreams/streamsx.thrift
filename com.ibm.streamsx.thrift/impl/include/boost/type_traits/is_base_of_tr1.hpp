
//  (C) Copyright Rani Sharoni 2003-2005.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.
 
#ifndef STREAMS_BOOST_TT_IS_BASE_OF_TR1_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_BASE_OF_TR1_HPP_INCLUDED

#include <streams_boost/type_traits/is_base_and_derived.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/type_traits/is_class.hpp>
#include <streams_boost/type_traits/detail/ice_or.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost { namespace tr1{

   namespace detail{
      template <class B, class D>
      struct is_base_of_imp
      {
          typedef typename remove_cv<B>::type ncvB;
          typedef typename remove_cv<D>::type ncvD;
          STREAMS_BOOST_STATIC_CONSTANT(bool, value = (::streams_boost::type_traits::ice_or<      
            (::streams_boost::detail::is_base_and_derived_impl<ncvB,ncvD>::value),
            (::streams_boost::is_same<ncvB,ncvD>::value)>::value));
      };
   }

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF2(
      is_base_of
    , Base
    , Derived
    , (::streams_boost::tr1::detail::is_base_of_imp<Base, Derived>::value))

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_2(typename Base,typename Derived,is_base_of,Base&,Derived,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_2(typename Base,typename Derived,is_base_of,Base,Derived&,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_2(typename Base,typename Derived,is_base_of,Base&,Derived&,false)
#endif

} } // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_BASE_OF_TR1_HPP_INCLUDED
